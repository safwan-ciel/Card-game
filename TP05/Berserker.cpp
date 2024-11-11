#include "Berserker.hpp"
#include <iostream>

Berserker::Berserker(int vie, std::string nom, int vitesse) : Personnage(vie, nom, vitesse), vie_max(1550) {}


void Berserker::Frappe_de_base(Personnage& autre) 
{
        //L'attaquant inflige au défenseur des dégâts égaux à l'attaque du personnage en prenant en compte sa défense 
        autre.Recevoir_degats((vie_max * 0.3) - autre.getDefense());
        int degat = ((vie_max * 0.3) - autre.getDefense());
        pt_de_vie = pt_de_vie * 0.9;
        //L'énergie est augmentée de 10
        Energie(20);
        std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+20 énergie   Énergie : " << m_energie <<  std::endl;
}

    void Berserker::Frappe_amelioree(Personnage& autre)
    {
         //L'attaquant inflige au défenseur des dégâts égaux à l'attaque du personnage en prenant en compte sa défense 
        autre.Recevoir_degats((vie_max * 0.5) - autre.getDefense());
        int degat = ((vie_max * 0.5) - autre.getDefense());
        pt_de_vie = pt_de_vie * 0.85;
        //L'énergie est augmentée de 10
        Energie(30);
        std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+30 énergie   Énergie : " << m_energie <<  std::endl;
    }

        void Berserker::Action_speciale(Personnage& autre)
        {
            if (m_energie == 100)
            {
                //L'attaquant inflige des dégâts égaux à 3.5 x l'attaque du personnage en prenant en compte sa défense
                autre.Recevoir_degats((vie_max * 0.75) - autre.getDefense());
                int degat = ((vie_max * 0.75) - autre.getDefense());

                //Toute l'énergie est utilisée pour l'attaque
                Energie(-100);        
                std::cout << "\n\nAttaque spéciale " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "-100 énergie   Énergie : " << m_energie <<  std::endl;
                pt_de_vie = pt_de_vie * 1.5;
            }
            
                else
                {
                    std::cout << "\n\nL'énergie n'est pas suffisante " << std::endl;
                    return;
                } 
        }
