# TP Blink

Ce fichier contient mon compte rendu du TP Blink consistant à découvrir le langage Arduino à travers la mise en oeuvre du clignotement du LED sur une carte Arduino Uno

## Premiers pas

### Initialisation

Dans un premier temps, on utilise la fonction


    void pinMode(uint8_t pin, uint8_t mode)

dans la fonction setup() pour initialiser les paramètres du système: on utilise les variable LED_BUILTIN et OUTPUT afin de préciser que l'on travaillera sur le PIN 13 qui sera initialisé à 1.
En effet, d'après la documentation, la constante LED_BUILTIN fait référence au PIN 13 associé à la LED à faire clignoter. La constante OUTPUT fait référence à la valeur 1, valeur associé aux bits des PINs utilisés comme ouptut.

### Implémentation du système

Une fois le système initialisé, on complète la fonction loop() pour définir le fonctionnement du système: 

* on utilise la fonction void digitalWrite(uint8_t pin, uint8_t val) avec les paramètres LED_BUITLIN (pour spécifier qu'on agit bien sur le PIN 13) et HIGH (correspondant à la valeur 1) pour allumer la LED. En effet, la documentation nous précise qu'allumer la LED revient à activer le PIN correspondant, i.e. placer le bit correspondant à la valeur 1.

* on utilise la fonction void delay(unsigned long ms) pour définir le temps à écouler avant de passer à l'étape suivante: l'extincion de la LED.

* pour éteindre la LED, la méthode est la même que pour l'allumage sauf que la valeur passée avec le PIN 13 est LOW (constante valant 0) pour placer le bit correspondant à 0 afin de spécifier l'extinction de la LED

* on réutilise ensuite la fonction delay pour maintenir la LED éteinte à la fin de la boucle


##