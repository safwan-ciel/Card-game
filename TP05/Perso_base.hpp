#ifndef DEFINE_EX1
#define DEFINE_EX1
#include <string>
#include "equipement.hpp"

class Personnage
{
protected:
    int pt_de_vie;
    float m_attaque, m_defense, m_vitesse;
    int m_energie;
    std::string m_nom;
public:
    Personnage(int vie, std::string nom, int vitesse);

    int getVie() const;             //
    int getDefense();               //  Accesseurs vers les attributs pt_de_vie, m_defense, m_vitesse, m_nom
    int getVitesse() const;         //
    std::string getNom() const;     //

        virtual void Frappe_de_base(Personnage &autre);     //
        virtual void Frappe_amelioree(Personnage &autre);   //  Méthodes virtuelles des différentes attaques
        virtual void Action_speciale(Personnage &autre);    //
        
        void Recevoir_degats(float degats);
        void Afficher() const;
        void Energie(int energie);
        bool estEnVie() const;
        void ajouterEquipement(Equipement* equipement);

};


#endif // !DEFINE_EX1