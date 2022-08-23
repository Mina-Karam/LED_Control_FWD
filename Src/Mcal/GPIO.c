/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void(*gp_IRQ_CALLBACK)(void) = NULL;



void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx , GPIO_PinConfig_t *PinConfig )
{
	
	if(GPIOx == GPIOF)
	{	
        RCGC_GPIOF_CLOCK_EN();
        NVIC_IRQ30_EN();
	}
	    
	// If pin is output
    if(PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT) 
	{
        GPIOx->GPIODIR |= (1<<(PinConfig->GPIO_PinNumber)); //MAKE Pin number AS OUTPUT PIN 

        if(PinConfig->GPIO_OUTPUT_SPEED == GPIO_SPEED_2mA)  //GPIO 2-mA Drive Select (GPIODR2R)
        {
            GPIOx->GPIODR2R |= (1<<PinConfig->GPIO_PinNumber);
        }
        else if(PinConfig->GPIO_OUTPUT_SPEED == GPIO_SPEED_4mA)//GPIO 2-mA Drive Select (GPIODR4R)
        {
                GPIOx->GPIODR4R |= (1<<PinConfig->GPIO_PinNumber);
        }
        else if(PinConfig->GPIO_OUTPUT_SPEED == GPIO_SPEED_8mA)//GPIO 2-mA Drive Select (GPIODR8R)
        {
                GPIOx->GPIODR8R |= (1<<PinConfig->GPIO_PinNumber);
        }
	}
			
	// If pin is input
    else if(PinConfig->GPIO_MODE==GPIO_MODE_INPUT)
    {
        GPIOx->GPIODIR &=~(1<<(PinConfig->GPIO_PinNumber)); //MAKE Pin number AS input PIN 
        
        if(PinConfig->GPIO_PullUp==GPIO_PullUp_Enable)
        {
            GPIOx->GPIOPUR = 0x11; // enable pullup resistors on PF4,PF0    
        }					
	}
				
	GPIOx->GPIODEN |=(1<<(PinConfig->GPIO_PinNumber)); //The digital functions for the corresponding pin are enabled
	
}


/**================================================================= */
void MCAL_GPIO_Write_Pin(GPIO_Typedef_t *GPIOx, uint8_t Pin_Number,Pin_Status_t Value)
{
	if(Value == Pin_Low)
	{
        GPIOF_DATA_REG &=~(1<<Pin_Number);
	}
	else if(Value == Pin_High)
	{
		GPIOF_DATA_REG |=(1<<Pin_Number);
	}
}


Pin_Status_t MCAL_GPIO_Read_Pin(GPIO_Typedef_t *GPIOx , uint8_t PinNumber)
{
	if(((GPIOF_DATA_REG & (1<<PinNumber))>>PinNumber)== Pin_Low)
	{
				 return Pin_Low;
	}
	else if( (GPIOF_DATA_REG & (1<<PinNumber)>>PinNumber) == Pin_High )
	{
		  return Pin_High;
	}
}


//exti

void MCAL_GPIO_EXTI_Init(GPIO_Typedef_t *GPIOx ,uint8_t PinNumber ,void(*P_IRQ_CALLBACK)(void))
{

    GPIO_PinConfig_t Pin_cfg;
	Pin_cfg.GPIO_MODE = GPIO_MODE_INPUT;
	Pin_cfg.GPIO_PullUp=GPIO_PullUp_Enable;
	Pin_cfg.GPIO_PinNumber = PinNumber;
	
	MCAL_GPIO_Init(GPIOF,&Pin_cfg);
	
	if(GPIOx == GPIOF)
	{	
        NVIC_IRQ30_EN();
	}
	    
			
	gp_IRQ_CALLBACK = P_IRQ_CALLBACK;
	

	GPIOx->GPIOIM |= (1<<PinNumber); 

	GPIOx->GPIOIS |= (1<<PinNumber);//The level on the corresponding pin is detected (level-sensitive).
	

	GPIOx->GPIOIEV |= (1<<PinNumber); //A rising edge or a High level on the corresponding pin triggers an interrupt
}



//isr
void GPIOF_Handler(void)
{
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
