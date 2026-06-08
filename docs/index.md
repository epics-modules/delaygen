---
layout: default
title: Home
nav_order: 1
---

# delaygen
{: .no_toc}

## Table of contents
{: .no_toc .text-delta}

- TOC
{:toc}

## Overview

The delaygen module provides EPICS support for five delay generator and
programmable delay line instruments. It builds a single IOC support
library (`delaygen`) containing asyn port drivers, devGpib device
support, and an asyn interpose interface.

The module supports three different communication approaches depending
on the device: custom asyn port drivers for the DG645, Colby PDL100A,
and Coherent SDG; devGpib device support for the DG535; and
StreamDevice for the BNC 505.

## Supported Devices

| Device | Communication | Driver Type |
| - | - | - |
| [SRS DG645](dg645) | Serial, Ethernet | asyn port driver |
| [SRS DG535](dg535) | GPIB | devGpib device support |
| [Colby PDL100A](colby) | Serial, Ethernet | asyn port driver |
| [Coherent SDG](coherentSDG) | Serial | asyn port driver |
| [BNC 505](bnc505) | Serial | StreamDevice |

## Dependencies

The delaygen module requires the following EPICS modules:

- [asyn](https://github.com/epics-modules/asyn) -- communication
  layer used by all drivers
- [calc](https://github.com/epics-modules/calc) -- provides sseq and
  sCalcout record support used by the Colby PDL100A database
- [stream](https://github.com/paulscherrerinstitute/StreamDevice) --
  StreamDevice protocol support used by the BNC 505

Additional dependencies are needed for GPIB on vxWorks:

- [ipac](https://github.com/epics-modules/ipac) -- Industry Pack
  carrier support
- [ip](https://github.com/epics-modules/ip) -- IP communication
  support

## Contact

Keenan Lang, klang@anl.gov  
Argonne National Laboratory  
X-ray Science Division  
Beamline Controls and Data Acquisition
