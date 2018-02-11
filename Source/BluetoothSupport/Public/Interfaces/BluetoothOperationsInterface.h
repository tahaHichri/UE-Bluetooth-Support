/**
* ! Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @copyright  Open Source project - 2018
* @license    This program is free software: you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the Free Software
*  Foundation, either version 3 of the License, or (at your option) any later version.
* @see        https://github.com/hishriTaha - hishri.com
*/

#pragma once


#include "Core.h"
#include "EngineMinimal.h"
#include "../Blueprint/BluetoothDevice.h"


class IBluetoothOperationsInterface
{ 
public:
	virtual bool IsEnabled() = 0;
	virtual bool EnableBluetoothAdapter() = 0;
	virtual bool DisableBluetoothAdapter() = 0;
	virtual bool IsBLESupported() =	0;
	virtual bool IsScanning() = 0;

	virtual bool ScanBLEdevices(int32 scanTimeout) = 0;
	virtual bool ScanByCharacteristic(int32 scanTimeout, FString characteristicUUID) = 0;
	virtual void StopScan() = 0;
	virtual TArray<UBluetoothDevice*> GetDiscoveredDevices() = 0;
	virtual void ClearDiscoveredDevicesList() = 0;
};

