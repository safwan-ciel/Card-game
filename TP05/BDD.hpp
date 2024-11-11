#ifndef DEFINE_BDD
#define DEFINE_BDD

#include <vector>
#include "equipement.hpp"

// Fonction pour charger les équipements depuis la base de données et qui retourne un vecteur de type Equipement
std::vector<Equipement> chargerEquipementsDepuisBDD();

#endif // !DEFINE_BDD