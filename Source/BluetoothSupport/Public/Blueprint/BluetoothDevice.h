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
#include "BluetoothDevice.generated.h"

UCLASS(Blueprintable)
class UBluetoothDevice : public UObject
{
	GENERATED_BODY()

public:
	FString     address;
	int32       rssi;

	// Returned with API > 26.
	int32       periodicAdvertisingInterval;	
	int32       txPower;

	int32		lastDiscovery;
	bool        isConnectable;


	void InitDevice(FString stringifiedDeviceInformation);

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FString GetAddress() { return address; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetRssi() { return rssi; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetPeriodicAdvertisingInterval() { return periodicAdvertisingInterval; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetTxPower() { return txPower; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetLastSeen() { return lastDiscovery; }

	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	bool IsConnectable() { return isConnectable; };
};
