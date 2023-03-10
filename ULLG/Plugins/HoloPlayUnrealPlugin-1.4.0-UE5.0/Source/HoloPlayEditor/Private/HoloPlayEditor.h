// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IHoloPlayEditor.h"
#include "PropertyEditorDelegates.h"

class FHoloPlayToolbar;
class FExtensibilityManager;

/**
 * @class	FHoloPlayEditorModule
 *
 * @brief	A HoloPlay editor module.
 * 			Editor UI and Editor commands
 */

class FHoloPlayEditorModule : public IHoloPlayEditor
{
public:

	/**
	 * @fn	virtual void FHoloPlayEditorModule::StartupModule() override;
	 *
	 * @brief	Called on LoadingPhase
	 */

	virtual void StartupModule() override;

	/**
	 * @fn	virtual void FHoloPlayEditorModule::ShutdownModule() override;
	 *
	 * @brief	Shutdown module when it is unloaded on on exit from the Game/Editor
	 */

	virtual void ShutdownModule() override;

private:

	/**
	 * @fn	void FHoloPlayEditorModule::AddEditorSettings();
	 *
	 * @brief	Adds editor settings to Unreal Engine project settings
	 */

	void AddEditorSettings();

	/**
	 * @fn	void FHoloPlayEditorModule::RemoveEditorSettings();
	 *
	 * @brief	Removes the editor settings from Unreal Engine project settings
	 */

	void RemoveEditorSettings();

	/**
	 * @fn	bool FHoloPlayEditorModule::OnSettingsSaved();
	 *
	 * @brief	Validation code in here and resave the settings in case an invalid
	 *
	 * @returns	True if it succeeds, false if it fails.
	 */

	bool OnSettingsSaved();

	/**
	 * @fn	void FHoloPlayEditorModule::OnPIEViewportStarted();
	 *
	 * @brief	Called when the PIE Viewport is created.
	 */

	void OnPIEViewportStarted();

	/**
	 * @fn	void FHoloPlayEditorModule::OnEndPIE(bool bIsSimulating);
	 *
	 * @brief	Called when the user closes the PIE instance window.
	 *
	 * @param	bIsSimulating	True if is simulating, false if not.
	 */

	void OnEndPIE(bool bIsSimulating);

	/**
	* Registers a custom struct
	*
	* @param StructName				The name of the struct to register for property customization
	* @param StructLayoutDelegate	The delegate to call to get the custom detail layout instance
	*/
	void RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate );

	void OnEditorSelectionChanged(const TArray<UObject*>& NewSelection, bool bForceRefresh);

private:
	TSharedPtr<FHoloPlayToolbar> HoloPlayToolbar;

	TSet< FName > RegisteredPropertyTypes;
};
