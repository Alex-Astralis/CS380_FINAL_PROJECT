// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CS380_FINAL_PROJECTEditorTarget : TargetRules
{
	public CS380_FINAL_PROJECTEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("CS380_FINAL_PROJECT");
	}
}
