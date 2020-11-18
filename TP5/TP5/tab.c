#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define TAILLEAJOUT 50



int initTab(int* tab, int size) {


	if ((tab == NULL) || (size<0)) {
		return -1;
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab+i) = 0;
		}
		return size;
	}

}




int afficheTab(int* tab, int size, int nbElts) {
	if ((tab == NULL) || (size < 0) || (size<nbElts)) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d  ",*(tab+i));
		}
		return 0;
	}




}



int ajoutElementDansTableau(int** tab, int* Size, int* nbElts, int element) {
	if (*nbElts < *Size) {                  
		*(*tab + *nbElts) = element;
		(*nbElts)++;
		return (*nbElts);
	}
	int* tab2 = (int*)realloc(*tab, (*Size + TAILLEAJOUT) * sizeof(int));   
	if (tab2 == NULL) { return(-1); }                                        
	*tab = tab2;
	*(*tab + *nbElts) = element;                                      
	*Size += TAILLEAJOUT;                                                 
	(*nbElts)++;
	return (*nbElts);