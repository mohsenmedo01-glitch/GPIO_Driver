#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "STD_TYPES.h"

#define GPIO_MODER_MASK       0x3U
#define GPIO_PORTS_NUM        6U


#define GPIOA_BASE_ADDRESS         (0x40020000UL)
#define GPIOB_BASE_ADDRESS         (0x40020400UL)
#define GPIOC_BASE_ADDRESS         (0x40020800UL)
#define GPIOD_BASE_ADDRESS         (0x40020C00UL)
#define GPIOE_BASE_ADDRESS         (0x40021000UL)
#define GPIOH_BASE_ADDRESS         (0x40021C00UL)





/* ================= GPIO Registers Structure ================= */

typedef struct
{
    volatile u32 GPIO_MODER;
    volatile u32 GPIO_OTYPER;
    volatile u32 GPIO_OSPEEDR;
    volatile u32 GPIO_PUPDR; 
    volatile u32 GPIO_IDR;   
    volatile u32 GPIO_ODR;   
    volatile u32 GPIO_BSRR;  
    volatile u32 GPIO_LCKR;  
    volatile u32 GPIO_AFRL;  
    volatile u32 GPIO_AFRH;  

} GPIO_tstrRegisters;

/* ================= GPIO Peripheral Pointers ================= */

#define GPIOA    ((volatile GPIO_tstrRegisters *)GPIOA_BASE_ADDRESS)
#define GPIOB    ((volatile GPIO_tstrRegisters *)GPIOB_BASE_ADDRESS)
#define GPIOC    ((volatile GPIO_tstrRegisters *)GPIOC_BASE_ADDRESS)
#define GPIOD    ((volatile GPIO_tstrRegisters *)GPIOD_BASE_ADDRESS)
#define GPIOE    ((volatile GPIO_tstrRegisters *)GPIOE_BASE_ADDRESS)
#define GPIOH    ((volatile GPIO_tstrRegisters *)GPIOH_BASE_ADDRESS)

#endif