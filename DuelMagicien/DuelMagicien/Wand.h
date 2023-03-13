#pragma once
#include<string>
class Wand
{
private:
	std::string m_name;
	int m_damages[2];
public:
	/**
	* Constructeur par d�faut
	*/
	Wand();
	/**
	* @return les statistique de la baguette, nom + dommage r�partit sur attque et d�fense
	*/
	std::string getStats();
	/**
	* @return uniquement les dommages offendifs ou d�fensif selon l'index.
	* @param index du tableau de dommages.
	*/
	int getDamage(int);
};

