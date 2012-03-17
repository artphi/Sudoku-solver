/* pile.h */

/* Type des objets empilés */
typedef struct {
	int lig;   // no de ligne (de 0 à nbligne-1)
	int col; // no de colonne (de 0 à nbcolonne-1)
    int valeur;
} typePosition;

typedef typePosition typedonnee;

/* Définition d'un objet descripteur de pile */
typedef struct {
	int max;           /* Nombre d'éléments max d'une pile */
	int sommet;        /* Indice du sommet de pile   */
	typedonnee *table; /* Tableau réservé pour stocker la pile */
} typePile;

/* Réservation de memoire pour la pile */
/* et initilisation de la structure    */
/* Entrée : taille max de la pile en nombre d'entiers */
/* Resultat : pointeur sur une structure typePile     */
typePile *initpile (int taille);

/* Resultat : Vrai (1) si la pile est vide et Faux (0) sinon */
int pilevide   (typePile *pile);

/* Resultat : Vrai (1) si la pile est pleine et Faux (0) sinon */
int pilepleine (typePile *pile);

/* Range la valeur en sommet de pile */
void empiler   (typePile *pile, typedonnee valeur);

/* Resultat : valeur rangée en sommet de pile */
/* La valeur est enlevée de la pile           */
typedonnee depiler    (typePile *pile);

/* Libère la zone mémoire réservée pour la pile */
void detruirePile (typePile *pile);

int taillePile (typePile *pile); //retourne la taille de la pil
