#include "Wizard.h"
#include "Wand.h"
#include "Constantes.h"
#include <iostream>
#include <string>
using namespace std;


Wizard::Wizard(){
    //sors un nom aleatoire dans le tableau de nom de magicien
    int rng = rand() % 10;
    m_name = nom_magicien[rng];
    //Attribut par defaut
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

int Wizard::castSpell()
{
    int damage{ 0 };
    if (m_mana < 10) {
        swapWand();
        return;
    }
    //random between 0 and 1
    int rng = rand() % 2;
    if(rng == 0){
        std::cout << "Vous avez utilisez une attaque offensive." << std::endl;
    }
    else
    {
        std::cout << "Vous avez utilisez une attaque defensive." << std::endl;
    }
    damage = m_wand.get_damage(rng); // A implementer
    return damage;
}

void Wizard::swapWand()
{
    m_wand = Wand::Wand();
    std::cout << "La baguette a ete changer." << std::endl;
}