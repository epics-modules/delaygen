### Berkely Nucleonics 505 pulse/delay generator


# Initialize SERIAL input/output EOS
asynOctetSetInputEos("serial1",-1,"\r\n")
asynOctetSetOutputEos("serial1",-1,"\r\n")

# set the protocol path for streamDevice
epicsEnvSet("STREAM_PROTOCOL_PATH", "$(TOP)/delaygenApp/Db")

# Load database
dbLoadRecords("$(TOP)/delaygenApp/Db/BNC_505.db","P=delaygen:,R=BNC:,PORT=serial1")
