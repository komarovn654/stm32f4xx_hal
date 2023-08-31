#include "stdint.h"
#include "stdio.h"
#include "hal_system_mstick.h"

void SysTickHandler(void) 
{
    system_mstick_inc();
}