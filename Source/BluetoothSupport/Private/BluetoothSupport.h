// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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