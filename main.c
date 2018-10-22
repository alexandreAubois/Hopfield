#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand((unsigned int) time(NULL));
	
	Entree * entree;
	
	initialise_entree(entree, NB_MOTIF);
	
	conversion_binaire(entree);
	
	Reseau * reseau;
	
	initialise_reseau(reseau, entree);
	
	return 0;
}
