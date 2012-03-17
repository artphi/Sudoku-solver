/*
 * ===============================================================
 *
 *       Filename:  fichier.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05. 03. 12 18:38:59
 *       Revision:  none
 *
 *         Author:  Raphaël Santos, Olivier Francillon
 *
 * ===============================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichier.h"

int lireTableau2Dim(char nomFichier[PATH_LENGTH],
               int tableau[TAILLE_SUDO][TAILLE_SUDO]) {

   int ligne,colonne,nbScan,nombre,resultat;
   FILE *fichier;
   resultat = 0;
   
   fichier = fopen(nomFichier, "r");

   /* Si le fichier n'a pas pu être ouvert, on met resultat à 1 */
   if (fichier == NULL ) {
        printf("Impossible d'ouvrir le fichier %s\n",nomFichier);
        resultat = 1;

   } else {      // Sinon, on parcours le fichier et enregistre
                 /* chaque valeur dans notre tableau */
      for (ligne = 0 ; ligne < TAILLE_SUDO && !resultat ; ligne++) {
         for (colonne = 0 ; colonne < TAILLE_SUDO && !resultat; colonne++) {
            nbScan = fscanf(fichier, "%d", &nombre);

            //Contrôle de la valeur scannée (0 <= X <= 9)
            //Sinon, resultat = 2, et sortie de la boucle
            if (nbScan == 1 && nombre >= 0 && nombre <= TAILLE_SUDO) {
               tableau[ligne][colonne] = nombre;
            } else {
               resultat = 2;
            }
         }
      }
      fclose(fichier);
   }
   return resultat;
}


void lirePath(char nomFichier[PATH_LENGTH]) {
   char path[PATH_LENGTH];
   char *p;

   printf("chemin vers le fichier:\n");
   printf("\t->");
   fgets(path,PATH_LENGTH,stdin);

   //Supprimer \n dans le chemin
   p = strchr(path, '\n');
   if (p) {
      *p = 0;
   }
   strcpy(nomFichier,path);
}
