#ifndef DEFINE_SNOW_QUEEN
#define DEFINE_SNOW_QUEEN
#include "Berserker.hpp"


class Snow_Queen : public Personnage
{
protected:
public:
    Snow_Queen(int vie, std::string nom, int vitesse);
    void Frappe_de_base(Personnage& autre) override;
    void Frappe_amelioree(Personnage &autre) override;
    void Action_speciale(Personnage &autre) override;
    void Recevoir_degats(float degats);
};
#endif 