#include "app_lcd.h"
#include "app_gpio_init.h"
#include "main.h"


void LCD_Out_DataToPort(unsigned char data, LCD_8BitMode_TypeDef *Lcd_T)
{
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T->D0|Lcd_T->D1|Lcd_T->D2|Lcd_T->D3|Lcd_T->D4|Lcd_T->D5|Lcd_T->D6|Lcd_T->D7, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D0, (uint8_t)(data & 0x01) >> 0);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D1, (uint8_t)(data & 0x02) >> 1);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D2, (uint8_t)(data & 0x04) >> 2);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D3, (uint8_t)(data & 0x08) >> 3);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D4, (uint8_t)(data & 0x10) >> 4);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D5, (uint8_t)(data & 0x20) >> 5);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D6, (uint8_t)(data & 0x40) >> 6);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> D7, (uint8_t)(data & 0x80) >> 7);
	
}



void LCD_Initialize_Port(LCD_8BitMode_TypeDef *Lcd_T) //, GPIO_TypeDef *GPIOx
{
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	Port_Clock_Initialize(Lcd_T->GPIOx);
	
	HAL_GPIO_WritePin(Lcd_T->GPIOx, 
										Lcd_T->RS |
										Lcd_T->RW |
										Lcd_T->EN |
										Lcd_T->D0 |
										Lcd_T->D1 |
										Lcd_T->D2 |
										Lcd_T->D3 |
										Lcd_T->D4 |
										Lcd_T->D5 |
										Lcd_T->D6 |
										Lcd_T->D7, 
										GPIO_PIN_RESET);
	
	/*Configure GPIO pins as outputs :  */
  GPIO_InitStruct.Pin = Lcd_T->RS|Lcd_T->RW|Lcd_T->EN|Lcd_T->D0|Lcd_T->D1|Lcd_T->D2|Lcd_T->D3|Lcd_T->D4|Lcd_T->D5|Lcd_T->D6|Lcd_T->D7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Lcd_T->GPIOx, &GPIO_InitStruct);
	
}



void LCD_Data(unsigned char data, LCD_8BitMode_TypeDef *Lcd_T) //, GPIO_TypeDef *GPIOx
{
	
	LCD_Out_DataToPort(data, Lcd_T);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> RS, GPIO_PIN_SET);				// Write to data register
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> RW, GPIO_PIN_RESET);			// Write mode
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> EN, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> EN, GPIO_PIN_RESET);

}



void LCD_Cmd(unsigned char cmd, LCD_8BitMode_TypeDef *Lcd_T)	//, GPIO_TypeDef *GPIOx
{
	
	LCD_Out_DataToPort(cmd, Lcd_T);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> RS, GPIO_PIN_RESET);			// Write to instruction register
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> RW, GPIO_PIN_RESET);			// Write mode
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> EN, GPIO_PIN_SET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(Lcd_T->GPIOx, Lcd_T -> EN, GPIO_PIN_RESET);

}
							


void LCD_Initialize(LCD_8BitMode_TypeDef *Lcd_T)
{

	LCD_Cmd(0x38, Lcd_T);
	//HAL_Delay(500);
	LCD_Cmd(0x0F, Lcd_T);
	//HAL_Delay(500);
	LCD_Cmd(0x06, Lcd_T);
	LCD_Cmd(0x01, Lcd_T);
	//HAL_Delay(500);	

	//HAL_Delay(500);

}

void LCD_String(char str[], char num, LCD_8BitMode_TypeDef *Lcd_T)
{

//	for (uint8_t i = 0; str[i] != '\0'; i++) {
//		LCD_Data(str[i], Lcd_T, GPIOx);
//  }
	uint8_t i;
	for(i = 0; i < num; i++){
		LCD_Data(str[i], Lcd_T);
	}

}

/*******************************************************************************/
/********************************** FIN ****************************************/
/*******************************************************************************/
