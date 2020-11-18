#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define TAILLEINITIALE 100



/* Creation du type tableau */
typedef struct Tableau
{
	int* elt;// le tableau d’entiers
	int size;// la taille de ce tableau d’entiers
	int eltsCount;// le nombre d’éléments dans le tableau
}TABLEAU;
TABLEAU newArray();
int incrementArraySize(TABLEAU* tab, int incrementValue);
int setElement(TABLEAU* tab, int pos, int element);
int displayElements(TABLEAU* tab, int startPos, int endPos);
int deleteElements(TABLEAU* tab, int startPos, int endPos);



/* Fonction de creation de tableau */
TABLEAU newArray() {
	TABLEAU tableau;
	tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	tableau.size = TAILLEINITIALE;
	tableau.eltsCount = 0;
	return tableau;
}

/* Fonction qui augmente la taille d'un tableau */
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tab2 = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));  // on réalloue de la mémoire à hauteur de l'ancienne place + la place qu'on veut rajouter
	if (tab2 == NULL) { return(-1); }                                                  // si cela echoue on renvoit 0
	tab->elt = tab2;                                                                       // sinon on affecte le nouvel emplacement mémoire
	tab->size += incrementValue;                                                      //on met à jour la nouvelle taille du tableau
	return (tab->size);
}

/* Fonction qui insere un element a une position donnee */
int setElement(TABLEAU* tab, int pos, int element) {
	if (pos < tab->eltsCount) {                             // si la position est déjà dans le tableau on remplace juste l'ancien contenu par element
		*(tab->elt + pos) = element;
		return pos;
	}
	int* tab2 = (int*)realloc(tab->elt, (pos + 1) * sizeof(int));     // sinon on réalloue de la mémoire pour le placer
	if (tab2 == NULL) { return(0); }
	tab->elt = tab2;
	for (int i = tab->eltsCount; i <= pos - 1; i++) {                     // on remplace tous les emplacements entre l'ancienne fin du tableau et la position par 0
		*(tab->elt + i) = 0;
	}
	*(tab->elt + pos) = element;                                    // on met element à pos
	tab->size = pos + 1;                                              // on met à jour la taille et le nombre d'elements du tableau
	tab->eltsCount = pos + 1;
	return pos;
}

/* Fonction qui affiche une partie du tableau en fonction d'un indice de debut et d'un indice de fin */
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if ((startPos >= 0) && (endPos < tab->size) && (endPos >= startPos)) {   // on vérifie la validité des paramètres en entrée
		for (int i = startPos; i <= endPos; i++) {                           // on affiche les elements du tableau entre StartPos et EndPos
			printf("%d ", *(tab->elt + i));
		}
		printf("\n\n");
		return 0;
	}
	return -1;
}

/* Fonction qui supprime un element et met a jour la taille du tableau */
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* tab2 = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int));    // on réalloue la memoire necessaire au traitement
	if (tab2 == NULL) { return(-1); }
	for (int i = 0; i <= tab->size - 1; i++) {
		if ((i < startPos) || (i > endPos)) {
			*(tab2 + j) = *(tab->elt + i);                                         //on copie chaque element du tableau dans la copie lorsque son indice correspond aux paramètres d'entrée
			j++;     //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et à mesure
		}
	}
}