/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* hishri.com - 2018
*/
#pragma once

#include "CoreDelegates.h"
#include "Blueprint/BluetoothAdapter.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BluetoothSupportBPLibrary.generated.h"

/* 
 *	Function library class.
 */
UCLASS()
class UBluetoothSupportBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		// The only method that can be called directly from BP.
		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		static UBluetoothAdapter* GetBluetoothAdapter();
};
