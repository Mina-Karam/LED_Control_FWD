/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  GPT  
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPT_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	uint8_t GPT_MODE;             // Specifies the GPT MODE (ons-shot or periodic) to be configured.
	                                // This parameter must be set based on @ref GPT_MODE_define
	
	uint8_t GPT_USE;              // Specifies the GPT USE (individual or concatenated) to be configured.
	                                // This parameter must be set based on @ref GPT_USE_define
	
	uint8_t GPT_COUNT_DIR;        // Specifies the GPT COUNT DIRECTION (up or down) to be configured.
	                                // This parameter must be set based on @ref TIMER_COUNT_DIR_define
	
	uint8_t GPT_PRESCALER;        // Specifies the GPT PRESCALLER (value of prescaller ) to be configured.
	                                // This parameter must be set based on @ref TIMER_PRESCALER_define
	
	uint32_t GPT_COUNTS_IN_mS;    // You should pass this value in the application layer same in (up count or down)
	
	void(*P_IRQ_CALLBACK)(void);    // Set The C Function() , this function will be send from app layer by user
	
}GPT_Config_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
void MCAL_TIMER_Init(GPT_Typedef_t *TIMERx, GPT_Config_t *TimerConfig);
void MCAL_TIMER_START(GPT_Typedef_t *TIMERx);

#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
