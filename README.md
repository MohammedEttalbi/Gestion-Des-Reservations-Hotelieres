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


![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/3ccd3e92-aaa3-4f16-8e3a-31a48ee7481a)

## ________________________________________________________________________________________________________________________________________

![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/a577e342-1834-4483-bc88-4b37c0b36722)

## ________________________________________________________________________________________________________________________________________


![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/87999958-9b69-4b5d-ba34-b60e6132f82e)


## ________________________________________________________________________________________________________________________________________


![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/11400245-d231-4857-a98e-1335dc71dac0)


## ________________________________________________________________________________________________________________________________________


![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/7ac02edf-8b8d-430a-9410-20fbb8f53200)


## ________________________________________________________________________________________________________________________________________


![image](https://github.com/MohammedEttalbi/Gestion-Des-Reservations-Hotelieres/assets/127549207/18cb004e-33d5-4e11-ae9c-7d9acc1268fc)




