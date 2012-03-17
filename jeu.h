/*
 * ===============================================================
 *
 *       Filename:  jeu.h
 *
 *        Version:  1.0
 *        Created:  08. 03. 12 13:51:33
 *       Revision:  none
 *
 *         Author:  Raphaël Santos, raph.snts@gmail.com
 *
 * ===============================================================
 */
#define TAILLE_SUDO 9
#define VRAI 1
#define FAUX 0

/*----------------------------------------------------------------
 *  afficherSudo
 *      Affichage du sudoku
 *      paramètres:  int tableau[TAILLE_SUDO][TAILLE_SUDO]
 *--------------------------------------------------------------*/
void afficherSudo(int sudoku[TAILLE_SUDO][TAILLE_SUDO]);

/*----------------------------------------------------------------
 *  checkNombre
 *      Controle si une valeur peut être mise dans le sudoku
 *      à la position donnée
 *      paramètres:  int valeur
 *                   int ligne
 *                   int colonne
 *                   int tableau[TAILLE_SUDO][TAILLE_SUDO]
 *      return:      VRAI ou FAUX
 *--------------------------------------------------------------*/
int checkNombre(int valeur, int ligne, int colonne,
            int sudoku[TAILLE_SUDO][TAILLE_SUDO]);
 
