#include "tab.h"        //inclusuion d'un fichier d'en-t�te personnel





//Fonction qui remplit un tableau d'entiers de taille size avec des 0
int initTab(int* tab, int size) {
    int i = 0;
    if ((tab == NULL) || (size < 0)) {          //Erreur si tab est un pointeur nul ou size strictement inf�rieur � 0
        return -1;
    }
    else {
        for (i = 0; i < size; i++) {
            *(tab + i) = 0;         //Chaque valeur est mise � 0 tour � tour
        }
    }
    return size;
}



//Fonction qui affiche les nbElts premiers �l�ments du tableau Tab sur une ligne de la console
int afficheTab(int* tab, int size, int nbElts) {
    if ((tab == NULL) || (size < 0) || (size < nbElts)) {       //Erreur si tab est un pointeur NULL ou si size strictement inf�rieur � 0 ou si size strictement inf�rieur � nbElts
        return -1;
    }
    else {
        for (int i = 0; i < nbElts; i++) {
            printf("%d ", tab[i]);          //Affiche les �l�ments du tableau
        }
    }
    return 0;
}



//Fonction qui ajoute un nombre entier � la suite des valeurs d�j� entr�es et met � jour le nombre d'�l�ments stock�s ainsi que la capacit� r�elle du tableau
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
    if (tab == NULL || *size < 0 || *nbElts < 0) {
        return NULL;
    }//Valeurs entr�es non valides
    if (*nbElts + 1 > * size) { //Test si d�passement de capacit�
        int* tmp = tab; //Sauvegarde de l'ancien pointeur si
        *tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la m�moire
        if (tab == NULL) { //V�rification que la m�moire a bien �t� allou�e
            *tab = tmp;
            return NULL;
        }
        *size += TAILLEAJOUT;           // Si le tableau est trop petit, il doit �tre agrandi de TAILLEAJOUT �l�ments
    }
    *(tab + *nbElts) = element;
    *nbElts += 1;
    return *nbElts;
}