/*
 * ===============================================================
 *
 *       Filename:  pile.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05. 03. 12 18:38:59
 *       Revision:  none
 *
 *         Author:  Rapha�l Santos, Olivier Francillon
 *
 * ===============================================================
 */

typedef struct {
    int ligne;
    int colonne;
    int valeur;
    int essai;
} typeDonnee;

/* D�finition d'un objet descripteur de pile */
typedef struct {
	int max;           /* Nombre d'�l�ments max d'une pile */
	int sommet;        /* Indice du sommet de pile   */
	typeDonnee *table; /* Tableau r�serv� pour stocker la pile */
} typePile;

/* R�servation de memoire pour la pile */
/* et initilisation de la structure    */
/* Entr�e : taille max de la pile en nombre d'�l�ments */
/* Resultat : pointeur sur une structure typePile     */
typePile *initpile (int taille);

/* Resultat : Vrai (1) si la pile est vide et Faux (0) sinon */
int pilevide(typePile *pile);

/* Resultat : Vrai (1) si la pile est pleine et Faux (0) sinon */
int pilepleine(typePile *pile);

/* Range la valeur en sommet de pile */
void empiler(typePile *pile, typeDonnee valeur);

/* Resultat : valeur rang�e en sommet de pile */
/* La valeur est enlev�e de la pile           */
typeDonnee depiler(typePile *pile);

/* Lib�rer la m�moire allou�e pour la pile */
void detruirePile(typePile *pile);
