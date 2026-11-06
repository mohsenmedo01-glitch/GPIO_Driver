                                    /*     author : Mohamed Junior          */
                                /*          Date 20/10/2026            */
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_





                /* Registers Address*/
#define RCC_CR       (*(volatile u32 *)0x40023800U)
#define RCC_PLLCFGR  (*(volatile u32 *)0x40023804U)
#define RCC_CFGR     (*(volatile u32 *)0x40023808U)
#define RCC_AHB1ENR  (*(volatile u32 *)0x40023830U)
#define RCC_APB1ENR  (*(volatile u32 *)0x40023840U)
#define RCC_APB2ENR  (*(volatile u32 *)0x40023844U)
#define RCC_CSR      (*(volatile u32 *)0x40023874U)



                    /* Bits number  */

#define RCC_HSI_ON_NUM                 0U
#define RCC_HSE_ON_NUM                 16U
#define RCC_PLL_ON_NUM                 24U
//#define RCC_PLLREADY                   25U
#define RCC_CR_HSERDY                  17U 
#define RCC_CR_HSIRDY                  1U 
#define RCC_CR_PLLRDY                  25U
#define RCC_RC_BIT                     18U
#define RCC_HSI_CLK_SRC          

#define RCC_AHB1_GPIOAEN                0U
#define RCC_APB1_WWDGEN                11U
#define RCC_APB2_USART1EN              4U


#define RCC_CSR_LPWRRSTF_NUM       31U
#define RCC_CSR_WWDGRSTF_NUM       30U
#define RCC_CSR_IWDGRSTF_NUM       29U
#define RCC_CSR_SFTRSTF_NUM        28U
#define RCC_CSR_PORRSTF_NUM        27U
#define RCC_CSR_PINRSTF_NUM        26U
#define RCC_CSR_BORRSTF_NUM        25U
#define RCC_CSR_RMVF_NUM           24U


#define RCC_SWS_bit_0           2U
#define RCC_SWS_bit_1           3U



#define RCC_RC_                      1
#define RCC_CRYSTAL_                 0



#define RCC_SW  0



#endif
