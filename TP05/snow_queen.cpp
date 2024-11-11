#include "snow_queen.hpp"
#include <iostream>

Snow_Queen::Snow_Queen(int vie, std::string nom, int vitesse) : Personnage(vie, nom, vitesse) {}


void Snow_Queen::Frappe_de_base(Personnage& autre)
{
    //L'attaquant inflige au défenseur des dégâts égaux à l'attaque du personnage en prenant en compte sa défense 
    autre.Recevoir_degats((m_attaque * 1.25) - autre.getDefense());
    int degat = ((m_attaque * 1.25) - autre.getDefense());

    //L'énergie est augmentée de 10
    Energie(20);
    std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+20 énergie   Énergie : " << m_energie <<  std::endl;
}


    void Snow_Queen::Frappe_amelioree(Personnage& autre)
    {
        //L'attaquant inflige au défenseur des dégâts égaux à l'attaque du personnage en prenant en compte sa défense 
        autre.Recevoir_degats((m_attaque * 1.5) - autre.getDefense());
        int degat = ((m_attaque * 1.5) - autre.getDefense());

        //L'énergie est augmentée de 10
        Energie(30);
        std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+30 énergie   Énergie : " << m_energie << std::endl;
    }

        void Snow_Queen::Action_speciale(Personnage &autre)
        {
            if (m_energie == 100)
            {
                //L'attaquant inflige des dégâts égaux à 3.5 x l'attaque du personnage en prenant en compte sa défense
                autre.Recevoir_degats((m_attaque * 1.75) - autre.getDefense());
                int degat = ((m_attaque * 1.75) - autre.getDefense());

                //Toute l'énergie est utilisée pour l'attaque
                Energie(-100);        
                std::cout << "\n\nAttaque spéciale " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "-100 énergie   Énergie : " << m_energie <<  std::endl;
            }
            
                else
                {
                    std::cout << "\n\nL'énergie n'est pas suffisante " << std::endl;
                    return;
                }
        }