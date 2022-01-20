#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "../Private/BluetoothSupport.h"
#include "Blueprint/BluetoothDevice.h"
#include "ScanDevicesCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeviceScanSuccessDynamicDelegate, UBluetoothDevice*, Device);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDeviceScanFinishDynamicDelegate);

UCLASS()
class  UScanDevicesCallback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	/** 
	 * This allows us to call multiple nodes.
	 */
	static TArray<UScanDevicesCallback*> instances;

	int32 searchTimeout;
	int64 scanReportDelay;
	FString searchService;
	FString searchAddress;

	FDeviceScanSucceedCompleteDelegate SucceedDelegate;
	FDelegateHandle SucceedDelegateHandle;

	FDeviceScanFinishDelegate FinishDelegate;
	FDelegateHandle FinishDelegateHandle;

	void OnSucceedComplete(UBluetoothDevice* Device);

	void OnScanFinishedFunction();

public:
	UPROPERTY(BlueprintAssignable)
	FDeviceScanSuccessDynamicDelegate OnResultFound;

	UPROPERTY(BlueprintAssignable)
	FDeviceScanFinishDynamicDelegate OnScanFinished;

	UScanDevicesCallback() :
		SucceedDelegate(FDeviceScanSucceedCompleteDelegate::CreateUObject(this, &UScanDevicesCallback::OnSucceedComplete)),
		FinishDelegate(FDeviceScanFinishDelegate::CreateUObject(this, &UScanDevicesCallback::OnScanFinishedFunction)) {}

	/**
	* Use BLE to scan for devices. Before calling this function make sure that the phone support BLE and Bluetooth & Geolocation are enabled.
	* Service UUID and MAC addr are optional filters. You can set them both for more strict filter.
	* @param timeout Time in milliseconds for scanning.
	* @param scanReportDelay If > 0 then delay for milliseconds & then return multiple scan reports.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Scan Nearby Bluetooth Devices",
		BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanNearbyDevices(int32 timeout, 
													const FString& serviceUUID, const FString& deviceAddress, int64 scanReportDelay = 5000);

	virtual void Activate() override;
};
