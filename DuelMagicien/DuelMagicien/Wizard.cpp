#include "Wizard.h"
#include "Wand.h"
#include <iostream>
#include <string>
using namespace std;


Wizard::Wizard(){
    m_name = "Gandalf";
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

Wizard::~Wizard(){}

Wizard::castSpell(){
    if(m_mana > 10){
        m_mana -= 10;
        //Implementer le sort.
    }
    else{
        swapWand();
    }
}

Wizard::swapWand(){
    m_wand = Wand::Wand();
}
