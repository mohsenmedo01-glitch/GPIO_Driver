#include "INTERFACE.h"
#include "STD_TYPES.h"
#include "STD_TYPES.h"
#include "Private.h"
#include "rcc/RCC_Interface.h"
int main(){
    //GPIO_PinValue_t Button_State;
    //Mcal_GPIO_enuGetPinValue(GPIO_C, GPIO_PIN_13, &Button_State);
    Mcal_GPIO_enuButtonLedInit();
    //Mcal_Rcc_Peripheral_EN_Clock(RCC_AHB1_GPIOCEN ,RCC_AHB1) ;
    //Mcal_GPIO_enuPinOutType(GPIO_C, GPIO_PIN_14,GPIO_PUSH_PULL); 
    //Mcal_GPIO_enuPinMode(GPIO_C,GPIO_PIN_14,General_purpose_output_mode);
    //Mcal_GPIO_enuPinMode(GPIO_C,GPIO_PIN_13,Input);
    
    //Mcal_GPIO_enuSetPinValue(GPIO_C,GPIO_PIN_14,GPIO_HIGH);
  //Mcal_GPIO_enuSetPinValue(GPIO_C,GPIO_PIN_14,GPIO_LOW);
    
    while(1){
        Mcal_GPIO_enuButtonLedControl();

    }
}
