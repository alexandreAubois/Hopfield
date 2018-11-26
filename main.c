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
	
	/*int i,j;
	for(i = 0; i<4; i++)
	{
		for(j=0; j< 20 ; j++)
		{
			printf("%f\t", reseau->poids[i][j]);
		}
		printf("\n");
	}
	getchar();*/
	apprentissageHebb(reseau, 1000000);
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

	Reseau * reseauTest = NULL;

	reseauTest = (Reseau *) malloc(sizeof(Reseau));

	initialise_reseau(reseauTest, entreeTest);
	
	printf("\n");
	printf("\n");
	calcul_noeud(reseauTest, 0);	
	printf("\n");
	calcul_noeud(reseauTest, 1);
	printf("\n");
	calcul_noeud(reseauTest, 2);
	printf("\n");
	calcul_noeud(reseauTest, 3);

	return 0;
}
