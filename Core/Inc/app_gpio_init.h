#ifndef _APP_GPIO_INIT_H
#define _APP_GPIO_INIT_H

#include "main.h"

void USR_GPIO_Init(void);

void USR_GPIO_7Seg_Init(void);

void USR_GPIO_Pushes_init(GPIO_TypeDef *GPIOx, uint16_t pin_push_up, uint16_t pin_push_down);

#endif


