# Linux startup file

## Define environment variables
< envPaths

cd ${TOP}

## Register all support components
dbLoadDatabase("../../dbd/iocdelaygenApp.dbd")
iocdelaygenApp_registerRecordDeviceDriver(pdbbase)

###################

## For IP Asyn support
## DG645
#drvAsynIPPortConfigure("serial1","x.x.x.x:5024",0,0,0)
## Colby
#drvAsynIPPortConfigure("serial1","x.x.x.x:7000",0,0,0)

###  OR  ####
 
## For Linux COM2 serial
## drvAsynSerialPortConfigure("portName","ttyName",priority,noAutoConnect,
##                             noProcessEos)
drvAsynSerialPortConfigure("serial1", "/dev/ttyS1", 0, 0, 0)

###################

asynSetOption(serial1, 0, "baud",   "19200")
asynSetOption(serial1, 0, "bits",   "8")
asynSetOption(serial1, 0, "parity", "none")
asynSetOption(serial1, 0, "stop",   "1")

## more options, possibly set in breakout command files
#asynSetOption(serial1, 0, "clocal",   "Y")
#asynSetOption(serial1, 0, "crtscts",   "N")
#asynOctetSetInputEos(const char *portName, int addr,
#                     const char *eosin,const char *drvInfo)
# asynOctetSetOutputEos(const char *portName, int addr,
#                       const char *eosin,const char *drvInfo)

#--------------------------

## Asyn record support for serial port
dbLoadRecords("$(ASYN)/db/asynRecord.db","P=delaygen:,R=asyn_1,PORT=serial1,ADDR=0,OMAX=0,IMAX=256")

#-------------------------

## Device specific configuration
## PICK ONE

#< colby.cmd
< dg645.cmd
#< coherentSDG.cmd
#< bnc505.cmd
## this device won't use serial1 as above, uses GPIB interface, see cmd file
#< dg535.cmd

#------------------------------------------------------------------------------
# Start IOC
cd ${TOP}/iocBoot/${IOC}
iocInit()

