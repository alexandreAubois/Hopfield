#include "hopfield.h"
#include <time.h>

int main(void)
{
	srand((unsigned int) time(NULL));

	Entree * entree = NULL;

	entree = (Entree*) malloc(sizeof(Entree));

	initialise_entree(entree, NB_MOTIF);

	conversion_binaire(entree);

	Reseau * reseau = NULL;

	reseau = (Reseau *) malloc(sizeof(Reseau));

	initialise_reseau(reseau, entree);

	calcul_noeud(reseau);

	return 0;
}
