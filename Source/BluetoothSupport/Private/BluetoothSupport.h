/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
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