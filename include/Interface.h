#ifndef INTERFACE_H_
#define INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Private.h"
#include "Config.h"



typedef enum
{
    GPIO_A,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E,
    GPIO_H
}GPIO_PORTS_TYPE_t;


typedef enum
{
    GPIO_PUSH_PULL,
    GPIO_OPEN_DRAIN

} GPIO_OutputType;

typedef enum
{
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15

} GPIO_PinNum_t;


typedef enum{
    Input ,
    General_purpose_output_mode,
    Alternate_function_mode,
    Analog_mode
} GPIO_port_mode_t; 

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} GPIO_PinValue_t;



Std_ReturnType Mcal_GPIO_enuPinOutType(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_OutputType copy_OTY_mode_status
);

Std_ReturnType Mcal_GPIO_enuPinMode(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_port_mode_t copy_mode_status
);

Std_ReturnType Mcal_GPIO_enuSetPinValue(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_PinValue_t copy_Pin_Value
);

Std_ReturnType Mcal_GPIO_enuGETPinValue(
    GPIO_PORTS_TYPE_t copy_port_type,
    GPIO_PinNum_t copy_Pin_Num,
    GPIO_PinValue_t *copy_Pin_Value
);

void Mcal_GPIO_enuButtonLedInit(void);

void Mcal_GPIO_enuButtonLedControl(void);














#endif