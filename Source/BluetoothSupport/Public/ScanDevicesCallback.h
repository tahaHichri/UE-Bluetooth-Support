#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "../Private/BluetoothSupport.h"
#include "Blueprint/BluetoothDevice.h"
#include "BluetoothSupportBPLibrary.h"
#include "ScanDevicesCallback.generated.h"


UCLASS()
class  UScanDevicesCallback : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	FString searchService;
	FString searchAddress;
	int32 searchTimeout;

	FDeviceScanSucceedCompleteDelegate SucceedDelegate;
	FDelegateHandle SucceedDelegateHandle;

	void OnSucceedComplete(UBluetoothDevice* Device);
public:
	UPROPERTY(BlueprintAssignable)
	FDeviceScanSuccessDelegate OnResultFound;

	UScanDevicesCallback() :
		SucceedDelegate(FDeviceScanSucceedCompleteDelegate::CreateUObject(this, &ThisClass::OnSucceedComplete)) {}

	/**
	* Service UUID and MAC addr are optional filters.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Scan Nearby Bluetooth Devices", ToolTip = "Discover all nearby broadcasting devices", 
		BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress);

	virtual void Activate() override;
};
