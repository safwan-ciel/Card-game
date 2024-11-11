#include "Perso_base.hpp"
#include <iostream>

//Constructeur qui initialise les attributs et intialise à null les pointeurs de la classe Equuipement
Personnage::Personnage(int vie, std::string nom, int vitesse) : pt_de_vie(vie), m_nom(nom), m_vitesse(vitesse), m_attaque(200), m_defense(100), m_energie(50){}


        void Personnage::Frappe_de_base(Personnage &autre)
        {
            //L'attaquant inflige au défenseur des dégâts égaux à l'attaque du personnage en prenant en compte sa défense 
            autre.Recevoir_degats(m_attaque - autre.m_defense);
            int degat = (m_attaque - autre.m_defense);

            //L'énergie est augmentée de 10
            Energie(10);
            std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+10 énergie   Énergie : " << m_energie <<  std::endl;
        }

        
            void Personnage::Frappe_amelioree(Personnage &autre)
            {
                //L'attaquant inflige des dégâts égaux à 1.5 x l'attaque du personnage en prenant en compte sa défense 
                autre.Recevoir_degats((m_attaque * 1.5) - autre.m_defense);
                int degat = (m_attaque * 1.5 - autre.m_defense);

                //L'énergie est augmentée de 15
                Energie(15);
                std::cout << "\n\nAttaque " << "de " << m_nom << "  dégâts infligés : " << degat << std::endl << "+15 énergie   Énergie : " << m_energie <<  std::endl;
            }


                void Personnage::Action_speciale(Personnage &autre)
                {
                    if (m_energie == 100)
                    {
                        //L'attaquant inflige des dégâts égaux à 3.5 x l'attaque du personnage en prenant en compte sa défense
                        autre.Recevoir_degats((m_attaque * 3.5) - autre.m_defense);
                        int degat = ((m_attaque * 3.5) - autre.m_defense);

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


                    void Personnage::Recevoir_degats(float degats)
                    {
                        pt_de_vie -= degats;
                    }

                        void Personnage::Afficher() const
                        {
                            if (pt_de_vie > 0)
                            {
                                std::cout << "\nPv "<< ": " << pt_de_vie << " | Énergie " << ": " << m_energie << std::endl;   
                            }
                            
                        }

                    //Augmente l'énergie sans pouvoir dépasser 100
                    void Personnage::Energie(int energie)
                    {
                        if (m_energie + energie >= 100)
                        {
                            m_energie = 100;
                        }
                            else
                            {
                                m_energie += energie;
                            }
                    }

                int Personnage::getVie() const
                {
                    return pt_de_vie;
                }
                
            int Personnage::getDefense()
            {
                return m_defense;
            }

        int Personnage::getVitesse() const
        {
            return m_vitesse;
        }

    std::string Personnage::getNom() const
    {
        return m_nom;
    }
    
//Verfie si le personnage est toujours vivant
bool Personnage::estEnVie() const
{
   return pt_de_vie > 0;
}

    void Personnage::ajouterEquipement(Equipement* equipement) {
        if (equipement) {
            //Les bonus de l'équipement sont ajoutés aux statistiques du personnage
            pt_de_vie += equipement->bonusVie;
            m_attaque += equipement->bonusAttaque;
            m_defense += equipement->bonusDefense;
            m_vitesse += equipement->bonusVitesse;
        }
    }
