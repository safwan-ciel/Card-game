#ifndef DEFINE_EQUIPEMENT
#define DEFINE_EQUIPEMENT
#include <string>

class Equipement {
public:
    std::string nom;
    std::string type;     
    int bonusVie;
    int bonusAttaque;
    int bonusDefense;
    int bonusVitesse;

    // Constructeur pour initialiser les bonus de l'équipement
    Equipement(const std::string& nom, const std::string& type, int vie, int attaque, int defense, int vitesse)
        : nom(nom), type(type), bonusVie(vie), bonusAttaque(attaque), bonusDefense(defense), bonusVitesse(vitesse) {}
};

#endif