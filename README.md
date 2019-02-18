# Bluetooth Support plugin for UE4
A code plugin for Unreal Engine that allows developers to access the Bluetooth SDK from Blueprint and C++.
This is the source code of "Bluetooth Support" code plugin on https://www.unrealengine.com/marketplace/bluetooth-support

<img src="https://i.imgur.com/F03ARye.png" />


## Prerequisites
Before adding the plugin to your projects, please take these points into consideration:
<ol>
<li>This plugin relies on Android native SDK. Only Android is currently supported.<br/>
    <i>It won't cause a problem for other platforms. It is safe to call any of the plugin methods on any platform.<br />You can always wrap platform-specific features by checking <a href="http://api.unrealengine.com/INT/BlueprintAPI/Game/GetPlatformName/">the platform name.</a></i></li>
<li>Android started supporting Bluetooth Low Energy since Android 4.3 (API level 18).<br />
    <ul>
        <li>Accessing the device's default bluetooth adapter (API level 18)</li>
        <li>Nearby device discovery, connection, characteristic reading (API level 21)</li>
        <li>Getting a nearby device's TXpower, connectablity, advertising intervale (API level 26)</li>
    </ul></li>
<li><a href="https://developer.android.com/guide/topics/connectivity/bluetooth-le#permissions">These permissions and capabilities</a> are required in the manifest file in order to be able to use Bluetooth LE on an Android device.
    <br />Don't worry, you can do that easily by following <u><a href="https://docs.unrealengine.com/en-us/Platforms/Android/AndroidManifestControl">this official guide</a></u></li>
<li>Your app should request <b>ACCESS_COARSE_LOCATION</b> runtime permission in order to be able to discover other BLE devices.<br />Here is <a href="https://api.unrealengine.com/INT/BlueprintAPI/AndroidPermission/index.html">how to check/request granted permissions</a> at runtime on UE4.</li>
</ol>


## Installation
<ol>
<li>Clone/download zip this repository</li>
<li>Move/unzip the plugin's downloaded folder inside <b>your projects directory</b>/Plugins/</li>
<li>Restart Unreal Engine (if it is running)</li>
<li>Find the plugin under the "Mobile" category and enable it.</li>
</ol>



<img src="https://i.imgur.com/XL5pKEv.jpg" />



# LICENSE
This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
