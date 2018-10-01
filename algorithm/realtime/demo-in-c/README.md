This is where our tech demo will go for testing the design processing of developing for the cRIO in C/C++ 

# Setup Documentation:

Everything stems from this [white paper](http://www.ni.com/white-paper/14623/en/).
- [Fancy C/C++ Eclipse Download](http://www.ni.com/download/labview-real-time-module-2017/6731/en/)

## Eclipse Setup:

Follow the [steps here](http://www.ni.com/tutorial/14625/en/) up to the point before you add the ...\c++\4.9.2\... path.

Add the path to Project > Properties > C/C++ Build > Settings > Cross GCC Compiler > Includes 
> C:\build\17.0\x64\sysroots\core2-64-nilrt-linux\usr\include


## Remote System Explorer Setup (if not already in Eclipse):

Add the link to Help > Install New Software > Add  
> http://download.eclipse.org/releases/indigo/

Then search "Remote" and download the stuff...

Start Eclipse Workbench, and choose Window > Open Perspective > Other > Remote System Explorer

## cRIO Connection
First, ensure that NI MAX is downloaded. It should come with the cRIO driver found here:
> http://www.ni.com/download/compactrio-device-drivers-may-2018/7321/en/
# Inital Setup for cRIO
Connect to the cRIO via ethernet or USB and then a popup should open notifying that the cRIO has been connected.
Choose the first option to open NI MAX. Now, expand remot systems and select the cRIO. 
Check startup settings and ensure that SSHD is enabled. If it is not enable, the admin login will be needed to enable it. Contact a team member for the password.
# Initial Setup for Eclipse
Open eclipse then navigate to the remote system explorer:
> Window > Open Perspective > Other > Remote System Explorer
Now, select create new connection and choose SSH only.
Enter the IP for the host name and give a brief description if you feel included. The IP should be:
> 172.22.11.2
If this does not work. The IP can be found in NI MAX
Now, create a folder on the cRIO (preferably under main) to SFTP the files into.
TODO: Finish description

## FPGA API
# Note:
> Remember to include libdl (add "dl" to libraries)
API Download
> http://www.ni.com/download/fpga-interface-c-api-17.0/6801/en/
API Documentation 
> http://zone.ni.com/reference/en-XX/help/372928G-01/capi/functions_write/
Run the NI FPGA C API Generator on the labview bitfile. 
Add the folder that the generated API was saved in to the includes and symbols in Ecliplse.
Use the NiFpga.h funcions to interface with the FPGA.
