---
# Projet IOT - Qualité de l'air
#Rapport technique

----
Ugo CIPRIANI

Mélina DEBONO

---

# Materiel
* Carte LoRa-e5-dev
* Carte STM32
* DHT22 temperature and humidity sensor
* Grove dust sensor

# Branchement
## Entre LoRa-e5-dev et carte STM32
(Câbles F/F)
| LoRa-e5-dev | couleur du câble liant | STM32 |
|-------------------------|:-----------------------------------|:------------:|
| DIO | Bleu | SWDIO |
| CLK | Jaune | SWCLK |
| GND | Noir | GND |

## Entre LoRa-e5-dev et DHT22 
(Câbles M/F)
| LoRa-e5-dev       | couleur du câble liant | DHT22   |
|-------------------------|:-----------------------------------|:------------:|
| VCC| Rouge| VCC |
| A3 | Blanc| DAT |
| GND | Noir | GND |

## Entre LoRa-e5-dev et Grove dust sensor
(Câbles M/F)
| LoRa-e5-dev       | couleur du câble liant | Grove dust sensor  |
|-------------------------|:-----------------------------------|:------------------------------:|
| 5V| Rouge| 5V|
| D5 | Blanc| D5 |
| GND | Noir | GND |
 ---
# Pin récupération de données
##  DHT22
On a les données qui arrivent sur la pin A3, soit d'après la documentation de la carte LoRa-e5-dev, PB3, ce qui dans le code se traduit par `GPIN(PORT_B, 3)`.

##  Grove dust sensor
On a les données qui arrivent sur la pin D5, soit d'après la documentation de la carte LoRa-e5-dev, PB5, ce qui dans le code se traduit par `GPIN(PORT_B, 5)`.

---
#Lorawan
Création d'un compte sous Helium.

Création d'un device et récupération du DevEUI, AppEUI, AppKey de l'application.

Utilisation des fonctions de connexion de RIOT préfixé par 'semtech_lorawan' (Ne marchaient pas - Problème interne au GitHub RIOT/RIOTOS d’après Germain).
