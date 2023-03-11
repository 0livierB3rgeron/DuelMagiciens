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
     * @brief Destructeur par défaut
     */
    ~Wizard();
    /**
     * @brief Lance un sort
     * @return Dommage infligé
     */
    int castSpell();
    /**
     * @brief Change de baguette
     * detruit l'ancienne et en crée une nouvelle
     */
    void swapWand();
};

