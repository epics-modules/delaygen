---
layout: default
title: Supported Devices
nav_order: 3
has_children: true
---

# Supported Devices
{: .no_toc}

The delaygen module provides EPICS support for the following delay
generator and programmable delay line instruments:

| Device | Description | Communication | Driver Type |
| - | - | - | - |
| [SRS DG645](dg645) | 8-channel digital delay generator with sub-picosecond resolution | Serial, Ethernet | asyn port driver |
| [SRS DG535](dg535) | 4-channel digital delay generator | GPIB | devGpib device support |
| [Colby PDL100A](colby) | Programmable delay line | Serial, Ethernet | asyn port driver |
| [Coherent SDG](coherentSDG) | 3-channel synchronization delay generator | Serial | asyn port driver |
| [BNC 505](bnc505) | Multi-channel pulse/delay generator | Serial | StreamDevice |

The three asyn port driver devices (DG645, Colby, Coherent SDG) each
register an iocsh command to create a driver instance. The DG535 uses
the devGpib framework and requires no driver initialization command.
The BNC 505 uses StreamDevice with a protocol file and requires no
driver initialization beyond the asyn port.
