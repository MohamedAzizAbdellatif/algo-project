#ifndef ARBRE_H
#define ARBRE_H

#define MAX_CHOIX 9
#define MAX_NIVEAU 5

typedef struct Noeud {
    int valeur;                        // coût de la case
    char deplacement[20];              // nom du déplacement
    struct Noeud* enfants[MAX_CHOIX];  // enfants pour chaque choix suivant
} Noeud;

typedef struct CheminOptimal {
    char deplacements[MAX_NIVEAU][20]; // chemin optimal (jusqu'à 3 déplacements)
    int longueur;                      // longueur du chemin
}CheminOptimal;

// Fonctions de gestion de l'arbre
Noeud* creerNoeud(int valeur, const char* deplacement);
void libererArbre(Noeud* noeud);
void parcourirArbre(Noeud* noeud, char cheminActuel[MAX_NIVEAU][20], int niveau, CheminOptimal* meilleurChemin, int* cout_minimal);
void afficherCheminOptimal(CheminOptimal* chemin);

#endif // ARBRE_H
