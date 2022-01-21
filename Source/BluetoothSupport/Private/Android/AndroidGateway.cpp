/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/

#pragma once	
#include "AndroidGateway.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Async.h"

FAndroidGateway::FAndroidGateway()
{
	// Java signatures: http://www.rgagnon.com/javadetails/java-0286.html.
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		IsBluetoothSupportedMethod		= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothSupported", "()Z", false);
		ShowAndroidToastMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "ShowToast", "(Ljava/lang/String;)V", false);
		IsGeolocationEnabledMethod		= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isGeolocationEnabled", "()Z", false);

		IsEnabledMethod					= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothEnabled", "()Z", false);
		EnableBluetoothAdapterMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "enableBluetooth", "()V", false);
		DisableBluetoothAdapterMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "disableBluetooth", "()V", false);
		GetBoundedDevicesMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getBluetoothBoundedDevices", "()[Ljava/lang/String;", false);
		IsBLESupportedMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothLowEnergySupported", "()Z", false);
		IsScanningMethod				= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isScanning", "()Z", false);

		ScanBLEdevicesMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startLEScan", "(IJ)V", false);
		ScanByCharacteristicMethod		= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startFilteredScan", "(IJLjava/lang/String;Ljava/lang/String;)V", false);
		StopScanMethod					= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "stopLEScan", "()V", false);
		GetDiscoveredDevicesMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getDiscoveredDevices", "()[Ljava/lang/String;", false);
		ClearDiscoveredDevicesListMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearDiscoveredDevices", "()V", false);
	}
}

bool FAndroidGateway::IsBluetoothSupported()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsBluetoothSupportedMethod);
	}
	return bResult;
}

void FAndroidGateway::ShowAndroidToast(FString toastString) 
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jstringMessageParam = Env->NewStringUTF(TCHAR_TO_UTF8(*toastString));
		if (!jstringMessageParam) {
			UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring from toastString"));
		}
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ShowAndroidToastMethod, jstringMessageParam);
		Env->DeleteLocalRef(jstringMessageParam);
	}
}

bool FAndroidGateway::IsGeolocationEnabled()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsGeolocationEnabledMethod);
	}
	return bResult;
}

bool FAndroidGateway::IsEnabled()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		return FJavaWrapper::CallBooleanMethod(Env,
											   FJavaWrapper::GameActivityThis,
											   FAndroidGateway::IsEnabledMethod);
	}
	return false;
}

bool FAndroidGateway::EnableBluetoothAdapter()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env,
									 FJavaWrapper::GameActivityThis,
									 FAndroidGateway::EnableBluetoothAdapterMethod);
		return true;
	}
	return false;
}

bool FAndroidGateway::DisableBluetoothAdapter()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env,
									 FJavaWrapper::GameActivityThis,
									 FAndroidGateway::DisableBluetoothAdapterMethod);
		return true;
	}
	return false;
}

TArray<UBluetoothDevice*> FAndroidGateway::GetBoundedDevices()
{
	TArray<UBluetoothDevice*> BoundedDevices;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jobjectArray BluetoothDevicesStrArr = (jobjectArray)Env->CallObjectMethod(FJavaWrapper::GameActivityThis, FAndroidGateway::GetBoundedDevicesMethod);
		int BluetoothDevicesStrArrSize = Env->GetArrayLength(BluetoothDevicesStrArr);

		// Splitting Devices info and creating a new Device object.
		for (int i = 0; i < BluetoothDevicesStrArrSize; ++i)
		{
			jstring string = (jstring)Env->GetObjectArrayElement(BluetoothDevicesStrArr, i);
			
			const char* mayarray = Env->GetStringUTFChars(string, 0);

			UBluetoothDevice* Ubd = NewObject<UBluetoothDevice>();
			Ubd->InitDevice(UTF8_TO_TCHAR(mayarray), false);

			BoundedDevices.Add(Ubd);

			Env->ReleaseStringUTFChars(string, mayarray);
			Env->DeleteLocalRef(string);
		}
	}
	return BoundedDevices;
}

bool FAndroidGateway::IsBLESupported()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsBLESupportedMethod);
	}
	return bResult;
}

bool FAndroidGateway::IsScanning()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsScanningMethod);
	}
	return bResult;
}

bool FAndroidGateway::ScanBLEdevices(int32 scanTimeout, int64 scanReportDelay)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ScanBLEdevicesMethod, (jint)scanTimeout, (jlong)scanReportDelay);
		return true;
	}
	return false;
}

bool FAndroidGateway::ScanByCharacteristic(int32 scanTimeout, int64 scanReportDelay, FString serviceUUID, FString deviceAddr)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring jStringUUIDParam = Env->NewStringUTF(TCHAR_TO_UTF8(*serviceUUID));
		jstring jStringAddrParam = Env->NewStringUTF(TCHAR_TO_UTF8(*deviceAddr));

		if (!jStringUUIDParam || !jStringAddrParam)
		{
			UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring from uuid or address string"));
		}

		FJavaWrapper::CallVoidMethod(Env, 
									 FJavaWrapper::GameActivityThis, 
									 FAndroidGateway::ScanByCharacteristicMethod, 
									 (jint)scanTimeout, 
									 (jlong)scanReportDelay,
									 jStringUUIDParam, 
									 jStringAddrParam);
		
		Env->DeleteLocalRef(jStringUUIDParam);
		Env->DeleteLocalRef(jStringAddrParam);
		return true;
	}
	return false;
}

void FAndroidGateway::StopScan()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::StopScanMethod);
	}
}

TArray<UBluetoothDevice*> FAndroidGateway::GetDiscoveredDevices()
{
	TArray<UBluetoothDevice*> DiscoveredDevices;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jobjectArray BluetoothDevicesStrArr = (jobjectArray)Env->CallObjectMethod(FJavaWrapper::GameActivityThis, FAndroidGateway::GetDiscoveredDevicesMethod);
		int BluetoothDevicesStrArrSize = Env->GetArrayLength(BluetoothDevicesStrArr);

		// Splitting Devices info and creating a new Device object.
		for (int i = 0; i < BluetoothDevicesStrArrSize; ++i)
		{
			jstring string = (jstring)Env->GetObjectArrayElement(BluetoothDevicesStrArr, i);
			
			const char* mayarray = Env->GetStringUTFChars(string, 0);

			UBluetoothDevice* Ubd = NewObject<UBluetoothDevice>();
			Ubd->InitDevice(UTF8_TO_TCHAR(mayarray), true);

			DiscoveredDevices.Add(Ubd);

			Env->ReleaseStringUTFChars(string, mayarray);
			Env->DeleteLocalRef(string);
		}
	}
	return DiscoveredDevices;
}

void FAndroidGateway::ClearDiscoveredDevicesList()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ClearDiscoveredDevicesListMethod);
	}
}

/** See native java functions implementation (where we use this macro)...
 */
#define CALL_BLSUPPORTMODULE_METHOD(FunctionAndArguments) \
	FBluetoothSupportModule * Module = FModuleManager::Get().LoadModulePtr<FBluetoothSupportModule>("BluetoothSupport"); \
	if (Module != nullptr) \
	{ \
		Module->FunctionAndArguments; \
		Module = NULL; \
	}


static FCriticalSection ReceiversLock;

extern "C"
{
	JNIEXPORT void Java_com_epicgames_ue4_GameActivity_scanNativeResultCallback(JNIEnv * jni, jclass clazz, jstring code)
	{
		ReceiversLock.Lock();
		const char* charsId = jni->GetStringUTFChars(code, 0);

		UBluetoothDevice* Ubd = NewObject<UBluetoothDevice>();
		Ubd->InitDevice(FString(UTF8_TO_TCHAR(charsId)), true);

		CALL_BLSUPPORTMODULE_METHOD(TriggerDeviceScanSucceedCompleteDelegates(Ubd));

		jni->ReleaseStringUTFChars(code, charsId);
		ReceiversLock.Unlock();
	}

	JNIEXPORT void Java_com_epicgames_ue4_GameActivity_scanNativeFinishedCallback(JNIEnv * jni, jclass clazz)
	{
		CALL_BLSUPPORTMODULE_METHOD(TriggerDeviceScanFinishDelegates());
	}

	JNIEXPORT void Java_com_epicgames_ue4_GameActivity_printDebugUEMessage(JNIEnv * jni, jclass clazz, jstring message)
	{
		const char* charsId = jni->GetStringUTFChars(message, 0);

		FString debug_Message = FString(UTF8_TO_TCHAR(charsId));

		if(GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, debug_Message);  
		}

		jni->ReleaseStringUTFChars(message, charsId);
	}
}