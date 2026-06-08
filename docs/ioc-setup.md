---
layout: default
title: IOC Setup
nav_order: 3
---

# IOC Setup
{: .no_toc}

## Table of contents
{: .no_toc .text-delta}

- TOC
{:toc}

## Building the Module

Add the required dependencies to `configure/RELEASE` or
`configure/RELEASE.local`:

```makefile
ASYN=/path/to/asyn
CALC=/path/to/calc
STREAM=/path/to/stream

# Only needed for GPIB on vxWorks
IPAC=/path/to/ipac
IP=/path/to/ip

EPICS_BASE=/path/to/base
```

Build the module with `make` from the top-level directory. This
builds the `delaygen` support library, installs the DBD files and
database files, and installs cfg files for downstream IOC dependency
resolution.

## Building the Example IOC

The module includes an example IOC under `iocs/delaygenIOC/`. IOC
builds are disabled by default. To enable them, create
`configure/CONFIG_SITE.local` with:

```makefile
BUILD_IOCS = YES
```

Then rebuild. The IOC inherits all dependency paths from the parent
module's `configure/RELEASE`.

## IOC Startup

The example IOC startup script (`st.cmd`) follows a two-part
structure: a common section that configures the communication port,
and a device-specific command file that initializes the driver and
loads the database.

### Communication Port

Configure either a serial port or an IP port before sourcing the
device-specific command file:

```
# Serial port
drvAsynSerialPortConfigure("serial1", "/dev/ttyS0", 0, 0, 0)
asynSetOption(serial1, 0, "baud", "19200")
asynSetOption(serial1, 0, "bits", "8")
asynSetOption(serial1, 0, "parity", "none")
asynSetOption(serial1, 0, "stop", "1")

# Or IP port (for devices that support Ethernet)
drvAsynIPPortConfigure("serial1", "x.x.x.x:5025", 0, 0, 0)
```

Each device has its own end-of-string (EOS) settings and additional
serial options. These are set in the device-specific command file.
See the individual device pages for details.

### Device Command Files

The startup script sources one of the following command files to
configure a specific device:

| File | Device |
| - | - |
| `dg645.cmd` | SRS DG645 |
| `dg535.cmd` | SRS DG535 (GPIB, does not use the serial port above) |
| `colby.cmd` | Colby PDL100A |
| `coherentSDG.cmd` | Coherent SDG |
| `bnc505.cmd` | BNC 505 |

### Database Macros

All databases use `P` and `R` macros for PV name prefixes. The full
PV name is constructed as `$(P)$(R)<field>`. Additional macros vary
by device and are documented on each device's page.

## Using delaygen in Your IOC

To use delaygen in a standalone IOC application, add `DELAYGEN` to
the IOC's `configure/RELEASE` and include the support DBD and library
in the IOC's `src/Makefile`:

```makefile
# If delaygen has cfg-deps support
$(PROD_NAME)_DBD += $(DELAYGEN_IOC_DBDS)
$(PROD_NAME)_LIBS += $(DELAYGEN_IOC_LIBS)

# Or list explicitly
$(PROD_NAME)_DBD += delaygenSupport.dbd
$(PROD_NAME)_LIBS += delaygen
```

The `delaygenSupport.dbd` file includes all five device drivers. You
also need to include the DBD files and libraries for the transitive
dependencies (asyn, calc, stream) that your IOC uses.
