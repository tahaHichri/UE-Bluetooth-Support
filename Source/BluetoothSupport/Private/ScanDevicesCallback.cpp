#include "ScanDevicesCallback.h"


UScanDevicesCallback* UScanDevicesCallback::ScanNearbyDevices(int32 timeout, const FString& serviceUUID, const FString& deviceAddress)
{
	UScanDevicesCallback* Proxy = NewObject<UScanDevicesCallback>();
	Proxy->searchTimeout = timeout;
	Proxy->searchService = FString(serviceUUID);
	Proxy->searchAddress = FString(deviceAddress);
	return Proxy;
}

void UScanDevicesCallback::Activete_imp()
{
	// Characteristic is optional, scan without filters if not present.
	if (searchService.IsEmpty() && searchAddress.IsEmpty())
	{
		UBluetoothAdapter::ScanBLEdevices(searchTimeout);
	} 
	else {
		UBluetoothAdapter::ScanByCharacteristic(searchTimeout, searchService, searchAddress);
	}
	
	// Call scan device start.
}