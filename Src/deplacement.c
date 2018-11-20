#include "deplacement.h"
#include "led.h"
#include "stm32f1xx_hal.h"

int TicksGauche = 0;
int TicksDroite = 0;

void ModifierTicksGauche(int increment) {
	TicksGauche += increment;
}
void ModifierTicksDroite(int increment) {
	TicksDroite += increment;
}

int LireEtat(void) {
	return TicksGauche + TicksDroite;
}

void Arret(void) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);

	
		//GPIOB->ODR |= (1<<12);
		//GPIOB->ODR &= ~(1<<13);
		
		/* Faire tourner la roue droite */
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
}

void Avancer(void)
{
		OnLEDVerte();
		/* Faire tourner la roue gauche */
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);

	
		//GPIOB->ODR |= (1<<12);
		//GPIOB->ODR &= ~(1<<13);
		
		/* Faire tourner la roue droite */
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	
		//GPIOB->ODR |= (1<<15);
		//GPIOB->ODR &= ~(1<<14);
}

void Reculer(void)
{
		OnLEDRouge();
		/* Faire tourner la roue gauche */
		GPIOB->ODR |= (1<<13);
		GPIOB->ODR &= ~(1<<12);
		
		/* Faire tourner la roue droite */
		GPIOB->ODR |= (1<<14);
		GPIOB->ODR &= ~(1<<15);
}

void TournerG(void)
{
		OnLEDOrange();
		/* Faire tourner la roue gauche */
		GPIOB->ODR |= (1<<12);
		GPIOB->ODR &= ~(1<<13);

		/* Faire tourner la roue droite */
		GPIOB->ODR |= (1<<14);
		GPIOB->ODR &= ~(1<<15);
}	

void TournerD(void)
{
		OnLEDOrange();	
		/* Faire tourner la roue gauche */
		GPIOB->ODR |= (1<<13);
		GPIOB->ODR &= ~(1<<12);

		/* Faire tourner la roue droite */
		GPIOB->ODR |= (1<<15);
		GPIOB->ODR &= ~(1<<14);

}


