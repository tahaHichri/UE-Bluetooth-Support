/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* hishri.com - 2018
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

	// Returned with API > 26
	int32       periodicAdvertisingInterval;	
	int32       txPower;

	int32		lastDiscovery;
	bool        isConnectable;


	void InitDevice(FString stringifiedDeviceInformation);

	
	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	FString GetAddress();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	int32 GetRssi();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	int32 GetPeriodicAdvertisingInterval();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	int32 GetTxPower();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	int32 GetLastSeen();

	UFUNCTION(BlueprintCallable, Category = "Bluetooth Device")
	bool IsConnectable();


};
