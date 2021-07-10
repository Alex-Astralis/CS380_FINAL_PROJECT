// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CS380_FINAL_PROJECTTarget : TargetRules
{
	public CS380_FINAL_PROJECTTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("CS380_FINAL_PROJECT");
	}
}
