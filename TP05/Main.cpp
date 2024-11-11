#include "Perso_base.hpp"
#include "Berserker.hpp"
#include "snow_queen.hpp"
#include "Perso_base.cpp"
#include "Berserker.cpp"
#include "snow_queen.cpp"
#include "equipement.hpp"
#include "BDD.cpp"
#include "BDD.hpp"
#include <iostream>
#include <string>

// Trouver l'indice du personnage avec la plus grande vitesse
int trouverIndicePlusRapide(Personnage* personnages[], int taille) {
    int indicePlusRapide = 0;
    for (int i = 1; i < taille; ++i) {
        if (personnages[i]->getVitesse() > personnages[indicePlusRapide]->getVitesse()) {
            indicePlusRapide = i;
        }
    }
    return indicePlusRapide;
}
int trouverIndicePlusRapide(Personnage* personnages[], int taille);


int main() 
{

    std::vector<Equipement> equipements = chargerEquipementsDepuisBDD();

        // Tableau de pointeurs qui pointent vers les personnages
        Personnage* Personnages[3] = {
            new Personnage(1000, "Personnage1", 15),
            new Berserker(1200, "Berserker1", 10),
            new Snow_Queen(800, "Snow_Queen1", 20)
        };

//Pour chaque personnage du tableau
for (int i = 0; i < 3; i++)
{
    // Chercher un équipement dans les équipements chargés depuis la BDD 
    for (auto& equip : equipements) {
        if (equip.type == "Heaume" ) {
            Personnages[i]->ajouterEquipement(&equip);  // Premier heaume trouvé
        } else if (equip.type == "Gilet" ) {
            Personnages[i]->ajouterEquipement(&equip);  // Premier gilet trouvé
        } else if (equip.type == "Gants" ) {
            Personnages[i]->ajouterEquipement(&equip);  // Premiers gants trouvés
        } else if (equip.type == "Bottes" ) {
            Personnages[i]->ajouterEquipement(&equip);  // Premières bottes trouvées
        } else if (equip.type == "Arme" ) {
            Personnages[i]->ajouterEquipement(&equip);  // Premières bottes trouvées
        } 
    }
    
}

        // Trouver le personnage avec la plus grande vitesse
        int indice_premier = trouverIndicePlusRapide(Personnages, 3);
            std::cout << "Le personnage avec la plus grande vitesse est : "<< Personnages[indice_premier]->getNom() <<"\n";
            int tour = indice_premier;


    bool combatEnCours = true;
    int choix;
    // Boucle de combat en tour par tour
    while (combatEnCours) {

    // Pointeur vers le personnage qui attaque au tour actuel
    Personnage* attaquant = Personnages[tour % 3];

    // Vérifier si l'attaquant est en vie
    if (attaquant->estEnVie()) {
        // Choisir une cible différente de l'attaquant
        for (int i = 0; i < 3; i++) {
            if (Personnages[i] != attaquant && Personnages[i]->estEnVie()) {

                //Affiche le personnage attaquant
                std::cout << "\n\n" << attaquant->getNom() << " attaque " << Personnages[i]->getNom() ; 
                attaquant->Afficher();

                std::cin >> choix;

                //Choix des attaques
                switch (choix) {
                    case 1:
                        attaquant->Frappe_de_base(*Personnages[i]);
                        break;
                    case 2:
                        attaquant->Frappe_amelioree(*Personnages[i]);
                        break;
                    case 3:
                        attaquant->Action_speciale(*Personnages[i]);
                        attaquant->Afficher();
                        break;
                    default:
                        std::cout << "Choix invalide" << std::endl;
                        break;
                }
                break;      // Sortir de la boucle dès qu'une cible est trouvée
            }
        }
    }
    // Passer au personnage suivant
        tour ++;
    
        // Compter les personnages en vie
        int survivants = 0;
        for (int i = 0; i < 3; i++) {
            if (Personnages[i]->estEnVie()) survivants++;
        }


        // Si un seul personnage reste en vie, le combat est terminé
        if (survivants <= 1) {
            combatEnCours = false;
            for (int i = 0; i < 3; i++) {
                if (Personnages[i]->estEnVie()) {
                    std::cout << Personnages[i]->getNom() << " est le dernier en vie !\n";
                }
            }
        }

 }
    // Libérer la mémoire allouée par le tableau
    for (int i = 0; i < 3; i++) {
            delete Personnages[i];
        }

    return 0; 
} 



