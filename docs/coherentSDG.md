---
layout: default
title: Coherent SDG
parent: Supported Devices
nav_order: 4
---

# Coherent Synchronization Delay Generator
{: .no_toc}

## Table of contents
{: .no_toc .text-delta}

- TOC
{:toc}

## Description

The Coherent SDG is a 3-channel synchronization delay generator. The
delaygen module provides an asyn port driver
(`drvAsynCoherentSDG`) that communicates with the instrument over a
serial connection.

## Communication

| Setting | Value |
| - | - |
| Input EOS | `\r` |
| Output EOS | `\r` |

```
drvAsynSerialPortConfigure("serial1", "/dev/ttyS0", 0, 0, 0)
asynOctetSetOutputEos("serial1", 0, "\r")
asynOctetSetInputEos("serial1", 0, "\r")
```

## Driver Initialization

```
drvAsynCoherentSDG(myport, ioport, ioaddr)
```

| Parameter | Type | Description |
| - | - | - |
| myport | string | Name for the driver's asyn port (e.g., "SDG"). |
| ioport | string | Name of the communication asyn port (e.g., "serial1"). |
| ioaddr | int | Address on the communication port. Use -1 for serial. |

Example:

```
drvAsynCoherentSDG("SDG", "serial1", -1)
```

## Database

Load `drvAsynCoherentSDG.db` with the following macros:

| Macro | Description |
| - | - |
| P | PV name prefix |
| R | PV name infix |
| PORT | Driver port name, must match the `myport` argument |

```
dbLoadRecords("$(DELAYGEN)/db/drvAsynCoherentSDG.db", "P=delaygen:,R=sdg:,PORT=SDG")
```

## Features

The Coherent SDG database provides:

- **Trigger** -- Rate selection (1, 2, 5, or 10 Hz), mode
  (continuous or single-shot), and manual trigger.
- **Output channels Ch1-Ch3** -- Each channel has an enable/disable
  switch, delay value, and delay step with increment/decrement tweak
  controls.
- **Status** -- BWD switch, photodiode (PD1/PD2), Vdc interlock
  readback, RF sync, and reset.
