#include "ScanDevicesCallback.h"

FString searchService;
FString searchAddress;
int32 searchTimeout;
UScanDevicesCallback* UScanDevicesCallback::ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	searchTimeout = timeout;
	searchService = FString(serviceUUID);
	searchAddress = FString(deviceAddress);
	return Proxy;
}

void UScanDevicesCallback::Activete_imp()
{
	// characteristic is optional, scan without filters if not present
	if (searchService.IsEmpty() && searchAddress.IsEmpty())
	{
		UBluetoothAdapter::ScanBLEdevices(searchTimeout);
	} 
	else {
		UBluetoothAdapter::ScanByCharacteristic(searchTimeout, searchService, searchAddress);
	}
	
	// call scan device start
}