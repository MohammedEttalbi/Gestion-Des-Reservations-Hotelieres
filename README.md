# Gestion de Réservation Hôtelière en C

## Introduction

Ce projet en langage C propose une application de gestion de réservation hôtelière. Elle permet de gérer les clients, les chambres et les réservations d'un hôtel. La présentation offre un aperçu des fonctionnalités implémentées, des règles de gestion, des structures de données et des captures d'écran.

## Technologies utilisées

- **Langage C :** Efficace et rapide, offrant un contrôle de bas niveau sur les ressources matérielles.
- **Structures de données :** Utilisation de listes doublement chaînées pour une gestion flexible des informations.
- **Fichiers :** Stockage permanent des données pour assurer la persistance même après la fermeture de l'application.
- **Bibliothèques :** <stdio.h>, <stdlib.h>, <string.h>, <time.h>, "fonctions.h", "conio2.h".

## Structures utilisées

### Structure « Client »
- id_client, nom, prenom, cin, tel.

### Structure « Chambre »
- num_chambre, type_chambre, prix.

### Structure « Reservation »
- id_reservation, date_reservation, nb_nuit, debut_sejour, fin_sejour, montant_avance, id_client, num_chambre.

## Fonctionnalités implémentées

- Gestion des clients, chambres et réservations.
- Navigation et manipulation des entités.
- Affichage des réservations en cours.
- Génération de factures pour les réservations.

## Comment utiliser

1. Clonez le dépôt : `git clone https://github.com/votre-utilisateur/votre-projet.git`
2. Compilez le programme : `gcc main.c -o gestion_hoteliere -std=c11`
3. Exécutez le programme : `./gestion_hoteliere`

---
![Captures d'écran de l'application]

![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/f72f4e5c-f080-4e8e-b2eb-7a7bd6d62f1c)


![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/edafb96f-dce1-41fd-81b8-67be579f5563)


![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/935c9a57-b6ce-4f2d-ad31-5ef234572169)


![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/5c9a1c49-f835-4c9d-ab2d-77ca5890e925)


![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/78ef213d-62eb-4bfb-b095-259cdb055c3d)


![image](https://github.com/MohammedEttalbi/gestion-des-r-servations-h-teli-res/assets/127549207/7358cc18-5bd5-481a-91ce-358f54c6d2d8)



