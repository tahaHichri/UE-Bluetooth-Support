/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#pragma once

#include "CoreMinimal.h"
#include "BluetoothAdapter.generated.h"

UCLASS(Blueprintable)
class UBluetoothAdapter : public UObject
{

	GENERATED_BODY()
	
public:
		FString Name;
		FString LocalAddress;

		static UBluetoothAdapter* GetInstance();

		UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
		bool IsEnabled();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool EnableBluetooth();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool DisableBluetooth();

		UFUNCTION(BlueprintPure, Category = "Bluetooth Support Plugin")
		bool IsLowEnergySupported();

		static bool ScanBLEdevices(int32 scanTimeout);
		
		static bool ScanByCharacteristic(int32 scanTimeout, FString serviceUUID, FString deviceAddress);


		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		void StopScan();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool IsScanning();


		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		TArray<UBluetoothDevice*> GetDiscoveredDevices();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		void ClearDiscoveredDevicesList();
};
