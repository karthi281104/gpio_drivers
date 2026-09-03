#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f4xx.h"
#include <stdint.h>

/* LEDs */

#define LED_GREEN_PIN       12
#define LED_ORANGE_PIN      13
#define LED_RED_PIN         14
#define LED_BLUE_PIN        15

#define LED_PORT            GPIOD


/* User Button */

#define USER_BUTTON_PIN     0
#define USER_BUTTON_PORT    GPIOA


/* Buzzer */

#define BUZZER_PIN          0
#define BUZZER_PORT         GPIOB


/* GPIO Initialization */

void GPIO_Driver_Init(void);


/* Green LED */

void LED_Green_On(void);
void LED_Green_Off(void);
void LED_Green_Toggle(void);


/* Orange LED */

void LED_Orange_On(void);
void LED_Orange_Off(void);
void LED_Orange_Toggle(void);


/* Red LED */

void LED_Red_On(void);
void LED_Red_Off(void);
void LED_Red_Toggle(void);


/* Blue LED */

void LED_Blue_On(void);
void LED_Blue_Off(void);
void LED_Blue_Toggle(void);


/* Buzzer */

void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Toggle(void);


/* Button */

uint8_t Button_Read(void);


/* Delay */

void Delay_ms(uint32_t ms);

#endif
