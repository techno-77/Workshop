/*----------------------------------------------------------------------------
 * File:  MicrowaveOven.c
 *
 * UML Component Port Messages
 * Component/Module Name:  MicrowaveOven
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/
/*
 

Domain Mission: Microwave Application Domain

To capture the retained data and event sequencing associated with the use of a domestic microwave oven comprising :

* a magnetron tube (with variable power output settings)
* a turntable
* an internal light
* a beeper to signal when cooking is complete
* an oven door

Bridges to other Domains:

* To Control Panel (Application User Interface Domain)
* To PIO domain (not shown)
* To Timer domain
 */

#include "MicrowaveOven_sys_types.h"
#include "MicrowaveOven.h"
#include "TIM_bridge.h"
#include "ARCH_bridge.h"

