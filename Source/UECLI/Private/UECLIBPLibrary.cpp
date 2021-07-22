// Copyright Epic Games, Inc. All Rights Reserved.

#include "UECLIBPLibrary.h"
#include "GenericPlatform/GenericApplication.h"
//#include "SlateApplication.h"
#include "UECLI.h"

UUECLIBPLibrary::UUECLIBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UUECLIBPLibrary::AreCapsLocked()
{
	return FSlateApplication::Get().GetModifierKeys().AreCapsLocked();
}

