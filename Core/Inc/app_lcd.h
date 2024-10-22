#ifndef _APP_LCD_H
#define _APP_LCD_H

#include "main.h"


typedef struct{
	uint16_t RS;
	uint16_t RW;
	uint16_t EN;
	uint16_t D0;
	uint16_t D1;
	uint16_t D2;
	uint16_t D3;
	uint16_t D4;
	uint16_t D5;
	uint16_t D6;
	uint16_t D7;
	GPIO_TypeDef *GPIOx;
} LCD_8BitMode_TypeDef;

void LCD_Out_DataToPort(unsigned char data, LCD_8BitMode_TypeDef *Lcd_T); //, GPIO_TypeDef *GPIOx
void LCD_Initialize_Port(LCD_8BitMode_TypeDef *LcdType);	//, GPIO_TypeDef *GPIOx
void LCD_Data(unsigned char data, LCD_8BitMode_TypeDef *LcdType); //, GPIO_TypeDef *GPIOx
void LCD_Cmd(unsigned char cmd, LCD_8BitMode_TypeDef *LcdType);  //, GPIO_TypeDef *GPIOx
void LCD_Initialize(LCD_8BitMode_TypeDef *LcdType);	//, GPIO_TypeDef *GPIOx
void LCD_String(char str[], char num, LCD_8BitMode_TypeDef *Lcd_T);	//, GPIO_TypeDef *GPIOx

void out_pins(char val, GPIO_TypeDef *GPIOx,
							uint16_t D0,
							uint16_t D1,
							uint16_t D2,
							uint16_t D3,
							uint16_t D4,
							uint16_t D5,
							uint16_t D6,
							uint16_t D7);


void lcd_initialize_pins(GPIO_TypeDef *GPIOx, uint16_t RS, uint16_t RW, uint16_t EN,
							uint16_t D0,
							uint16_t D1,
							uint16_t D2,
							uint16_t D3,
							uint16_t D4,
							uint16_t D5,
							uint16_t D6,
							uint16_t D7);


void lcd_data(GPIO_TypeDef *GPIOx, char data, uint16_t RS, uint16_t RW, uint16_t EN,						
							uint16_t D0,
							uint16_t D1,
							uint16_t D2,
							uint16_t D3,
							uint16_t D4,
							uint16_t D5,
							uint16_t D6,
							uint16_t D7);


void lcd_cmd(GPIO_TypeDef *GPIOx, char cmd, uint16_t RS, uint16_t RW, uint16_t EN,
							uint16_t D0,
							uint16_t D1,
							uint16_t D2,
							uint16_t D3,
							uint16_t D4,
							uint16_t D5,
							uint16_t D6,
							uint16_t D7);



void lcd_initialize(GPIO_TypeDef *GPIOx, uint16_t RS, uint16_t RW, uint16_t EN,
							uint16_t D0,
							uint16_t D1,
							uint16_t D2,
							uint16_t D3,
							uint16_t D4,
							uint16_t D5,
							uint16_t D6,
							uint16_t D7);



#endif