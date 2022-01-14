#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ScanCallbackBase.h"
#include "ScanDevicesCallback.generated.h"


UCLASS()
class  UScanDevicesCallback : public UScanCallbackBase
{
	GENERATED_BODY()

	FString searchService;
	FString searchAddress;
	int32 searchTimeout;
public:

	/**
	* Service UUID and MAC addr are optional filters, if both are empty, nothing will be done.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Scan Nearby Bluetooth Devices", ToolTip = "Discover all nearby broadcasting devices", 
		BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress);


	virtual void Activete_imp() override;

};
