/*
 * ===============================================================
 *
 *       Filename:  solvermain.c
 *
 *    Description:  main du solver
 *
 *        Version:  1.0
 *        Created:  05. 03. 12 19:17:52
 *       Revision:  none
 *
 *         Author:  Raphaël Santos, Olivier Francillon
 *
 * ===============================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"
#include "pile.h"
#include "jeu.h"
#define TAILLE_PILE 400

void main(){
   char path[PATH_LENGTH];
   int sudoku[TAILLE_SUDO][TAILLE_SUDO];
   int i,j,k,res;
   int erreur = FAUX;

   typeDonnee possibilite;
   typePile *pile;
   pile = initpile(TAILLE_PILE);

   lirePath(path);
   res = lireTableau2Dim(path, sudoku);
   while (res != 0) {
      switch(res) {
         case 1:
            printf("Impossible d'ouvrir le fichier %s\n",path);
            break;
         case 2:
            printf("Erreur dans le fichier %s\n",path);
            break;
         }
      lirePath(path);
      res = lireTableau2Dim(path, sudoku);
   }

   afficherSudo(sudoku);

   int val,posH,posV,trouve;

   // Parcours du sudoku
   for (i = 0;i<TAILLE_SUDO && !erreur;i++) {
      for (j=0;j<TAILLE_SUDO && !erreur;j++) {

         // Si l'on trouve un zéro
         if (sudoku[i][j] == 0) {
            trouve = 0;

            // On essaie tous les nombres et on vérifie si c'est une
            // solution possible
            for (k=1;k<10;k++) {
               // Si oui, on empile cette/ces  possibilité/s
               if ( checkNombre(k,i,j,sudoku)) {
                  trouve = 1;
                  possibilite.ligne = i;
                  possibilite.colonne = j;
                  possibilite.valeur = k;
                  possibilite.essai = 0;
                  if (!pilepleine(pile)) {
                     empiler(pile, possibilite);
                  } else {
                     printf("Pile pleine!!\n");
                     erreur = VRAI;
                  }
               }
            }

            // Si au moins une solution a été trouvée, on dépile la dernière
            // on l'insère dans le sudoku et on indique dans la pile
            // qu'elle est utilisée
            if (trouve == 1 && !erreur) {
               possibilite = depiler(pile);
               possibilite.essai = 1;
               empiler(pile,possibilite);
               sudoku[possibilite.ligne][possibilite.colonne] = possibilite.valeur;
               afficherSudo(sudoku);
            }
            
            // Sinon, on dépile toutes les possibilités essayées jusqu'à une
            // possibilité non essayée, on l'utilise et indique qu'elle
            // est utilisée à son tour. On replace également un zéro dans
            // les cases pour un retour en arrière
            else {
               if (!pilevide(pile)) {
                  possibilite = depiler(pile);
                  afficherSudo(sudoku);
                  while (possibilite.essai == 1 && !erreur) {
                     sudoku[possibilite.ligne][possibilite.colonne] = 0;
                     if (!pilevide(pile)) {
                        possibilite = depiler(pile);
                        afficherSudo(sudoku);
                     } else {
                        printf("Pas de solution possible!\n");
                        erreur = VRAI;
                     }
                  }
                  possibilite.essai = 1;
                  empiler(pile,possibilite);
                  sudoku[possibilite.ligne][possibilite.colonne] = possibilite.valeur;
                  i = possibilite.ligne - 1;
                  j = possibilite.colonne - 1;
               } else {
                  printf("Pas de solution possible!\n");
                  erreur = VRAI;
               }
            }
         }
      }
   }
   // Si le sudoku est résolu
   if (!erreur) {
      printf("Le sudoku est resolu: \n");
      afficherSudo(sudoku);
   }
}
