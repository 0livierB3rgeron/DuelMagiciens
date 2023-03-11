// DuelMagicien.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"Wand.h";
#include"Wizard.h";
#include<string>
#include <stdlib.h>     
#include <time.h>

int main()
{
    Wizard ennemi;
    std::string nom;
    std::cout << "Entrez votre nom: ";
    std::cin >> nom;
    Wizard joueur(nom);
    while (joueur.alive() && ennemi.alive()) // tant que les 2 magiciens sont en vie.
    {
        //Stats des personnages
        std::cout << "Joueur:" << std::endl;
        joueur.getStats();
        std::cout << "Ennemie:" << std::endl;
        ennemi.getStats();
        //fin stats personnages.
        
    }
}

    