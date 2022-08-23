/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ================================================================ */
/* ================= Base Addresses of Memories =================== */
/* ================================================================ */

#define FLASH_BASE 			((uint32_t)0x00000000)	/* FLASH base address in the alias region */
#define SRAM_BASE			((uint32_t)0x20000000)	/* SRAM base address in the alias region */
#define PERIPHERALS_BASE	((uint32_t)0x40000000)	/* Peripheral base address in the alias region */

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// NVIC (Non-Vectored Interrupt Controller)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_BASE_ADDRESS	            ((uint32_t)0xE000E100)
#define NVIC_PRI_BASE_ADDRESS			((uint32_t)0xE000E400)

#define NVIC_EN0			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x00)
#define NVIC_EN1			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x04)
#define NVIC_EN2			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x08)
#define NVIC_EN3			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x0C)
#define NVIC_EN4			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x10)

#define NVIC_DIS0			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x80)
#define NVIC_DIS1			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x84)
#define NVIC_DIS2			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x88)
#define NVIC_DIS3			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x8C)
#define NVIC_DIS4			*(vuint32_t *)(NVIC_BASE_ADDRESS + 0x90)

#define NVIC_PRI0			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x00)
#define NVIC_PRI1			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x04)
#define NVIC_PRI2			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x08)
#define NVIC_PRI3			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x0C)
#define NVIC_PRI4			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x10)
#define NVIC_PRI5			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x14)
#define NVIC_PRI6			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x18)
#define NVIC_PRI7			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x1C)
#define NVIC_PRI8			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x20)
#define NVIC_PRI9			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x24)
#define NVIC_PRI10			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x28)
#define NVIC_PRI11			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x2C)
#define NVIC_PRI12			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x30)
#define NVIC_PRI13			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x34)
#define NVIC_PRI14			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x38)
#define NVIC_PRI15			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x3C)
#define NVIC_PRI16			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x40)
#define NVIC_PRI17			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x44)
#define NVIC_PRI18			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x48)
#define NVIC_PRI19			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x4C)
#define NVIC_PRI20			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x50)
#define NVIC_PRI21			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x54)
#define NVIC_PRI22			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x58)
#define NVIC_PRI23			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x5C)
#define NVIC_PRI24			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x60)
#define NVIC_PRI25			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x64)
#define NVIC_PRI26			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x68)
#define NVIC_PRI27			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x6C)
#define NVIC_PRI28			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x70)
#define NVIC_PRI29			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x74)
#define NVIC_PRI30			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x78)
#define NVIC_PRI31			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x7C)
#define NVIC_PRI32			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x80)
#define NVIC_PRI33			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x84)
#define NVIC_PRI34			*(vuint32_t *)(NVIC_PRI_BASE_ADDRESS + 0x88)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// SCB (System Control Block)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define SCB_BASE_ADDRESS		        ((uint32_t)0xE000ED00)

#define SCB_ACTLR			*(vuint32_t *)(0xE000E008)
#define SCB_INTCTRL			*(vuint32_t*)(SCB_BASE_ADDRESS + 0x04)
#define SCB_APINT			*(vuint32_t *)(SCB_BASE_ADDRESS + 0x0C)

/*
typedef union 
{
    vuint32_t Reg;
    struct 
    {
        vuint32_t VECACT    :8;
        vuint32_t           :3;
        vuint32_t RETBASE   :1;
        vuint32_t VECPEND   :8;
        vuint32_t           :2;
        vuint32_t ISRPEND   :1;
        vuint32_t ISRPRE    :1;
        vuint32_t           :1;
        vuint32_t PENDSTCLR :1;
        vuint32_t PENDSTSET :1;
        vuint32_t UNPENDSV  :1;
        vuint32_t PENDSV    :1;
        vuint32_t           :2;
        vuint32_t NMISET    :1; 
    }INTCTRL_BIT;
}INTCTRL;
*/
/*
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// SYSCTRL (System Control)
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define SYSCTRL_BASE_ADDRESS		        ((uint32_t)0x400FE000)

#define SYSCTRL_RCC			    *(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x060)
#define SYSCTRL_RCC2			*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x070)

#define SYSCTRL_RCGC0			*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x100)
#define SYSCTRL_RCGC1			*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x104)
#define SYSCTRL_RCGC2			*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x108)

#define SYSCTRL_RCGCGPIO		*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x608)
#define SYSCTRL_RCGCTIMER		*(vuint32_t *)(SYSCTRL_BASE_ADDRESS + 0x604)


/* ================================================================ */
/* ================== Peripheral Base Addresses =================== */
/* ================================================================ */

//GPIOx Base Address
#define GPIOA_APB_BASE_ADDRESS              ((uint32_t)0x40004000)
#define GPIOB_APB_BASE_ADDRESS              ((uint32_t)0x40005000)
#define GPIOC_APB_BASE_ADDRESS              ((uint32_t)0x40006000)
#define GPIOD_APB_BASE_ADDRESS              ((uint32_t)0x40007000)
#define GPIOE_APB_BASE_ADDRESS              ((uint32_t)0x40024000)
#define GPIOF_APB_BASE_ADDRESS			    ((uint32_t)0x40025000)


//TIMERx Base Address
#define TIMER0_BASE_ADDRESS                 ((uint32_t)0x40030000)
#define TIMER1_BASE_ADDRESS            		((uint32_t)0x40031000)
#define TIMER2_BASE_ADDRESS            	    ((uint32_t)0x40032000)
#define TIMER3_BASE_ADDRESS           		((uint32_t)0x40033000)
#define TIMER4_BASE_ADDRESS            		((uint32_t)0x40034000)
#define TIMER5_BASE_ADDRESS  		 		((uint32_t)0x40035000)

//WTIMERx Base Address
#define WTIMER0_BASE_ADDRESS                ((uint32_t)0x40036000)
#define WTIMER1_BASE_ADDRESS                ((uint32_t)0x40037000)
#define WTIMER2_BASE_ADDRESS                ((uint32_t)0x4004C000)
#define WTIMER3_BASE_ADDRESS                ((uint32_t)0x4004D000)
#define WTIMER4_BASE_ADDRESS                ((uint32_t)0x4004E000)
#define WTIMER5_BASE_ADDRESS                ((uint32_t)0x4004F000)

/* ================================================================ */
/* ===== Peripheral Register Type Definitions (Structures)========= */
/* ================================================================ */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: NVIC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
    vuint32_t EN[5];
    uint32_t RESERVED_0[27];
    vuint32_t DIS[5];
    uint32_t RESERVED_1[27];
    vuint32_t PEND[5];
    uint32_t RESERVED_2[27];
    vuint32_t UNPEND[5];
    uint32_t RESERVED_3[27];
    vuint32_t ACTIV[5];
    uint32_t RESERVED_4[59];
    vuint32_t PRI[35];
    uint32_t RESERVED_5[669];
    vuint32_t SWTRIG;
} NVIC_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: SCB
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
    vuint32_t CPUID;
    vuint32_t INTCTRL;
    vuint32_t VTABLE;
    vuint32_t APINT;
    vuint32_t SYSCTRL;
    vuint32_t CFGCTRL;
    vuint32_t SYSPRI1;
    vuint32_t SYSPRI2;
    vuint32_t SYSPRI3;
    vuint32_t SYSHNDCTRL;
    vuint32_t FAULTSTAT;
    vuint32_t HFAULTSTAT;
    vuint32_t reserved2;
    vuint32_t MMADDR;
    vuint32_t FAULTADDR;
} SCB_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
    vuint32_t GPIODATA[256];
    vuint32_t GPIODIR;
    vuint32_t GPIOIS;
    vuint32_t GPIOIBE;
    vuint32_t GPIOIEV;
    vuint32_t GPIOIM;
    vuint32_t GPIORIS;
    vuint32_t GPIOMIS;
    vuint32_t GPIOICR;
    vuint32_t GPIOAFSEL;
    uint32_t RESERVED_0[55];
    vuint32_t GPIODR2R;
    vuint32_t GPIODR4R;
    vuint32_t GPIODR8R;
    vuint32_t GPIOODR;
    vuint32_t GPIOPUR;
    vuint32_t GPIOPDR;
    vuint32_t GPIOSLR;
    vuint32_t GPIODEN;
    vuint32_t GPIOLOCK;
    vuint32_t GPIOCR;
    vuint32_t GPIOAMSEL;
    vuint32_t GPIOPCTL;
    vuint32_t GPIOADCCTL;
    vuint32_t GPIODMACTL;
    uint32_t RESERVED_2[678];
    vuint32_t GPIOPeriphID4;
    vuint32_t GPIOPeriphID5;
    vuint32_t GPIOPeriphID6;
    vuint32_t GPIOPeriphID7;
    vuint32_t GPIOPeriphID0;
    vuint32_t GPIOPeriphID1;
    vuint32_t GPIOPeriphID2;
    vuint32_t GPIOPeriphID3;
    vuint32_t GPIOPCellID0;
    vuint32_t GPIOPCellID1;
    vuint32_t GPIOPCellID2;
    vuint32_t GPIOPCellID3;
}GPIO_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: System Control
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
/* Not All Registers */
typedef struct
{
    vuint32_t RESERVED_0[383];
    vuint32_t RCGCWD;
    vuint32_t RCGCTIMER;
    vuint32_t RCGCGPIO;
    vuint32_t RCGCDMA;
    vuint32_t RESERVED_1;
    vuint32_t RCGCHIB;
    vuint32_t RCGCUART;
    vuint32_t RCGCSSI;
    vuint32_t RCGCI2C;
    vuint32_t reserved2;
    vuint32_t RCGCUSB;
    vuint32_t RESERVED_2[2];
    vuint32_t RCGCCAN;
    vuint32_t RCGCADC;
    vuint32_t RCGCACMP;
    vuint32_t RCGCPWM;
    vuint32_t RCGCQEI;
    vuint32_t RESERVED_4[4];
    vuint32_t RCGCEEPROM;
    vuint32_t RCGCWTIMER;
    vuint32_t RESERVED_5[232];
    vuint32_t PRWD;
    vuint32_t PRTIMER;
    vuint32_t PRGPIO;
    vuint32_t PRDMA;
    vuint32_t RESERVED_6;
    vuint32_t PRHIB;
    vuint32_t PRUART;
    vuint32_t PRSSI;
    vuint32_t PRI2C;
    vuint32_t RESERVED_7;
    vuint32_t PRUSB;
    vuint32_t RESERVED_8[2];
    vuint32_t PRCAN;
    vuint32_t PRADC;
    vuint32_t PRACMP;
    vuint32_t PRPWM;
    vuint32_t PRQEI;
    vuint32_t RESERVED_9[4];
    vuint32_t PREEPROM;
    vuint32_t PRWTIMER;
} SYSCTRL_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Peripheral register: General Prpose Timers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
    vuint32_t GPTMCFG;
    vuint32_t GPTMTAMR;
    vuint32_t GPTMTBMR;
    vuint32_t GPTMCTL;
    vuint32_t GPTMSYNC;
    vuint32_t reserved1;
    vuint32_t GPTMIMR;
    vuint32_t GPTMRIS;
    vuint32_t GPTMMIS;
    vuint32_t GPTMICR;
    vuint32_t GPTMTAILR;
    vuint32_t GPTMTBILR;
    vuint32_t GPTMTAMATCHR;
    vuint32_t GPTMTAMBTCHR;
    vuint32_t GPTMTAPR;
    vuint32_t GPTMTBPR;
    vuint32_t GPTMTAPMR;
    vuint32_t GPTMTBPMR;
    vuint32_t GPTMTAR;
    vuint32_t GPTMTBR;
    vuint32_t GPTMTAV;
    vuint32_t GPTMTBV;
    vuint32_t GPTMTCPD;
    vuint32_t GPTMTAPS;
    vuint32_t GPTMTBPS;
    vuint32_t GPTMTAPV;
    vuint32_t GPTMTBPV;
    vuint32_t RESERVED_0[918];
    vuint32_t GPTMPP;
} GPT_Typedef_t;


/* ================================================================ */
/* =================== Peripheral Instants  ======================= */
/* ================================================================ */

/*
 * NVIC
 */
#define NVIC ((NVIC_Typedef_t *)(NVIC_BASE_ADDRESS))

/*
 * SCB
 */
#define SCB ((SCB_Typedef_t *)(SCB_BASE_ADDRESS))

/*
 * GPIOx
 */
#define GPIOA                           ((GPIO_Typedef_t *)(GPIOA_APB_BASE_ADDRESS))
#define GPIOB                  		    ((GPIO_Typedef_t *)(GPIOB_APB_BASE_ADDRESS))
#define GPIOC                           ((GPIO_Typedef_t *)(GPIOC_APB_BASE_ADDRESS))
#define GPIOD                           ((GPIO_Typedef_t *)(GPIOD_APB_BASE_ADDRESS))
#define GPIOE                           ((GPIO_Typedef_t *)(GPIOE_APB_BASE_ADDRESS))
#define GPIOF                           ((GPIO_Typedef_t *)(GPIOF_APB_BASE_ADDRESS))

#define GPIO(GPIO_BASE)                 ((GPIO_Typedef_t *)(GPIO_BASE))

/*
 * System Control
 */
#define SYSCTRL                         ((SYSCTRL_Typedef_t *)(SYSCTRL_BASE_ADDRESS))

/*
 * General Purpose Timers
 */

#define TIMER0                          ((GPT_Typedef_t *)(TIMER0_BASE_ADDRESS))
#define TIMER1                          ((GPT_Typedef_t *)(TIMER1_BASE_ADDRESS))
#define TIMER2                          ((GPT_Typedef_t *)(TIMER2_BASE_ADDRESS))
#define TIMER3                          ((GPT_Typedef_t *)(TIMER3_BASE_ADDRESS))
#define TIMER4                          ((GPT_Typedef_t *)(TIMER4_BASE_ADDRESS))
#define TIMER5                          ((GPT_Typedef_t *)(TIMER5_BASE_ADDRESS))

#define Timer(TIMER_BASE)               ((GPT_Typedef_t *)(TIMER_BASE))

#define WTimer0                         ((GPT_Typedef_t *)(WTIMER0_BASE_ADDRESS))
#define WTimer1                         ((GPT_Typedef_t *)(WTIMER1_BASE_ADDRESS))
#define WTimer2                         ((GPT_Typedef_t *)(WTIMER2_BASE_ADDRESS))
#define WTimer3                         ((GPT_Typedef_t *)(WTIMER3_BASE_ADDRESS))
#define WTimer4                         ((GPT_Typedef_t *)(WTIMER4_BASE_ADDRESS))
#define WTimer5                         ((GPT_Typedef_t *)(WTIMER5_BASE_ADDRESS))

#define WTimer(WTIMER_BASE)             ((GPT_Typedef_t *)(WTIMER_BASE))
/* ================================================================ */
/* =========== Clock Enable/Disable/Reset Macros ================== */
/* ================================================================ */

/*
 * Enable clock
 */
#define RCGC_GPIOA_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 0))
#define RCGC_GPIOB_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 1))
#define RCGC_GPIOC_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 2))
#define RCGC_GPIOD_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 3))
#define RCGC_GPIOE_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 4))
#define RCGC_GPIOF_CLOCK_EN()          (SYSCTRL->RCGCGPIO |= (1 << 5))

#define RCGC_TIMER0_CLOCK_EN()         (SYSCTRL->RCGCTIMER |= ( 1<< 0)) 


/*
 * Disable clock
 */
#define RCGC_GPIOA_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 0))
#define RCGC_GPIOB_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 1))
#define RCGC_GPIOC_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 2))
#define RCGC_GPIOD_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 3))
#define RCGC_GPIOE_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 4))
#define RCGC_GPIOF_RESET()             (SYSCTRL->RCGCGPIO &= ~(1 << 5))

#define RCGC_TIMER0_RESET()            (SYSCTRL->RCGCTIMER &= ~( 1<< 0)) 


/* ================================================================ */
/* ================= Interrupt Vector Table ======================= */
/* ================================================================ */

/*
 * GPIOx
 */
#define GPIOA_IRQ              					0
#define GPIOB_IRQ              					1
#define GPIOC_IRQ              					2
#define GPIOD_IRQ              					3
#define GPIOE_IRQ              					4
#define GPIOF_IRQ              					30

/*
 * TIMERxx
 */
#define TIMER0A_IRQ           				 	19
#define TIMER0B_IRQ            					20
#define TIMER1A_IRQ            					21
#define TIMER1B_IRQ            					22
#define TIMER2A_IRQ            					23
#define TIMER2B_IRQ            					24
	
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*--*-*-*-
//NVIC IRQ Enable/Disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-

/*
 * GPIOx
 */
#define NVIC_IRQ0_EN()    					(NVIC->EN[0] |= (1 << GPIOA_IRQ))   /*Enable GPIOA IRQ0 */
#define NVIC_IRQ1_EN()    					(NVIC->EN[0] |= (1 << GPIOB_IRQ))   /*Enable GPIOB IRQ1 */
#define NVIC_IRQ2_EN()    					(NVIC->EN[0] |= (1 << GPIOC_IRQ))   /*Enable GPIOC IRQ2 */
#define NVIC_IRQ3_EN()    					(NVIC->EN[0] |= (1 << GPIOD_IRQ))   /*Enable GPIOD IRQ3 */
#define NVIC_IRQ4_EN()    					(NVIC->EN[0] |= (1 << GPIOE_IRQ))   /*Enable GPIOE IRQ4 */
#define NVIC_IRQ30_EN()    					(NVIC->EN[0] |= (1 << GPIOF_IRQ))   /*Enable GPIOF IRQ30 */

/*
 * TIMERxx
 */
#define NVIC_IRQ19_EN()    					(NVIC->EN[0] |= (1 << TIMER0A_IRQ)) /*Enable TIMER0A IRQ19 */
#define NVIC_IRQ20_EN()    					(NVIC->EN[0] |= (1 << TIMER0B_IRQ)) /*Enable TIMER0B IRQ20 */
#define NVIC_IRQ21_EN()    					(NVIC->EN[0] |= (1 << TIMER1A_IRQ)) /*Enable TIMER1A IRQ21 */
#define NVIC_IRQ22_EN()    					(NVIC->EN[0] |= (1 << TIMER1B_IRQ)) /*Enable TIMER1B IRQ22 */
#define NVIC_IRQ23_EN()    					(NVIC->EN[0] |= (1 << TIMER2A_IRQ)) /*Enable TIMER2A IRQ23 */
#define NVIC_IRQ24_EN()    					(NVIC->EN[0] |= (1 << TIMER2B_IRQ)) /*Enable TIMER2B IRQ24 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
