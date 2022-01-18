/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothSupportBPLibrary.h"
#include "TaDispatcher.h"

UBluetoothSupportBPLibrary::UBluetoothSupportBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}

bool UBluetoothSupportBPLibrary::IsBluetoothSupported()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsBluetoothSupported();
#endif
	return false;
}

void UBluetoothSupportBPLibrary::ShowAndroidToast(FString string)
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ShowAndroidToast(string);
#endif
}

bool UBluetoothSupportBPLibrary::IsGeolocationEnabled()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsGeolocationEnabled();
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::IsBluetoothEnabled()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsEnabled();
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::EnableBluetooth()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->EnableBluetoothAdapter();
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::DisableBluetooth()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->DisableBluetoothAdapter();
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::IsLowEnergySupported()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsBLESupported();
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::IsBluetoothScanning()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->IsScanning();
#endif
	return false;
}

void UBluetoothSupportBPLibrary::StopBluetoothScan()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->StopScan();
#endif
}

TArray<UBluetoothDevice*> UBluetoothSupportBPLibrary::GetDiscoveredDevices()
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->GetDiscoveredDevices();
#endif
	return {};
}

void UBluetoothSupportBPLibrary::ClearDiscoveredDevicesList()
{
#if PLATFORM_ANDROID
	TaDispatcher::Get().GetAndroidGatewayInterface()->ClearDiscoveredDevicesList();
#endif
}

bool UBluetoothSupportBPLibrary::ScanBLEdevices(int32 scanTimeout, int64 scanReportDelay)
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanBLEdevices(scanTimeout, scanReportDelay);
#endif
	return false;
}

bool UBluetoothSupportBPLibrary::ScanByCharacteristic(int32 scanTimeout, int64 scanReportDelay, FString serviceUUID, FString deviceAddress)
{
#if PLATFORM_ANDROID
	return TaDispatcher::Get().GetAndroidGatewayInterface()->ScanByCharacteristic(scanTimeout, scanReportDelay, serviceUUID, deviceAddress);
#endif
	return false;
}