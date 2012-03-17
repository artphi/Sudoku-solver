/*
 * ===============================================================
 *
 *       Filename:  fichier.h
 *
 *    Description:  Fonctions pour la lecture d'un fichier
 *
 *        Version:  1.0
 *        Created:  05. 03. 12 18:38:43
 *       Revision:  none
 *
 *         Author:  Raphaël Santos, Olivier Francillon
 *
 * ===============================================================
 */

#define PATH_LENGTH 50
#define TAILLE_SUDO 9

/*----------------------------------------------------------------
 *  lireTableau2Dim
 *      Copie d'un sudoku contenu dans un fichier vers
 *      un tableau
 *      paramètres: char nomFichier[PATH_LENGTH]
 *                  int tableau[TAILLE_SUDO][TAILLE_SUDO]
 *      return:     0 si ok
 *                  1 si impossible d'ouvrir le fichier
 *                  2 si erreur à la lecture du fichier
 *--------------------------------------------------------------*/
int lireTableau2Dim(char nomFichier[PATH_LENGTH],
               int sudoku[TAILLE_SUDO][TAILLE_SUDO]);


/*----------------------------------------------------------------
 *  lirePath
        Lecture d'une chaine de caractères
 *      paramètres: char nomFichier[PATH_LENGTH]
 *--------------------------------------------------------------*/
void lirePath(char nomFichier[PATH_LENGTH]);
