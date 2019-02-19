#include "ScanDevicesCallback.h"

FString searchCharacteristic;
int32 searchTimeout;
UScanDevicesCallback* UScanDevicesCallback::ScanNearbyDevices(int32 timeout, const FString& characteristic)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	searchTimeout = timeout;
	searchCharacteristic = FString(characteristic);
	return Proxy;
}

void UScanDevicesCallback::Activete_imp()
{
	// characteristic is optional, scan without filters if not present
	if (searchCharacteristic.IsEmpty())
	{
		UBluetoothAdapter::ScanBLEdevices(searchTimeout);
	}
	else {
		UBluetoothAdapter::ScanByCharacteristic(searchTimeout, searchCharacteristic);
	}
	
	// call scan device start
}