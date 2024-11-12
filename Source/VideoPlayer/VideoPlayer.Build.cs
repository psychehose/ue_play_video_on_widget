// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VideoPlayer : ModuleRules
{
	public VideoPlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicIncludePaths.AddRange(new string[] { "VideoPlayer" });


		PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"MediaAssets",
				"Media",
				"UMG"
			}
		);
		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
