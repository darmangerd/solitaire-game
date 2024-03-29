/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : affichage.cpp
 Auteur(s)   : Melvin Merk, David Darmanger, Rébecca Tevaearai
 Date        : 17.12.2019

 But         :  Utilisation de tableaux (type C) bi-dimensionnels ou vecteurs
                Utilisation de type enuméré
                Conception et mise en oeuvre de fonctions
                Approfondissement de la notion de tests et décision
                Manipulation de chaines de caractères
                Mise en oeuvre de la compilation séparée en plusieurs fichiers.

 Remarque(s) : Ne fonctionne que avec un tablier de taille strictement inférieur à 10

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "affichage.h"
#include <iostream>
#include <iomanip>

using namespace std;

/* Constantes */
const string CASE_LIBRE = "..";
const string CASE_VIDE  = "  ";
const int LARGEUR_COLONNE = 3;

void afficheTablier(EtatCase tablier[][TAILLE_TABLIER]) {
  
  for(unsigned i = 0; i < TAILLE_TABLIER; i++) {
    for(unsigned j = 0; j < TAILLE_TABLIER; j++) {
      switch(tablier[i][j]) {
        case EtatCase::VIDE:
          cout << setw(LARGEUR_COLONNE) << CASE_VIDE;
          break;
        case EtatCase::BILLE:
          cout << setw(LARGEUR_COLONNE-1) << (i + 1) << (j + 1);
          break;
          
        case EtatCase::LIBRE:
          cout << setw(LARGEUR_COLONNE) << CASE_LIBRE;
          break;
      }
    }
    cout << endl;
  }
}

void afficheAide(EtatCase tablier[][TAILLE_TABLIER]) {
  vector<string> move = allPossibleMoves(tablier);
  cout << "Deplacements possibles: ";
  // parcourt chaque case du vecteur move et affiche son contenu.
  for_each(move.cbegin(), move.cend(), [](const string &str) { cout << str << " "; });
  cout << endl;
}

void afficheFinPartie(int billeRestante, bool centre) {
    if(centre) {
        cout << "Parfait, il ne reste qu'une bille au centre" << endl;
    } else if(billeRestante == 1) {
        cout << "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait" << endl;
    } else if(billeRestante > NB_BILLE_BIEN_MIN && billeRestante < NB_BILLE_BIEN_MAX) {
        cout << "Pas mal, il ne reste que " << billeRestante << " billes" << endl;
    } else {
        cout << "Vous pouvez faire mieux, il reste " << billeRestante << " billes" << endl;
    }
}