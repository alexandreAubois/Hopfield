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
