#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ScanCallbackBase.h"
#include "ScanDevicesCallback.generated.h"


UCLASS()
class  UScanDevicesCallback : public UScanCallbackBase
{
	GENERATED_BODY()


public:


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Search all nearby BLE devices", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanDeviceByMACaddr(int32 timeout);


	virtual void Activete_imp() override;

};
