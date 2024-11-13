// main.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arbre.h"

int main() {
    int mouvementsInitials = 9;
    t_node* racine = createNode(0, 0, mouvementsInitials);

    construireArbreMouvements(racine, 0, mouvementsInitials);

    int chemin[5];
    int meilleurChemin[5];
    int coutMin = 100000;

    trouverCheminMinimal(racine, chemin, meilleurChemin, 0, &coutMin);

    printf("Cout minimal: %d\n", coutMin);
    printf("Meilleur chemin: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", meilleurChemin[i]);
    }
    printf("\n");

    // Libération de la mémoire
    freeNode(racine);

    return 0;
};