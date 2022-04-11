---
# Projet IOT - Qualité de l'air
# Vie privée et sécurité

----

Mélina DEBONO

---

#Les menaces
| Menace | Solution |
|-------------------|:----------------:|
| Accès non autorisé | Authentification mutuelle des end-point |
| Usurpation d'identité  | Authentification de l'origine des données |
| Usurpation d'identité |Protection contre la relecture|
| Modification  | Protection de l'intégrité |
| Écoute clandestine | Chiffrement|

# LoRaWAN 
LoRaWAN  utilise la cryptographie à clé symétrique. Les clés racine sont utilisées pour dériver les clés de session à la fois pour l'authentification au niveau des paquets et le chiffrement des end-point. Cela signifie qu'une clé racine stockée dans un capteur doit également être mise à la disposition du réseau afin de générer des clés de session.

# OTAA
OTAA ( Over the Air Activation) génère de manière dynamique des clés de session à part ir de clés racine.

Pour l'OTAA, chaque dispositif LoRaWAN a besoin d'un identifiant d'application (AppEUI), d'un identifiant de dispositif (DevEUI) et d'une clé d'application secrète (AppKey). 


# Conseils: 
- Générer les clefs de manière aléatoire et par appareil, livrées et stockées en toute sécurité.
- Ne pas utiliser de DevEUI arbitraires (respectez les OUI de l'IEEE).
- Ne pas utiliser de JoinEUI/AppEUI arbitraire
- Utiliser un système d'exploitation et une sécurité matérielle de confiance pour les applications sensibles.
- Assurer la sécurité du système de bout en bout, sur toute la pile.



# Notre application
Comme elle n'envoie actuellement aucune donnée, nous n'avons aucun problème de sécurité.
Cependant, nous avons respecté les conseils ci-dessus et laissé soin à Helium de généré les clefs pour nous.
Notons que avec Helium, nous aurions utilisé la connection OTAA.


# Sources:
<https://www.actility.com/wp-content/uploads/2019/01/lorawan-security-webinar-190116093900.pdf>

<https://www.onethinx.com/Content/downloads/002-24026_Web.pdf>

<https://www.thethingsnetwork.org/forum/t/registration-of-node-with-pre-configured-lorawan-keys/8716>