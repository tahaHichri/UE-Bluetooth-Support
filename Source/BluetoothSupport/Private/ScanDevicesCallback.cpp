#include "ScanDevicesCallback.h"
#include "BluetoothSupportBPLibrary.h"
#include "Async.h"

/**
 * Only one UScanDeviceCallback can be binded to OnResultFound event.
 */
static FCriticalSection FinishHandlerAccessLock;
/**
 * If multiple UScanDevicesCallback will try to start scanning for devices, we allow only one of them 
 * (others will get OnScanFinishedFunction event immidiately after they started the scanning).
 */
static FCriticalSection ActivateFunctionLock;

void UScanDevicesCallback::Activate()
{
	ActivateFunctionLock.Lock();
	/* If scanning is already started then the call scanBLEdevices(ScanByCharacteristic) will trigger our FinishDelegateHandle.
	** To overcome this problem we stop the scan here ourself.
	** Also there may be situation when one UScanDevicesCallback locked FinishHandlerAccessLock and created bindings, but has not been
	** start the scan yet and other UScanDevicesCallback made this condition check, saw that scanning haven't started yet and blocked on 
	** FinishHandlerAccessLock. To othercome this problem we make all the Activate() function as critical section (see ActivateFunctionLock).
	*/
	if (UBluetoothSupportBPLibrary::IsBluetoothScanning()) {
		UBluetoothSupportBPLibrary::StopBluetoothScan();
	}

	/* Took semaphore. Wait until other instance of this class will remove handlers bindnig.
	** So finish bind function will be called only once.
	*/
	FinishHandlerAccessLock.Lock();

	SucceedDelegateHandle = TaModule->AddDeviceScanSucceedCompleteDelegate_Handle(SucceedDelegate);
	FinishDelegateHandle = TaModule->AddDeviceScanFinishDelegate_Handle(FinishDelegate);
	if (searchTimeout <= scanReportDelay) {
		UE_LOG(LogTemp, Warning, TEXT("Scan stop will fire before scan report."));
	}
	checkf(searchTimeout > 0 && scanReportDelay >= 0, TEXT("Invalid parameters passed to scan function."));

	// Characteristic is optional, scan without filters if not present.
	if (searchService.IsEmpty() && searchAddress.IsEmpty())
	{
		UBluetoothSupportBPLibrary::ScanBLEdevices(searchTimeout, scanReportDelay);
	} 
	else {
		UBluetoothSupportBPLibrary::ScanByCharacteristic(searchTimeout, scanReportDelay, searchService, searchAddress);
	}
	ActivateFunctionLock.Unlock();
}

UScanDevicesCallback* UScanDevicesCallback::ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress, int64 scanReportDelay)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	Proxy->searchTimeout = timeout;
	Proxy->scanReportDelay = scanReportDelay;
	Proxy->searchService = FString(serviceUUID);
	Proxy->searchAddress = FString(deviceAddress);
	return Proxy;
}

void UScanDevicesCallback::OnSucceedComplete(UBluetoothDevice* Device)
{
	OnResultFound.Broadcast(Device);
}

void UScanDevicesCallback::OnScanFinishedFunction()
{
	TaModule->ClearDeviceScanSucceedCompleteDelegate_Handle(SucceedDelegateHandle);
	TaModule->ClearDeviceScanFinishDelegate_Handle(FinishDelegateHandle);
	OnScanFinished.Broadcast();

	// Release semaphore. Other UScanDevicesCallback can now bind functions to OnFinish event & start scanning process.
	FinishHandlerAccessLock.Unlock();

	SetReadyToDestroy();
}