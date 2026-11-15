/**
 * @file    gpio_button_led.c
 * @brief   STM32 HAL：按键消抖扫描 + LED 翻转（PA0 按键输入，PB0 推挽输出接 LED）
 */

#include "main.h"

/* -------------------------------------------------------------------------- */
/* 1. GPIO 初始化：PA0 按键输入、PB0 LED 输出                                  */
/* -------------------------------------------------------------------------- */

HAL_GPIO_Init();

HAL_GPIO_WritePin(..., GPIO_PIN_SET);   // 点亮

/* -------------------------------------------------------------------------- */
/* 2. 按键扫描：检测到 PA0 低电平后消抖，确认按下则翻转 PB0，并等待松手          */
/* -------------------------------------------------------------------------- */

if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
{
    HAL_Delay(20);                      // 消抖

    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);   // 翻转

        while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
        {
        }
    }
}
