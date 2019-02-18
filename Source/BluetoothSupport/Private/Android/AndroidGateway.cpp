/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/



#pragma once	
// 
#include "AndroidGateway.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"


jmethodID FAndroidGateway::IsEnabledMethod;

jmethodID FAndroidGateway::EnableBluetoothAdapterMethod;
jmethodID FAndroidGateway::DisableBluetoothAdapterMethod;
jmethodID FAndroidGateway::IsBLESupportedMethod;
jmethodID FAndroidGateway::IsScanningMethod;

jmethodID FAndroidGateway::ScanBLEdevicesMethod;
jmethodID FAndroidGateway::ScanByCharacteristicMethod;
jmethodID FAndroidGateway::StopScanMethod;
jmethodID FAndroidGateway::GetDiscoveredDevicesMethod;
jmethodID FAndroidGateway::ClearDiscoveredDevicesListMethod;

//jclass	  FAndroidGateway::NativeBluetoothDeviceClass;



	FAndroidGateway::FAndroidGateway()
	{
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			DisableBluetoothAdapterMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "disableBluetooth", "()V", false);
			IsBLESupportedMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothLowEnergySupported", "()Z", false);
			IsScanningMethod				= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isScanning", "()Z", false);
			EnableBluetoothAdapterMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "enableBluetooth", "()V", false);

			IsEnabledMethod						= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "isBluetoothEnabled", "()Z", false);
			ScanBLEdevicesMethod				= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "startLEScan", "(I)V", false);
			ScanByCharacteristicMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "scanByCharacteristic", "(ILjava/lang/String;)V", false);
			StopScanMethod						= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "stopLEScan", "()V", false);
			
			
			GetDiscoveredDevicesMethod			= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "getDiscoveredDevices", "()[Ljava/lang/String;", false);
			ClearDiscoveredDevicesListMethod	= FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "clearDiscoveredDevices", "()V", false);

			
			// Find the inner class
			//NativeBluetoothDeviceClass =  Env->FindClass("GameActivity$CBluetoothDevice");

		}
	}

	FAndroidGateway::~FAndroidGateway()
	{
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


	bool FAndroidGateway::IsBLESupported()
	{
		bool bResult = false;
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::IsBLESupportedMethod);
		}
		return bResult;
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


	bool FAndroidGateway::ScanBLEdevices(int32 scanTimeout)
	{
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ScanBLEdevicesMethod, (jvalue*)(jlong)scanTimeout);
			return true;
		}
		return false;
	}



	bool FAndroidGateway::ScanByCharacteristic(int32 scanTimeout, FString characteristicUUID)
	{
		if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
		{
			jstring jStringParam = Env->NewStringUTF( (std::string( TCHAR_TO_UTF8(*characteristicUUID) )).c_str());

			if (!jStringParam)
			{
				UE_LOG(LogTemp, Fatal, TEXT("Could Not generate jstring from uuid"));
			}

			FJavaWrapper::CallVoidMethod( Env, FJavaWrapper::GameActivityThis, FAndroidGateway::ScanByCharacteristicMethod, scanTimeout, jStringParam);
			
			 Env->DeleteLocalRef(jStringParam);
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
			// TODO parse and do stuff
			jobjectArray BluetoothDevicesStrArr = (jobjectArray) Env->CallObjectMethod(FJavaWrapper::GameActivityThis, FAndroidGateway::GetDiscoveredDevicesMethod);
			
			int BluetoothDevicesStrArrSize = Env->GetArrayLength(BluetoothDevicesStrArr);

			// splitting Devices info and creating a new Device object
			for (int i = 0; i < BluetoothDevicesStrArrSize; ++i)
			{
				jstring string = (jstring) Env->GetObjectArrayElement(BluetoothDevicesStrArr, i);
				
				const char* mayarray = Env->GetStringUTFChars(string, 0);

				UBluetoothDevice* Ubd = NewObject<UBluetoothDevice>();
				Ubd->InitDevice(mayarray);

				DiscoveredDevices.Add(Ubd);

				Env->ReleaseStringUTFChars(string, mayarray);
				Env->DeleteLocalRef(string);
			}

			return DiscoveredDevices;
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



	/**
	** Callback from JAVA activity class
	*/
	static void TriggerScanDeviceCallback(UBluetoothDevice* Ubd)
	{
		FBluetoothSupportModule * Module = FModuleManager::Get().LoadModulePtr<FBluetoothSupportModule>("BluetoothSupport");
		if (Module != nullptr)
		{

			Module->TriggerDeviceScanSucceedCompleteDelegates(Ubd);

			Module = NULL;
		}
	}

	static FCriticalSection ReceiversLock;

	extern "C"
	{
		JNIEXPORT void Java_com_epicgames_ue4_GameActivity_scanNativeResultCallback(JNIEnv * jni, jclass clazz, jstring code)
		{
			ReceiversLock.Lock();
			const char* charsId = jni->GetStringUTFChars(code, 0);

			UBluetoothDevice* Ubd = NewObject<UBluetoothDevice>();
			Ubd->InitDevice(charsId);

			// OurString = FString(UTF8_TO_TCHAR(charsId));

			TriggerScanDeviceCallback(Ubd);

			jni->ReleaseStringUTFChars(code, charsId);
			ReceiversLock.Unlock();
		}
	}