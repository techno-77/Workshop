/*----------------------------------------------------------------------------
 * Description:   Methods for bridging to an external entity.
 *
 * External Entity:  Architecture (ARCH)
 * The Architecture external entity is used to model a shutdown bridge operation. This operation is called when the system has finished the test scenario.  

When the microwave oven models are translated into code by the model compiler, the call to this bridge operation is mapped to an architecture method used to shut down the system.
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "MicrowaveOven_sys_types.h"
#include "MicrowaveOven_ARCH_bridge.h"
#include "TIM_bridge.h"
#include "MicrowaveOven_classes.h"
extern bool Escher_run_flag; /* Turn this false to stop the event queues.  */

/*
 * Bridge:  shutdown
 */
void
MicrowaveOven_ARCH_shutdown()
{
  Escher_run_flag = false; /* default automatic action for this bridge */
  return;
  /* Replace/Insert your implementation code here... */
}

