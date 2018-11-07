#include "deplacement.h"

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
