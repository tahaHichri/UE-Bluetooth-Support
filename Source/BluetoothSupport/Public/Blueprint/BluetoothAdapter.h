/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* hishri.com - 2018
*/

#pragma once

#include "CoreMinimal.h"
#include "BluetoothAdapter.generated.h"

UCLASS(Blueprintable)
class UBluetoothAdapter : public UObject
{

	GENERATED_BODY()
	
public:
		//UBluetoothAdapter(const FObjectInitializer& ObjectInitializer);
		
		FString Name;
		FString LocalAddress;

		static UBluetoothAdapter* GetInstance();

		//UBluetoothAdapter();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool IsEnabled();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool EnableBluetooth();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool DisableBluetooth();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool IsLowEnergySupported();


		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool ScanBLEdevices(int32 scanTimeout);
		
		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool ScanByCharacteristic(int32 scanTimeout, FString characteristicUUID);


		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		void StopScan();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		bool IsScanning();


		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		TArray<UBluetoothDevice*> GetDiscoveredDevices();

		UFUNCTION(BlueprintCallable, Category = "Bluetooth Support Plugin")
		void ClearDiscoveredDevicesList();



	
};
