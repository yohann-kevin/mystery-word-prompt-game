#include "jeu.h"
#include <iostream>

using namespace std;

void afficherLettresTrouvees(string_view lettres) {
    for(auto lettre : lettres) {
        cout << lettre << " ";
    }
    cout << endl;
}

void afficherPendu(int mauvaisesReponses) {
    cout << endl;
    switch(mauvaisesReponses) {
    case 11:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |   / \
                                                    |
                                                  __|__
                )" << endl;
        break;

    case 10:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |   /
                                                    |
                                                  __|__
                )" << endl;
        break;

    case 9:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|\
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 8:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |   /|
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 7:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 6:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |    o
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 5:
        cout << R"(
                                                    ______
                                                    |/   |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 4:
        cout << R"(
                                                    ______
                                                    |/
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
     case 3:
        cout << R"(
                                                    ______
                                                    |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 2:
        cout << R"(

                                                    |
                                                    |
                                                    |
                                                    |
                                                    |
                                                  __|__
                )" << endl;
        break;
    case 1:
        cout << R"(






                                                  _____
                )" << endl;
        break;
    default:
        cout << endl;
        break;
    }
    cout << endl;
}

char demanderLettre() {
    cout << "Proposez une lettre : ";
    auto lettre{'A'};
    cin >> lettre;
    return lettre;
}

bool verifierLettre(string_view mot, char lettre, string& lettresTrouvees) {
    auto lettrePresente{false};
    for(auto i{0u}; i<mot.length(); ++i) {
        if(mot[i] == lettre) {
            // On vérifie que la lettre n’était pas déjà trouvée pour ne pas incrémenter nombreLettresTrouvees à tort
            if(lettresTrouvees[i] != lettre) {
                lettresTrouvees[i] = lettre;
            }
            lettrePresente = true;
        }
    }
    return lettrePresente;
}

char passerLettreEnMajuscule(char lettre) {
    if(lettre >= 'a' && lettre <= 'z') {
        return static_cast<char>(lettre+('A'-'a'));
    }
    return '-';
}

void jouerPartie(string_view mot) {
    auto lettresTrouvees = string(mot.length(), '-');
    auto mauvaisesReponses{0};
    auto continuer{true};

    do {
        afficherLettresTrouvees(lettresTrouvees);
        auto lettre = passerLettreEnMajuscule(demanderLettre());

        auto lettrePresente = verifierLettre(mot, lettre, lettresTrouvees);
        if(!lettrePresente) {
            mauvaisesReponses++;
            afficherPendu(mauvaisesReponses);
            if(mauvaisesReponses >= NOMBRE_ETAPES_PENDU) {
                cout << "Vous avez perdu !!!" << endl;
                continuer = false;
            }
        }
        if(lettresTrouvees == mot) {
            cout << "Vous avez gagné !!!" << endl;
            continuer = false;
        }
    } while(continuer);
}
