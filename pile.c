/*
 * ===============================================================
 *
 *       Filename:  pile.c
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

#include <stdlib.h>
#include "pile.h"

typePile *initpile (int taille) {
   typePile *pile;
	/* Allouer une zone memoire pour la structure pile */
	pile = (typePile *) malloc (sizeof (typePile));
      if (pile != NULL) {
		   /* Allocation de memoire pour le tableau d'entiers */
		   /* dans lequel seront stock�s les valeurs empil�es */
		   pile->table = (typeDonnee *) malloc (taille * sizeof(typeDonnee));
		   if (pile->table != NULL) {
			   /* Sommet pointe sur le premier element du tableau alloue */
			   pile->max = taille; // Nombre max d'element dans la pile
			   pile->sommet = 0;       // Nombre d'elements empiles
      } else {
		   free (pile);
			pile = NULL;
		}
   }
	return pile;
}

int pilevide (typePile *pile) {
	/* retourne VRAI (1) s'il n'y a pas d'elements et FAUX (0) sinon */
	return (pile->sommet == 0);
}

int pilepleine (typePile *pile) {
	/* retourne VRAI (1) si le nombre d'elements est egal au max et
	FAUX (0) sinon */
	return (pile->sommet == pile->max);
}

void empiler (typePile *pile, typeDonnee valeur) {
	/* Ranger la valeur en sommet de pile */
	pile->table [pile->sommet] = valeur;
	pile->sommet++; /* Incrementer le sommet de pile */
}

typeDonnee depiler (typePile *pile) {
	pile->sommet--;         /* Decrementer le sommet de pile */
	return (pile->table [pile->sommet]); /* retourner la valeur du sommet */
}

void detruirePile (typePile *pile) {
	free (pile->table); /* Lib�rer la zone m�moire pour le tableau */
	free (pile); /* Lib�rer la zone m�moire pour la structure */
}
