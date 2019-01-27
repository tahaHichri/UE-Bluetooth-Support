#include "ScanDevicesCallback.h"

FString searchDeviceAddr;
int32 searchTimeout;
UScanDevicesCallback* UScanDevicesCallback::ScanDeviceByMACaddr(int32 timeout)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	searchTimeout = timeout;
	return Proxy;
}

void UScanDevicesCallback::Activete_imp()
{
	UBluetoothAdapter::ScanBLEdevices(searchTimeout);
	// call scan device start
}