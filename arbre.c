// arbre.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "arbre.h"

// Crée un nouveau nœud avec une valeur de coût et un déplacement
Noeud* creerNoeud(int valeur, const char* deplacement) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    nouveauNoeud->valeur = valeur;
    strcpy(nouveauNoeud->deplacement, deplacement);
    for (int i = 0; i < MAX_CHOIX; i++) {
        nouveauNoeud->enfants[i] = NULL;
    }
    return nouveauNoeud;
}

// Libère la mémoire allouée pour l'arbre
void libererArbre(Noeud* noeud) {
    if (noeud == NULL) return;
    for (int i = 0; i < MAX_CHOIX; i++) {
        libererArbre(noeud->enfants[i]);
    }
    free(noeud);
}

// Parcourt l'arbre pour trouver la feuille de coût minimal
void parcourirArbre(Noeud* noeud, char cheminActuel[MAX_NIVEAU][20], int niveau, CheminOptimal* meilleurChemin, int* cout_minimal) {
    if (noeud == NULL) return;

    // Ajouter le déplacement actuel au chemin
    if (niveau < MAX_NIVEAU) {
        strcpy(cheminActuel[niveau], noeud->deplacement);
    }

    // Vérifie si le nœud est une feuille
    int estFeuille = 1;
    for (int i = 0; i < MAX_CHOIX; i++) {
        if (noeud->enfants[i] != NULL) {
            estFeuille = 0;
            break;
        }
    }

    // Si c'est une feuille, on vérifie si elle a le coût minimal
    if (estFeuille) {
        if (noeud->valeur < *cout_minimal) {
            *cout_minimal = noeud->valeur;
            // Copier le chemin actuel dans le chemin optimal
            for (int i = 0; i <= niveau; i++) {
                strcpy(meilleurChemin->deplacements[i], cheminActuel[i]);
            }
            meilleurChemin->longueur = niveau + 1;
        }
    } else {
        // Parcourir les enfants
        for (int i = 0; i < MAX_CHOIX; i++) {
            if (noeud->enfants[i] != NULL) {
                parcourirArbre(noeud->enfants[i], cheminActuel, niveau + 1, meilleurChemin, cout_minimal);
            }
        }
    }
}

// Affiche le chemin optimal
void afficherCheminOptimal(CheminOptimal* chemin) {
    printf("Chemin optimal :\n");
    for (int i = 0; i < chemin->longueur; i++) {
        printf("  %s\n", chemin->deplacements[i]);
    }
}
