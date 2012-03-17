/*
 * ===============================================================
 *
 *       Filename:  jeu.c
 *
 *        Version:  1.0
 *        Created:  08. 03. 12 13:39:39
 *       Revision:  none
 *
 *         Author:  Raphaël Santos, Olivier Francillon
 *
 * ===============================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"

void afficherSudo(int sudoku[TAILLE_SUDO][TAILLE_SUDO]) {
   int i,j;

   for (i = 0 ; i < TAILLE_SUDO ; i++) {
      if (i%3 == 0) {    // Toutes les 3 lignes
         printf("+-------+-------+-------+\n");
      }
      for (j = 0 ; j < TAILLE_SUDO ; j++) {
         if(!(j%3)) {   // Toutes les 3 colonnes
            printf("| ");
         }
         printf("%d ", sudoku[i][j]);
      }
      printf("|\n");
   }
   printf("+-------+-------+-------+\n");
}


int checkNombre(int valeur, int ligne, int colonne,
            int sudoku[TAILLE_SUDO][TAILLE_SUDO]) {

   int i,j,ligneRel,colonneRel,ligneCarre,colonneCarre;
   int resultat = VRAI;

   //Verif sur la ligne
   for (j = 0 ; j < TAILLE_SUDO && resultat; j++) {
      if (sudoku[ligne][j] == valeur) {
         resultat = FAUX;
      }
   }

   //Verif sur la colonne
   for (i = 0 ; i < TAILLE_SUDO && resultat; i++) {
      if (sudoku[i][colonne] == valeur) {
         resultat = FAUX;
      }
   }

   //Verif sur le carré
   //Position relative par rapport au carré
   ligneRel = ligne % 3;
   colonneRel = colonne % 3;
   //Position du carré
   ligneCarre = ligne - ligneRel;
   colonneCarre = colonne - colonneRel;

   for(i = 0 ; i < 3 && resultat; i++) {
      for(j = 0 ; j < 3 && resultat; j++) {
         if (sudoku[ligneCarre + i][colonneCarre + j] == valeur) {
            resultat = FAUX;
         }
      }
   }
   return resultat;
}
