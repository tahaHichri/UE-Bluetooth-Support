/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/

#pragma once


#include "Interfaces/BluetoothOperationsInterface.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#include "EngineMinimal.h"
#include "Core.h"
#include <string>

#include "../BluetoothSupport.h"


class FAndroidGateway : public IBluetoothOperationsInterface
{
public:
	FAndroidGateway();
	virtual ~FAndroidGateway() {}

	virtual bool IsBluetoothSupported()		override;
	virtual void ShowAndroidToast(FString toastString)		override;
	virtual bool IsGeolocationEnabled()		override;

	virtual bool IsEnabled()				override;
	virtual bool EnableBluetoothAdapter()	override;
	virtual bool DisableBluetoothAdapter()  override;
	virtual TArray<UBluetoothDevice*> GetBoundedDevices() override;
	virtual bool IsBLESupported()			override;
	virtual bool IsScanning()				override;

	virtual bool ScanBLEdevices(int32 scanTimeout, int64 scanReportDelay)													override;
	virtual bool ScanByCharacteristic(int32 scanTimeout, int64 scanReportDelay, FString serviceUUID, FString deviceAddress)	override;
	virtual void StopScan()					   override;
	virtual TArray<UBluetoothDevice*> GetDiscoveredDevices()	override;
	virtual void ClearDiscoveredDevicesList()  override;

	jmethodID IsBluetoothSupportedMethod;
	jmethodID ShowAndroidToastMethod;
	jmethodID IsGeolocationEnabledMethod;

	jmethodID IsEnabledMethod;
	jmethodID EnableBluetoothAdapterMethod;
	jmethodID DisableBluetoothAdapterMethod;
	jmethodID GetBoundedDevicesMethod;
	jmethodID IsBLESupportedMethod;
	jmethodID IsScanningMethod;

	jmethodID ScanBLEdevicesMethod;
	jmethodID ScanByCharacteristicMethod;
	jmethodID StopScanMethod;
	jmethodID GetDiscoveredDevicesMethod;
	jmethodID ClearDiscoveredDevicesListMethod;
};