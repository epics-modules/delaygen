### Coherent SDG support

# Initialize input/output EOS
asynOctetSetOutputEos("serial1",0,"\r")
asynOctetSetInputEos("serial1",0,"\r")

## Coherent SDG controls
#   drvAsynCoherentSDG(myport,ioport,ioaddr)
#       myport  - Interface asyn port name (i.e. "SDG0")
#       ioport  - Comm asyn port name (i.e. "S2")
#       ioaddr  - Comm asyn port addr
#
drvAsynCoherentSDG("SDG","serial1",-1);
dbLoadRecords("$(TOP)/delaygenApp/Db/drvAsynCoherentSDG.db","P=delaygen:,R=sdg:,PORT=SDG")
