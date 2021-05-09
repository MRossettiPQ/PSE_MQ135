#ifndef _HAL_TIMER_HEADER_SENTRY_
#define _HAL_TIMER_HEADER_SENTRY_

#include "main.h"
void hal_timer_init(void);

void atualizaOLED(void);
void MX_TIM2_Init(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif

