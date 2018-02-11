// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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