#include "equipement.hpp"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <iostream>

std::vector<Equipement> chargerEquipementsDepuisBDD() {
    std::vector<Equipement> equipements;
    
    try {
        //Crée un un objet driver qui va permettre de se connecter à une base de données MySQL
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        
        //Connexion au compte mySQL gràce à l'IP, le port, le nom d'utilisateur et le mot de passe 
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "safwan", "safwan"));
        //Choix de la BDD
        con->setSchema("Projet");

        
        std::unique_ptr<sql::Statement> stmt(con->createStatement());
        //Création d'une requête SQL qui récupère toutes les données de la table "Equipement" de la BDD
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT nom, type, bonusVie, bonusAttaque, bonusDefense, bonusVitesse FROM Equipements"));

            //Boucle while qui permet de lire les données de chaque colonne de la table
            while (res->next()) {
                //On récupére le nom grâce à getString dans une variable "nom"
                std::string nom = res->getString("nom");
                std::string type = res->getString("type");
                int bonusVie = res->getInt("bonusVie");
                int bonusAttaque = res->getInt("bonusAttaque");
                int bonusDefense = res->getInt("bonusDefense");
                int bonusVitesse = res->getInt("bonusVitesse");

                //On ajoute chaque données récupérées dans le vecteur créé au début du programme
                equipements.emplace_back(nom, type, bonusVie, bonusAttaque, bonusDefense, bonusVitesse);
            }

        } catch (sql::SQLException& e) {
        //Si une exception survient, un message d'erreur s'affiche
        std::cerr << "Erreur de connexion à la base de données : " << e.what() << "\n";
    }


    return equipements;
}

