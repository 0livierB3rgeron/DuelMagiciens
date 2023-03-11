#pragma once

#include <string>
#include "Wand.h"
class Wizard
{
    private: 
        std::string m_name;
        int m_hp;
        int m_mana;
        int m_shield;
        Wand m_wand;
    public:
    Wizard();
    ~Wizard();
    Wizard(std::string);
    void castSpell();
    void swapWand();
};

