/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothSupportBPLibrary.h"
#include "BluetoothSupport.h"


static UBluetoothAdapter* BluetoothAdapterIns;

UBluetoothSupportBPLibrary::UBluetoothSupportBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BluetoothAdapterIns = NewObject<UBluetoothAdapter>();
}

UBluetoothAdapter* UBluetoothSupportBPLibrary::GetBluetoothAdapter()
{
	return BluetoothAdapterIns;
}