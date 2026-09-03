#include "stm32f4xx.h"
#include "gpio_driver.h"


int main(void)
{
    GPIO_Driver_Init();

    while (1)
    {
        LED_Green_On();
        Delay_ms(500);

        LED_Green_Off();


        LED_Orange_On();
        Delay_ms(500);

        LED_Orange_Off();


        LED_Red_On();
        Delay_ms(500);

        LED_Red_Off();


        LED_Blue_On();
        Delay_ms(500);

        LED_Blue_Off();


        Buzzer_On();
        Delay_ms(500);

        Buzzer_Off();

        Delay_ms(500);
    }
}
