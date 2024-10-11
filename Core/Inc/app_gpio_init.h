#ifndef _APP_GPIO_INIT_H
#define _APP_GPIO_INIT_H

#include "main.h"

void USR_GPIO_Init(void);

void USR_GPIO_7Seg_Init(GPIO_TypeDef *GPIOx, uint16_t SEG_A, uint16_t SEG_B, uint16_t SEG_C, uint16_t SEG_D, uint16_t SEG_E, uint16_t SEG_F, uint16_t SEG_G, uint16_t SEG_PT);

void USR_GPIO_Pushes_init(GPIO_TypeDef *GPIOx, uint16_t pin_push_up, uint16_t pin_push_down);

void USR_GPIO_4x4Matrix_init(GPIO_TypeDef *GPIOx, uint16_t col1, uint16_t col2, uint16_t col3, uint16_t col4, uint16_t row1, uint16_t row2, uint16_t row3 , uint16_t row4);

#endif


