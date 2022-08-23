/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO.h
 *       Module:  GPIO
 *
 *  Description:  GPIO    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define GPIO_PORTF_DATA_RD      (*(vuint32_t *)0x40025040) 
#define GPIO_PORTF_PUR_R        (*(vuint32_t *)0x40025510)
	
#define GPIOF_DATA_REG         *((vuint32_t*)0x400253FC)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	uint8_t GPIO_PinNumber;             // Specifies the GPIO pins to be configured
	                                    // This parameters must be a value of @ref GPIO_Pin_Define
	
	uint8_t GPIO_MODE ;                 // Specifies the operating mode for the selected pins.
	                                    // This parameter must be set based on @ref GPIO_Mode_define
	
	uint8_t GPIO_PullUp;                // Specifies enable or disable pullup
	                                    // This parameter must be set based on @ref GPIO_PullUp_define

	uint8_t GPIO_OUTPUT_SPEED;          // Specifies the speed for the selected pins.
	                                    // This parameter must be set based on @ref GPIO_SPEED_define
	
}GPIO_PinConfig_t;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx , GPIO_PinConfig_t *PinConfig );
void MCAL_GPIO_Write_Pin(GPIO_Typedef_t *GPIOx , uint8_t PinNumber ,Pin_Status_t Value);
Pin_Status_t MCAL_GPIO_Read_Pin(GPIO_Typedef_t *GPIOx , uint8_t PinNumber);

void MCAL_GPIO_EXTI_Init(GPIO_Typedef_t *GPIOx ,uint8_t PinNumber ,void(* P_IRQ_CALLBACK)(void));

#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
