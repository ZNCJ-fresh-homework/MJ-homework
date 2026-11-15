
HAL_GPIO_Init();

HAL_GPIO_WritePin(..., GPIO_PIN_SET);   // 点亮


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
