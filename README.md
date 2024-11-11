# Jeu de Combat en Tour par Tour

Ce projet est un programme de jeu de combat en tour par tour en C++. Le jeu permet de simuler des combats entre plusieurs personnages, chacun ayant des caractéristiques propres et un équipement spécifique. Le but est de faire en sorte qu'un seul personnage reste en vie.

## Description du Code

Le programme inclut plusieurs fichiers et classes pour structurer le jeu :
- **Classes principales** :
  - `Personnage` : la classe de base pour les personnages.
  - `Berserker` et `Snow_Queen` : des sous-classes de `Personnage`, avec des capacités et caractéristiques uniques.
- **Classes d'équipement** :
  - `Equipement` : classe pour gérer les équipements (comme les heaumes, gilets, gants, bottes, etc.), stockés dans une base de données simulée.
- **Base de données** :
  - `BDD` : classe qui permet de se connecter à une base de données contenant les différents équipements disponibles.

## Fonctionnalités

Le programme suit une structure en tour par tour où chaque personnage attaque les autres jusqu'à ce qu'un seul reste en vie :

1. **Chargement des Équipements** :
   - Les équipements sont chargés depuis une base de données et attribués aux personnages.

2. **Tour de Combat** :
   - À chaque tour, le personnage ayant la plus grande vitesse commence l’attaque.
   - Chaque personnage choisit une cible et peut utiliser différentes attaques :
     - **Frappe de base** : attaque standard.
     - **Frappe améliorée** : attaque avec plus de puissance.
     - **Action spéciale** : attaque spéciale unique pour chaque type de personnage qui requiert 100 points d'énergie pour être lancéé

3. **Gestion des Points de Vie** :
   - Le combat se termine quand un seul personnage est encore en vie.

4. **Libération de la Mémoire** :
   - À la fin du programme, la mémoire allouée aux objets `Personnage` est libérée pour éviter les fuites de mémoire.

## Structure du Projet

- `main.cpp` : fichier principal qui exécute le jeu de combat.
- `Perso_base.hpp`, `Perso_base.cpp` : classe de base des personnages.
- `Berserker.hpp`, `Berserker.cpp` : classe dérivée `Berserker`.
- `snow_queen.hpp`, `snow_queen.cpp` : classe dérivée `Snow_Queen`.
- `equipement.hpp` : définit les caractéristiques des équipements.
- `BDD.hpp`, `BDD.cpp` : Connnexion à la base de données d'équipements.
  - Dans le fichier `BDD.cpp` changer les informations du compte mySQL 

## Exécution

1. **Compiler le code** :
  - Avant de compiler changer les informations du compte mySQL dans le fichier `BDD.cpp` à la ligne 16
  - g++ Main.cpp -o Main -lmysqlcppconn
