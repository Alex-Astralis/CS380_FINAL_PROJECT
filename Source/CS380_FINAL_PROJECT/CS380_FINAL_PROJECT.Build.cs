// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CS380_FINAL_PROJECT : ModuleRules
{
	public CS380_FINAL_PROJECT(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
