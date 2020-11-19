#include "tab.h"        //inclusuion d'un fichier d'en-tête personnel





//Fonction qui remplit un tableau d'entiers de taille size avec des 0
int initTab(int* tab, int size) {
    int i = 0;
    if ((tab == NULL) || (size < 0)) {          //Erreur si tab est un pointeur nul ou size strictement inférieur à 0
        return -1;
    }
    else {
        for (i = 0; i < size; i++) {
            *(tab + i) = 0;         //Chaque valeur est mise à 0 tour à tour
        }
    }
    return size;
}



//Fonction qui affiche les nbElts premiers éléments du tableau Tab sur une ligne de la console
int afficheTab(int* tab, int size, int nbElts) {
    if ((tab == NULL) || (size < 0) || (size < nbElts)) {       //Erreur si tab est un pointeur NULL ou si size strictement inférieur à 0 ou si size strictement inférieur à nbElts
        return -1;
    }
    else {
        for (int i = 0; i < nbElts; i++) {
            printf("%d ", tab[i]);          //Affiche les éléments du tableau
        }
    }
    return 0;
}



//Fonction qui ajoute un nombre entier à la suite des valeurs déjà entrées et met à jour le nombre d'éléments stockés ainsi que la capacité réelle du tableau
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
    if (tab == NULL || *size < 0 || *nbElts < 0) {
        return NULL;
    }//Valeurs entrées non valides
    if (*nbElts + 1 > * size) { //Test si dépassement de capacité
        int* tmp = tab; //Sauvegarde de l'ancien pointeur si
        *tab = (int*)realloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  //Allocation de la mémoire
        if (tab == NULL) { //Vérification que la mémoire a bien été allouée
            *tab = tmp;
            return NULL;
        }
        *size += TAILLEAJOUT;           // Si le tableau est trop petit, il doit être agrandi de TAILLEAJOUT éléments
    }
    *(tab + *nbElts) = element;
    *nbElts += 1;
    return *nbElts;
}