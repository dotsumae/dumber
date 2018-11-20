#include "led.h"
#include "stm32f1xx_hal.h"

void OnLEDVerte(void)
{
	GPIOB->ODR |= (1<<1);
	GPIOB->ODR &= ~(1<<0);
}

void OnLEDRouge(void)
{
	GPIOB->ODR |= (1<<0);
	GPIOB->ODR &= ~(1<<1);
}

void OnLEDOrange(void)
{
	GPIOB->ODR |= (1<<1);
	GPIOB->ODR |= (1<<0);
}


