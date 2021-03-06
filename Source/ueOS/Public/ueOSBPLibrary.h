// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "ueOSBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UueOSBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool FileSaveString(FString SaveTextB, FString FileNameB);

	UFUNCTION(BlueprintPure, Category = "ueOS_Library")
	static bool FileLoadString(FString FileNameA, FString& SaveTextA);

	UFUNCTION(BlueprintPure, Category = "ueOS_Library")
	static bool GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

	UFUNCTION(BlueprintPure, Category = "ueOS_Library")
	static int32 GetFileSize(FString RootFolderFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool CreateDirectory(FString NewDir);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool DeleteFile(FString RootFolderFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool MoveFile(FString SourceFullPath, FString DestinationFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool CopyFile(FString SourceFullPath, FString DestinationFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool DeleteDirectory(FString RootFolderFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool DeleteDirectoryRecursively(FString RootFolderFullPath);

	UFUNCTION(BlueprintCallable, Category = "ueOS_Library")
	static bool CopyDirectoryRecursively(FString SourceFullPath, FString DestinationFullPath, bool Overwrite);

	UFUNCTION(BlueprintPure, Category = "ueOS_Library")
	static bool DoesDirectoryExist(FString RootFolderFullPath);

	UFUNCTION(BlueprintPure, Category = "ueOS_Library")
	static bool DoesFileExist(FString RootFolderFullPath);
};

