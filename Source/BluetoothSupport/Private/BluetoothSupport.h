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

#include "../Public/Blueprint/BluetoothDevice.h"

#define LOCTEXT_NAMESPACE "BluetoothSupport"


DECLARE_MULTICAST_DELEGATE_OneParam(FDeviceScanSucceedComplete, UBluetoothDevice*);
typedef FDeviceScanSucceedComplete::FDelegate FDeviceScanSucceedCompleteDelegate;


class FBluetoothSupportModule : public TaDispatcher
{
public:

	/** IModuleInterface implementation. */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private: 
	FDeviceScanSucceedComplete DeviceScanSucceedCompleteDelegates; 

public: 
	virtual FDelegateHandle AddDeviceScanSucceedCompleteDelegate_Handle(const FDeviceScanSucceedCompleteDelegate& Delegate) 
	{ 
		DeviceScanSucceedCompleteDelegates.Add(Delegate); 
		return Delegate.GetHandle(); 
	} 

	virtual void ClearAllDeviceScanSucceedCompleteDelegate_Handle() 
	{ 
		DeviceScanSucceedCompleteDelegates.Clear(); 
	}

	virtual void TriggerDeviceScanSucceedCompleteDelegates(UBluetoothDevice* Param1) 
	{ 
		DeviceScanSucceedCompleteDelegates.Broadcast(Param1); 
	}
};