---
layout: default
title: Colby PDL100A
parent: Supported Devices
nav_order: 3
---

# Colby Instruments PDL100A
{: .no_toc}

## Table of contents
{: .no_toc .text-delta}

- TOC
{:toc}

## Description

The Colby Instruments PDL100A is a programmable delay line. The
delaygen module provides an asyn port driver (`drvAsynColby`) that
communicates with the instrument over serial or Ethernet.

## Communication

### Serial

Requires a null-modem cable.

| Setting | Value |
| - | - |
| Baud rate | 9600 |
| Data bits | 8 |
| Parity | None |
| Stop bits | 2 |
| Input EOS | `:` |
| Output EOS | `\r\n` |

```
drvAsynSerialPortConfigure("serial1", "/dev/ttyS0", 0, 0, 0)
asynSetOption(serial1, 0, "baud", "9600")
asynSetOption(serial1, 0, "bits", "8")
asynSetOption(serial1, 0, "parity", "none")
asynSetOption(serial1, 0, "stop", "2")
asynOctetSetInputEos("serial1", -1, ":")
asynOctetSetOutputEos("serial1", -1, "\r\n")
```

### Ethernet

```
drvAsynIPPortConfigure("serial1", "x.x.x.x:7000", 0, 0, 0)
asynOctetSetInputEos("serial1", -1, ":")
asynOctetSetOutputEos("serial1", -1, "\r\n")
```

## Driver Initialization

```
drvAsynColby(myport, ioport, addr, units, iface)
```

| Parameter | Type | Description |
| - | - | - |
| myport | string | Name for the driver's asyn port (e.g., "COL"). |
| ioport | string | Name of the communication asyn port (e.g., "serial1"). |
| addr | int | Address on the communication port. Use -1 for serial/Ethernet. |
| units | string | Default delay units: `"ps"` (picoseconds) or `"ns"` (nanoseconds). |
| iface | int | Communication interface: 0 for Ethernet, 1 for serial. |

Example:

```
drvAsynColby("COL", "serial1", -1, "ns", 1)
```

## Database

Load `colbyPDL100A.db` with the following macros:

| Macro | Description |
| - | - |
| P | PV name prefix |
| R | PV name infix |
| PORT | Driver port name, must match the `myport` argument |
| PREC | Display precision for delay values |
| A | Asyn record name used by sseq records for connect/disconnect |

```
dbLoadRecords("$(DELAYGEN)/db/colbyPDL100A.db", "P=delaygen:,R=Colby:,PREC=3,A=Colby,PORT=COL")
```

## Features

The Colby database provides:

- **Delay** -- Set and read the delay value, with
  increment/decrement tweak support.
- **Units** -- Select nanoseconds or picoseconds.
- **Network configuration** -- Read IP address, gateway, netmask,
  TCP port, DHCP status, and MAC address (Ethernet mode).
- **Connection control** -- Connect and disconnect sequences.
