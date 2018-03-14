### Stanford Research Systems (SRS) DG645
# You can use the serial port or the network port, as in the main st.cmd.

# Initialize input/output EOS
asynOctetSetInputEos("serial1",0,"\r\n")
asynOctetSetOutputEos("serial1",0,"\n")

# the device actually uses hardware handshaking
asynSetOption(serial1, 0, "crtscts",   "Y")

## drvAsynDG645(myport,ioport,ioaddr)
#       myport  - Interface asyn port name (i.e. "DG0")
#       ioport  - Comm asyn port name (i.e. "L2")
#       ioaddr  - Comm asyn port addr
#
drvAsynDG645("DG1","serial1",-1);

# Load database
dbLoadRecords("$(TOP)/delaygenApp/Db/drvDG645.db","P=delaygen:,R=DG1:,PORT=DG1")

