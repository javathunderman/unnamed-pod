This is where our tech demo will go for testing the design processing of developing for the cRIO in C/C++ 

# Setup Documentation:

Everything stems from this [white paper](http://www.ni.com/white-paper/14623/en/).
[Fancy C/C++ Eclipse Download](http://www.ni.com/download/labview-real-time-module-2017/6731/en/)

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
for Mark to fill out

> 172.22.11.2
