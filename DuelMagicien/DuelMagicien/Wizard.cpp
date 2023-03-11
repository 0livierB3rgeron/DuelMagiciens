#include "Wizard.h"
#include "Wand.h"
#include "Constantes.h"
#include <iostream>
#include <string>
using namespace std;

Wizard::Wizard()
{
    // sors un nom aleatoire dans le tableau de nom de magicien
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
Wizard::~Wizard() {}

void Wizard::castSpell()
{
    int damage{0};
    if (m_mana < 10)
    {
        swapWand();
        return;
    }
    // random between 0 and 1
    int rng = rand() % 2;
    if (rng == 0)
    {
        std::cout << "Vous avez utilisez une attaque offensive." << std::endl;
    }
    else
    {
        std::cout << "Vous avez utilisez une attaque defensive." << std::endl;
    }
    damage = m_wand.getDamage(rng);
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
