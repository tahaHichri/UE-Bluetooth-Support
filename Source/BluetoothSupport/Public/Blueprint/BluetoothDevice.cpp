/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothDevice.h"

void UBluetoothDevice::InitDevice(FString stringifiedDeviceInformation, bool BLEScanned)
{
	// Split stringified information
	// "name|address|rssi|periodicAdvertisingInterval|txPower|isConnectable|lastDiscovery".

	TArray<FString> DeviceInfoArr = {};
	stringifiedDeviceInformation.ParseIntoArray(DeviceInfoArr, TEXT("|"), true);

	checkf(DeviceInfoArr.Num() == 7, TEXT("Invalid device information string"));

	name = DeviceInfoArr[0];
	address	= DeviceInfoArr[1];
	rssi = FCString::Atoi(*DeviceInfoArr[2]);
	periodicAdvertisingInterval = FCString::Atoi(*DeviceInfoArr[3]);
	txPower = FCString::Atoi(*DeviceInfoArr[4]);
	isConnectable = (DeviceInfoArr[5] == "true") ? true : false;
	// Java' method getTime() returns the time from January 1, 1970, 00:00:00 GMT in milliseconds, so we devide by 1000.
	lastDiscovery = FDateTime::FromUnixTimestamp((int64)FCString::Atoi64(*DeviceInfoArr[6])/1000);

	this->canAccessBLEParameters = BLEScanned;
}