// main.c
#include <stdio.h>
#include <limits.h>
#include "arbre.h"

int main() {
    // Initialisation de l'arbre avec 5 niveaux et 9 choix
    Noeud* racine = creerNoeud(5, "Depart");

    // Premier niveau de choix
    racine->enfants[0] = creerNoeud(10, "Avancer de 10 m");
    racine->enfants[1] = creerNoeud(12, "Tourner à gauche");
    racine->enfants[2] = creerNoeud(15, "Tourner à droite");
    racine->enfants[3] = creerNoeud(8, "Avancer de 20 m");
    racine->enfants[4] = creerNoeud(18, "Reculer de 10 m");
    racine->enfants[5] = creerNoeud(9, "Avancer de 30 m");
    racine->enfants[6] = creerNoeud(7, "Reculer de 20 m");
    racine->enfants[7] = creerNoeud(14, "Tourner à gauche légèrement");
    racine->enfants[8] = creerNoeud(11, "Tourner à droite légèrement");

    // Deuxième niveau de choix (exemple pour enfants[0] de chaque choix au premier niveau)
    for (int i = 0; i < 9; i++) {
        if (racine->enfants[i] != NULL) {
            racine->enfants[i]->enfants[0] = creerNoeud(6, "Avancer de 5 m");
            racine->enfants[i]->enfants[1] = creerNoeud(13, "Reculer de 5 m");
            racine->enfants[i]->enfants[2] = creerNoeud(9, "Tourner à droite");
            racine->enfants[i]->enfants[3] = creerNoeud(10, "Tourner à gauche");
            racine->enfants[i]->enfants[4] = creerNoeud(12, "Avancer de 15 m");
            racine->enfants[i]->enfants[5] = creerNoeud(14, "Reculer de 15 m");
            racine->enfants[i]->enfants[6] = creerNoeud(11, "Tourner à droite fort");
            racine->enfants[i]->enfants[7] = creerNoeud(15, "Tourner à gauche fort");
            racine->enfants[i]->enfants[8] = creerNoeud(20, "Avancer de 20 m");
        }
    }

    // Répétez cette logique pour le troisième, quatrième et cinquième niveau
    // Exemple pour le troisième niveau de choix
    /*for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (racine->enfants[i] && racine->enfants[i]->enfants[j]) {
                racine->enfants[i]->enfants[j]->enfants[0] = creerNoeud(6, "Option niveau 3");
                // Continuez à ajouter les choix pour chaque noeud au troisième niveau
            }
        }
    }*/
    // Continuez jusqu'au cinquième niveau en suivant le même modèle

    // Recherche du chemin optimal
    char cheminActuel[MAX_NIVEAU][20];
    CheminOptimal meilleurChemin;
    meilleurChemin.longueur = 0;
    int cout_minimal = INT_MAX;

    parcourirArbre(racine, cheminActuel, 0, &meilleurChemin, &cout_minimal);

    // Affiche le chemin optimal
    afficherCheminOptimal(&meilleurChemin);

    // Libérer la mémoire de l'arbre
    libererArbre(racine);

    return 0;
}
