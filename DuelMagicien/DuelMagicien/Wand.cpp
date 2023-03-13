#include "Wand.h"
#include"Constantes.h"
#include <stdlib.h>     
#include <time.h>
#include<iostream>


Wand::Wand()
{
	//génération d'index aléatoire pour indexer les constantes de sorts et de dommages
	srand(time(NULL));
	int rng = rand() % 2;

	m_name = spells_name[0][rng];
	m_name += " de ";
	//reroll
	srand(time(NULL));
	rng = rand() % 2;
	m_name += spells_name[1][rng];
	//reroll
	srand(time(NULL));
	rng = rand() % 2;
	m_damages[0] = spells_damage[0][rng];
	//reroll
	srand(time(NULL));
	rng = rand() % 2;
	m_damages[1] = spells_damage[1][rng];
}

std::string Wand::getStats()
{
	std::string str;
	
	str = "Nom : " + m_name;
	str += "\n";
	str += " Dommage offensif: " + std::to_string(m_damages[0]) + "; Dommage defensif: " + std::to_string(m_damages[1]);

	return str;
}

int Wand::getDamage(int index)
{
	// index 0 est les dommages offensif, index 1 est les dommages defensif
	return m_damages[index];
}
