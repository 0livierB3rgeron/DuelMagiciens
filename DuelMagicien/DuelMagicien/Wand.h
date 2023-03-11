#pragma once
#include<string>
class Wand
{
private:
	std::string m_name;
	int m_damages[2];
	std::string description;
public:
	Wand();
	std::string getStats();
};

