/**
 * ! Created By Taha HICHRI
 * @project    Bluetooth Support for UNREAL engine.
 * @author     Taha HICHRI <hishri.taha@gmail.com>
 * @copyright  Open Source project - 2018
 * @license    This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 * @see        https://github.com/hishriTaha - hishri.com
 */

using System.IO;

namespace UnrealBuildTool.Rules
{
    public class BluetoothSupport : ModuleRules
    {
        public BluetoothSupport(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            PrivateIncludePaths.AddRange(
                new string[] {
                "BluetoothSupport/Private",
                }
                );


            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                "Core",
                "Engine",
                "CoreUObject"
                }
                );


            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                 "Settings"
                }
                );


            DynamicallyLoadedModuleNames.AddRange(
                new string[]
                {
                }
                );

            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PrivateIncludePaths.Add("BluetoothSupport/Private/Android");

                PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });

                string PluginRelativePath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginRelativePath, "TaModuleAPL.xml")));
            }
        }
    }
}