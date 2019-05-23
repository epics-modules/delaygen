TOP=../..

include $(TOP)/configure/CONFIG
#-----------------------------------------------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================================================================

#=============================================================================
# Build an IOC support library
LIBRARY_IOC += delaygen

delaygen_SRCS += nigpibInterpose.c
delaygen_SRCS += drvAsynDG645.cpp
delaygen_SRCS += drvAsynColby.cpp
delaygen_SRCS += devDG535.c
delaygen_SRCS += drvAsynCoherentSDG.cpp

delaygen_LIBS += asyn
delaygen_LIBS += $(EPICS_BASE_IOC_LIBS)

delaygen_LIBS_vxWorks += asyn TyGSOctal Ipac ip
delaygen_LIBS_vxWorks += $(EPICS_BASE_IOC_LIBS)

DBD += devDG535.dbd
DBD += drvAsynDG645.dbd
DBD += drvAsynColby.dbd
DBD += nigpibSupport.dbd
DBD += drvAsynCoherentSDG.dbd 
DBD += delaygenSupport.dbd

#=============================================================================
# Build an IOC application
ifeq ($(OS_CLASS),Linux)
PROD_IOC = delaygenApp
endif

#-----------------------------------------------------------------------------
# <name>.dbd will be created and installed
DBD += delaygenApp.dbd

#-----------------------------------------------------------------------------
# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
# mw100_registerRecordDeviceDriver.cpp derives from mw100ex.dbd
delaygenApp_SRCS += delaygenApp_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
delaygenApp_SRCS_DEFAULT += delaygenMain.cpp

#-----------------------------------------------------------------------------
# Include libraries
delaygenApp_LIBS += delaygen
delaygenApp_LIBS += asyn
delaygenApp_LIBS += calc
delaygenApp_LIBS += stream
delaygenApp_LIBS += $(EPICS_BASE_IOC_LIBS)

#
#=============================================================================

include $(TOP)/configure/RULES
#-----------------------------------------------------------------------------
#  ADD RULES AFTER THIS LINE
