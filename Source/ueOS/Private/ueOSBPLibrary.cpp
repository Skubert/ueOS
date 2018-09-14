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

bool UueOSBPLibrary::CreateDirectory(FString NewDir)
{ 
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	NewDir = FPaths::GameContentDir() + NewDir;

	// Directory Exists? 
	if (!PlatformFile.DirectoryExists(*NewDir)) { 
		
		PlatformFile.CreateDirectory(*NewDir);

		if (!PlatformFile.DirectoryExists(*NewDir)) {
			return false; 
		} 
	} return true; 
} 

bool UueOSBPLibrary::DeleteFile(FString RootFolderFullPath) {

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*RootFolderFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::MoveFile(FString SourceFullPath, FString DestinationFullPath) {

	SourceFullPath = FPaths::GameContentDir() + SourceFullPath;
	DestinationFullPath = FPaths::GameContentDir() + DestinationFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*SourceFullPath)) {
		return false;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().MoveFile(*DestinationFullPath, *SourceFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::CopyFile(FString SourceFullPath, FString DestinationFullPath) {

	SourceFullPath = FPaths::GameContentDir() + SourceFullPath;
	DestinationFullPath = FPaths::GameContentDir() + DestinationFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*SourceFullPath)) {
		return false;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().CopyFile(*DestinationFullPath, *SourceFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::DeleteDirectory(FString RootFolderFullPath) {

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteDirectory(*RootFolderFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::DeleteDirectoryRecursively(FString RootFolderFullPath) {

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*RootFolderFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::CopyDirectoryRecursively(FString SourceFullPath, FString DestinationFullPath, bool Overwrite) {

	SourceFullPath = FPaths::GameContentDir() + SourceFullPath;
	DestinationFullPath = FPaths::GameContentDir() + DestinationFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().CopyDirectoryTree(*DestinationFullPath, *SourceFullPath, Overwrite)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::DoesDirectoryExist(FString RootFolderFullPath) {

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*RootFolderFullPath)) {
		return false;
	}
	return true;
}

bool UueOSBPLibrary::DoesFileExist(FString RootFolderFullPath) {

	RootFolderFullPath = FPaths::GameContentDir() + RootFolderFullPath;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*RootFolderFullPath)) {
		return false;
	}
	return true;
}