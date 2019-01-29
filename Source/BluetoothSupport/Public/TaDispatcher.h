/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/


#pragma once

#include "Modules/ModuleManager.h"
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
