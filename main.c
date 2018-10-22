#include "hopfield.h"
#include <time.h>

int main(void)
{
	srand((unsigned int) time(NULL));

	struct Entree * entree;

	initialise_entree(entree, NB_MOTIF);

	conversion_binaire(entree);

	struct Reseau * reseau;

	initialise_reseau(reseau, entree);

	calcul_noeud(reseau);

	return 0;
}
