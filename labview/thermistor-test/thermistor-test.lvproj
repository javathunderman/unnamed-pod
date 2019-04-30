<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="18008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Initialization VIs" Type="Folder">
			<Item Name="thermistor_param_init.vi" Type="VI" URL="../thermistor_param_init.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
	<Item Name="RT CompactRIO Target" Type="RT CompactRIO">
		<Property Name="alias.name" Type="Str">RT CompactRIO Target</Property>
		<Property Name="alias.value" Type="Str">0.0.0.0</Property>
		<Property Name="CCSymbols" Type="Str">TARGET_TYPE,RT;OS,Linux;CPU,x64;DeviceCode,774B;</Property>
		<Property Name="crio.ControllerPID" Type="Str">774B</Property>
		<Property Name="host.ResponsivenessCheckEnabled" Type="Bool">true</Property>
		<Property Name="host.ResponsivenessCheckPingDelay" Type="UInt">5000</Property>
		<Property Name="host.ResponsivenessCheckPingTimeout" Type="UInt">1000</Property>
		<Property Name="host.TargetCPUID" Type="UInt">9</Property>
		<Property Name="host.TargetOSID" Type="UInt">19</Property>
		<Property Name="host.TargetUIEnabled" Type="Bool">false</Property>
		<Property Name="target.cleanupVisa" Type="Bool">false</Property>
		<Property Name="target.FPProtocolGlobals_ControlTimeLimit" Type="Int">300</Property>
		<Property Name="target.getDefault-&gt;WebServer.Port" Type="Int">80</Property>
		<Property Name="target.getDefault-&gt;WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.IOScan.Faults" Type="Str"></Property>
		<Property Name="target.IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="target.IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="target.IOScan.Period" Type="UInt">10000</Property>
		<Property Name="target.IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="target.IOScan.Priority" Type="UInt">0</Property>
		<Property Name="target.IOScan.ReportModeConflict" Type="Bool">true</Property>
		<Property Name="target.IsRemotePanelSupported" Type="Bool">true</Property>
		<Property Name="target.RTCPULoadMonitoringEnabled" Type="Bool">true</Property>
		<Property Name="target.RTDebugWebServerHTTPPort" Type="Int">8001</Property>
		<Property Name="target.RTTarget.ApplicationPath" Type="Path">/c/ni-rt/startup/startup.rtexe</Property>
		<Property Name="target.RTTarget.EnableFileSharing" Type="Bool">true</Property>
		<Property Name="target.RTTarget.IPAccess" Type="Str">+*</Property>
		<Property Name="target.RTTarget.LaunchAppAtBoot" Type="Bool">false</Property>
		<Property Name="target.RTTarget.VIPath" Type="Path">/home/lvuser/natinst/bin</Property>
		<Property Name="target.server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.tcp.access" Type="Str">+*</Property>
		<Property Name="target.server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="target.server.tcp.paranoid" Type="Bool">true</Property>
		<Property Name="target.server.tcp.port" Type="Int">3363</Property>
		<Property Name="target.server.tcp.serviceName" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.tcp.serviceName.default" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.vi.access" Type="Str">+*</Property>
		<Property Name="target.server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="target.server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.WebServer.Enabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogEnabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogPath" Type="Path">/c/ni-rt/system/www/www.log</Property>
		<Property Name="target.WebServer.Port" Type="Int">80</Property>
		<Property Name="target.WebServer.RootPath" Type="Path">/c/ni-rt/system/www</Property>
		<Property Name="target.WebServer.TcpAccess" Type="Str">c+*</Property>
		<Property Name="target.WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.WebServer.ViAccess" Type="Str">+*</Property>
		<Property Name="target.webservices.SecurityAPIKey" Type="Str">PqVr/ifkAQh+lVrdPIykXlFvg12GhhQFR8H9cUhphgg=:pTe9HRlQuMfJxAG6QCGq7UvoUpJzAzWGKy5SbZ+roSU=</Property>
		<Property Name="target.webservices.ValidTimestampWindow" Type="Int">15</Property>
		<Item Name="Chassis" Type="cRIO Chassis">
			<Property Name="crio.ProgrammingMode" Type="Str">fpga</Property>
			<Property Name="crio.ResourceID" Type="Str">RIO0</Property>
			<Property Name="crio.Type" Type="Str">cRIO-9031</Property>
			<Property Name="NI.SortType" Type="Int">3</Property>
			<Item Name="Real-Time Scan Resources" Type="Module Container">
				<Property Name="crio.ModuleContainerType" Type="Str">crio.RSIModuleContainer</Property>
			</Item>
			<Item Name="FPGA Target" Type="FPGA Target">
				<Property Name="AutoRun" Type="Bool">false</Property>
				<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
				<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				<Property Name="Mode" Type="Int">1</Property>
				<Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
				<Property Name="NI.LV.FPGA.Version" Type="Int">6</Property>
				<Property Name="Resource Name" Type="Str">RIO0</Property>
				<Property Name="Target Class" Type="Str">cRIO-9031</Property>
				<Property Name="Top-Level Timing Source" Type="Str">40 MHz Onboard Clock</Property>
				<Property Name="Top-Level Timing Source Is Default" Type="Bool">true</Property>
				<Item Name="Chassis I/O" Type="Folder">
					<Item Name="Chassis Temperature" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Chassis Temperature</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{DE5046D3-F84F-4343-B07D-ADE12FF71B49}</Property>
					</Item>
					<Item Name="Sleep" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Sleep</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{79175359-FE4A-4026-BB31-23C03771ED47}</Property>
					</Item>
					<Item Name="System Reset" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/System Reset</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}</Property>
					</Item>
					<Item Name="USER FPGA LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/USER FPGA LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{65686107-0239-41C7-A101-AAA2F6F63366}</Property>
					</Item>
					<Item Name="USER Push Button" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="NumberOfSyncRegistersForReadInProject">
   <Value>0</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/USER Push Button</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E1AC87C3-9C64-4025-9864-905BE39AB783}</Property>
					</Item>
					<Item Name="Scan Clock" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Scan Clock</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}</Property>
					</Item>
				</Item>
				<Item Name="40 MHz Onboard Clock" Type="FPGA Base Clock">
					<Property Name="FPGA.PersistentID" Type="Str">{549DEC14-1E77-4E49-A6F0-B255CA78304E}</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig" Type="Str">ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.Accuracy" Type="Dbl">100</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ClockSignalName" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MaxFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinDutyCycle" Type="Dbl">50</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.MinFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.NominalFrequency" Type="Dbl">40000000</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.PeakPeriodJitter" Type="Dbl">250</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.ResourceName" Type="Str">40 MHz Onboard Clock</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.SupportAndRequireRuntimeEnableDisable" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.TopSignalConnect" Type="Str">Clk40</Property>
					<Property Name="NI.LV.FPGA.BaseTSConfig.VariableFrequency" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.Valid" Type="Bool">true</Property>
					<Property Name="NI.LV.FPGA.Version" Type="Int">5</Property>
				</Item>
				<Item Name="IP Builder" Type="IP Builder Target">
					<Item Name="Dependencies" Type="Dependencies"/>
					<Item Name="Build Specifications" Type="Build"/>
				</Item>
				<Item Name="Thermistor Fitting Params" Type="FPGA Memory Block">
					<Property Name="FPGA.PersistentID" Type="Str">{393A0830-0663-4D60-AFB7-781A4B198947}</Property>
					<Property Name="fullEmulation" Type="Bool">false</Property>
					<Property Name="Memory Latency" Type="UInt">0</Property>
					<Property Name="Multiple Clock Domains" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0</Property>
					<Property Name="NI.LV.FPGA.MEMORY.ActualNumberOfElements" Type="UInt">4</Property>
					<Property Name="NI.LV.FPGA.MEMORY.DataWidth" Type="UInt">9</Property>
					<Property Name="NI.LV.FPGA.MEMORY.DramIncludeByteEnables" Type="Bool">false</Property>
					<Property Name="NI.LV.FPGA.MEMORY.DramMaxOutstandingRequests" Type="Int">64</Property>
					<Property Name="NI.LV.FPGA.MEMORY.DramSelection" Type="Str"></Property>
					<Property Name="NI.LV.FPGA.MEMORY.Init" Type="Bool">true</Property>
					<Property Name="NI.LV.FPGA.MEMORY.InitData" Type="Str">00001101011010100000000000000000000000000000101000001100001111000000111110001001000000000000000000000000001111100000111110000100</Property>
					<Property Name="NI.LV.FPGA.MEMORY.InitVIPath" Type="Str">thermistor_param_init.vi</Property>
					<Property Name="NI.LV.FPGA.MEMORY.InterfaceAArbitration" Type="UInt">2</Property>
					<Property Name="NI.LV.FPGA.MEMORY.InterfaceBArbitration" Type="UInt">2</Property>
					<Property Name="NI.LV.FPGA.MEMORY.InterfaceConfig" Type="UInt">1</Property>
					<Property Name="NI.LV.FPGA.MEMORY.RequestedNumberOfElements" Type="UInt">4</Property>
					<Property Name="NI.LV.FPGA.MEMORY.Type" Type="UInt">1</Property>
					<Property Name="NI.LV.FPGA.ScriptConfigString" Type="Str">Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0Persist Memory ValuesFALSE;</Property>
					<Property Name="NI.LV.FPGA.Valid" Type="Bool">true</Property>
					<Property Name="NI.LV.FPGA.Version" Type="Int">10</Property>
					<Property Name="Type Descriptor" Type="Str">1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000</Property>
				</Item>
				<Item Name="thermistors.vi" Type="VI" URL="../../fpga-func-template/thermistors.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="ln.vi" Type="VI" URL="../ln.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="shift_below_1.vi" Type="VI" URL="../shift_below_1.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="consecutive_true.vi" Type="VI" URL="../consecutive_true.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="consecutive_false.vi" Type="VI" URL="../consecutive_false.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="counter_mod_n.vi" Type="VI" URL="../counter_mod_n.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="thermistor transfer function.vi" Type="VI" URL="../thermistor transfer function.vi">
					<Property Name="BuildSpec" Type="Str">{1640433A-8E8F-4E7A-8053-39B397C26FE4}</Property>
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="count_reset.vi" Type="VI" URL="../count_reset.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="test-for-john.vi" Type="VI" URL="../test-for-john.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="thermistor transfer function OLD.vi" Type="VI" URL="../thermistor transfer function OLD.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="thermistor_reduced_R.vi" Type="VI" URL="../thermistor_reduced_R.vi">
					<Property Name="configString.guid" Type="Str">{1DAAAE7A-5E18-4860-BB5F-CE02A646696D}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{393A0830-0663-4D60-AFB7-781A4B198947}Actual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0{549DEC14-1E77-4E49-A6F0-B255CA78304E}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{65686107-0239-41C7-A101-AAA2F6F63366}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{79175359-FE4A-4026-BB31-23C03771ED47}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{D7C92809-AB2C-472D-BC9B-8717D69E3CF4}resource=/Scan Clock;0;ReadMethodType=bool{DE5046D3-F84F-4343-B07D-ADE12FF71B49}resource=/Chassis Temperature;0;ReadMethodType=i16{E1AC87C3-9C64-4025-9864-905BE39AB783}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAScan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolThermistor Fitting ParamsActual Number of Elements=4;ReadArbs=2;WriteArbs=2;Implementation=1;DataType=1000800000000001003C005F031100200000001000000001000000010000000000000000000000200000001000000000FFFFFFFF00000001FFFFFFF1000000000000000100010000000000000000000000000000;InitDataHash=6BBC6775FB98962D875F0342FB9CE68D;DRAM Selection=;DRAM Max Outstanding Requests=64;DRAM Include Byte Enables=FALSE;DRAM Grant Time=50;Interface Configuration=Read A-Read B;Multiple Clock Domains=FALSE;Memory Latency=0USER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				</Item>
				<Item Name="Dependencies" Type="Dependencies">
					<Item Name="vi.lib" Type="Folder">
						<Item Name="FxpSim.dll" Type="Document" URL="/&lt;vilib&gt;/rvi/FXPMathLib/sim/FxpSim.dll"/>
					</Item>
				</Item>
				<Item Name="Build Specifications" Type="Build">
					<Item Name="thermistor transfer function" Type="{F4C5E96F-7410-48A5-BB87-3559BC9B167F}">
						<Property Name="AllowEnableRemoval" Type="Bool">false</Property>
						<Property Name="BuildSpecDecription" Type="Str"></Property>
						<Property Name="BuildSpecName" Type="Str">thermistor transfer function</Property>
						<Property Name="Comp.BitfileName" Type="Str">thermistor-test_FPGATarget_thermistortransf_i-3qeCUVKgc.lvbitx</Property>
						<Property Name="Comp.CustomXilinxParameters" Type="Str"></Property>
						<Property Name="Comp.MaxFanout" Type="Int">-1</Property>
						<Property Name="Comp.RandomSeed" Type="Bool">false</Property>
						<Property Name="Comp.Version.Build" Type="Int">0</Property>
						<Property Name="Comp.Version.Fix" Type="Int">0</Property>
						<Property Name="Comp.Version.Major" Type="Int">1</Property>
						<Property Name="Comp.Version.Minor" Type="Int">0</Property>
						<Property Name="Comp.VersionAutoIncrement" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.EnableMultiThreading" Type="Bool">true</Property>
						<Property Name="Comp.Vivado.OptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PhysOptDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.PlaceDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RouteDirective" Type="Str"></Property>
						<Property Name="Comp.Vivado.RunPowerOpt" Type="Bool">false</Property>
						<Property Name="Comp.Vivado.Strategy" Type="Str">Default</Property>
						<Property Name="Comp.Xilinx.DesignStrategy" Type="Str">balanced</Property>
						<Property Name="Comp.Xilinx.MapEffort" Type="Str">default(noTiming)</Property>
						<Property Name="Comp.Xilinx.ParEffort" Type="Str">standard</Property>
						<Property Name="Comp.Xilinx.SynthEffort" Type="Str">normal</Property>
						<Property Name="Comp.Xilinx.SynthGoal" Type="Str">speed</Property>
						<Property Name="Comp.Xilinx.UseRecommended" Type="Bool">true</Property>
						<Property Name="DefaultBuildSpec" Type="Bool">true</Property>
						<Property Name="DestinationDirectory" Type="Path">FPGA Bitfiles</Property>
						<Property Name="ProjectPath" Type="Path">/C/repos/umdloop/labview/thermistor-test/thermistor-test.lvproj</Property>
						<Property Name="RelativePath" Type="Bool">true</Property>
						<Property Name="RunWhenLoaded" Type="Bool">false</Property>
						<Property Name="SupportDownload" Type="Bool">true</Property>
						<Property Name="SupportResourceEstimation" Type="Bool">false</Property>
						<Property Name="TargetName" Type="Str">FPGA Target</Property>
						<Property Name="TopLevelVI" Type="Ref">/RT CompactRIO Target/Chassis/FPGA Target/thermistor transfer function.vi</Property>
					</Item>
				</Item>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
	<Item Name="NI-cRIO-9031-ItWorked" Type="RT CompactRIO">
		<Property Name="alias.name" Type="Str">NI-cRIO-9031-ItWorked</Property>
		<Property Name="alias.value" Type="Str">172.22.11.2</Property>
		<Property Name="CCSymbols" Type="Str">TARGET_TYPE,RT;OS,Linux;CPU,x64;DeviceCode,774B;</Property>
		<Property Name="crio.ControllerPID" Type="Str">774B</Property>
		<Property Name="host.ResponsivenessCheckEnabled" Type="Bool">true</Property>
		<Property Name="host.ResponsivenessCheckPingDelay" Type="UInt">5000</Property>
		<Property Name="host.ResponsivenessCheckPingTimeout" Type="UInt">1000</Property>
		<Property Name="host.TargetCPUID" Type="UInt">9</Property>
		<Property Name="host.TargetOSID" Type="UInt">19</Property>
		<Property Name="host.TargetUIEnabled" Type="Bool">false</Property>
		<Property Name="target.cleanupVisa" Type="Bool">false</Property>
		<Property Name="target.FPProtocolGlobals_ControlTimeLimit" Type="Int">300</Property>
		<Property Name="target.getDefault-&gt;WebServer.Port" Type="Int">80</Property>
		<Property Name="target.getDefault-&gt;WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.IOScan.Faults" Type="Str"></Property>
		<Property Name="target.IOScan.NetVarPeriod" Type="UInt">100</Property>
		<Property Name="target.IOScan.NetWatchdogEnabled" Type="Bool">false</Property>
		<Property Name="target.IOScan.Period" Type="UInt">10000</Property>
		<Property Name="target.IOScan.PowerupMode" Type="UInt">0</Property>
		<Property Name="target.IOScan.Priority" Type="UInt">0</Property>
		<Property Name="target.IOScan.ReportModeConflict" Type="Bool">true</Property>
		<Property Name="target.IsRemotePanelSupported" Type="Bool">true</Property>
		<Property Name="target.RTCPULoadMonitoringEnabled" Type="Bool">true</Property>
		<Property Name="target.RTDebugWebServerHTTPPort" Type="Int">8001</Property>
		<Property Name="target.RTTarget.ApplicationPath" Type="Path">/c/ni-rt/startup/startup.rtexe</Property>
		<Property Name="target.RTTarget.EnableFileSharing" Type="Bool">true</Property>
		<Property Name="target.RTTarget.IPAccess" Type="Str">+*</Property>
		<Property Name="target.RTTarget.LaunchAppAtBoot" Type="Bool">false</Property>
		<Property Name="target.RTTarget.VIPath" Type="Path">/home/lvuser/natinst/bin</Property>
		<Property Name="target.server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.server.tcp.access" Type="Str">+*</Property>
		<Property Name="target.server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="target.server.tcp.paranoid" Type="Bool">true</Property>
		<Property Name="target.server.tcp.port" Type="Int">3363</Property>
		<Property Name="target.server.tcp.serviceName" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.tcp.serviceName.default" Type="Str">Main Application Instance/VI Server</Property>
		<Property Name="target.server.vi.access" Type="Str">+*</Property>
		<Property Name="target.server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="target.server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="target.WebServer.Enabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogEnabled" Type="Bool">false</Property>
		<Property Name="target.WebServer.LogPath" Type="Path">/c/ni-rt/system/www/www.log</Property>
		<Property Name="target.WebServer.Port" Type="Int">80</Property>
		<Property Name="target.WebServer.RootPath" Type="Path">/c/ni-rt/system/www</Property>
		<Property Name="target.WebServer.TcpAccess" Type="Str">c+*</Property>
		<Property Name="target.WebServer.Timeout" Type="Int">60</Property>
		<Property Name="target.WebServer.ViAccess" Type="Str">+*</Property>
		<Property Name="target.webservices.SecurityAPIKey" Type="Str">PqVr/ifkAQh+lVrdPIykXlFvg12GhhQFR8H9cUhphgg=:pTe9HRlQuMfJxAG6QCGq7UvoUpJzAzWGKy5SbZ+roSU=</Property>
		<Property Name="target.webservices.ValidTimestampWindow" Type="Int">15</Property>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
