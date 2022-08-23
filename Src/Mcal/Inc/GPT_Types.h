/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Types.h
 *       Module:  GPT
 *
 *  Description:  GPT    
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//@ref TIMER_MODE_define
#define TIMER_MODE_ONE_SHOT        0
#define TIMER_MODE_PERIODIC        1

//@ref TIMER_USE_define
#define TIMER_USE_INDIVIDUAL       0
#define TIMER_USE_CONCATENATED     1

//@ref TIMER_COUNT_DIR_define
#define TIMER_COUNT_DIR_UP         0
#define TIMER_COUNT_DIR_DOWN       1

//@ref TIMER_PRESCALER_define
#define TIMER_PRESCALER_250       249
#define TIMER_PRESCALER_251       250
#define TIMER_PRESCALER_252       251
#define TIMER_PRESCALER_253       252
#define TIMER_PRESCALER_254       253
#define TIMER_PRESCALER_255       254
#define TIMER_PRESCALER_256       255

#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/
