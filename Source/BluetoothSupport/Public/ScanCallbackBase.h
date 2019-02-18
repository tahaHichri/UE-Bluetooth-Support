#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "../Private/BluetoothSupport.h"
#include "Blueprint/BluetoothDevice.h"
#include "BluetoothSupportBPLibrary.h"
#include "ScanCallbackBase.generated.h"


UCLASS()
class  UScanCallbackBase : public UBlueprintAsyncActionBase {
	GENERATED_BODY()

public:

	UScanCallbackBase();

	
	UPROPERTY(BlueprintAssignable)
	FDeviceScanSuccessDelegate OnResultFound;

	virtual void Activate() override;
	virtual void Activete_imp();
	virtual void PostSucceedComplete(UBluetoothDevice* Device);

private:

	FDeviceScanSucceedCompleteDelegate SucceedDelegate;
	FDelegateHandle SucceedDelegateHandle;

	void OnSucceedComplete(UBluetoothDevice* Device);

};