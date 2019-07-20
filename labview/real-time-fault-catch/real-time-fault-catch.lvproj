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
				<Property Name="configString.guid" Type="Str">{07241D9F-1772-4A02-AE32-BDFBE5503DFF}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool{08CAAE0C-2792-49D8-B323-0DCD03D08487}resource=/crio_Mod1/AI22;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{0E8E30C4-9BDA-46D9-8783-902D4A968DB0}resource=/crio_Mod1/AI20;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{0EC356A1-F5AA-4B02-8FBB-3DC86EC5E968}resource=/crio_Mod1/AI27;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{14FF2D1F-EB83-4F85-9527-68B9ECEB851D}resource=/crio_Mod1/AI19;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{15946E51-4BD7-405E-A89B-1DBD3539CC88}resource=/crio_Mod1/AI7;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{177EFE3F-BF73-4862-AE22-A2D27B807ADC}resource=/crio_Mod2/DIO7:0;0;ReadMethodType=u8;WriteMethodType=u8{187B7C1A-CBC0-4A1F-B967-B42BF2E61313}resource=/crio_Mod2/DIO30;0;ReadMethodType=bool;WriteMethodType=bool{1A223F0B-A811-4B4E-874B-1B78C2252731}resource=/crio_Mod1/AI21;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{1EE9A483-3BF4-4CAA-9C97-2D2856E1A1BE}resource=/crio_Mod2/DIO22;0;ReadMethodType=bool;WriteMethodType=bool{20899980-4CAD-49BB-954C-528EC47BBF8F}resource=/crio_Mod2/DIO28;0;ReadMethodType=bool;WriteMethodType=bool{215C4390-54AF-4E7F-A4B2-975E2F75B6A6}resource=/crio_Mod2/DIO31:0;0;ReadMethodType=u32;WriteMethodType=u32{22C4F42E-CE3B-4464-B1D5-9DBB12A123C9}resource=/crio_Mod1/AI16;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{22E59746-DC86-4D08-BB6E-ACAFC5DF263F}resource=/crio_Mod2/DIO25;0;ReadMethodType=bool;WriteMethodType=bool{248EA9B9-D2B5-404F-B4DB-053A1D92CE7F}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO6;0;ReadMethodType=bool;WriteMethodType=bool{253BD8EB-A0C4-4C68-88FD-AF4313FEF927}resource=/crio_Mod2/DIO20;0;ReadMethodType=bool;WriteMethodType=bool{256D5CDB-66A1-4137-963C-2CC831AEFFC9}resource=/crio_Mod1/AI8;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{265D6EAB-0B6B-4DB7-BD87-F423C255D11D}resource=/crio_Mod2/DIO23;0;ReadMethodType=bool;WriteMethodType=bool{2AC24A55-73B9-4FCB-93DD-8F2D5D60FFC0}resource=/crio_Mod2/DIO21;0;ReadMethodType=bool;WriteMethodType=bool{2FFA3CEB-AD19-4E97-86C5-8FB2A7484B54}resource=/crio_Mod1/AI26;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{2FFAF33C-C0B6-4D4A-A278-B32EDD46322F}resource=/crio_Mod1/AI10;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{30C3CF6B-6FBA-4C6C-A3D6-44C710B7F82C}resource=/crio_Mod4/TC3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{31042BD3-65ED-434D-ACF1-CD4B3E668EA6}resource=/crio_Mod1/AI4;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{33425133-4C44-42EE-ACD9-6B03B7C637B5}resource=/crio_Mod1/AI14;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{335F1EE5-1C92-4211-8C1C-3138C11F090C}resource=/crio_Mod1/AI3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{33A98F5E-E082-4B03-A56B-67859ECC7EBD}resource=/crio_Mod1/AI12;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{3596D672-1A23-4509-905A-9B33F089EFE7}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO5;0;ReadMethodType=bool;WriteMethodType=bool{3632BF45-5488-4346-81DD-DA334D0E6928}resource=/crio_Mod4/CJC;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{369AE2EE-2352-4592-9D66-9357CA268D80}resource=/crio_Mod2/DIO15;0;ReadMethodType=bool;WriteMethodType=bool{3D37AD98-83E7-499C-80E0-3760A2790FA0}resource=/crio_Mod1/AI23;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{499C87DC-E1F9-4CF1-B338-7A6B2922D264}resource=/crio_Mod1/AI11;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{4D548D81-C4CC-4F74-85CA-8120C7A3EE74}resource=/crio_Mod2/DIO1;0;ReadMethodType=bool;WriteMethodType=bool{4D733EEE-21B8-466F-826F-CDCD07EAA86B}resource=/crio_Mod2/DIO15:8;0;ReadMethodType=u8;WriteMethodType=u8{5705BA54-5A6E-4A65-AB63-F7BF57E503E0}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{5B2CEE3F-0034-4A00-B2DE-0406AEAA4A64}resource=/Chassis Temperature;0;ReadMethodType=i16{609A093E-3939-46F9-877E-F7814E8B7DE4}resource=/crio_Mod1/AI13;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{6124E451-CA70-451C-BB93-8B2FDE43C364}resource=/crio_Mod2/DIO4;0;ReadMethodType=bool;WriteMethodType=bool{65076FE8-2CEA-451D-B373-B779EBF09239}resource=/crio_Mod2/DIO23:16;0;ReadMethodType=u8;WriteMethodType=u8{65BEB2D0-01A1-4155-8A67-3CE2F6C379C0}resource=/crio_Mod1/AI30;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{660C804D-D13D-4728-8E67-B8D5116CD55B}resource=/crio_Mod2/DIO0;0;ReadMethodType=bool;WriteMethodType=bool{674044F1-B226-4C72-8DC4-526B74B877B7}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 4,crio.Type=NI 9211,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]{6777E432-E37B-4549-8D8C-BB4771D4E4F1}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO0;0;ReadMethodType=bool;WriteMethodType=bool{6C7121C2-7635-44C5-B574-A98ADCB5A386}resource=/crio_Mod1/AI6;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{6E3DAA5E-135B-4C28-A0BA-355EDB3A081E}resource=/crio_Mod2/DIO5;0;ReadMethodType=bool;WriteMethodType=bool{6F1B1777-66CF-4516-9A2F-6307302B9A63}resource=/crio_Mod1/AI17;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{75612308-2FF4-4401-A2E7-7BF493CFAE60}resource=/crio_Mod2/DIO2;0;ReadMethodType=bool;WriteMethodType=bool{77156762-466F-4CAF-BADF-E5A72B4E00AB}resource=/crio_Mod1/AI25;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{77E91E60-A3D2-4CD9-8160-2853A8DDF11D}resource=/crio_Mod1/AI15;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{7825F7AC-4C1F-4504-9C9C-4C71CE7BFF39}resource=/crio_Mod2/DIO11;0;ReadMethodType=bool;WriteMethodType=bool{7B760C81-150D-4C34-9D16-B28ECA351D68}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9472,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{7F14741E-4E1D-4F4E-8C8F-2AE34D2B1E60}resource=/crio_Mod1/AI28;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{81D18035-3B86-40F7-BE04-52CBD2B563F9}resource=/crio_Mod1/AI9;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{8408D1A2-2697-48D5-AFCE-CCF99D597BEE}resource=/crio_Mod1/AI1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{8C1A3F38-39B1-4FF5-94F5-0DF049F058F2}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{9546DD23-2C33-47DC-A09E-967BB5378F08}resource=/crio_Mod1/AI18;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{99D1B5C2-25B4-44AD-B412-2B4E37C65DC0}resource=/crio_Mod2/DIO9;0;ReadMethodType=bool;WriteMethodType=bool{9CAD961C-4595-4838-BA10-CDAFC031A799}resource=/crio_Mod2/DIO19;0;ReadMethodType=bool;WriteMethodType=bool{9CB64339-944C-4B37-A7CC-838B6FD803CC}resource=/crio_Mod1/AI29;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{9F2331D1-81F3-4F1E-8643-DB59C51D4361}resource=/crio_Mod2/DIO8;0;ReadMethodType=bool;WriteMethodType=bool{9FB7A7D4-4B01-4A66-927F-5C6F74327FC9}resource=/crio_Mod2/DIO27;0;ReadMethodType=bool;WriteMethodType=bool{9FF6EE80-2ABE-4922-B5F1-BD485896F54D}resource=/crio_Mod2/DIO6;0;ReadMethodType=bool;WriteMethodType=bool{A734C667-1689-46A3-880E-830EC1607091}resource=/crio_Mod1/AI24;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{AA898AD2-F1F5-4029-820D-C982F5D6E367}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{AC8981F2-7D89-45FF-B171-AABE9F2F8C7D}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO4;0;ReadMethodType=bool;WriteMethodType=bool{AD8C5513-28C6-4C82-9E04-B82C9DEA6CC8}resource=/crio_Mod4/Autozero;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{AE7128BB-5332-444B-BF39-B08DC5049773}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9403,cRIOModule.DisableArbitration=false,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.Initial Line Direction=00000000000000000000000000000000,cRIOModule.RsiAttributes=[crioConfig.End]{B0897961-3243-45BD-85D5-A349C1B431C9}resource=/crio_Mod2/DIO7;0;ReadMethodType=bool;WriteMethodType=bool{B43AD548-05FC-4671-87D4-BC167A5683FC}resource=/crio_Mod2/DIO12;0;ReadMethodType=bool;WriteMethodType=bool{BB1F0EBB-4771-42EC-B15D-F9E31023AA48}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7;0;ReadMethodType=bool;WriteMethodType=bool{C5E8F213-0251-4E9A-A7AB-34CB6C005266}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8{C6C8CDE5-747F-42A8-9F40-FA0F565ED113}resource=/crio_Mod4/TC2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{D20092C5-EACF-4C7B-9C81-28F15ECA299C}resource=/crio_Mod2/DIO3;0;ReadMethodType=bool;WriteMethodType=bool{D2394D95-6FCE-49E1-8EAA-F178CB677582}resource=/crio_Mod2/DIO18;0;ReadMethodType=bool;WriteMethodType=bool{D268A59E-B0A1-4E84-A873-C8421EAC28ED}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO1;0;ReadMethodType=bool;WriteMethodType=bool{D48CAF8D-F933-4E2B-93F9-FC4660B50A0F}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9209,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI0.Terminal Mode=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI1.Terminal Mode=0,cRIOModule.AI10.DegreeRange=2,cRIOModule.AI10.TCoupleType=0,cRIOModule.AI10.Terminal Mode=0,cRIOModule.AI11.DegreeRange=2,cRIOModule.AI11.TCoupleType=0,cRIOModule.AI11.Terminal Mode=0,cRIOModule.AI12.DegreeRange=2,cRIOModule.AI12.TCoupleType=0,cRIOModule.AI12.Terminal Mode=0,cRIOModule.AI13.DegreeRange=2,cRIOModule.AI13.TCoupleType=0,cRIOModule.AI13.Terminal Mode=0,cRIOModule.AI14.DegreeRange=2,cRIOModule.AI14.TCoupleType=0,cRIOModule.AI14.Terminal Mode=0,cRIOModule.AI15.DegreeRange=2,cRIOModule.AI15.TCoupleType=0,cRIOModule.AI15.Terminal Mode=0,cRIOModule.AI16.Terminal Mode=0,cRIOModule.AI17.Terminal Mode=0,cRIOModule.AI18.Terminal Mode=0,cRIOModule.AI19.Terminal Mode=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI2.Terminal Mode=0,cRIOModule.AI20.Terminal Mode=0,cRIOModule.AI21.Terminal Mode=0,cRIOModule.AI22.Terminal Mode=0,cRIOModule.AI23.Terminal Mode=0,cRIOModule.AI24.Terminal Mode=0,cRIOModule.AI25.Terminal Mode=0,cRIOModule.AI26.Terminal Mode=0,cRIOModule.AI27.Terminal Mode=0,cRIOModule.AI28.Terminal Mode=0,cRIOModule.AI29.Terminal Mode=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.AI3.Terminal Mode=0,cRIOModule.AI30.Terminal Mode=0,cRIOModule.AI31.Terminal Mode=0,cRIOModule.AI4.DegreeRange=2,cRIOModule.AI4.TCoupleType=0,cRIOModule.AI4.Terminal Mode=0,cRIOModule.AI5.DegreeRange=2,cRIOModule.AI5.TCoupleType=0,cRIOModule.AI5.Terminal Mode=0,cRIOModule.AI6.DegreeRange=2,cRIOModule.AI6.TCoupleType=0,cRIOModule.AI6.Terminal Mode=0,cRIOModule.AI7.DegreeRange=2,cRIOModule.AI7.TCoupleType=0,cRIOModule.AI7.Terminal Mode=0,cRIOModule.AI8.DegreeRange=2,cRIOModule.AI8.TCoupleType=0,cRIOModule.AI8.Terminal Mode=0,cRIOModule.AI9.DegreeRange=2,cRIOModule.AI9.TCoupleType=0,cRIOModule.AI9.Terminal Mode=0,cRIOModule.Conversion Time=1,cRIOModule.Enable Open TC Detection=true,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]{D6BA5AD4-BF95-4A18-939D-1917B482D3A5}resource=/Scan Clock;0;ReadMethodType=bool{D906B0C5-C55F-45B9-BE8C-BAF2D9276E47}resource=/crio_Mod2/DIO17;0;ReadMethodType=bool;WriteMethodType=bool{DBAD45D8-1982-4204-B973-A72048975143}resource=/crio_Mod4/TC0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{DCBA2FEC-1D56-4AE6-A444-5C2463E4B70F}resource=/crio_Mod2/DIO26;0;ReadMethodType=bool;WriteMethodType=bool{E0560254-82B6-42D6-BB3C-9980234B2DFD}resource=/crio_Mod2/DIO14;0;ReadMethodType=bool;WriteMethodType=bool{E0AF840C-7CA1-4EF9-B3CE-930171A2E73C}resource=/crio_Mod1/AI5;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{E1BA66DC-601B-4B93-ADEF-5A9CF2B5A251}resource=/crio_Mod1/AI2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{EC2F2D43-49E9-420A-A01E-BA87AEFD55A8}resource=/crio_Mod4/TC1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{EEF9E8E0-D51C-4030-9DB7-E937644438CB}resource=/crio_Mod1/AI0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{F1EF5E4D-84F4-42AF-9B35-FB5238F42E10}resource=/crio_Mod2/DIO31:24;0;ReadMethodType=u8;WriteMethodType=u8{F434B6CC-DAF0-4EEB-871D-35FFF2F687EC}resource=/crio_Mod2/DIO24;0;ReadMethodType=bool;WriteMethodType=bool{F4CA4FBD-6FB5-47D6-89D0-B2800984360F}resource=/crio_Mod1/AI31;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{F6E1A615-C9B8-4083-9EC6-65E5E49A4534}resource=/crio_Mod2/DIO29;0;ReadMethodType=bool;WriteMethodType=bool{F7358327-6937-43D3-ABC3-4E4B9F18D8AF}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO3;0;ReadMethodType=bool;WriteMethodType=bool{F7629210-299E-4B93-A839-3EE90A2E8D6C}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO2;0;ReadMethodType=bool;WriteMethodType=bool{F9F3188A-B9FC-4D8A-A1C5-5582EF7560FE}resource=/crio_Mod2/DIO13;0;ReadMethodType=bool;WriteMethodType=bool{FB4C7067-E7A7-480C-88BB-73BC4BD51F34}resource=/crio_Mod2/DIO10;0;ReadMethodType=bool;WriteMethodType=bool{FBB2A9C6-33CC-48FC-AA2B-966E4448A73F}resource=/crio_Mod2/DIO31;0;ReadMethodType=bool;WriteMethodType=bool{FEFE015B-3606-42AB-B188-A939EEA6022F}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{FFB95158-0C8F-4842-89B7-0963A77A71B4}resource=/crio_Mod2/DIO16;0;ReadMethodType=bool;WriteMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
				<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAMod1/AI0resource=/crio_Mod1/AI0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI10resource=/crio_Mod1/AI10;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI11resource=/crio_Mod1/AI11;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI12resource=/crio_Mod1/AI12;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI13resource=/crio_Mod1/AI13;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI14resource=/crio_Mod1/AI14;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI15resource=/crio_Mod1/AI15;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI16resource=/crio_Mod1/AI16;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI17resource=/crio_Mod1/AI17;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI18resource=/crio_Mod1/AI18;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI19resource=/crio_Mod1/AI19;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI1resource=/crio_Mod1/AI1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI20resource=/crio_Mod1/AI20;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI21resource=/crio_Mod1/AI21;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI22resource=/crio_Mod1/AI22;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI23resource=/crio_Mod1/AI23;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI24resource=/crio_Mod1/AI24;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI25resource=/crio_Mod1/AI25;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI26resource=/crio_Mod1/AI26;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI27resource=/crio_Mod1/AI27;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI28resource=/crio_Mod1/AI28;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI29resource=/crio_Mod1/AI29;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI2resource=/crio_Mod1/AI2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI30resource=/crio_Mod1/AI30;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI31resource=/crio_Mod1/AI31;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI3resource=/crio_Mod1/AI3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI4resource=/crio_Mod1/AI4;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI5resource=/crio_Mod1/AI5;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI6resource=/crio_Mod1/AI6;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI7resource=/crio_Mod1/AI7;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI8resource=/crio_Mod1/AI8;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI9resource=/crio_Mod1/AI9;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9209,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI0.Terminal Mode=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI1.Terminal Mode=0,cRIOModule.AI10.DegreeRange=2,cRIOModule.AI10.TCoupleType=0,cRIOModule.AI10.Terminal Mode=0,cRIOModule.AI11.DegreeRange=2,cRIOModule.AI11.TCoupleType=0,cRIOModule.AI11.Terminal Mode=0,cRIOModule.AI12.DegreeRange=2,cRIOModule.AI12.TCoupleType=0,cRIOModule.AI12.Terminal Mode=0,cRIOModule.AI13.DegreeRange=2,cRIOModule.AI13.TCoupleType=0,cRIOModule.AI13.Terminal Mode=0,cRIOModule.AI14.DegreeRange=2,cRIOModule.AI14.TCoupleType=0,cRIOModule.AI14.Terminal Mode=0,cRIOModule.AI15.DegreeRange=2,cRIOModule.AI15.TCoupleType=0,cRIOModule.AI15.Terminal Mode=0,cRIOModule.AI16.Terminal Mode=0,cRIOModule.AI17.Terminal Mode=0,cRIOModule.AI18.Terminal Mode=0,cRIOModule.AI19.Terminal Mode=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI2.Terminal Mode=0,cRIOModule.AI20.Terminal Mode=0,cRIOModule.AI21.Terminal Mode=0,cRIOModule.AI22.Terminal Mode=0,cRIOModule.AI23.Terminal Mode=0,cRIOModule.AI24.Terminal Mode=0,cRIOModule.AI25.Terminal Mode=0,cRIOModule.AI26.Terminal Mode=0,cRIOModule.AI27.Terminal Mode=0,cRIOModule.AI28.Terminal Mode=0,cRIOModule.AI29.Terminal Mode=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.AI3.Terminal Mode=0,cRIOModule.AI30.Terminal Mode=0,cRIOModule.AI31.Terminal Mode=0,cRIOModule.AI4.DegreeRange=2,cRIOModule.AI4.TCoupleType=0,cRIOModule.AI4.Terminal Mode=0,cRIOModule.AI5.DegreeRange=2,cRIOModule.AI5.TCoupleType=0,cRIOModule.AI5.Terminal Mode=0,cRIOModule.AI6.DegreeRange=2,cRIOModule.AI6.TCoupleType=0,cRIOModule.AI6.Terminal Mode=0,cRIOModule.AI7.DegreeRange=2,cRIOModule.AI7.TCoupleType=0,cRIOModule.AI7.Terminal Mode=0,cRIOModule.AI8.DegreeRange=2,cRIOModule.AI8.TCoupleType=0,cRIOModule.AI8.Terminal Mode=0,cRIOModule.AI9.DegreeRange=2,cRIOModule.AI9.TCoupleType=0,cRIOModule.AI9.Terminal Mode=0,cRIOModule.Conversion Time=1,cRIOModule.Enable Open TC Detection=true,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]Mod2/DIO0resource=/crio_Mod2/DIO0;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO10resource=/crio_Mod2/DIO10;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO11resource=/crio_Mod2/DIO11;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO12resource=/crio_Mod2/DIO12;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO13resource=/crio_Mod2/DIO13;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO14resource=/crio_Mod2/DIO14;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO15:8resource=/crio_Mod2/DIO15:8;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO15resource=/crio_Mod2/DIO15;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO16resource=/crio_Mod2/DIO16;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO17resource=/crio_Mod2/DIO17;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO18resource=/crio_Mod2/DIO18;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO19resource=/crio_Mod2/DIO19;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO1resource=/crio_Mod2/DIO1;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO20resource=/crio_Mod2/DIO20;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO21resource=/crio_Mod2/DIO21;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO22resource=/crio_Mod2/DIO22;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO23:16resource=/crio_Mod2/DIO23:16;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO23resource=/crio_Mod2/DIO23;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO24resource=/crio_Mod2/DIO24;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO25resource=/crio_Mod2/DIO25;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO26resource=/crio_Mod2/DIO26;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO27resource=/crio_Mod2/DIO27;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO28resource=/crio_Mod2/DIO28;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO29resource=/crio_Mod2/DIO29;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO2resource=/crio_Mod2/DIO2;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO30resource=/crio_Mod2/DIO30;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO31:0resource=/crio_Mod2/DIO31:0;0;ReadMethodType=u32;WriteMethodType=u32Mod2/DIO31:24resource=/crio_Mod2/DIO31:24;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO31resource=/crio_Mod2/DIO31;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO3resource=/crio_Mod2/DIO3;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO4resource=/crio_Mod2/DIO4;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO5resource=/crio_Mod2/DIO5;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO6resource=/crio_Mod2/DIO6;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO7:0resource=/crio_Mod2/DIO7:0;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO7resource=/crio_Mod2/DIO7;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO8resource=/crio_Mod2/DIO8;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO9resource=/crio_Mod2/DIO9;0;ReadMethodType=bool;WriteMethodType=boolMod2[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9403,cRIOModule.DisableArbitration=false,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.Initial Line Direction=00000000000000000000000000000000,cRIOModule.RsiAttributes=[crioConfig.End]Mod3/DO0ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO0;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO1ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO1;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO2ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO2;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO3ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO3;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO4ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO4;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO5ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO5;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO6ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO6;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO7:0ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8Mod3/DO7ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7;0;ReadMethodType=bool;WriteMethodType=boolMod3[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9472,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Mod4/Autozeroresource=/crio_Mod4/Autozero;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/CJCresource=/crio_Mod4/CJC;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC0resource=/crio_Mod4/TC0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC1resource=/crio_Mod4/TC1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC2resource=/crio_Mod4/TC2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC3resource=/crio_Mod4/TC3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 4,crio.Type=NI 9211,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]Scan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolUSER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
				<Property Name="Mode" Type="Int">1</Property>
				<Property Name="NI.LV.FPGA.CompileConfigString" Type="Str">cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
				<Property Name="NI.LV.FPGA.Version" Type="Int">6</Property>
				<Property Name="niFpga_TopLevelVIID" Type="Path">/C/repos/umdloop/labview/real-time-fault-catch/real-time-fault-handler.vi</Property>
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
						<Property Name="FPGA.PersistentID" Type="Str">{5B2CEE3F-0034-4A00-B2DE-0406AEAA4A64}</Property>
					</Item>
					<Item Name="Sleep" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Sleep</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FEFE015B-3606-42AB-B188-A939EEA6022F}</Property>
					</Item>
					<Item Name="System Reset" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/System Reset</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{AA898AD2-F1F5-4029-820D-C982F5D6E367}</Property>
					</Item>
					<Item Name="USER FPGA LED" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/USER FPGA LED</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{5705BA54-5A6E-4A65-AB63-F7BF57E503E0}</Property>
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
						<Property Name="FPGA.PersistentID" Type="Str">{07241D9F-1772-4A02-AE32-BDFBE5503DFF}</Property>
					</Item>
					<Item Name="Scan Clock" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/Scan Clock</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D6BA5AD4-BF95-4A18-939D-1917B482D3A5}</Property>
					</Item>
				</Item>
				<Item Name="Mod1" Type="Folder">
					<Item Name="Mod1/AI0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{EEF9E8E0-D51C-4030-9DB7-E937644438CB}</Property>
					</Item>
					<Item Name="Mod1/AI1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{8408D1A2-2697-48D5-AFCE-CCF99D597BEE}</Property>
					</Item>
					<Item Name="Mod1/AI2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E1BA66DC-601B-4B93-ADEF-5A9CF2B5A251}</Property>
					</Item>
					<Item Name="Mod1/AI3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{335F1EE5-1C92-4211-8C1C-3138C11F090C}</Property>
					</Item>
					<Item Name="Mod1/AI4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{31042BD3-65ED-434D-ACF1-CD4B3E668EA6}</Property>
					</Item>
					<Item Name="Mod1/AI5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E0AF840C-7CA1-4EF9-B3CE-930171A2E73C}</Property>
					</Item>
					<Item Name="Mod1/AI6" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI6</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6C7121C2-7635-44C5-B574-A98ADCB5A386}</Property>
					</Item>
					<Item Name="Mod1/AI7" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI7</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{15946E51-4BD7-405E-A89B-1DBD3539CC88}</Property>
					</Item>
					<Item Name="Mod1/AI8" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI8</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{256D5CDB-66A1-4137-963C-2CC831AEFFC9}</Property>
					</Item>
					<Item Name="Mod1/AI9" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI9</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{81D18035-3B86-40F7-BE04-52CBD2B563F9}</Property>
					</Item>
					<Item Name="Mod1/AI10" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI10</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{2FFAF33C-C0B6-4D4A-A278-B32EDD46322F}</Property>
					</Item>
					<Item Name="Mod1/AI11" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI11</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{499C87DC-E1F9-4CF1-B338-7A6B2922D264}</Property>
					</Item>
					<Item Name="Mod1/AI12" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI12</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{33A98F5E-E082-4B03-A56B-67859ECC7EBD}</Property>
					</Item>
					<Item Name="Mod1/AI13" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI13</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{609A093E-3939-46F9-877E-F7814E8B7DE4}</Property>
					</Item>
					<Item Name="Mod1/AI14" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI14</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{33425133-4C44-42EE-ACD9-6B03B7C637B5}</Property>
					</Item>
					<Item Name="Mod1/AI15" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI15</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{77E91E60-A3D2-4CD9-8160-2853A8DDF11D}</Property>
					</Item>
					<Item Name="Mod1/AI16" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI16</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{22C4F42E-CE3B-4464-B1D5-9DBB12A123C9}</Property>
					</Item>
					<Item Name="Mod1/AI17" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI17</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6F1B1777-66CF-4516-9A2F-6307302B9A63}</Property>
					</Item>
					<Item Name="Mod1/AI18" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI18</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9546DD23-2C33-47DC-A09E-967BB5378F08}</Property>
					</Item>
					<Item Name="Mod1/AI19" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI19</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{14FF2D1F-EB83-4F85-9527-68B9ECEB851D}</Property>
					</Item>
					<Item Name="Mod1/AI20" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI20</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{0E8E30C4-9BDA-46D9-8783-902D4A968DB0}</Property>
					</Item>
					<Item Name="Mod1/AI21" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI21</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{1A223F0B-A811-4B4E-874B-1B78C2252731}</Property>
					</Item>
					<Item Name="Mod1/AI22" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI22</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{08CAAE0C-2792-49D8-B323-0DCD03D08487}</Property>
					</Item>
					<Item Name="Mod1/AI23" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI23</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{3D37AD98-83E7-499C-80E0-3760A2790FA0}</Property>
					</Item>
					<Item Name="Mod1/AI24" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI24</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{A734C667-1689-46A3-880E-830EC1607091}</Property>
					</Item>
					<Item Name="Mod1/AI25" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI25</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{77156762-466F-4CAF-BADF-E5A72B4E00AB}</Property>
					</Item>
					<Item Name="Mod1/AI26" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI26</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{2FFA3CEB-AD19-4E97-86C5-8FB2A7484B54}</Property>
					</Item>
					<Item Name="Mod1/AI27" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI27</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{0EC356A1-F5AA-4B02-8FBB-3DC86EC5E968}</Property>
					</Item>
					<Item Name="Mod1/AI28" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI28</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{7F14741E-4E1D-4F4E-8C8F-2AE34D2B1E60}</Property>
					</Item>
					<Item Name="Mod1/AI29" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI29</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9CB64339-944C-4B37-A7CC-838B6FD803CC}</Property>
					</Item>
					<Item Name="Mod1/AI30" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI30</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{65BEB2D0-01A1-4155-8A67-3CE2F6C379C0}</Property>
					</Item>
					<Item Name="Mod1/AI31" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod1/AI31</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F4CA4FBD-6FB5-47D6-89D0-B2800984360F}</Property>
					</Item>
				</Item>
				<Item Name="Mod2" Type="Folder">
					<Item Name="Mod2/DIO0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{660C804D-D13D-4728-8E67-B8D5116CD55B}</Property>
					</Item>
					<Item Name="Mod2/DIO1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{4D548D81-C4CC-4F74-85CA-8120C7A3EE74}</Property>
					</Item>
					<Item Name="Mod2/DIO2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{75612308-2FF4-4401-A2E7-7BF493CFAE60}</Property>
					</Item>
					<Item Name="Mod2/DIO3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D20092C5-EACF-4C7B-9C81-28F15ECA299C}</Property>
					</Item>
					<Item Name="Mod2/DIO4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6124E451-CA70-451C-BB93-8B2FDE43C364}</Property>
					</Item>
					<Item Name="Mod2/DIO5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6E3DAA5E-135B-4C28-A0BA-355EDB3A081E}</Property>
					</Item>
					<Item Name="Mod2/DIO6" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO6</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9FF6EE80-2ABE-4922-B5F1-BD485896F54D}</Property>
					</Item>
					<Item Name="Mod2/DIO7" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO7</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{B0897961-3243-45BD-85D5-A349C1B431C9}</Property>
					</Item>
					<Item Name="Mod2/DIO8" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO8</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9F2331D1-81F3-4F1E-8643-DB59C51D4361}</Property>
					</Item>
					<Item Name="Mod2/DIO9" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO9</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{99D1B5C2-25B4-44AD-B412-2B4E37C65DC0}</Property>
					</Item>
					<Item Name="Mod2/DIO10" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO10</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FB4C7067-E7A7-480C-88BB-73BC4BD51F34}</Property>
					</Item>
					<Item Name="Mod2/DIO11" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO11</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{7825F7AC-4C1F-4504-9C9C-4C71CE7BFF39}</Property>
					</Item>
					<Item Name="Mod2/DIO12" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO12</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{B43AD548-05FC-4671-87D4-BC167A5683FC}</Property>
					</Item>
					<Item Name="Mod2/DIO13" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO13</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F9F3188A-B9FC-4D8A-A1C5-5582EF7560FE}</Property>
					</Item>
					<Item Name="Mod2/DIO14" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO14</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{E0560254-82B6-42D6-BB3C-9980234B2DFD}</Property>
					</Item>
					<Item Name="Mod2/DIO15" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO15</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{369AE2EE-2352-4592-9D66-9357CA268D80}</Property>
					</Item>
					<Item Name="Mod2/DIO16" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO16</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FFB95158-0C8F-4842-89B7-0963A77A71B4}</Property>
					</Item>
					<Item Name="Mod2/DIO17" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO17</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D906B0C5-C55F-45B9-BE8C-BAF2D9276E47}</Property>
					</Item>
					<Item Name="Mod2/DIO18" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO18</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D2394D95-6FCE-49E1-8EAA-F178CB677582}</Property>
					</Item>
					<Item Name="Mod2/DIO19" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO19</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9CAD961C-4595-4838-BA10-CDAFC031A799}</Property>
					</Item>
					<Item Name="Mod2/DIO20" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO20</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{253BD8EB-A0C4-4C68-88FD-AF4313FEF927}</Property>
					</Item>
					<Item Name="Mod2/DIO21" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO21</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{2AC24A55-73B9-4FCB-93DD-8F2D5D60FFC0}</Property>
					</Item>
					<Item Name="Mod2/DIO22" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO22</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{1EE9A483-3BF4-4CAA-9C97-2D2856E1A1BE}</Property>
					</Item>
					<Item Name="Mod2/DIO23" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO23</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{265D6EAB-0B6B-4DB7-BD87-F423C255D11D}</Property>
					</Item>
					<Item Name="Mod2/DIO24" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO24</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F434B6CC-DAF0-4EEB-871D-35FFF2F687EC}</Property>
					</Item>
					<Item Name="Mod2/DIO25" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO25</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{22E59746-DC86-4D08-BB6E-ACAFC5DF263F}</Property>
					</Item>
					<Item Name="Mod2/DIO26" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO26</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{DCBA2FEC-1D56-4AE6-A444-5C2463E4B70F}</Property>
					</Item>
					<Item Name="Mod2/DIO27" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO27</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{9FB7A7D4-4B01-4A66-927F-5C6F74327FC9}</Property>
					</Item>
					<Item Name="Mod2/DIO28" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO28</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{20899980-4CAD-49BB-954C-528EC47BBF8F}</Property>
					</Item>
					<Item Name="Mod2/DIO29" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO29</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F6E1A615-C9B8-4083-9EC6-65E5E49A4534}</Property>
					</Item>
					<Item Name="Mod2/DIO30" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO30</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{187B7C1A-CBC0-4A1F-B967-B42BF2E61313}</Property>
					</Item>
					<Item Name="Mod2/DIO31" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO31</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{FBB2A9C6-33CC-48FC-AA2B-966E4448A73F}</Property>
					</Item>
					<Item Name="Mod2/DIO7:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO7:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{177EFE3F-BF73-4862-AE22-A2D27B807ADC}</Property>
					</Item>
					<Item Name="Mod2/DIO15:8" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO15:8</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{4D733EEE-21B8-466F-826F-CDCD07EAA86B}</Property>
					</Item>
					<Item Name="Mod2/DIO23:16" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO23:16</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{65076FE8-2CEA-451D-B373-B779EBF09239}</Property>
					</Item>
					<Item Name="Mod2/DIO31:24" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO31:24</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F1EF5E4D-84F4-42AF-9B35-FB5238F42E10}</Property>
					</Item>
					<Item Name="Mod2/DIO31:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod2/DIO31:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{215C4390-54AF-4E7F-A4B2-975E2F75B6A6}</Property>
					</Item>
				</Item>
				<Item Name="Mod3" Type="Folder">
					<Item Name="Mod3/DO0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{6777E432-E37B-4549-8D8C-BB4771D4E4F1}</Property>
					</Item>
					<Item Name="Mod3/DO1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{D268A59E-B0A1-4E84-A873-C8421EAC28ED}</Property>
					</Item>
					<Item Name="Mod3/DO2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F7629210-299E-4B93-A839-3EE90A2E8D6C}</Property>
					</Item>
					<Item Name="Mod3/DO3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{F7358327-6937-43D3-ABC3-4E4B9F18D8AF}</Property>
					</Item>
					<Item Name="Mod3/DO4" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO4</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{AC8981F2-7D89-45FF-B171-AABE9F2F8C7D}</Property>
					</Item>
					<Item Name="Mod3/DO5" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO5</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{3596D672-1A23-4509-905A-9B33F089EFE7}</Property>
					</Item>
					<Item Name="Mod3/DO6" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO6</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{248EA9B9-D2B5-404F-B4DB-053A1D92CE7F}</Property>
					</Item>
					<Item Name="Mod3/DO7" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO7</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{BB1F0EBB-4771-42EC-B15D-F9E31023AA48}</Property>
					</Item>
					<Item Name="Mod3/DO7:0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="ArbitrationForOutputData">
   <Value>NeverArbitrate</Value>
   </Attribute>
   <Attribute name="resource">
   <Value>/crio_Mod3/DO7:0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C5E8F213-0251-4E9A-A7AB-34CB6C005266}</Property>
					</Item>
				</Item>
				<Item Name="Mod4" Type="Folder">
					<Item Name="Mod4/TC0" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/TC0</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{DBAD45D8-1982-4204-B973-A72048975143}</Property>
					</Item>
					<Item Name="Mod4/TC1" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/TC1</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{EC2F2D43-49E9-420A-A01E-BA87AEFD55A8}</Property>
					</Item>
					<Item Name="Mod4/TC2" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/TC2</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{C6C8CDE5-747F-42A8-9F40-FA0F565ED113}</Property>
					</Item>
					<Item Name="Mod4/TC3" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/TC3</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{30C3CF6B-6FBA-4C6C-A3D6-44C710B7F82C}</Property>
					</Item>
					<Item Name="Mod4/CJC" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/CJC</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{3632BF45-5488-4346-81DD-DA334D0E6928}</Property>
					</Item>
					<Item Name="Mod4/Autozero" Type="Elemental IO">
						<Property Name="eioAttrBag" Type="Xml"><AttributeSet name="">
   <Attribute name="resource">
   <Value>/crio_Mod4/Autozero</Value>
   </Attribute>
</AttributeSet>
</Property>
						<Property Name="FPGA.PersistentID" Type="Str">{AD8C5513-28C6-4C82-9E04-B82C9DEA6CC8}</Property>
					</Item>
				</Item>
				<Item Name="40 MHz Onboard Clock" Type="FPGA Base Clock">
					<Property Name="FPGA.PersistentID" Type="Str">{8C1A3F38-39B1-4FF5-94F5-0DF049F058F2}</Property>
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
				<Item Name="Mod1" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 1</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9209</Property>
					<Property Name="cRIOModule.AI0.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI0.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI0.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI1.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI1.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI1.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI10.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI10.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI10.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI11.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI11.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI11.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI12.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI12.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI12.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI13.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI13.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI13.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI14.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI14.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI14.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI15.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI15.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI15.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI16.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI17.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI18.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI19.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI2.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI2.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI2.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI20.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI21.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI22.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI23.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI24.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI25.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI26.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI27.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI28.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI29.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI3.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI3.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI3.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI30.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI31.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI4.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI4.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI4.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI5.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI5.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI5.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI6.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI6.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI6.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI7.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI7.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI7.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI8.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI8.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI8.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.AI9.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI9.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI9.Terminal Mode" Type="Str">0</Property>
					<Property Name="cRIOModule.Conversion Time" Type="Str">1</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.Enable Open TC Detection" Type="Str">true</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{D48CAF8D-F933-4E2B-93F9-FC4660B50A0F}</Property>
				</Item>
				<Item Name="Mod2" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 2</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">true</Property>
					<Property Name="crio.Type" Type="Str">NI 9403</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.DisableArbitration" Type="Str">false</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.Initial Line Direction" Type="Str">00000000000000000000000000000000</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{AE7128BB-5332-444B-BF39-B08DC5049773}</Property>
				</Item>
				<Item Name="Mod3" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 3</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SDPWMPeriod0" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod1" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod2" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod3" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod4" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod5" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod6" Type="Str">0</Property>
					<Property Name="crio.SDPWMPeriod7" Type="Str">0</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9472</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.DIO3_0InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.DIO7_4InitialDir" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="cRIOModule.NumSyncRegs" Type="Str">11111111</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{7B760C81-150D-4C34-9D16-B28ECA351D68}</Property>
				</Item>
				<Item Name="Mod4" Type="RIO C Series Module">
					<Property Name="crio.Calibration" Type="Str">1</Property>
					<Property Name="crio.Location" Type="Str">Slot 4</Property>
					<Property Name="crio.RequiresValidation" Type="Bool">false</Property>
					<Property Name="crio.SDcounterSlaveChannelMask" Type="Str">0</Property>
					<Property Name="crio.SDCounterSlaveMasterSlot" Type="Str">0</Property>
					<Property Name="crio.SDInputFilter" Type="Str">128</Property>
					<Property Name="crio.SupportsDynamicRes" Type="Bool">false</Property>
					<Property Name="crio.Type" Type="Str">NI 9211</Property>
					<Property Name="cRIOModule.AI0.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI0.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI1.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI1.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI2.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI2.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.AI3.DegreeRange" Type="Str">2</Property>
					<Property Name="cRIOModule.AI3.TCoupleType" Type="Str">0</Property>
					<Property Name="cRIOModule.DigitalIOMode" Type="Str">0</Property>
					<Property Name="cRIOModule.EnableSpecialtyDigital" Type="Str">false</Property>
					<Property Name="FPGA.PersistentID" Type="Str">{674044F1-B226-4C72-8DC4-526B74B877B7}</Property>
				</Item>
				<Item Name="real-time-fault-handler.vi" Type="VI" URL="../real-time-fault-handler.vi">
					<Property Name="configString.guid" Type="Str">{07241D9F-1772-4A02-AE32-BDFBE5503DFF}NumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool{08CAAE0C-2792-49D8-B323-0DCD03D08487}resource=/crio_Mod1/AI22;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{0E8E30C4-9BDA-46D9-8783-902D4A968DB0}resource=/crio_Mod1/AI20;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{0EC356A1-F5AA-4B02-8FBB-3DC86EC5E968}resource=/crio_Mod1/AI27;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{14FF2D1F-EB83-4F85-9527-68B9ECEB851D}resource=/crio_Mod1/AI19;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{15946E51-4BD7-405E-A89B-1DBD3539CC88}resource=/crio_Mod1/AI7;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{177EFE3F-BF73-4862-AE22-A2D27B807ADC}resource=/crio_Mod2/DIO7:0;0;ReadMethodType=u8;WriteMethodType=u8{187B7C1A-CBC0-4A1F-B967-B42BF2E61313}resource=/crio_Mod2/DIO30;0;ReadMethodType=bool;WriteMethodType=bool{1A223F0B-A811-4B4E-874B-1B78C2252731}resource=/crio_Mod1/AI21;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{1EE9A483-3BF4-4CAA-9C97-2D2856E1A1BE}resource=/crio_Mod2/DIO22;0;ReadMethodType=bool;WriteMethodType=bool{20899980-4CAD-49BB-954C-528EC47BBF8F}resource=/crio_Mod2/DIO28;0;ReadMethodType=bool;WriteMethodType=bool{215C4390-54AF-4E7F-A4B2-975E2F75B6A6}resource=/crio_Mod2/DIO31:0;0;ReadMethodType=u32;WriteMethodType=u32{22C4F42E-CE3B-4464-B1D5-9DBB12A123C9}resource=/crio_Mod1/AI16;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{22E59746-DC86-4D08-BB6E-ACAFC5DF263F}resource=/crio_Mod2/DIO25;0;ReadMethodType=bool;WriteMethodType=bool{248EA9B9-D2B5-404F-B4DB-053A1D92CE7F}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO6;0;ReadMethodType=bool;WriteMethodType=bool{253BD8EB-A0C4-4C68-88FD-AF4313FEF927}resource=/crio_Mod2/DIO20;0;ReadMethodType=bool;WriteMethodType=bool{256D5CDB-66A1-4137-963C-2CC831AEFFC9}resource=/crio_Mod1/AI8;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{265D6EAB-0B6B-4DB7-BD87-F423C255D11D}resource=/crio_Mod2/DIO23;0;ReadMethodType=bool;WriteMethodType=bool{2AC24A55-73B9-4FCB-93DD-8F2D5D60FFC0}resource=/crio_Mod2/DIO21;0;ReadMethodType=bool;WriteMethodType=bool{2FFA3CEB-AD19-4E97-86C5-8FB2A7484B54}resource=/crio_Mod1/AI26;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{2FFAF33C-C0B6-4D4A-A278-B32EDD46322F}resource=/crio_Mod1/AI10;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{30C3CF6B-6FBA-4C6C-A3D6-44C710B7F82C}resource=/crio_Mod4/TC3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{31042BD3-65ED-434D-ACF1-CD4B3E668EA6}resource=/crio_Mod1/AI4;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{33425133-4C44-42EE-ACD9-6B03B7C637B5}resource=/crio_Mod1/AI14;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{335F1EE5-1C92-4211-8C1C-3138C11F090C}resource=/crio_Mod1/AI3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{33A98F5E-E082-4B03-A56B-67859ECC7EBD}resource=/crio_Mod1/AI12;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{3596D672-1A23-4509-905A-9B33F089EFE7}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO5;0;ReadMethodType=bool;WriteMethodType=bool{3632BF45-5488-4346-81DD-DA334D0E6928}resource=/crio_Mod4/CJC;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{369AE2EE-2352-4592-9D66-9357CA268D80}resource=/crio_Mod2/DIO15;0;ReadMethodType=bool;WriteMethodType=bool{3D37AD98-83E7-499C-80E0-3760A2790FA0}resource=/crio_Mod1/AI23;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{499C87DC-E1F9-4CF1-B338-7A6B2922D264}resource=/crio_Mod1/AI11;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{4D548D81-C4CC-4F74-85CA-8120C7A3EE74}resource=/crio_Mod2/DIO1;0;ReadMethodType=bool;WriteMethodType=bool{4D733EEE-21B8-466F-826F-CDCD07EAA86B}resource=/crio_Mod2/DIO15:8;0;ReadMethodType=u8;WriteMethodType=u8{5705BA54-5A6E-4A65-AB63-F7BF57E503E0}resource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8{5B2CEE3F-0034-4A00-B2DE-0406AEAA4A64}resource=/Chassis Temperature;0;ReadMethodType=i16{609A093E-3939-46F9-877E-F7814E8B7DE4}resource=/crio_Mod1/AI13;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{6124E451-CA70-451C-BB93-8B2FDE43C364}resource=/crio_Mod2/DIO4;0;ReadMethodType=bool;WriteMethodType=bool{65076FE8-2CEA-451D-B373-B779EBF09239}resource=/crio_Mod2/DIO23:16;0;ReadMethodType=u8;WriteMethodType=u8{65BEB2D0-01A1-4155-8A67-3CE2F6C379C0}resource=/crio_Mod1/AI30;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{660C804D-D13D-4728-8E67-B8D5116CD55B}resource=/crio_Mod2/DIO0;0;ReadMethodType=bool;WriteMethodType=bool{674044F1-B226-4C72-8DC4-526B74B877B7}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 4,crio.Type=NI 9211,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]{6777E432-E37B-4549-8D8C-BB4771D4E4F1}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO0;0;ReadMethodType=bool;WriteMethodType=bool{6C7121C2-7635-44C5-B574-A98ADCB5A386}resource=/crio_Mod1/AI6;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{6E3DAA5E-135B-4C28-A0BA-355EDB3A081E}resource=/crio_Mod2/DIO5;0;ReadMethodType=bool;WriteMethodType=bool{6F1B1777-66CF-4516-9A2F-6307302B9A63}resource=/crio_Mod1/AI17;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{75612308-2FF4-4401-A2E7-7BF493CFAE60}resource=/crio_Mod2/DIO2;0;ReadMethodType=bool;WriteMethodType=bool{77156762-466F-4CAF-BADF-E5A72B4E00AB}resource=/crio_Mod1/AI25;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{77E91E60-A3D2-4CD9-8160-2853A8DDF11D}resource=/crio_Mod1/AI15;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{7825F7AC-4C1F-4504-9C9C-4C71CE7BFF39}resource=/crio_Mod2/DIO11;0;ReadMethodType=bool;WriteMethodType=bool{7B760C81-150D-4C34-9D16-B28ECA351D68}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9472,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]{7F14741E-4E1D-4F4E-8C8F-2AE34D2B1E60}resource=/crio_Mod1/AI28;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{81D18035-3B86-40F7-BE04-52CBD2B563F9}resource=/crio_Mod1/AI9;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{8408D1A2-2697-48D5-AFCE-CCF99D597BEE}resource=/crio_Mod1/AI1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{8C1A3F38-39B1-4FF5-94F5-0DF049F058F2}ResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;{9546DD23-2C33-47DC-A09E-967BB5378F08}resource=/crio_Mod1/AI18;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{99D1B5C2-25B4-44AD-B412-2B4E37C65DC0}resource=/crio_Mod2/DIO9;0;ReadMethodType=bool;WriteMethodType=bool{9CAD961C-4595-4838-BA10-CDAFC031A799}resource=/crio_Mod2/DIO19;0;ReadMethodType=bool;WriteMethodType=bool{9CB64339-944C-4B37-A7CC-838B6FD803CC}resource=/crio_Mod1/AI29;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{9F2331D1-81F3-4F1E-8643-DB59C51D4361}resource=/crio_Mod2/DIO8;0;ReadMethodType=bool;WriteMethodType=bool{9FB7A7D4-4B01-4A66-927F-5C6F74327FC9}resource=/crio_Mod2/DIO27;0;ReadMethodType=bool;WriteMethodType=bool{9FF6EE80-2ABE-4922-B5F1-BD485896F54D}resource=/crio_Mod2/DIO6;0;ReadMethodType=bool;WriteMethodType=bool{A734C667-1689-46A3-880E-830EC1607091}resource=/crio_Mod1/AI24;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{AA898AD2-F1F5-4029-820D-C982F5D6E367}resource=/System Reset;0;ReadMethodType=bool;WriteMethodType=bool{AC8981F2-7D89-45FF-B171-AABE9F2F8C7D}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO4;0;ReadMethodType=bool;WriteMethodType=bool{AD8C5513-28C6-4C82-9E04-B82C9DEA6CC8}resource=/crio_Mod4/Autozero;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{AE7128BB-5332-444B-BF39-B08DC5049773}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9403,cRIOModule.DisableArbitration=false,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.Initial Line Direction=00000000000000000000000000000000,cRIOModule.RsiAttributes=[crioConfig.End]{B0897961-3243-45BD-85D5-A349C1B431C9}resource=/crio_Mod2/DIO7;0;ReadMethodType=bool;WriteMethodType=bool{B43AD548-05FC-4671-87D4-BC167A5683FC}resource=/crio_Mod2/DIO12;0;ReadMethodType=bool;WriteMethodType=bool{BB1F0EBB-4771-42EC-B15D-F9E31023AA48}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7;0;ReadMethodType=bool;WriteMethodType=bool{C5E8F213-0251-4E9A-A7AB-34CB6C005266}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8{C6C8CDE5-747F-42A8-9F40-FA0F565ED113}resource=/crio_Mod4/TC2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{D20092C5-EACF-4C7B-9C81-28F15ECA299C}resource=/crio_Mod2/DIO3;0;ReadMethodType=bool;WriteMethodType=bool{D2394D95-6FCE-49E1-8EAA-F178CB677582}resource=/crio_Mod2/DIO18;0;ReadMethodType=bool;WriteMethodType=bool{D268A59E-B0A1-4E84-A873-C8421EAC28ED}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO1;0;ReadMethodType=bool;WriteMethodType=bool{D48CAF8D-F933-4E2B-93F9-FC4660B50A0F}[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9209,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI0.Terminal Mode=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI1.Terminal Mode=0,cRIOModule.AI10.DegreeRange=2,cRIOModule.AI10.TCoupleType=0,cRIOModule.AI10.Terminal Mode=0,cRIOModule.AI11.DegreeRange=2,cRIOModule.AI11.TCoupleType=0,cRIOModule.AI11.Terminal Mode=0,cRIOModule.AI12.DegreeRange=2,cRIOModule.AI12.TCoupleType=0,cRIOModule.AI12.Terminal Mode=0,cRIOModule.AI13.DegreeRange=2,cRIOModule.AI13.TCoupleType=0,cRIOModule.AI13.Terminal Mode=0,cRIOModule.AI14.DegreeRange=2,cRIOModule.AI14.TCoupleType=0,cRIOModule.AI14.Terminal Mode=0,cRIOModule.AI15.DegreeRange=2,cRIOModule.AI15.TCoupleType=0,cRIOModule.AI15.Terminal Mode=0,cRIOModule.AI16.Terminal Mode=0,cRIOModule.AI17.Terminal Mode=0,cRIOModule.AI18.Terminal Mode=0,cRIOModule.AI19.Terminal Mode=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI2.Terminal Mode=0,cRIOModule.AI20.Terminal Mode=0,cRIOModule.AI21.Terminal Mode=0,cRIOModule.AI22.Terminal Mode=0,cRIOModule.AI23.Terminal Mode=0,cRIOModule.AI24.Terminal Mode=0,cRIOModule.AI25.Terminal Mode=0,cRIOModule.AI26.Terminal Mode=0,cRIOModule.AI27.Terminal Mode=0,cRIOModule.AI28.Terminal Mode=0,cRIOModule.AI29.Terminal Mode=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.AI3.Terminal Mode=0,cRIOModule.AI30.Terminal Mode=0,cRIOModule.AI31.Terminal Mode=0,cRIOModule.AI4.DegreeRange=2,cRIOModule.AI4.TCoupleType=0,cRIOModule.AI4.Terminal Mode=0,cRIOModule.AI5.DegreeRange=2,cRIOModule.AI5.TCoupleType=0,cRIOModule.AI5.Terminal Mode=0,cRIOModule.AI6.DegreeRange=2,cRIOModule.AI6.TCoupleType=0,cRIOModule.AI6.Terminal Mode=0,cRIOModule.AI7.DegreeRange=2,cRIOModule.AI7.TCoupleType=0,cRIOModule.AI7.Terminal Mode=0,cRIOModule.AI8.DegreeRange=2,cRIOModule.AI8.TCoupleType=0,cRIOModule.AI8.Terminal Mode=0,cRIOModule.AI9.DegreeRange=2,cRIOModule.AI9.TCoupleType=0,cRIOModule.AI9.Terminal Mode=0,cRIOModule.Conversion Time=1,cRIOModule.Enable Open TC Detection=true,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]{D6BA5AD4-BF95-4A18-939D-1917B482D3A5}resource=/Scan Clock;0;ReadMethodType=bool{D906B0C5-C55F-45B9-BE8C-BAF2D9276E47}resource=/crio_Mod2/DIO17;0;ReadMethodType=bool;WriteMethodType=bool{DBAD45D8-1982-4204-B973-A72048975143}resource=/crio_Mod4/TC0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{DCBA2FEC-1D56-4AE6-A444-5C2463E4B70F}resource=/crio_Mod2/DIO26;0;ReadMethodType=bool;WriteMethodType=bool{E0560254-82B6-42D6-BB3C-9980234B2DFD}resource=/crio_Mod2/DIO14;0;ReadMethodType=bool;WriteMethodType=bool{E0AF840C-7CA1-4EF9-B3CE-930171A2E73C}resource=/crio_Mod1/AI5;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{E1BA66DC-601B-4B93-ADEF-5A9CF2B5A251}resource=/crio_Mod1/AI2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{EC2F2D43-49E9-420A-A01E-BA87AEFD55A8}resource=/crio_Mod4/TC1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctl{EEF9E8E0-D51C-4030-9DB7-E937644438CB}resource=/crio_Mod1/AI0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{F1EF5E4D-84F4-42AF-9B35-FB5238F42E10}resource=/crio_Mod2/DIO31:24;0;ReadMethodType=u8;WriteMethodType=u8{F434B6CC-DAF0-4EEB-871D-35FFF2F687EC}resource=/crio_Mod2/DIO24;0;ReadMethodType=bool;WriteMethodType=bool{F4CA4FBD-6FB5-47D6-89D0-B2800984360F}resource=/crio_Mod1/AI31;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctl{F6E1A615-C9B8-4083-9EC6-65E5E49A4534}resource=/crio_Mod2/DIO29;0;ReadMethodType=bool;WriteMethodType=bool{F7358327-6937-43D3-ABC3-4E4B9F18D8AF}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO3;0;ReadMethodType=bool;WriteMethodType=bool{F7629210-299E-4B93-A839-3EE90A2E8D6C}ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO2;0;ReadMethodType=bool;WriteMethodType=bool{F9F3188A-B9FC-4D8A-A1C5-5582EF7560FE}resource=/crio_Mod2/DIO13;0;ReadMethodType=bool;WriteMethodType=bool{FB4C7067-E7A7-480C-88BB-73BC4BD51F34}resource=/crio_Mod2/DIO10;0;ReadMethodType=bool;WriteMethodType=bool{FBB2A9C6-33CC-48FC-AA2B-966E4448A73F}resource=/crio_Mod2/DIO31;0;ReadMethodType=bool;WriteMethodType=bool{FEFE015B-3606-42AB-B188-A939EEA6022F}resource=/Sleep;0;ReadMethodType=bool;WriteMethodType=bool{FFB95158-0C8F-4842-89B7-0963A77A71B4}resource=/crio_Mod2/DIO16;0;ReadMethodType=bool;WriteMethodType=boolcRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGA</Property>
					<Property Name="configString.name" Type="Str">40 MHz Onboard ClockResourceName=40 MHz Onboard Clock;TopSignalConnect=Clk40;ClockSignalName=Clk40;MinFreq=40000000.000000;MaxFreq=40000000.000000;VariableFreq=0;NomFreq=40000000.000000;PeakPeriodJitter=250.000000;MinDutyCycle=50.000000;MaxDutyCycle=50.000000;Accuracy=100.000000;RunTime=0;SpreadSpectrum=0;GenericDataHash=D41D8CD98F00B204E9800998ECF8427E;Chassis Temperatureresource=/Chassis Temperature;0;ReadMethodType=i16cRIO-9031/Clk40/falsetrueFPGA_EXECUTION_MODEDEV_COMPUTER_SIM_IOFPGA_TARGET_CLASSCRIO_9031FPGA_TARGET_FAMILYKINTEX7TARGET_TYPEFPGAMod1/AI0resource=/crio_Mod1/AI0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI10resource=/crio_Mod1/AI10;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI11resource=/crio_Mod1/AI11;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI12resource=/crio_Mod1/AI12;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI13resource=/crio_Mod1/AI13;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI14resource=/crio_Mod1/AI14;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI15resource=/crio_Mod1/AI15;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI16resource=/crio_Mod1/AI16;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI17resource=/crio_Mod1/AI17;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI18resource=/crio_Mod1/AI18;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI19resource=/crio_Mod1/AI19;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI1resource=/crio_Mod1/AI1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI20resource=/crio_Mod1/AI20;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI21resource=/crio_Mod1/AI21;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI22resource=/crio_Mod1/AI22;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI23resource=/crio_Mod1/AI23;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI24resource=/crio_Mod1/AI24;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI25resource=/crio_Mod1/AI25;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI26resource=/crio_Mod1/AI26;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI27resource=/crio_Mod1/AI27;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI28resource=/crio_Mod1/AI28;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI29resource=/crio_Mod1/AI29;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI2resource=/crio_Mod1/AI2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI30resource=/crio_Mod1/AI30;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI31resource=/crio_Mod1/AI31;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI3resource=/crio_Mod1/AI3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI4resource=/crio_Mod1/AI4;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI5resource=/crio_Mod1/AI5;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI6resource=/crio_Mod1/AI6;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI7resource=/crio_Mod1/AI7;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI8resource=/crio_Mod1/AI8;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1/AI9resource=/crio_Mod1/AI9;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_5.ctlMod1[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 1,crio.Type=NI 9209,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI0.Terminal Mode=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI1.Terminal Mode=0,cRIOModule.AI10.DegreeRange=2,cRIOModule.AI10.TCoupleType=0,cRIOModule.AI10.Terminal Mode=0,cRIOModule.AI11.DegreeRange=2,cRIOModule.AI11.TCoupleType=0,cRIOModule.AI11.Terminal Mode=0,cRIOModule.AI12.DegreeRange=2,cRIOModule.AI12.TCoupleType=0,cRIOModule.AI12.Terminal Mode=0,cRIOModule.AI13.DegreeRange=2,cRIOModule.AI13.TCoupleType=0,cRIOModule.AI13.Terminal Mode=0,cRIOModule.AI14.DegreeRange=2,cRIOModule.AI14.TCoupleType=0,cRIOModule.AI14.Terminal Mode=0,cRIOModule.AI15.DegreeRange=2,cRIOModule.AI15.TCoupleType=0,cRIOModule.AI15.Terminal Mode=0,cRIOModule.AI16.Terminal Mode=0,cRIOModule.AI17.Terminal Mode=0,cRIOModule.AI18.Terminal Mode=0,cRIOModule.AI19.Terminal Mode=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI2.Terminal Mode=0,cRIOModule.AI20.Terminal Mode=0,cRIOModule.AI21.Terminal Mode=0,cRIOModule.AI22.Terminal Mode=0,cRIOModule.AI23.Terminal Mode=0,cRIOModule.AI24.Terminal Mode=0,cRIOModule.AI25.Terminal Mode=0,cRIOModule.AI26.Terminal Mode=0,cRIOModule.AI27.Terminal Mode=0,cRIOModule.AI28.Terminal Mode=0,cRIOModule.AI29.Terminal Mode=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.AI3.Terminal Mode=0,cRIOModule.AI30.Terminal Mode=0,cRIOModule.AI31.Terminal Mode=0,cRIOModule.AI4.DegreeRange=2,cRIOModule.AI4.TCoupleType=0,cRIOModule.AI4.Terminal Mode=0,cRIOModule.AI5.DegreeRange=2,cRIOModule.AI5.TCoupleType=0,cRIOModule.AI5.Terminal Mode=0,cRIOModule.AI6.DegreeRange=2,cRIOModule.AI6.TCoupleType=0,cRIOModule.AI6.Terminal Mode=0,cRIOModule.AI7.DegreeRange=2,cRIOModule.AI7.TCoupleType=0,cRIOModule.AI7.Terminal Mode=0,cRIOModule.AI8.DegreeRange=2,cRIOModule.AI8.TCoupleType=0,cRIOModule.AI8.Terminal Mode=0,cRIOModule.AI9.DegreeRange=2,cRIOModule.AI9.TCoupleType=0,cRIOModule.AI9.Terminal Mode=0,cRIOModule.Conversion Time=1,cRIOModule.Enable Open TC Detection=true,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]Mod2/DIO0resource=/crio_Mod2/DIO0;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO10resource=/crio_Mod2/DIO10;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO11resource=/crio_Mod2/DIO11;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO12resource=/crio_Mod2/DIO12;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO13resource=/crio_Mod2/DIO13;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO14resource=/crio_Mod2/DIO14;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO15:8resource=/crio_Mod2/DIO15:8;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO15resource=/crio_Mod2/DIO15;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO16resource=/crio_Mod2/DIO16;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO17resource=/crio_Mod2/DIO17;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO18resource=/crio_Mod2/DIO18;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO19resource=/crio_Mod2/DIO19;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO1resource=/crio_Mod2/DIO1;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO20resource=/crio_Mod2/DIO20;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO21resource=/crio_Mod2/DIO21;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO22resource=/crio_Mod2/DIO22;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO23:16resource=/crio_Mod2/DIO23:16;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO23resource=/crio_Mod2/DIO23;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO24resource=/crio_Mod2/DIO24;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO25resource=/crio_Mod2/DIO25;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO26resource=/crio_Mod2/DIO26;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO27resource=/crio_Mod2/DIO27;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO28resource=/crio_Mod2/DIO28;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO29resource=/crio_Mod2/DIO29;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO2resource=/crio_Mod2/DIO2;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO30resource=/crio_Mod2/DIO30;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO31:0resource=/crio_Mod2/DIO31:0;0;ReadMethodType=u32;WriteMethodType=u32Mod2/DIO31:24resource=/crio_Mod2/DIO31:24;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO31resource=/crio_Mod2/DIO31;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO3resource=/crio_Mod2/DIO3;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO4resource=/crio_Mod2/DIO4;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO5resource=/crio_Mod2/DIO5;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO6resource=/crio_Mod2/DIO6;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO7:0resource=/crio_Mod2/DIO7:0;0;ReadMethodType=u8;WriteMethodType=u8Mod2/DIO7resource=/crio_Mod2/DIO7;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO8resource=/crio_Mod2/DIO8;0;ReadMethodType=bool;WriteMethodType=boolMod2/DIO9resource=/crio_Mod2/DIO9;0;ReadMethodType=bool;WriteMethodType=boolMod2[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 2,crio.Type=NI 9403,cRIOModule.DisableArbitration=false,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.Initial Line Direction=00000000000000000000000000000000,cRIOModule.RsiAttributes=[crioConfig.End]Mod3/DO0ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO0;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO1ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO1;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO2ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO2;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO3ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO3;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO4ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO4;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO5ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO5;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO6ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO6;0;ReadMethodType=bool;WriteMethodType=boolMod3/DO7:0ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7:0;0;ReadMethodType=u8;WriteMethodType=u8Mod3/DO7ArbitrationForOutputData=NeverArbitrate;resource=/crio_Mod3/DO7;0;ReadMethodType=bool;WriteMethodType=boolMod3[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 3,crio.Type=NI 9472,cRIOModule.DIO3_0InitialDir=0,cRIOModule.DIO7_4InitialDir=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.NumSyncRegs=11111111,cRIOModule.RsiAttributes=[crioConfig.End]Mod4/Autozeroresource=/crio_Mod4/Autozero;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/CJCresource=/crio_Mod4/CJC;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC0resource=/crio_Mod4/TC0;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC1resource=/crio_Mod4/TC1;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC2resource=/crio_Mod4/TC2;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4/TC3resource=/crio_Mod4/TC3;0;ReadMethodType=vi.lib\LabVIEW Targets\FPGA\cRIO\shared\nicrio_FXP_Controls\nicrio_FXP_S_24_neg2.ctlMod4[crioConfig.Begin]crio.Calibration=1,crio.Location=Slot 4,crio.Type=NI 9211,cRIOModule.AI0.DegreeRange=2,cRIOModule.AI0.TCoupleType=0,cRIOModule.AI1.DegreeRange=2,cRIOModule.AI1.TCoupleType=0,cRIOModule.AI2.DegreeRange=2,cRIOModule.AI2.TCoupleType=0,cRIOModule.AI3.DegreeRange=2,cRIOModule.AI3.TCoupleType=0,cRIOModule.EnableDECoM=false,cRIOModule.EnableInputFifo=false,cRIOModule.EnableOutputFifo=false,cRIOModule.RsiAttributes=[crioConfig.End]Scan Clockresource=/Scan Clock;0;ReadMethodType=boolSleepresource=/Sleep;0;ReadMethodType=bool;WriteMethodType=boolSystem Resetresource=/System Reset;0;ReadMethodType=bool;WriteMethodType=boolUSER FPGA LEDresource=/USER FPGA LED;0;ReadMethodType=u8;WriteMethodType=u8USER Push ButtonNumberOfSyncRegistersForReadInProject=0;resource=/USER Push Button;0;ReadMethodType=bool</Property>
					<Property Name="NI.LV.FPGA.InterfaceBitfile" Type="Str">C:\Users\markt\Documents\GitHub\umdloop\labview\real-time-fault-catch\FPGA Bitfiles\real-time-fault-_FPGATarget_real-time-fault-_GASSChVGhic.lvbitx</Property>
				</Item>
				<Item Name="Dependencies" Type="Dependencies"/>
				<Item Name="Build Specifications" Type="Build">
					<Item Name="real-time-fault-handler" Type="{F4C5E96F-7410-48A5-BB87-3559BC9B167F}">
						<Property Name="AllowEnableRemoval" Type="Bool">false</Property>
						<Property Name="BuildSpecDecription" Type="Str"></Property>
						<Property Name="BuildSpecName" Type="Str">real-time-fault-handler</Property>
						<Property Name="Comp.BitfileName" Type="Str">real-time-fault-_FPGATarget_real-time-fault-_GASSChVGhic.lvbitx</Property>
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
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePath" Type="Path">/C/Users/markt/Documents/GitHub/umdloop/labview/real-time-fault-catch/FPGA Bitfiles/real-time-fault-_FPGATarget_real-time-fault-_GASSChVGhic.lvbitx</Property>
						<Property Name="NI.LV.FPGA.LastCompiledBitfilePathRelativeToProject" Type="Path">FPGA Bitfiles/real-time-fault-_FPGATarget_real-time-fault-_GASSChVGhic.lvbitx</Property>
						<Property Name="ProjectPath" Type="Path">/C/Users/markt/Documents/GitHub/umdloop/labview/real-time-fault-catch/real-time-fault-catch.lvproj</Property>
						<Property Name="RelativePath" Type="Bool">true</Property>
						<Property Name="RunWhenLoaded" Type="Bool">false</Property>
						<Property Name="SupportDownload" Type="Bool">true</Property>
						<Property Name="SupportResourceEstimation" Type="Bool">false</Property>
						<Property Name="TargetName" Type="Str">FPGA Target</Property>
						<Property Name="TopLevelVI" Type="Ref">/NI-cRIO-9031-ItWorked/Chassis/FPGA Target/real-time-fault-handler.vi</Property>
					</Item>
				</Item>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
