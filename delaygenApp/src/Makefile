TOP=../..

include $(TOP)/configure/CONFIG
#-----------------------------------------------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================================================================

#=============================================================================
# Build an IOC support library
LIBRARY_IOC += delaygen

DBD += devDG535.dbd
DBD += drvAsynDG645.dbd
DBD += drvAsynColby.dbd
DBD += nigpibSupport.dbd
DBD += drvAsynCoherentSDG.dbd 
DBD += delaygenSupport.dbd

LIB_SRCS += nigpibInterpose.c
LIB_SRCS += drvAsynDG645.cpp
LIB_SRCS += drvAsynColby.cpp
LIB_SRCS += devDG535.c
LIB_SRCS += drvAsynCoherentSDG.cpp

LIB_LIBS += calc asyn
LIB_LIBS += $(EPICS_BASE_IOC_LIBS)

LIB_LIBS_vxWorks += calc asyn TyGSOctal Ipac ip
LIB_LIBS_vxWorks += $(EPICS_BASE_IOC_LIBS)

#=============================================================================
# Build an IOC application
PROD_IOC = delaygenApp

#-----------------------------------------------------------------------------
# <name>.dbd will be created and installed
DBD += delaygenApp.dbd
DBD += delaygenAppVxWorks.dbd

#delaygenApp_DBD += base.dbd
#delaygenApp_DBD += delaygenSupport.db
#delaygenApp_DBD += asyn.dbd
#delaygenApp_DBD += drvAsynSerialPort.dbd

#-----------------------------------------------------------------------------
# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
# mw100_registerRecordDeviceDriver.cpp derives from mw100ex.dbd
PROD_SRCS += delaygenApp_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
PROD_SRCS_DEFAULT += delaygenMain.cpp
PROD_SRCS_vxWorks += -nil-

#-----------------------------------------------------------------------------
# Include libraries
PROD_LIBS += delaygen
PROD_LIBS += calc
PROD_LIBS += asyn
ifdef STREAM
	PROD_LIBS += stream
endif
PROD_LIBS += $(EPICS_BASE_IOC_LIBS)
PROD_SYS_LIBS_solaris += socket

#
#=============================================================================

include $(TOP)/configure/RULES
#-----------------------------------------------------------------------------
#  ADD RULES AFTER THIS LINE
