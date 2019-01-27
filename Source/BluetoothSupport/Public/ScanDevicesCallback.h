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


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Find Launch By MAC address", BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Bluetooth Support Plugin")
	static UScanDevicesCallback* ScanDeviceByMACaddr(FString deviceAddr);


	virtual void Activete_imp() override;

};
