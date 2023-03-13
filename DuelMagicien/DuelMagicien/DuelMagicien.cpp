#include <iostream>
#include"Wand.h";
#include"Wizard.h";
#include<string>

void jouerTourJoueur(Wizard& joueur, Wizard& cpu) {
    
    int input = 0;
    
    while (input == 0 || input > 2) {
        std::cout << "appuyer sur 1 pour attaquer et 2 pour vous defendre." << std::endl;
        std::cin >> input;
    }

    //Faire un check sur la mana pour le swich de wand
    if (joueur.getMana() < 10) {
        std::cout << "Niveau de mana trop bas pour lancer un sors, vous changerez de baguette" << std::endl;
        joueur.swapWand();
    }
    else {
        if (input==1)
        {
            std::cout << "Vous attaquer l'adversaire!" << std::endl;
            cpu.takeDamage(joueur.attack());
        }
        else
        {
            std::cout << "Vous vous defendez" << std::endl;
            joueur.defend();
        }
    }

}

void jouerTourCPU(Wizard& cpu, Wizard& joueur) {
    
    //génération d'un chiffre aléatoire pour simuler le tour du CPU
    srand(time(NULL));
    int input = rand() % 2;

    //un check sur la mana pour switch de wand
    if (cpu.getMana() < 10) {
        
        std::cout << "L'adversaire change de baguette!" << std::endl;
        cpu.swapWand();
    }
    else {
        if (input==1)
        {
            std::cout << "L'adversaire attaque!" << std::endl;
            joueur.takeDamage(cpu.attack());
            
        }
        else
        {
            std::cout << "L'adversaire se défend" << std::endl;
            cpu.defend();
        }
    }
}

int main()
{
    Wizard ennemi;
    std::string nom;
    std::cout << "Entrez votre nom: ";
    std::cin >> nom;
    Wizard joueur(nom);

    //génération d'un nombre aléatoire pour savoir qui jouera en premier.
    srand(time(NULL));
    int premierJoueur = rand() % 2;
    while (joueur.alive() && ennemi.alive()) // tant que les 2 magiciens sont en vie.
    {
        //Stats des personnages
        std::cout << "Joueur:" << std::endl;
        joueur.getStats();
        std::cout << "Ennemie:" << std::endl;
        ennemi.getStats();
        //fin stats personnages.

        //si premier joueur on joue le tour.
        // C'est juste l'ordre du tour qui change ici.
        if (premierJoueur == 1) {
            jouerTourJoueur(joueur, ennemi);
            jouerTourCPU(ennemi, joueur);

        }
        else {
            jouerTourCPU(ennemi, joueur);

            jouerTourJoueur(joueur, ennemi);

        }
        system("cls");
    }
    if (!ennemi.alive()) {
        system("cls");
        std::cout << "Felicitation vous avez gagner le duel" << std::endl;
    }
    else if (!joueur.alive())
    {
        system("cls");
        std::cout << "Le magicien ennemi vous a demoli, YIKES" << std::endl;
    }

}