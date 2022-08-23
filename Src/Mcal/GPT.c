/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        file  GPT.c
 *        brief  
 *
 *      details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPT.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

void(*GP_Timer_CallBack)(void) = NULL;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void Enable_Clock_Timer(GPT_Typedef_t *TIMERx);
void Enable_NVIC_Timer_IRQ(GPT_Typedef_t *TIMERx);
void TIMER0A_Handler(void);


void Enable_Clock_Timer(GPT_Typedef_t *TIMERx)
{
	if(TIMERx == TIMER0) // Enable clock for Timer0
    {
        RCGC_TIMER0_CLOCK_EN();
    }
}


void Enable_NVIC_Timer_IRQ(GPT_Typedef_t *TIMERx)
{
	if(TIMERx == TIMER0) // Enable NVIC IRQ for Timer0
    {
        NVIC_IRQ19_EN(); 
    }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*2^16 = 65536
16MHz = 16000000 
Maximum delay  = 65536/16000000 = 4.096 millisecond*/


void MCAL_TIMER_Init(GPT_Typedef_t *TIMERx ,GPT_Config_t *TimerConfig)
{
	GP_Timer_CallBack = TimerConfig->P_IRQ_CALLBACK; //assign the callback which the user will pass it from the app layer
	
	Enable_Clock_Timer(TIMERx);
	Enable_NVIC_Timer_IRQ(TIMERx);
	 
    if(TimerConfig->GPT_USE == TIMER_USE_INDIVIDUAL)
    {
        //For a 16/32-bit timer, this value selects the 16-bit timerconfiguration
        TIMERx->GPTMCFG = 0x4;

        //For the 16/32-bit GPTM, this field contains the entire 8-bit prescaler
        //set prescaller
        TIMERx->GPTMTAPR = TimerConfig->GPT_PRESCALER; 
    }
    if(TimerConfig->GPT_MODE == TIMER_MODE_PERIODIC && TimerConfig->GPT_COUNT_DIR == TIMER_COUNT_DIR_DOWN)
    {
        //0x2 Periodic Timer mode and doun
        TIMERx->GPTMTAMR = 0x02;
    }
    TIMERx->GPTMTAILR =  ((TimerConfig->GPT_COUNTS_IN_mS)*64) - 1 ;  /* TimerA counter starting count down value  */
    TIMERx->GPTMIMR = (1<<0);  /*Enables TimerA time-out  interrupt mask */
}

void MCAL_TIMER_START(GPT_Typedef_t *TIMERx)
{
	
	if(TIMERx==TIMER0)
	{
		/*Timer A is enabled and begins counting or the capture logic is enabled based on the GPTMCFG register.*/
		TIMERx->GPTMCTL = 0x01; /* Enable TimerA module */
	}

}

//ISR
void TIMER0A_Handler(void)
{
		GP_Timer_CallBack();

	TIMER0->GPTMICR =0x1; /* Timer1A timeout flag bit clears*/
}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
