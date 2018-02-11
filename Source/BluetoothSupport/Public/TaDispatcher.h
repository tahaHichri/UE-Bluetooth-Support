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

#include "ModuleManager.h"
#include "EngineMinimal.h"
#include "Core.h"
#include "Interfaces/BluetoothOperationsInterface.h"


typedef TSharedPtr<IBluetoothOperationsInterface, ESPMode::ThreadSafe> FAndroidGatewayPtr;

class TaDispatcher : public IModuleInterface
{
public:
	static inline TaDispatcher& Get()
	{
		return FModuleManager::LoadModuleChecked< TaDispatcher >("BluetoothSupport");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("BluetoothSupport");
	}

	inline FAndroidGatewayPtr GetAndroidGatewayInterface() const
	{
		return AndroidGatewayInterface;
	}

protected:
	FAndroidGatewayPtr AndroidGatewayInterface;
};
