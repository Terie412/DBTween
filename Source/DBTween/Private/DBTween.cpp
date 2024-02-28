// Copyright 2020-2021, DearBing. All Rights Reserved.

#include "DBTween.h"

#define LOCTEXT_NAMESPACE "FDBTweenModule"

void FDBTweenModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FDBTweenModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDBTweenModule, DBTween)
