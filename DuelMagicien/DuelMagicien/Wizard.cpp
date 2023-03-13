#include "Wizard.h"
#include "Wand.h"
#include "Constantes.h"
#include <iostream>
#include <string>

using namespace std;

Wizard::Wizard()
{
    // sors un nom aleatoire dans le tableau de nom de magicien
    srand(time(NULL));
    int rng = rand() % 10;
    m_name = nom_magicien[rng];
    // Attribut par defaut
    m_hp = 50;
    m_mana = 50;
    m_shield = 0;
    m_wand = Wand::Wand();
}

Wizard::Wizard(std::string nom)
{
    m_name = nom;
    m_hp = 50;
    m_mana = 50;
    m_shield = 0;
    m_wand = Wand::Wand();
}

void Wizard::swapWand()
{
    m_wand = Wand::Wand();
    std::cout << "La baguette a ete changer." << std::endl;
}

bool Wizard::alive()
{
    if (m_hp <= 0)
    {
        return false;
    }
    return true;
}

void Wizard::takeDamage(int damage)
{
    if (damage > 0)
    {
        if (m_shield > 0)
        {
            m_shield -= damage;
            if (m_shield < 0)
            {
                m_hp += m_shield;
                m_shield = 0;
            }
        }
        else
        {
            m_hp -= damage;
        }
    }
    else
    {
        m_hp -= damage;
    }
}

int Wizard::attack()
{
    return m_wand.getDamage(0);
}

void Wizard::defend()
{
    if(m_wand.getDamage(1) > 0)
    {
        // Si negatif, on ajoute des points de vie
        m_hp -= m_wand.getDamage(1);
    }
    else
    {
        // Si positif, on ajout au bouclier
        m_shield += m_wand.getDamage(1);
    }
}



void Wizard::getStats()
{
    std::cout << "Nom du magicien : " << m_name << std::endl;
    std::cout << "Points de vie : " << m_hp << std::endl;
    std::cout << "Points de mana : " << m_mana << std::endl;
    std::cout << "Points de bouclier : " << m_shield << std::endl;
    std::cout << "Baguette : " << m_wand.getStats() << std::endl;
    std::cout << "===============================================" << std::endl;
}

int Wizard::getMana()
{
    return m_mana;
}
