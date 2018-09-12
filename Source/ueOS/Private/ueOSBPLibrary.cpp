// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ueOSBPLibrary.h"
#include "ueOS.h"

UueOSBPLibrary::UueOSBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UueOSBPLibrary::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UueOSBPLibrary::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}

bool UueOSBPLibrary::GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	FPaths::NormalizeDirectoryName(RootFolderFullPath);

	IFileManager& FileManager = IFileManager::Get();

	if (Ext == "")
	{
		Ext = "*.*";
	}
	else
	{
		Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
	}

	FString FinalPath = RootFolderFullPath + "/" + Ext;
	FileManager.FindFiles(Files, *FinalPath, true, true);

	return true;
}

int32 UueOSBPLibrary::GetFileSize(FString RootFolderFullPath) {
	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*RootFolderFullPath)) { return -1; }

	const int32 FileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*RootFolderFullPath);

	return FileSize;
}
