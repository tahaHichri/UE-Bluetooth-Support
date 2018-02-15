/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* hishri.com - 2018
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