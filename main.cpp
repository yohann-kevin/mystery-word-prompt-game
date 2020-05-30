#include <iostream>
#include <random>
#include "jeu.h"

#include "motsPossibles.h"

using namespace std;

int main()
{
    auto generateurAleatoire = std::random_device{};
    auto generateur = std::mt19937{generateurAleatoire()};
    auto distribution = std::uniform_int_distribution{0, TAILLE_MOTS_POSSIBLES-1};

    cout << "Bienvenue au jeu du pendu !" << endl;
    auto mot = motsPossibles[distribution(generateur)];
    jouerPartie(mot);

    return 0;
}
