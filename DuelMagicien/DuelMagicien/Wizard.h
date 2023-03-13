#pragma once

#include <string>
#include "Wand.h"
class Wizard
{
    private: 
        //Attributs
        std::string m_name; //Nom du magicien
        int m_hp; //Points de vie
        int m_mana; //Points de mana
        int m_shield; //Points de bouclier
        Wand m_wand; //Baguette du magicien
    public:
    /**
     * @brief Constructeur par défaut
     */
    Wizard();
     /**
     * @brief Constructeur par paramètre
     * @param nom Nom du magicien
     */
    Wizard(std::string);
    /**
     * @brief Change de baguette
     * detruit l'ancienne et en crée une nouvelle
     */
    void swapWand();
    /**
     * @brief Verifie que le magicien est en vie
     * @return Vrai si le magicien est en vie
     */
    bool alive();
    /**
     * @brief Enleve des points de vie au magicien ou modifie son bouclier
     */
    void takeDamage(int);

    /**
     * @brief Dommage du sort de notre attaque.
     * @return int Dommage de l'attaque
     */
    int attack();
    /**
     * @brief ajoute des points au bouclier
     */
    void defend();

    /**
     * @brief Affiche les statistiques du magicien
     */
    void getStats();
    /**
    * @brief Retourne le nombre de mana du magicien
    */
    int getMana();
};

