#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"tab.h"
#define tabsize 10
#define TAB2SIZE 100
#define nbElts 20
#define TAILLEAJOUT 50


int main() {
	
	int myTab1[tabsize];
	initTab(myTab1, tabsize);
	afficheTab(myTab1, tabsize, 10);

	int* myTab2 = NULL;
	int tabSize = TAB2SIZE;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); 

	if (myTab2 != NULL) { 
		initTab(myTab2, TAB2SIZE); 
	}
	else { 
		printf("mémoire insuffisante"); return(-1); 
	}

	
	for (int i = 0; i < nbElts; i++) {
		myTab2[i] = i + 1;

	}

	afficheTab(myTab2, TAB2SIZE, nbElts);
	
	free(myTab2);

	myTab2 = (int*)realloc(*myTab2, (TAB2SIZE + TAILLEAJOUT) * sizeof(int));
	ajoutElementDansTableau(myTab2, TAB2SIZE, nbElts, 3);




	return EXIT_SUCCESS;
}