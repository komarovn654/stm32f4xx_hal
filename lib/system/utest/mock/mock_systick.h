#pragma once

#include "core_cm4.h"

#ifdef SysTick
#undef SysTick
#define SysTick malloc(sizeof(SysTick_Type))
#elif
#error "need a systick's header"
#endif