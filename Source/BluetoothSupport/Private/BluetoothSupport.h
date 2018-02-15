/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* hishri.com - 2018
*/

#pragma once

#include "ModuleManager.h"
#include "TaDispatcher.h"

#define LOCTEXT_NAMESPACE "BluetoothSupport"

class FBluetoothSupportModule : public TaDispatcher
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};