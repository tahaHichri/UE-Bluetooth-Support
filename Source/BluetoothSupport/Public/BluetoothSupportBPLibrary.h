// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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
