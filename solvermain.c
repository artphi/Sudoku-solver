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
#define TAILLE_PILE 100

void main(){
   char path[PATH_LENGTH];
   int sudoku[TAILLE_SUDO][TAILLE_SUDO];
   int i,res;
   int trouve = FAUX;
   int lig=0;
   int col=0;
   int valeur = 1;
   int erreur = FAUX;


   typeDonnee pos;
   typePile *pile;
   pile = initpile(TAILLE_PILE);
    //Lecture du chemin pour charger le sudoku
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
   // On affiche le sudoku en début de partie
   afficherSudo(sudoku);

   // Parcours de la grille à la recherche des 0
   while (lig<TAILLE_SUDO && !erreur)
   {
       col=0;
       while (col<TAILLE_SUDO && !erreur)
       {
           if (sudoku[lig][col] == 0) //On regarde si la valeur testée = 0
           {
               trouve = FAUX; //On initialise trouve à faux avant chaque recherche de la valeur possible
               while (valeur <= TAILLE_SUDO && !trouve)
               {
                   if (checkNombre(valeur,lig,col,sudoku)) //On lance la procédure de test des possibilité
                   {
                       /* Si un nombre est possible on l'empile et on passe trouve à vrai et on passe à la case 0 suivante */
                       pos.lig = lig;
                       pos.col = col;
                       pos.valeur = valeur;
                       sudoku[lig][col] = valeur;
                       valeur = 0;
                       empiler(pile,pos);
                       trouve = VRAI;
                   }
                   valeur++;
               }
               if(!trouve) //Si on a pas trouvé de valeur possible
               {
                   if(pilevide(pile)) //On vérifie que la pile n'est pas vide
                   {
                       printf("Résolution impossible\n");
                       erreur = VRAI;
                   }
                   else     //Si elle n'est pas vide
                   {
                       pos=depiler(pile);           //On dépile
                       sudoku[pos.lig][pos.col]=0;  //Réattribue un 0 à la case dépilée
                       lig=pos.lig;                 //On se repositionne une case avant
                       col=pos.col-1;
                       valeur=pos.valeur+1;         //On incrémente la valeur trouvée précédemment

                   }
               }
           }
           col++; //On passe à la colonne suivante
       }
       lig++; //On passe à la ligne suivante
   }

   // Si le sudoku est résolu
   if (!erreur) {
      printf("Le sudoku est resolu: \n");
      afficherSudo(sudoku);
   }
}
