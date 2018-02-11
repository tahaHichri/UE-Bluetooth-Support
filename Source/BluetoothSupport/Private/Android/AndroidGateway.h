/**
* ! Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @copyright  Open Source project - 2018
* @license    This program is free software: you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the Free Software
*  Foundation, either version 3 of the License, or (at your option) any later version.
* @see        https://github.com/hishriTaha - hishri.com
*/

#pragma once


#include "Interfaces/BluetoothOperationsInterface.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#include "EngineMinimal.h"
#include "Core.h"
#include <string>


class FAndroidGateway : public IBluetoothOperationsInterface
{
public:
	FAndroidGateway();
	virtual ~FAndroidGateway();

	virtual bool IsEnabled()				override;

	virtual bool EnableBluetoothAdapter()	override;
	virtual bool DisableBluetoothAdapter()  override;
	virtual bool IsBLESupported()			override;
	virtual bool IsScanning()				override;

	virtual bool ScanBLEdevices(int32 scanTimeout)									 override;
	virtual bool ScanByCharacteristic(int32 scanTimeout, FString characteristicUUID)	 override;

	virtual void StopScan()					   override;

	virtual void ClearDiscoveredDevicesList()  override;

	virtual TArray<UBluetoothDevice*> GetDiscoveredDevices()	override;

	// JNI Methods
	static jmethodID IsEnabledMethod;

	static jmethodID EnableBluetoothAdapterMethod;
	static jmethodID DisableBluetoothAdapterMethod;
	static jmethodID IsBLESupportedMethod;
	static jmethodID IsScanningMethod;
	static jmethodID ScanBLEdevicesMethod;
	static jmethodID ScanByCharacteristicMethod;

	static jmethodID StopScanMethod;

	static jmethodID GetDiscoveredDevicesMethod;
	static jmethodID ClearDiscoveredDevicesListMethod;

	static jclass NativeBluetoothDeviceClass;



};