#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

// Définition de la structure t_node pour un arbre
typedef struct s_node {
    int value;              // Coût associé à la position atteinte par ce nœud
    int depth;              // Profondeur du nœud dans l'arbre
    struct s_node** sons;   // Tableau dynamique de pointeurs vers les fils
    int nbSons;             // Nombre de fils actuels
} t_node;

// Fonction pour créer un nœud avec un nombre spécifique de fils
t_node* createNode(int value, int depth, int nbSons);

// Fonction pour construire un arbre de mouvements
void construireArbreMouvements(t_node* noeud, int niveau, int mouvementsRestants);

// Fonction pour trouver le chemin minimal dans l'arbre
int trouverCheminMinimal(t_node* noeud, int* chemin, int* meilleurChemin, int niveau, int* coutMin);

void freeNode(t_node* node);

#endif // NODE_H
