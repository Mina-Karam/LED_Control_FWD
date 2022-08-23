/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Types.h
 *       Module:  GPIO
 *
 *  Description:  GPIO    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//@ref GPIO_PINS_define
#define GPIO_PIN_0              0 
#define GPIO_PIN_1              1 
#define GPIO_PIN_2              2 
#define GPIO_PIN_3              3
#define GPIO_PIN_4              4 
#define GPIO_PIN_5              5
#define GPIO_PIN_6              6 
#define GPIO_PIN_7              7

//@ref GPIO_MODE_define
#define GPIO_MODE_INPUT         0        
#define GPIO_MODE_OUTPUT        1    

//@ref GPIO_PullUp_define
#define GPIO_PullUp_Disable     0        
#define GPIO_PullUp_Enable      1    

//@ref GPIO_SPEED_define
#define GPIO_SPEED_2mA          0
#define GPIO_SPEED_4mA          1
#define GPIO_SPEED_8mA          2

//Pin value
typedef enum
{
    Pin_Low,
    Pin_High
} Pin_Status_t;

//Port value
typedef enum
{
    Port_Low,
    Port_High
} Port_Status_t;

#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/
