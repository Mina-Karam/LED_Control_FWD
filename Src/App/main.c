#include "IntCtrl.h"
#include "SYSCTRL.h"
#include "GPIO.h"
#include "GPT.h"

/* ================================================== */
/* ================= Global Variables =============== */
/* ================================================== */

vuint8_t gvu8Flag = 0;

uint8_t gu8ON_TIME = 2;
uint8_t gu8OFF_TIME = 4;

vuint8_t gvu8Count1 = 0;
vuint8_t gvu8Count2 = 0;

/* ================================================== */
/* =============== Functions Prototype ============== */
/* ================================================== */

void Determine_ON_And_OFF_Time(uint8_t On_Time, uint8_t Off_Time);
void TIMER_CallBack(void);

int main()
{
	//IntCrtl_Init();


	//init PORTF PIN 1 --> led
	GPIO_PinConfig_t Pin_cfg;
	Pin_cfg.GPIO_MODE = GPIO_MODE_OUTPUT;
	Pin_cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_2mA;
	Pin_cfg.GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOF, &Pin_cfg);

	
	//timer init for timer0
	GPT_Config_t Timer_cfg;
	Timer_cfg.GPT_MODE = TIMER_MODE_PERIODIC;
	Timer_cfg.GPT_USE = TIMER_USE_INDIVIDUAL;
	Timer_cfg.GPT_COUNT_DIR = TIMER_COUNT_DIR_DOWN;
	Timer_cfg.GPT_PRESCALER = TIMER_PRESCALER_250;
	Timer_cfg.GPT_COUNTS_IN_mS = 1000;
	Timer_cfg.P_IRQ_CALLBACK = TIMER_CallBack;
	MCAL_TIMER_Init(TIMER0, &Timer_cfg);
	MCAL_TIMER_START(TIMER0);
	
	
	while(1)
	{

	}
	
}

void TIMER_CallBack(void)
{
		Determine_ON_And_OFF_Time(gu8ON_TIME, gu8OFF_TIME);
}


void Determine_ON_And_OFF_Time(uint8_t On_Time , uint8_t Off_Time)
{
	//1-set number of counts of TIMER0A_Handler by seconds --->On_Time
	if(gvu8Count1 < On_Time && gvu8Flag == 0)
	{
			MCAL_GPIO_Write_Pin(GPIOF,GPIO_PIN_1,Pin_High);
	}
	if(gvu8Count1==On_Time)
	{
		gvu8Flag = 1;
		gvu8Count1 =0;
	}
	
	//2-set number of counts of TIMER0A_Handler by seconds --->Off_Time
	if(gvu8Count2 < Off_Time && gvu8Flag == 1)
	{
		MCAL_GPIO_Write_Pin(GPIOF, GPIO_PIN_1, Pin_Low);
	} 

	if(gvu8Count2 == Off_Time)
	{
		gvu8Flag = 0;
		gvu8Count2 = 0;
	}
	
	/*******************updates the counters*****************/
	if(gvu8Flag == 0)
	{
		gvu8Count1++;
	}
	
	if(gvu8Flag == 1)
	{
		gvu8Count2++;
	}
	
}
