# Dumber
Projet de TP à l'INSA. Dumber est un petit robot qui ne peut que se déplacer.


# Configuration de Keil
Dans 'Options for target, entrer 'DARMSTM.DLL' avec les paramètres '-pSTM32F103C6' dans Dialog DLL. 
Ensuite, dans les réglages du debuger, choisir 'debug under Reset', et 'HW RESET'.


# Abstract
Ce projet est développé en C sur Keil (base de projet CubeMX).  

# Liens utiles 
Pour la PWM : https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM

# Infos utiles
Pour les encodeurs: on peut utiliser directement le mode encodeur des timers. (combined channel: encoder mode dans CubeMx) (p328 du gros doc)

# Trucs Nuls
Quand on compile de CubeMX vers Keil, on perd la config du mode debug Simu
