---
layout: default
title: Release Notes
nav_order: 2
---


delaygenReleaseNotes
====================

Release 1.2.4
-------------

Adjusted to build against new Scalar module

Documentation moved to github pages

Release 1.2.3
-------------

BNC 505 support

Added Running and SetStopped

DG645 support

Added event status register support

Release 1.2.2
-------------

delaygenApp/op

Added bob files, updated ui and edl files

Release 1.2.1
-------------

delaygenApp/Db

req files now installed to top-level db folder

Release 1.2
-----------

DG645 support

Reduced the overhead for its use by removing the database status checking with the device after every operation. The status is checked at the driver level, and if it changes an interrupt will be generated instead to trigger reading by the database. Removed the disable checking from all the database records. Implemented delay tweaks using the hardware tweak functions instead of incrementing using calcs.

devDG535daa.db

Added alternate database support for the DG535, named devDG535daa.db, which uses the existing devDG535.c code. There is a parallel set of screens: devDG535daa.adl, devDG535Operationsdaa.adl, and devDG535Outputsdaa.adl. This alternate support is meant to be friendlier for frequent usage.

Updated OPI, UI, and EDL screens

Converted all the ADL files to the three other formats, and put them in each type's autoconvert directory.

Updated example IOC directory

The broken example IOC directory has been redone and tested (with a Linux IOC).

Release 1.1.1
-------------

delaygenApp/src/Makefile

Publish individual .dbd files

delaygenApp/op/ui/\*

fixed menus

Release 1.1.0
-------------

Modified drvAsynDG645.cpp, drvDG645.db, and DG645 screens.  

  
Removed race condition when there were multiple DG645 devices, simplified the code a bit, and had driver use DrvInfo field. Added new "Advanced Triggering" fields: mode enable/disable, prescale phases and trigger holdoff. Added a label for the device. Redid the screens, and removed the reference to the asyn record on the main screen. As the delay PV names were changed to make it simpler to open the individual delay screens, the rest of the PV names were changed to be consistent (where the first letter is now capitalized).

Moved all Gigabuadics support files (digitalDelay.\*) into file called "digitalDelay.tar.gz", in the "src" directory.  

  
This code was based on a custom hardware implementation of a solution for using a specific Gigabaudics delay generator. It is highly unlikely that anyone has used this code, and if it was used, it can be moved back into position by untarring the file in the root of the module.

Modified OPI files:  
BNC\_505.opi  
colbyMain.opi  
delaygen.opi  
devDG535.opi  
srsDG645.opi  

  
Remove relative paths

Release 1.0.7
-------------

Modified drvAsynDG645.cpp, srsDG645.adl, and drvDG645.db  

  
Applied Eric Norum's patch to add some additional prescale PVs

Release 1.0.6
-------------

Added opi  
Added BNC\_505.opi  
Added BNC\_505\_Pn.opi  
Added CoherentSDG.opi  
Added colbyConfig.opi  
Added colbyHelp.opi  
Added colbyMain.opi  
Added delaygen.opi  
Added devDG535.opi  
Added devDG535Outputs.opi  
Added digDelay.opi  
Added digDelayOutWord.opi  
Added srsDG645.opi  
Added srsDG645Iface.opi  
Added srsDG645Outputs.opi  

  
CSS-BOY displays

Modified drvAsynDG645.cpp  

  
Installed David Kline's DG645 support code, for multiple devices

Modified drvAsynCoherentSDG.cpp  
Modified drvAsynColby.cpp  
Modified nigpibInterpose.c  

  
Move epicsExport.h for win32 compatibility.

Modified drvDG645.db  

  
fix DG645 calc expressions from using A?B to A?B:0

Modified RELEASE  

  
Do not expand $(SUPPORT) ; include files to define SUPPORT and EPICS\_BASE

Deleted RELEASE.win32-x86  
Deleted RELEASE.win32-x86-debug  

  
Not needed

Modified drvAsynDG645.cpp  

  
Move epicsExport.h for win32 compatibility. Remove unistd.h which is not needed and is not win32 compatible. Add extern C for epicsExportRegistrar.
