#include "deplacement.h"
#include "led.h"
#include "stm32f1xx_hal.h"

#define TICKS_ROTATION 70 //parametre pour les rotations
int TicksGauche;
int TicksDroite;


void DeplacerDe(int destination) {
	
	int AncienEtat = LireEtat(TOUTES);
	
	if (destination > 0)
	{
		while(LireEtat(TOUTES) - AncienEtat < destination)
		{
			Avancer();
		}	
		
	}
	
	
	else if (destination < 0) 
	{
		while(LireEtat(TOUTES) - AncienEtat < - destination)
		{
			Reculer();
		}	
		
	}
	
	else //destination = 0
	{
		Arret();
	}
}




void ModifierTicksGauche(int increment) {
	TicksGauche += increment;
}
void ModifierTicksDroite(int increment) {
	TicksDroite += increment;
}


void ResetEtat(void) {
	TicksGauche = 0;
	TicksDroite = 0;
}



int LireEtat(enum roue selection_roue) {
	
	int resultat;
	switch (selection_roue) {
		
		case GAUCHE : 
			resultat = TicksGauche;
			break;
		case DROITE :
			resultat = TicksDroite;
			break;
		case TOUTES : 
			resultat = TicksGauche + TicksDroite;
			break;
	}
	
	return resultat;
	
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
	int AncienTicksDroite = LireEtat(DROITE);
		OnLEDOrange();
		/* Faire tourner la roue gauche */
		GPIOB->ODR |= (1<<12);
		GPIOB->ODR &= ~(1<<13);

		/* Faire tourner la roue droite */
		GPIOB->ODR |= (1<<14);
		GPIOB->ODR &= ~(1<<15);
	
	while(LireEtat(DROITE) - AncienTicksDroite < TICKS_ROTATION) { HAL_Delay(10); }
		Arret();
}	

void TournerD(void)
{
		int AncienTicksGauche = LireEtat(GAUCHE);

		OnLEDOrange();	
		/* Faire tourner la roue gauche */
		GPIOB->ODR |= (1<<13);
		GPIOB->ODR &= ~(1<<12);

		/* Faire tourner la roue droite */
		GPIOB->ODR |= (1<<15);
		GPIOB->ODR &= ~(1<<14);
	
	while(LireEtat(GAUCHE) - AncienTicksGauche < TICKS_ROTATION) { HAL_Delay(10); }

	Arret();
}


