
#ifndef DEPLACEMENT
#define DEPLACEMENT

enum roue {GAUCHE, DROITE, TOUTES};

void DeplacerDe(int destination);
void ModifierTicksGauche(int increment);
void ModifierTicksDroite(int increment);
void ResetEtat(void);
int LireEtat(enum roue selection_roue);
void Arret(void);
void Avancer(void);
void Reculer(void);
void TournerG(void);
void TournerD(void);


#endif
