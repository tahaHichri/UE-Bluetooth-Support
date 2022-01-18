/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/

#pragma once

#include "CoreDelegates.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BluetoothSupportBPLibrary.generated.h"


UCLASS()
class UBluetoothSupportBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



	UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
	static bool IsBluetoothSupported();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static void ShowAndroidToast(FString toastString);

	UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
	static bool IsGeolocationEnabled();

	UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
	static bool IsBluetoothEnabled();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static bool EnableBluetooth();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static bool DisableBluetooth();

	UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
	static bool IsLowEnergySupported();

	UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
	static bool IsBluetoothScanning();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static void StopBluetoothScan();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static TArray<UBluetoothDevice*> GetDiscoveredDevices();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
	static void ClearDiscoveredDevicesList();

	/** These functions are for c++ only: */

	static bool ScanBLEdevices(int32 scanTimeout, int64 scanReportDelay);
	
	static bool ScanByCharacteristic(int32 scanTimeout, int64 scanReportDelay, FString serviceUUID, FString deviceAddress);
};
