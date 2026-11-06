                                    /*     author : Mohamed Junior          */
                                /*          Date 20/10/2026            */
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "STD_TYPES.h"
#define RCC_AHB1_GPIOCEN                2U

typedef enum {
    ENABLE,
    DISABLE

}RCC_CLK_MODE;

typedef enum {
    RCC_HSE,
    RCC_HSI,
    RCC_PLL
}RCC_CLK_TYPE;

typedef enum {
    RCC_AHB1,
    RCC_APB1,
    RCC_APB2

}RCC_BUS_TYPES;

typedef enum {
    RCC_HSI_READY,
    RCC_HSE_READY,
    RCC_HSI_NOT_READY,
    RCC_HSE_NOT_READY,
    INVALID_CLOCK
}RCC_CLOCK_STATUS;


typedef enum{
    RCC_RESET_LOW_POWER,
    RCC_RESET_WINDOW_WATCHDOG,
    RCC_RESET_INDEPENDENT_WATCHDOG,
    RCC_RESET_SOFTWARE,
    RCC_RESET_POWER_ON,
    RCC_RESET_PIN,
    RCC_RESET_BROWN_OUT,
    RCC_RESET_UNKNOWN
} RCC_RESET_CAUSE;


/* ==================== APB1 Prescaler ==================== */

#define RCC_u32APB1_DIV_BY_1       0x00000000U
#define RCC_u32APB1_DIV_BY_2       0x00001000U
#define RCC_u32APB1_DIV_BY_4       0x00001400U
#define RCC_u32APB1_DIV_BY_8       0x00001800U
#define RCC_u32APB1_DIV_BY_16      0x00001C00U


/* ==================== APB2 Prescaler ==================== */

#define RCC_u32APB2_DIV_BY_1       0x00000000U
#define RCC_u32APB2_DIV_BY_2       0x00008000U
#define RCC_u32APB2_DIV_BY_4       0x0000A000U
#define RCC_u32APB2_DIV_BY_8       0x0000C000U
#define RCC_u32APB2_DIV_BY_16      0x0000E000U


/* ==================== AHB Prescaler ==================== */

#define RCC_u32AHB_DIV_BY_1        0x00000000U
#define RCC_u32AHB_DIV_BY_2        0x00000080U
#define RCC_u32AHB_DIV_BY_4        0x00000090U
#define RCC_u32AHB_DIV_BY_8        0x000000A0U
#define RCC_u32AHB_DIV_BY_16       0x000000B0U
#define RCC_u32AHB_DIV_BY_64       0x000000C0U
#define RCC_u32AHB_DIV_BY_128      0x000000D0U
#define RCC_u32AHB_DIV_BY_256      0x000000E0U
#define RCC_u32AHB_DIV_BY_512      0x000000F0U

#define RCC_AHB1     0U
#define RCC_APB1    1U
#define RCC_APB2    2U


Std_ReturnType Mcal_EN_CLK(
    RCC_CLK_TYPE copy_clock_type,
    RCC_CLK_MODE copy_clock_mode
);

Std_ReturnType Mcal_SYS_CLK(RCC_CLK_TYPE copy_clock_type);
RCC_CLOCK_STATUS Mcal_CLK_STATUS(RCC_CLK_TYPE copy_clock_type);

RCC_CLK_TYPE Mcal_RETURN_SYS_CLK(void);

RCC_RESET_CAUSE Mcal_RCC_RESET_CAUSE(void);
u32 Mcal_Get_SYS_CLK_Freq(void);

Std_ReturnType Mcal_RCC_SetBusPrescaler(u32 Copy_u32Bus, u32 Copy_u32Prescaler);


Std_ReturnType Mcal_Rcc_Peripheral_EN_Clock(u8 copy_Perpheral_Id ,RCC_BUS_TYPES Bus_Id);

Std_ReturnType Mcal_Rcc_Peripheral_Dis_Clock(u8 copy_Perpheral_Id , RCC_BUS_TYPES Bus_Id);

#endif
