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

#include "BluetoothAdapter.h"

UBluetoothAdapter* UBluetoothAdapter::GetInstance()
{
	static UBluetoothAdapter Inst;
	return &Inst;
}


bool UBluetoothAdapter::IsEnabled()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsEnabled();
#endif
	return false;
}


bool UBluetoothAdapter::EnableBluetooth()
{
	#if PLATFORM_ANDROID
		return TaDispatcher::Get().GetAndroidGatewayInterface()->EnableBluetoothAdapter();
	#endif
	return false;
}


bool UBluetoothAdapter::DisableBluetooth()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->DisableBluetoothAdapter();
#endif
	return false;
}



bool UBluetoothAdapter::IsLowEnergySupported()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsBLESupported();
#endif
	return false;
}



bool UBluetoothAdapter::ScanBLEdevices(int32 scanTimeout)
{
	// 
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanBLEdevices( scanTimeout );
#endif
	return false;
}


bool UBluetoothAdapter::ScanByCharacteristic(int32 scanTimeout, FString characteristicUUID)
{
	// 
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanByCharacteristic(scanTimeout, characteristicUUID);
#endif
	return false;
}



void UBluetoothAdapter::StopScan()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->StopScan();
#endif
}



bool UBluetoothAdapter::IsScanning()
{
	//
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsScanning();
#endif
	return false;
}


TArray<UBluetoothDevice*> UBluetoothAdapter::GetDiscoveredDevices()
{
	TArray<UBluetoothDevice*> DiscoveredDevices;
	// 
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->GetDiscoveredDevices();
#endif
	return DiscoveredDevices;
}


void UBluetoothAdapter::ClearDiscoveredDevicesList()
{
	//
#if PLATFORM_ANDROID
	TaDispatcher::Get().GetAndroidGatewayInterface()->ClearDiscoveredDevicesList();
#endif
}



