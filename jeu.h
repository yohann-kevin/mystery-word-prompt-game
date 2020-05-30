#ifndef JEU_H
#define JEU_H

#include <string_view>

const auto NOMBRE_ETAPES_PENDU{11};

void afficherLettresTrouvees(std::string_view lettres);
void afficherPendu(int mauvaisesReponses);
char demanderLettre();
bool verifierLettre(std::string_view mot, char lettre, std::string& lettresTrouvees);
char passerLettreEnMajuscule(char lettre);
void jouerPartie(std::string_view mot);

#endif // JEU_H
