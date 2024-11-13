// arbre.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "arbre.h"

// Fonction pour créer un nœud avec un nombre spécifique de fils
t_node* createNode(int value, int depth, int nbSons) {
    t_node* newNode = (t_node*)malloc(sizeof(t_node));
    if (!newNode) return NULL; // Vérification allocation mémoire

    newNode->value = value;
    newNode->depth = depth;
    newNode->nbSons = nbSons;
    newNode->sons = (t_node**)malloc(nbSons * sizeof(t_node*));
    for (int i = 0; i < nbSons; i++) {
        newNode->sons[i] = NULL;
    }

    return newNode;
}
void construireArbreMouvements(t_node* noeud, int niveau, int mouvementsRestants) {
    if (niveau >= 5 || mouvementsRestants <= 0) {
        return; // Arrête la construction à 5 niveaux ou sans mouvements restants
    }

    for (int i = 0; i < mouvementsRestants; i++) {
        int newValue = noeud->value + (i + 1); // Calculer un coût arbitraire
        noeud->sons[i] = createNode(newValue, niveau + 1, mouvementsRestants - 1);

        construireArbreMouvements(noeud->sons[i], niveau + 1, mouvementsRestants - 1);
    }
}
int trouverCheminMinimal(t_node* noeud, int* chemin, int* meilleurChemin, int niveau, int* coutMin) {
    if (niveau == 5 || noeud->nbSons == 0) { // Si feuille atteinte
        if (noeud->value < *coutMin) {
            *coutMin = noeud->value;
            for (int i = 0; i < niveau; i++) {
                meilleurChemin[i] = chemin[i];
            }
        }
        return noeud->value;
    }

    for (int i = 0; i < noeud->nbSons; i++) {
        chemin[niveau] = i; // Stocker le mouvement actuel
        trouverCheminMinimal(noeud->sons[i], chemin, meilleurChemin, niveau + 1, coutMin);
    }
    return *coutMin;
}

#include <stdlib.h>

void freeNode(t_node* node) {
    if (node == NULL) return;

    // Libère chaque fils de manière récursive
    for (int i = 0; i < node->nbSons; i++) {
        freeNode(node->sons[i]);
    }

    // Libère le tableau dynamique des fils
    free(node->sons);

    // Libère le nœud lui-même
    free(node);
}