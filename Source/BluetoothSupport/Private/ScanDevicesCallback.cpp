#include "ScanDevicesCallback.h"

FString searchDeviceAddr;
UScanDevicesCallback* UScanDevicesCallback::ScanDeviceByMACaddr(FString deviceAddr)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	searchDeviceAddr = deviceAddr;
	return Proxy;
}

void UScanDevicesCallback::Activete_imp()
{
	UBluetoothSupportBPLibrary::findNearbyLaunchDevice(searchDeviceAddr);
	// call scan device start
}