#include "gpio_driver.h"


void GPIO_Driver_Init(void)
{
    /* Enable GPIO clocks */

    RCC->AHB1ENR |= (1U << 0);     /* GPIOA */
    RCC->AHB1ENR |= (1U << 1);     /* GPIOB */
    RCC->AHB1ENR |= (1U << 3);     /* GPIOD */


    /* =========================
       LEDs: PD12, PD13, PD14, PD15
       ========================= */

    GPIOD->MODER &= ~(
        (3U << (12 * 2)) |
        (3U << (13 * 2)) |
        (3U << (14 * 2)) |
        (3U << (15 * 2))
    );

    GPIOD->MODER |= (
        (1U << (12 * 2)) |
        (1U << (13 * 2)) |
        (1U << (14 * 2)) |
        (1U << (15 * 2))
    );

    GPIOD->OTYPER &= ~(
        (1U << 12) |
        (1U << 13) |
        (1U << 14) |
        (1U << 15)
    );

    GPIOD->PUPDR &= ~(
        (3U << (12 * 2)) |
        (3U << (13 * 2)) |
        (3U << (14 * 2)) |
        (3U << (15 * 2))
    );

    GPIOD->OSPEEDR &= ~(
        (3U << (12 * 2)) |
        (3U << (13 * 2)) |
        (3U << (14 * 2)) |
        (3U << (15 * 2))
    );


    /* =========================
       Buzzer: PB0
       ========================= */

    GPIOB->MODER &= ~(3U << (BUZZER_PIN * 2));

    GPIOB->MODER |= (1U << (BUZZER_PIN * 2));

    GPIOB->OTYPER &= ~(1U << BUZZER_PIN);

    GPIOB->PUPDR &= ~(3U << (BUZZER_PIN * 2));

    GPIOB->OSPEEDR &= ~(3U << (BUZZER_PIN * 2));


    /* =========================
       User Button: PA0
       ========================= */

    GPIOA->MODER &= ~(3U << (USER_BUTTON_PIN * 2));

    GPIOA->PUPDR &= ~(3U << (USER_BUTTON_PIN * 2));


    /* =========================
       Initial State
       ========================= */

    GPIOD->BSRR =
        (1U << (LED_GREEN_PIN + 16)) |
        (1U << (LED_ORANGE_PIN + 16)) |
        (1U << (LED_RED_PIN + 16)) |
        (1U << (LED_BLUE_PIN + 16));

    GPIOB->BSRR =
        (1U << (BUZZER_PIN + 16));
}


/* =========================
   Green LED
   ========================= */

void LED_Green_On(void)
{
    GPIOD->BSRR = (1U << LED_GREEN_PIN);
}

void LED_Green_Off(void)
{
    GPIOD->BSRR = (1U << (LED_GREEN_PIN + 16));
}

void LED_Green_Toggle(void)
{
    GPIOD->ODR ^= (1U << LED_GREEN_PIN);
}


/* =========================
   Orange LED
   ========================= */

void LED_Orange_On(void)
{
    GPIOD->BSRR = (1U << LED_ORANGE_PIN);
}

void LED_Orange_Off(void)
{
    GPIOD->BSRR = (1U << (LED_ORANGE_PIN + 16));
}

void LED_Orange_Toggle(void)
{
    GPIOD->ODR ^= (1U << LED_ORANGE_PIN);
}


/* =========================
   Red LED
   ========================= */

void LED_Red_On(void)
{
    GPIOD->BSRR = (1U << LED_RED_PIN);
}

void LED_Red_Off(void)
{
    GPIOD->BSRR = (1U << (LED_RED_PIN + 16));
}

void LED_Red_Toggle(void)
{
    GPIOD->ODR ^= (1U << LED_RED_PIN);
}


/* =========================
   Blue LED
   ========================= */

void LED_Blue_On(void)
{
    GPIOD->BSRR = (1U << LED_BLUE_PIN);
}

void LED_Blue_Off(void)
{
    GPIOD->BSRR = (1U << (LED_BLUE_PIN + 16));
}

void LED_Blue_Toggle(void)
{
    GPIOD->ODR ^= (1U << LED_BLUE_PIN);
}


/* =========================
   Buzzer
   ========================= */

void Buzzer_On(void)
{
    GPIOB->BSRR = (1U << BUZZER_PIN);
}

void Buzzer_Off(void)
{
    GPIOB->BSRR = (1U << (BUZZER_PIN + 16));
}

void Buzzer_Toggle(void)
{
    GPIOB->ODR ^= (1U << BUZZER_PIN);
}


/* =========================
   Button
   ========================= */

uint8_t Button_Read(void)
{
    return (uint8_t)((GPIOA->IDR >> USER_BUTTON_PIN) & 1U);
}


/* =========================
   Delay
   ========================= */

void Delay_ms(uint32_t ms)
{
    uint32_t i;
    uint32_t j;

    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 16000U; j++)
        {
            __NOP();
        }
    }
}
