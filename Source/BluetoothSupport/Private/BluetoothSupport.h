/**
* !Created By Taha HICHRI
* @project    Bluetooth Support for UNREAL engine.
* @author     Taha HICHRI <hishri.taha@gmail.com>
* @see        https://github.com/hishriTaha
* Copyright (c) 2018 hishri.com
*/

#pragma once

#include "Modules/ModuleManager.h"
#include "TaDispatcher.h"
#include "../Public/BluetoothSupportBPLibrary.h"

#define LOCTEXT_NAMESPACE "BluetoothSupport"




DECLARE_MULTICAST_DELEGATE_OneParam(FDeviceScanSucceedComplete, UBluetoothDevice*);
typedef FDeviceScanSucceedComplete::FDelegate FDeviceScanSucceedCompleteDelegate;



#define DEFINE_SCAN_DELEGATE_BASE(DelegateName) \
public: \
	F##DelegateName DelegateName##Delegates; \
public: \
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
	virtual void ClearAll##DelegateName##Delegate_Handle() \
	{ \
		DelegateName##Delegates.Clear(); \
	}




#define DEFINE_SCAN_DELEGATE_ONE_PARAM(DelegateName, Param1Type) \
	DEFINE_SCAN_DELEGATE_BASE(DelegateName) \
	virtual void Trigger##DelegateName##Delegates(Param1Type Param1) \
	{ \
		DelegateName##Delegates.Broadcast(Param1); \
	}



class FBluetoothSupportModule : public TaDispatcher
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	DEFINE_SCAN_DELEGATE_ONE_PARAM(DeviceScanSucceedComplete, UBluetoothDevice*);

};