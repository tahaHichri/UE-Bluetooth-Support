/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothDevice.h"

void UBluetoothDevice::InitDevice(FString stringifiedDeviceInformation)
{
	// Split stringified information
	// "address|rssi|periodicAdvertisingInterval|txPower|isConnectable".

	TArray<FString> DeviceInfoArr = {};
	stringifiedDeviceInformation.ParseIntoArray(DeviceInfoArr, TEXT("|"), true);

	address	= DeviceInfoArr[0];
	rssi = FCString::Atoi(*DeviceInfoArr[1]);
	periodicAdvertisingInterval = FCString::Atoi(*DeviceInfoArr[2]);
	txPower = FCString::Atoi(*DeviceInfoArr[3]);
	isConnectable = (DeviceInfoArr[4] == "true") ? true : false;
	lastDiscovery = FCString::Atoi(*DeviceInfoArr[5]);
}