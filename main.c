#include "hopfield.h"
#include <time.h>

int main(void)
{
	srand((unsigned int) time(NULL));

	Entree * entree = NULL;

	entree = (Entree*) malloc(sizeof(Entree));

	initialise_entree(entree, NB_MOTIF);

	conversion_binaire(entree, 1);

	Reseau * reseau = NULL;

	reseau = (Reseau *) malloc(sizeof(Reseau));

	initialise_reseau(reseau, entree);
	
	apprentissageHebb(reseau, 1000);
	printf("\n");
	calcul_noeud(reseau, 0);	
	printf("\n");
	calcul_noeud(reseau, 1);
	printf("\n");
	calcul_noeud(reseau, 2);
	printf("\n");
	calcul_noeud(reseau, 3);
	
	Entree * entreeTest = NULL;

	entreeTest = (Entree*) malloc(sizeof(Entree));

	initialise_entree(entreeTest, NB_MOTIF);

	conversion_binaire(entreeTest, 0);
	
	set_entree(reseau, entreeTest);
	
	printf("\n");
	printf("\n");
	calcul_noeud(reseau, 0);	
	printf("\n");
	calcul_noeud(reseau, 1);
	printf("\n");
	calcul_noeud(reseau, 2);
	printf("\n");
	calcul_noeud(reseau, 3);

	return 0;
}
