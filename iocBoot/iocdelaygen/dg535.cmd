### Stanford Research Systems (SRS) DG535
## This device is GPIB only

## The device support requires you use a port name of L followed by number.


###################################

## From a VME crate, one would use:

## SBS IP488 GPIB
## gsIP488Configure(char *portName, int carrier, int module, int vector,
##                  unsigned int priority, int noAutoConnect)
##     portName      - Ascii string specifying the port name that will be
##                     registered with asynDriver.
##     carrier       - Integer identifying the Industry Pack Carrier (numbere#d
##                     from 0)
##     module        - Integer identifying the module on the carrier (numbere#d
##                     from 0)
##     intVec        - Integer specifying the interrupt vector
##     priority      - Integer specifying the priority of the portThread. 
##                     Value of 0 will result in default value being assigned.
##     noAutoConnect - Zero or missing indicates that portThread should 
##                     automatically connect. Non-zero if explicit connect
##                     command must be issued.

#gsIP488Configure("L1",0,1,0x69,0,0)

#################################

## From Linux, one could use:

## Interpose interface for NI GPIB-RS232 converter
##   nigpibInterfaceConfig(ioport,addr,conv,timeout)
##       ioport  - Asyn port name (i.e. "L2")
##       addr    - GPIB device address (valid when conv=1)
##       bsiz    - NI GPIB-RS232 read buffer size (in bytes)
##       timeout - Communication timeout (default 3s)

nigpibInterposeConfig("L1",23,60,0);

###################################

## Load database

## Original database
dbLoadRecords("$(TOP)/delaygenApp/Db/devDG535.db","P=delaygen:,R=DG1:,L=1,A=15")
## Database modified by DAA
#dbLoadRecords("$(TOP)/delaygenApp/Db/devDG535daa.db","P=delaygen:,R=DG1:,L=1,A=15")