#ifndef DEFINE_BERSERKER
#define DEFINE_BERSERKER
#include "Perso_base.hpp"


class Berserker : public Personnage
{
protected:
    int vie_max;
public:
    Berserker(int vie, std::string nom, int vitesse);
    void Frappe_de_base(Personnage& autre) override;
    void Frappe_amelioree(Personnage &autre) override;
    void Action_speciale(Personnage &autre) override;
    void Recevoir_degats(float degats);
};

#endif 