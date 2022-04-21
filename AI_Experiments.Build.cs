// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_Experiments : ModuleRules
{
	public AI_Experiments(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
