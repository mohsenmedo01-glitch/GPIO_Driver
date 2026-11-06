#ifndef GPIO_Program_C_
#define GPIO_Program_C_
#endif
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Private.h"
#include "Config.h"
#include "Interface.h"
#include "RCC/RCC_INTERFACE.h"
#include <stddef.h>


GPIO_tstrRegisters * GPIO_APTR[GPIO_PORTS_NUM] ={GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH};

Std_ReturnType Mcal_GPIO_enuPinOutType(GPIO_PORTS_TYPE_t copy_port_type, GPIO_PinNum_t copy_Pin_Num, GPIO_OutputType copy_OTY_mode_status)
{
    Std_ReturnType Local_status = C_NOT_OK;
    switch (copy_port_type)
    {
    case GPIO_A:
        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOA->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else if (copy_OTY_mode_status == GPIO_OPEN_DRAIN)
        {
            SET_BIT(GPIOA->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }
        break;

    case GPIO_B:
        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOB->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }

        /* Open Drain Mode*/
        else if ((copy_OTY_mode_status == GPIO_OPEN_DRAIN))

        {
            SET_BIT(GPIOB->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }
        break;


    case GPIO_C:

        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOC->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }

        /* Open Drain Mode*/
        else if ((copy_OTY_mode_status == GPIO_OPEN_DRAIN))

        {
            SET_BIT(GPIOC->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }

        break;

    case GPIO_D:
        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOD->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }

        /* Open Drain Mode*/
        else if ((copy_OTY_mode_status == GPIO_OPEN_DRAIN))

        {
            SET_BIT(GPIOD->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }

        break;

    case GPIO_E:
        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOE->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }

        /* Open Drain Mode*/
        else if ((copy_OTY_mode_status == GPIO_OPEN_DRAIN))

        {
            SET_BIT(GPIOE->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }

        break;

    case GPIO_H:
        if (copy_OTY_mode_status == GPIO_PUSH_PULL)
        {
            CLR_BIT(GPIOH->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }

        /* Open Drain Mode*/
        else if ((copy_OTY_mode_status == GPIO_OPEN_DRAIN))

        {
            SET_BIT(GPIOH->GPIO_OTYPER, copy_Pin_Num);
            Local_status = C_OK;
        }
        else
        {
            Local_status = C_NOT_OK;
        }

        break;
    }
    return Local_status;
}

Std_ReturnType Mcal_GPIO_enuPinMode(GPIO_PORTS_TYPE_t copy_port_type , GPIO_PinNum_t copy_Pin_Num, GPIO_port_mode_t copy_mode_status)
{

    Std_ReturnType Local_status = C_NOT_OK;
    CLR_2BITS(GPIO_APTR[copy_port_type]->GPIO_MODER,copy_Pin_Num*2, GPIO_MODER_MASK);
    SET_2BITS_VALUE(GPIO_APTR[copy_port_type]->GPIO_MODER, copy_Pin_Num*2 ,copy_mode_status);
    Local_status = C_OK;    
    return Local_status;    
    }


Std_ReturnType Mcal_GPIO_enuSetPinValue(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_PinValue_t copy_Pin_Value
)
{
    Std_ReturnType Local_status = C_NOT_OK;

    /* Configure Pin as Output */
    Local_status = Mcal_GPIO_enuPinMode(
        copy_port_type,
        copy_Pin_Num,
        General_purpose_output_mode
    );

    if (Local_status == C_OK)
    {
        /* Configure Push Pull */
        Local_status = Mcal_GPIO_enuPinOutType(
            copy_port_type,
            copy_Pin_Num,
            GPIO_PUSH_PULL
        );
    }

    if (Local_status == C_OK)
    {
        /* Set Pin Value */
        if (copy_Pin_Value == GPIO_HIGH)
        {
            SET_BIT(GPIO_APTR[copy_port_type]->GPIO_ODR, copy_Pin_Num);
            Local_status = C_OK;
        }
        else if (copy_Pin_Value == GPIO_LOW)
        {
            CLR_BIT(GPIO_APTR[copy_port_type]->GPIO_ODR, copy_Pin_Num);
            Local_status = C_OK;
        }
    }

    return Local_status;
}

Std_ReturnType Mcal_GPIO_enuGetPinValue(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_PinValue_t * copy_Pin_Value
)

{
    Std_ReturnType Local_status = C_NOT_OK;
    if(copy_Pin_Value != NULL){
        if(GET_BIT(GPIO_APTR[copy_port_type]->GPIO_IDR, copy_Pin_Num)==1)
        {
           *copy_Pin_Value = GPIO_HIGH;
        
        }
        else
        {
            *copy_Pin_Value = GPIO_LOW;
            
        }
        Local_status=C_OK;
    }
    return Local_status;

}


void Mcal_GPIO_enuButtonLedInit(void)
{
    /* Enable GPIOC Clock */
    Mcal_Rcc_Peripheral_EN_Clock(RCC_AHB1_GPIOCEN, RCC_AHB1);

    /* Configure PC14 as Output (LED) */
    Mcal_GPIO_enuPinMode( GPIO_C, GPIO_PIN_14, General_purpose_output_mode
    );

    /* Configure PC13 as Input (Button) */
    Mcal_GPIO_enuPinMode( GPIO_C, GPIO_PIN_13, Input);

    /* LED initially OFF */
    Mcal_GPIO_enuSetPinValue(GPIO_C, GPIO_PIN_14, GPIO_LOW);
}



void Mcal_GPIO_enuButtonLedControl(void)
{
    static GPIO_PinValue_t Previous_Button_State = GPIO_HIGH;
    static GPIO_PinValue_t LED_State = GPIO_LOW;

    GPIO_PinValue_t Button_State;

    /* Read Button */
    Mcal_GPIO_enuGetPinValue( GPIO_C, GPIO_PIN_13, &Button_State );

    /* Detect new button press */
    if ((Button_State == GPIO_LOW) &&
        (Previous_Button_State == GPIO_HIGH))
    {
        if (LED_State == GPIO_LOW)
        {
            /* SET LED */
            Mcal_GPIO_enuSetPinValue( GPIO_C, GPIO_PIN_14, GPIO_HIGH);

            LED_State = GPIO_HIGH;
        }
        else
        {
            /* CLEAR LED */
            Mcal_GPIO_enuSetPinValue( GPIO_C, GPIO_PIN_14, GPIO_LOW);
            LED_State = GPIO_LOW;
        }
    }

    Previous_Button_State = Button_State;
}


