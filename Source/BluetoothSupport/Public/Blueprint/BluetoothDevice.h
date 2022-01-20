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
	FDateTime	lastDiscovery;
	int32       periodicAdvertisingInterval;
	int32       txPower;
	bool        isConnectable;

	bool canAccessBLEParameters;


	void InitDevice(FString stringifiedDeviceInformation, bool BLEScanned);

	/** 
	 * Get device name (not alias).
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FString GetFriendlyName() { return name; }

	/** 
	 * Get MAC bluetooth device address.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FString GetAddress() { return address; }

	/** 
	 * You are able to get rssi only when the device was obtained while scanning in BLE mode.
	 * If the device was get in some other way then this value is -200.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetRssi() { return rssi; }

	/** 
	 * You are able to get periodicAdvertisingInterval only when the device was obtained while scanning in BLE mode.
	 * If the device was get in some other way then this value is -200.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetPeriodicAdvertisingInterval() { return periodicAdvertisingInterval; }

	/** 
	 * You are able to get txPower only when the device was obtained while scanning in BLE mode.
	 * If the device was get in some other way then this value is -200.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	int32 GetTxPower() { return txPower; }

	/** 
	 * Lastseen parameter is set only when the device was obtained while scanning in BLE mode.
	 * If you get the device in some other way then this value is 01.01.1970, 00:00:00 GMT.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	FDateTime GetLastSeen() { return lastDiscovery; }

	/** 
	 * IsConnectable parameter is set only when the device was obtained while scanning in BLE mode.
	 * If you get the device in some other way then this value is definitely false.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	bool IsConnectable() { return isConnectable; };

	/** 
	 * If you can read rssi, lastDiscovery, periodicAdvertisingInterval, txPower and isConnectable parameters.
	 */
	UFUNCTION(BlueprintPure, Category = "Bluetooth Device") FORCEINLINE 
	bool IsBLEScanned() { return canAccessBLEParameters; };
};
