#include "main.h"
#include "gpio_driver.h"

int main(void)
{
    HAL_Init();

    GPIO_Driver_Init();

    while (1)
    {
        /* Green LED */
        LED_Green_On();
        HAL_Delay(500);

        LED_Green_Off();

        /* Orange LED */
        LED_Orange_On();
        HAL_Delay(500);

        LED_Orange_Off();

        /* Red LED */
        LED_Red_On();
        HAL_Delay(500);

        LED_Red_Off();

        /* Blue LED */
        LED_Blue_On();
        HAL_Delay(500);

        LED_Blue_Off();

        /* Buzzer */
        Buzzer_On();
        HAL_Delay(500);

        Buzzer_Off();
        HAL_Delay(500);
    }
}
