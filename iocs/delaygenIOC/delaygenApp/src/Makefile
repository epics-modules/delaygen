TOP=../..
include $(TOP)/configure/CONFIG

PROD_NAME = delaygenApp
PROD_IOC = $(PROD_NAME)

DBD += $(PROD_NAME).dbd

$(PROD_NAME)_DBD += base.dbd

# delaygen (cfg-deps)
$(PROD_NAME)_DBD += $(DELAYGEN_IOC_DBDS)

# asyn (no cfg-deps)
$(PROD_NAME)_DBD += asyn.dbd
$(PROD_NAME)_DBD += drvAsynSerialPort.dbd
$(PROD_NAME)_DBD += drvAsynIPPort.dbd

# calc (cfg-deps)
$(PROD_NAME)_DBD += $(CALC_IOC_DBDS)

# stream (no cfg-deps)
$(PROD_NAME)_DBD += stream.dbd

$(PROD_NAME)_SRCS += $(PROD_NAME)_registerRecordDeviceDriver.cpp
$(PROD_NAME)_SRCS_DEFAULT += $(PROD_NAME)Main.cpp
$(PROD_NAME)_SRCS_vxWorks += -nil-

$(PROD_NAME)_LIBS += $(DELAYGEN_IOC_LIBS)
$(PROD_NAME)_LIBS += $(CALC_IOC_LIBS)
$(PROD_NAME)_LIBS += stream
$(PROD_NAME)_LIBS += asyn
ifdef SNCSEQ
$(PROD_NAME)_LIBS += seq pv
endif
$(PROD_NAME)_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
