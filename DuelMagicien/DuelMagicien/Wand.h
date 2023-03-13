#pragma once
#include<string>
class Wand
{
private:
	std::string m_name;
	int m_damages[2];
public:
	/**
	* Constructeur par défaut
	*/
	Wand();
	/**
	* @return les statistique de la baguette, nom + dommage répartit sur attque et défense
	*/
	std::string getStats();
	/**
	* @return uniquement les dommages offendifs ou défensif selon l'index.
	* @param index du tableau de dommages.
	*/
	int getDamage(int);
};

