#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "../Private/BluetoothSupport.h"
#include "Blueprint/BluetoothDevice.h"
#include "ScanDevicesCallback.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeviceScanSuccessDelegate, UBluetoothDevice*, Device);

UCLASS()
class  UScanDevicesCallback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	int32 searchTimeout;
	int64 scanReportDelay;
	FString searchService;
	FString searchAddress;

	FDeviceScanSucceedCompleteDelegate SucceedDelegate;
	FDelegateHandle SucceedDelegateHandle;

	void OnSucceedComplete(UBluetoothDevice* Device);
public:
	UPROPERTY(BlueprintAssignable)
	FDeviceScanSuccessDelegate OnResultFound;

	UScanDevicesCallback() :
		SucceedDelegate(FDeviceScanSucceedCompleteDelegate::CreateUObject(this, &UScanDevicesCallback::OnSucceedComplete)) {}

	/**
	* Service UUID and MAC addr are optional filters.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Scan Nearby Bluetooth Devices", ToolTip = "Discover all nearby broadcasting devices", 
		BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress, int64 scanReportDelay = 5000);

	virtual void Activate() override;
};
