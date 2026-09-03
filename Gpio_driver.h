#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx_hal.h"

/* LEDs */
#define LED_GREEN_PIN      GPIO_PIN_12
#define LED_GREEN_PORT     GPIOD

#define LED_ORANGE_PIN     GPIO_PIN_13
#define LED_ORANGE_PORT    GPIOD

#define LED_RED_PIN        GPIO_PIN_14
#define LED_RED_PORT       GPIOD

#define LED_BLUE_PIN       GPIO_PIN_15
#define LED_BLUE_PORT      GPIOD

/* Push Button */
#define USER_BUTTON_PIN    GPIO_PIN_0
#define USER_BUTTON_PORT   GPIOA

/* Buzzer */
#define BUZZER_PIN         GPIO_PIN_0
#define BUZZER_PORT        GPIOB

void GPIO_Driver_Init(void);

void LED_Green_On(void);
void LED_Green_Off(void);
void LED_Green_Toggle(void);

void LED_Orange_On(void);
void LED_Orange_Off(void);
void LED_Orange_Toggle(void);

void LED_Red_On(void);
void LED_Red_Off(void);
void LED_Red_Toggle(void);

void LED_Blue_On(void);
void LED_Blue_Off(void);
void LED_Blue_Toggle(void);

void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Toggle(void);

uint8_t Button_Read(void);

#endif
