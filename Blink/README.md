# TP Blink

Ce fichier contient mon compte rendu du TP Blink consistant à découvrir le langage Arduino à travers la mise en oeuvre du clignotement du LED sur une carte Arduino Uno

## Premiers pas

### Initialisation

Dans un premier temps, on utilise la fonction
```C++
    void pinMode(uint8_t pin, uint8_t mode)
```

dans la fonction setup() pour initialiser les paramètres du système: on utilise les variable LED_BUILTIN et OUTPUT afin de préciser que l'on travaillera sur le PIN 13 qui sera initialisé à 1.
En effet, d'après la documentation, la constante LED_BUILTIN fait référence au PIN 13 associé à la LED à faire clignoter. La constante OUTPUT fait référence à la valeur 1, valeur associé aux bits des PINs utilisés comme ouptut.

### Implémentation du système

Une fois le système initialisé, on complète la fonction loop() pour définir le fonctionnement du système: 

* on utilise la fonction void digitalWrite(uint8_t pin, uint8_t val) avec les paramètres LED_BUITLIN (pour spécifier qu'on agit bien sur le PIN 13) et HIGH (correspondant à la valeur 1) pour allumer la LED. En effet, la documentation nous précise qu'allumer la LED revient à activer le PIN correspondant, i.e. placer le bit correspondant à la valeur 1.

* on utilise la fonction void delay(unsigned long ms) pour définir le temps à écouler avant de passer à l'étape suivante: l'extincion de la LED.

* pour éteindre la LED, la méthode est la même que pour l'allumage sauf que la valeur passée avec le PIN 13 est LOW (constante valant 0) pour placer le bit correspondant à 0 afin de spécifier l'extinction de la LED

* on réutilise ensuite la fonction delay pour maintenir la LED éteinte à la fin de la boucle


## Appropriation des fonctions

Dans un second temps, nous allons essayer d'utiliser un maximum de fonctions personnelles pour remplacer les fonctions définies par Arduino.

### Initialisation

Nous allons définir une fonction
```C++
void led_setup()
```

qui permettra de remplacer la fonction
```C++
void pinMode(uint8_t pin, uint8_t mode)
```

Pour remplacer la fonction pinMode() tel que nous l'utilisons, nous devons interagir avec le pin 13 de la carte. D'après le pinout de la carte Arduino Uno, celle-ci appartient au port B et d'après la documentation elle est identifiée par le 5ème bit de ce port.
La fonction pinMode se charge d'activer le bit renseigné dans l'état demandé. Pour utiliser le pin 13 comme sortie, on va donc chercher à placer le 5ème bit du port B à 1.

```C++
void led_setup(){
  DDRB |= (1<<5); 
}
```

On met le 5ème bit du registre de donnée B à 1 en effectuant un décalage de 5 à gauche sur 1 (00000001 -> 00100000) sur le registre DDRB.

### Implémentation de la boucle

Maintenant que nous avons paramétré le pin 13 (5ème bit du port B) comme sortie (à 1), nous allons remplacer les fonctions de la boucle d'exécution en déclanchant le bit correspondant via deux fonction led_on() et led_off() qui remplaceront les appels à digitalWrite.

La fonction led_on() aura pour but d'allumer la LED. Pour se faire, on se réfère à la documentation qui nous précise que le pin correspondant (13) est accessible au 5ème bit du port B qu'on va donc placer à 1 pour HIGH.

```C++
void led_on(){
  PORTB |= (1<<5);
}
```

La fonction led_off() devra éteindre la LED.

```C++
void led_off(){
  PORTB &= ~(1<<5); //remise à 0 du bit 5
                    // 00100000 & ~(00100000) -> 00100000 & 11011111 
                    //                        -> 00000000
}
```

On définit la constante
```C++
#define LED_MASK (1<<5)
```