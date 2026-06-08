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

CFG += DELAYGEN_DEPS

#=============================================================================

include $(TOP)/configure/RULES
#-----------------------------------------------------------------------------
#  ADD RULES AFTER THIS LINE
