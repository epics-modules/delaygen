### Colby Instruments PDL100A - Programmable Delay Line


# Initialize SERIAL input/output EOS
asynOctetSetInputEos("serial1",-1,":")
asynOctetSetOutputEos("serial1",-1,"\r\n")

## drvAsynColby(myport,ioport,addr,units,iface)
#       myport - Interface asyn port driver name (i.e. "COL")
#       ioport - Comm asyn port name (i.e. "D0")
#       addr   - Comm asyn port addr
#       units  - Default units string ("ps" or "ns")
#       iface  - Communication interface (0=Ethernet,1=Serial)
#
drvAsynColby("COL","serial1",-1,"ns",1)

# Load databases
dbLoadRecords("$(TOP)/delaygenApp/Db/colbyPDL100A.db","P=delaygen:,R=Colby:,PREC=3,A=Colby,PORT=COL")
