/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#include "BluetoothSupport.h"
#include "BluetoothSupportBPLibrary.h"


IMPLEMENT_MODULE(FBluetoothSupportModule, BluetoothSupport)

// for legacy code, this is done repeatedly with every method call.
// I am tiying this module's lifecycle with the game engine's lifecycle
FBluetoothSupportModule* TaModule = NULL;


void FBluetoothSupportModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// AndroidGateway relies heavily on Android-specific dependencies, hence, won't be loaded unless we are building for android.
	#if PLATFORM_ANDROID
		AndroidGatewayInterface = MakeShareable(new FAndroidGateway());
	#endif

	TaModule = &FModuleManager::LoadModuleChecked<FBluetoothSupportModule>("BluetoothSupport");
	
}

void FBluetoothSupportModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	TaModule = NULL;
	
}

#undef LOCTEXT_NAMESPACE