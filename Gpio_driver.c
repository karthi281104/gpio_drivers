#include "gpio_driver.h"

void GPIO_Driver_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOD,
        GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15,
        GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

/* Green LED */
void LED_Green_On(void){ HAL_GPIO_WritePin(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_PIN_SET); }
void LED_Green_Off(void){ HAL_GPIO_WritePin(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_PIN_RESET); }
void LED_Green_Toggle(void){ HAL_GPIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN); }

/* Orange LED */
void LED_Orange_On(void){ HAL_GPIO_WritePin(LED_ORANGE_PORT, LED_ORANGE_PIN, GPIO_PIN_SET); }
void LED_Orange_Off(void){ HAL_GPIO_WritePin(LED_ORANGE_PORT, LED_ORANGE_PIN, GPIO_PIN_RESET); }
void LED_Orange_Toggle(void){ HAL_GPIO_TogglePin(LED_ORANGE_PORT, LED_ORANGE_PIN); }

/* Red LED */
void LED_Red_On(void){ HAL_GPIO_WritePin(LED_RED_PORT, LED_RED_PIN, GPIO_PIN_SET); }
void LED_Red_Off(void){ HAL_GPIO_WritePin(LED_RED_PORT, LED_RED_PIN, GPIO_PIN_RESET); }
void LED_Red_Toggle(void){ HAL_GPIO_TogglePin(LED_RED_PORT, LED_RED_PIN); }

/* Blue LED */
void LED_Blue_On(void){ HAL_GPIO_WritePin(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_PIN_SET); }
void LED_Blue_Off(void){ HAL_GPIO_WritePin(LED_BLUE_PORT, LED_BLUE_PIN, GPIO_PIN_RESET); }
void LED_Blue_Toggle(void){ HAL_GPIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN); }

/* Buzzer */
void Buzzer_On(void){ HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET); }
void Buzzer_Off(void){ HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET); }
void Buzzer_Toggle(void){ HAL_GPIO_TogglePin(BUZZER_PORT, BUZZER_PIN); }

/* Button */
uint8_t Button_Read(void)
{
    return (uint8_t)HAL_GPIO_ReadPin(USER_BUTTON_PORT, USER_BUTTON_PIN);
}
