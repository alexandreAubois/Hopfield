#include "hopfield.h"

int initialise_entree(Entree * entree, int nombre_motifs);
{
	int i;

	entree->motif = (int**)malloc(sizeof(int*)*nombre_motifs);
	for(i = 0; i < nombres_motifs ; i++)
	{
		entree->motif[i] = (int*)malloc(sizeof(int)*TAILLE_IMAGE);
	}

	entree->hauteur_image = HAUTEUR_IMAGE;
	entree->largeur_image = LARGEUR_IMAGE;
	entree->nombre_motif = nombre_motifs;
}

int initialise_reseau(Reseau * reseau, Entree * entree)
{

}

void conversion_binaire(Entree * entree)
{
	int n, x, y;

	for (n = 0; n < entree->nombre_motif; n++) {
		for (x = 0; x < entree->largeur_image; x++) {
			for (y = 0; y < entree->hauteur_image; y++) {
				switch (MOTIF[n][x][y]) {
					case " ":
					entree->motif[n][x*LARGEUR_IMAGE+y] = -1;
					break;

					case "0":
					entree->motif[n][x*LARGEUR_IMAGE+y] = 1;
					break;

					default:
					entree->motif[n][x*LARGEUR_IMAGE+y] = -1;
					break;
				}
			}
		}
	}

}
