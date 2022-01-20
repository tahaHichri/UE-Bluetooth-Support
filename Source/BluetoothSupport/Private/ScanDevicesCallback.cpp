#include "ScanDevicesCallback.h"
#include "BluetoothSupportBPLibrary.h"

TArray<UScanDevicesCallback*> UScanDevicesCallback::instances = {};

void UScanDevicesCallback::Activate()
{
	// Run scan finished function on all other instances.
	while (UScanDevicesCallback::instances.Num() > 0) {
		UScanDevicesCallback::instances.Pop(true)->OnScanFinishedFunction();
	}
	instances.AddUnique(this);

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
	UScanDevicesCallback::instances.Remove(this);
	OnScanFinished.Broadcast();

	SetReadyToDestroy();
}