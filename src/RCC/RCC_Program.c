                                    /*     author : Mohamed Junior          */
                                /*          Date 20/10/2026            */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "rcc/RCC_Private.h"
#include "rcc/RCC_Config.h"
#include "rcc/RCC_Interface.h"


Std_ReturnType Mcal_EN_CLK(RCC_CLK_TYPE copy_clock_type,RCC_CLK_MODE copy_clock_mode)
{
    u32 time_out = RCC_TIMEOUT;
    Std_ReturnType status = C_OK;

    switch (copy_clock_type)
    {
        case RCC_HSE:

            if (copy_clock_mode == ENABLE)
            {
                SET_BIT(RCC_CR, RCC_HSE_ON_NUM);

                while (!GET_BIT(RCC_CR, RCC_CR_HSERDY))
                {
                    if (time_out == 0U)
                    {
                        status = C_NOT_OK;
                        break;
                    }

                    time_out--;
                }
            }
            else if (copy_clock_mode == DISABLE)
            {
                CLR_BIT(RCC_CR, RCC_HSE_ON_NUM);
            }
            else
            {
                status = C_NOT_OK;
            }

            break;

        case RCC_HSI:

            if (copy_clock_mode == ENABLE)
            {
                SET_BIT(RCC_CR, RCC_HSI_ON_NUM);

                while (!GET_BIT(RCC_CR, RCC_CR_HSIRDY))
                {
                    if (time_out == 0U)
                    {
                        status = C_NOT_OK;
                        break;
                    }

                    time_out--;
                }
            }
            else if (copy_clock_mode == DISABLE)
            {
                CLR_BIT(RCC_CR, RCC_HSI_ON_NUM);
            }
            else
            {
                status = C_NOT_OK;
            }

            break;

        case RCC_PLL:

            if (copy_clock_mode == ENABLE)
            {
                SET_BIT(RCC_CR, RCC_PLL_ON_NUM);

                while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY))
                {
                    if (time_out == 0U)
                    {
                        status = C_NOT_OK;
                        break;
                    }

                    time_out--;
                }
            }
            else if (copy_clock_mode == DISABLE)
            {
                CLR_BIT(RCC_CR, RCC_PLL_ON_NUM);
            }
            else
            {
                status = C_NOT_OK;
            }

            break;

        default:

            status = C_NOT_OK;
            break;
    }

    return status;
}

       /* ================= SOURCE CLOCK FUNCTION ================= */

    
Std_ReturnType Mcal_SYS_CLK(RCC_CLK_TYPE copy_clock_type){
    Std_ReturnType status = C_NOT_OK;
    u32 time_out=RCC_TIMEOUT;

    switch(copy_clock_type){


        /* ================= HSE IS SOURCE CLOCK ================= */


        case RCC_HSE:
            SET_BIT(RCC_CR,RCC_HSE_ON_NUM);
            while(!GET_BIT(RCC_CR,RCC_CR_HSERDY)){
                if (time_out==0){
                    status=C_NOT_OK;
                    break;
                }time_out--;
            }
            RCC_CFGR=0x00001;
            break;

            /* ================= HSI IS SOURCE CLOCK ================= */


        case RCC_HSI:
            SET_BIT(RCC_CR,RCC_HSI_ON_NUM);
            while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY)){
                if (time_out==0){
                    status=C_NOT_OK;
                    break;
                }time_out--;
            }
            RCC_CFGR=0x00000;
            break;
        default:
            status= C_NOT_OK;
            break;    
    }
    return status;   
}



Std_ReturnType Mcal_Rcc_Peripheral_EN_Clock(u8 copy_Perpheral_Id , u8 Bus_Id)
{

    Std_ReturnType status=C_OK;
    switch(Bus_Id){
        case RCC_AHB1:
            SET_BIT(RCC_AHB1ENR,copy_Perpheral_Id);
            status= C_OK;
            break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR,copy_Perpheral_Id);
            status= C_OK;
            break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR,copy_Perpheral_Id );
            status = C_OK;
            break;  
        default:
            status = C_NOT_OK;
            break;
    }  
    return status;
}



Std_ReturnType Mcal_Rcc_Peripheral_Dis_Clock(u8 copy_Perpheral_Id , u8 Bus_Id)
{
        Std_ReturnType status=C_OK;
    switch(Bus_Id){
        case RCC_AHB1:
            CLR_BIT(RCC_AHB1ENR,copy_Perpheral_Id);
            status= C_OK;
            break;
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR,copy_Perpheral_Id);
            status= C_OK;
            break;
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR,copy_Perpheral_Id );
            status = C_OK;
            break;  
        default:
            status = C_NOT_OK;
            break;
    }  
    return status;
}


Std_ReturnType Mcal_RCC_SetBusPrescaler(u32 Copy_u32Bus, u32 Copy_u32Prescaler)
{
    Std_ReturnType status = C_OK;

    switch (Copy_u32Bus)
    {
        /* ================= AHB ================= */

        case RCC_AHB1:

            switch (Copy_u32Prescaler)
            {
                case RCC_u32AHB_DIV_BY_1:
                case RCC_u32AHB_DIV_BY_2:
                case RCC_u32AHB_DIV_BY_4:
                case RCC_u32AHB_DIV_BY_8:
                case RCC_u32AHB_DIV_BY_16:
                case RCC_u32AHB_DIV_BY_64:
                case RCC_u32AHB_DIV_BY_128:
                case RCC_u32AHB_DIV_BY_256:
                case RCC_u32AHB_DIV_BY_512:

                    RCC_CFGR &= ~(0xFU << 4);
                    RCC_CFGR |= Copy_u32Prescaler;
                    break;

                default:
                    status = C_NOT_OK;
                    break;
            }
            break;

        /* ================= APB1 ================= */

        case RCC_APB1:

            switch (Copy_u32Prescaler)
            {
                case RCC_u32APB1_DIV_BY_1:
                case RCC_u32APB1_DIV_BY_2:
                case RCC_u32APB1_DIV_BY_4:
                case RCC_u32APB1_DIV_BY_8:
                case RCC_u32APB1_DIV_BY_16:

                    RCC_CFGR &= ~(0x7U << 10);
                    RCC_CFGR |= Copy_u32Prescaler;
                    break;

                default:
                    status = C_NOT_OK;
                    break;
            }
            break;

        /* ================= APB2 ================= */

        case RCC_APB2:

            switch (Copy_u32Prescaler)
            {
                case RCC_u32APB2_DIV_BY_1:
                case RCC_u32APB2_DIV_BY_2:
                case RCC_u32APB2_DIV_BY_4:
                case RCC_u32APB2_DIV_BY_8:
                case RCC_u32APB2_DIV_BY_16:

                    RCC_CFGR &= ~(0x7U << 13);
                    RCC_CFGR |= Copy_u32Prescaler;
                    break;

                default:
                    status = C_NOT_OK;
                    break;
            }
            break;

        default:
            status = C_NOT_OK;
            break;
    }

    return status;
}

RCC_CLOCK_STATUS Mcal_CLK_STATUS(RCC_CLK_TYPE copy_clock_type){
    RCC_CLOCK_STATUS clock_status= INVALID_CLOCK;
    switch(copy_clock_type){
        case RCC_HSI :
            if (GET_BIT(RCC_CR,RCC_CR_HSIRDY)==1){
                clock_status= RCC_HSI_READY;

                
            }else{
                clock_status= RCC_HSI_NOT_READY;

            }
        case RCC_HSE :

            if (GET_BIT(RCC_CR,RCC_CR_HSERDY)==1){
                clock_status= RCC_HSE_READY;

                
            }else{
                clock_status= RCC_HSE_NOT_READY;

            }
        default:
                clock_status= INVALID_CLOCK;    

    }
    return clock_status;
        
}


RCC_RESET_CAUSE Mcal_RCC_RESET_CAUSE(void)
{
    RCC_RESET_CAUSE reset_cause = RCC_RESET_UNKNOWN;

    if (GET_BIT(RCC_CSR, RCC_CSR_LPWRRSTF_NUM))
    {
        reset_cause = RCC_RESET_LOW_POWER;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_WWDGRSTF_NUM))
    {
        reset_cause = RCC_RESET_WINDOW_WATCHDOG;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_IWDGRSTF_NUM))
    {
        reset_cause = RCC_RESET_INDEPENDENT_WATCHDOG;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_SFTRSTF_NUM))
    {
        reset_cause = RCC_RESET_SOFTWARE;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_PORRSTF_NUM))
    {
        reset_cause = RCC_RESET_POWER_ON;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_PINRSTF_NUM))
    {
        reset_cause = RCC_RESET_PIN;
    }
    else if (GET_BIT(RCC_CSR, RCC_CSR_BORRSTF_NUM))
    {
        reset_cause = RCC_RESET_BROWN_OUT;
    }

    return reset_cause;
}


RCC_CLK_TYPE Mcal_RETURN_SYS_CLK(void)
{
    RCC_CLK_TYPE clock_source = RCC_HSI;

    if ((GET_BIT(RCC_CFGR, RCC_SWS_bit_0) == 0) &&
        (GET_BIT(RCC_CFGR, RCC_SWS_bit_1) == 0))
    {
        clock_source = RCC_HSI;
    }
    else if ((GET_BIT(RCC_CFGR, RCC_SWS_bit_0) == 1) &&
            (GET_BIT(RCC_CFGR, RCC_SWS_bit_1) == 0))
    {
        clock_source = RCC_HSE;
    }
    else if ((GET_BIT(RCC_CFGR, RCC_SWS_bit_0) == 0) &&
            (GET_BIT(RCC_CFGR, RCC_SWS_bit_1) == 1))
    {
        clock_source = RCC_PLL;
    }

    return clock_source;
}

u32 Mcal_Get_SYS_CLK_Freq(void)
{
    u32 frequency = 0;

    switch (Mcal_RETURN_SYS_CLK())
    {
        case RCC_HSI:
            frequency= RCC_HSI_FREQ;
            break;

        case RCC_HSE:
            frequency = RCC_HSE_FREQ;
            break;

        default:
            frequency = 0;
            break;
    }

    return frequency;
}