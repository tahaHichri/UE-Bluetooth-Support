// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BluetoothSupport.h"
#include "BluetoothSupportBPLibrary.h"


IMPLEMENT_MODULE(FBluetoothSupportModule, BluetoothSupport)


void FBluetoothSupportModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// AndroidGateway relies heavily on Android-specific dependencies, hence, won't be loaded unless we are building for android.
	#if PLATFORM_ANDROID
		AndroidGatewayInterface = MakeShareable(new FAndroidGateway());
	#endif
	
}

void FBluetoothSupportModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE