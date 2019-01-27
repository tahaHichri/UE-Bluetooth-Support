/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
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

// Changing async
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


