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

DECLARE_MULTICAST_DELEGATE(FDeviceScanFinish);
typedef FDeviceScanFinish::FDelegate FDeviceScanFinishDelegate;

#define DEFINE_DELEGATE_HANDLERS_METHODS(DelegateName) \
	virtual FDelegateHandle Add##DelegateName##Delegate_Handle(const F##DelegateName##Delegate& Delegate) \
	{ \
		DelegateName##Delegates.Add(Delegate); \
		return Delegate.GetHandle(); \
	} \
	virtual void Clear##DelegateName##Delegate_Handle(FDelegateHandle& Handle) \
	{ \
		DelegateName##Delegates.Remove(Handle); \
		Handle.Reset(); \
	}\
	virtual void ClearAll##DelegateName##Delegate_Handles() \
	{ \
		DelegateName##Delegates.Clear(); \
	}

class FBluetoothSupportModule : public TaDispatcher
{
public:

	/** IModuleInterface implementation. */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private: 
	FDeviceScanSucceedComplete DeviceScanSucceedCompleteDelegates; 
	FDeviceScanFinish DeviceScanFinishDelegates;

public: 
	DEFINE_DELEGATE_HANDLERS_METHODS(DeviceScanSucceedComplete)
	DEFINE_DELEGATE_HANDLERS_METHODS(DeviceScanFinish)

	virtual void TriggerDeviceScanSucceedCompleteDelegates(UBluetoothDevice* Param1) 
	{ 
		DeviceScanSucceedCompleteDelegates.Broadcast(Param1); 
	}

	virtual void TriggerDeviceScanFinishDelegates() 
	{ 
		DeviceScanFinishDelegates.Broadcast();
	}
};