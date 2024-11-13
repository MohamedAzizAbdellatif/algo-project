// main.c
#include <stdio.h>
#include <limits.h>
#include "arbre.h"

void construireArbre(Noeud* noeud, int niveau) {
    if (niveau >= MAX_NIVEAU) {
        return; // Arrête la création de branches au niveau maximal
    }
    int choix = MAX_CHOIX - niveau;  // Diminue les choix à chaque niveau
    for (int i = 0; i < choix; i++) {
        char description[20];
        snprintf(description, sizeof(description), "Mouvement %d au niveau %d", i + 1, niveau + 1);
        noeud->enfants[i] = creerNoeud(5 + niveau + i, description); // coût arbitraire pour le test
        construireArbre(noeud->enfants[i], niveau + 1); // Appel récursif pour le niveau suivant
    }
}

int main() {
    // Initialisation de l'arbre avec le nœud racine
    Noeud* racine = creerNoeud(0, "Depart");

    // Construction de l'arbre avec la structure spécifiée
    construireArbre(racine, 0);

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
};