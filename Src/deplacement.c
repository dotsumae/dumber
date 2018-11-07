#include "deplacement.h"

int TicksGauche; 
int TicksDroite;

void ModifierTicksGauche(int increment) {
	TicksGauche += increment;
}

void ModifierTicksDroite(int increment) {
	TicksDroite += increment;
}

int LireEtat(void) {
	return TicksGauche + TicksDroite;
}
