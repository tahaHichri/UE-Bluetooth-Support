/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#pragma once
#include "CString.h"
#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "BluetoothDevice.generated.h"

UCLASS(Blueprintable)
class UBluetoothDevice : public UObject
{
	GENERATED_BODY()

public:
	FString     name;
	FString     address;
	int32       rssi;
	FDateTime		lastDiscovery;

	// Returned with API >= 26. See comments below for values in case of API < 26.
	// If bluetoothLowEnergy is enabled then you can be sure that API >= 26.
	int32       periodicAdvertisingInterval;	// 0 
	int32       txPower;						// 127
	bool        isConnectable;					// false


	void InitDevice(FString stringifiedDeviceInformation);

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FString GetFriendlyName() { return name; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FString GetAddress() { return address; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetRssi() { return rssi; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetPeriodicAdvertisingInterval() { return periodicAdvertisingInterval; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetTxPower() { return txPower; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FDateTime GetLastSeen() { return lastDiscovery; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	bool IsConnectable() { return isConnectable; };
};
