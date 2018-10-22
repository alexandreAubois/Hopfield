#include "hopfield.h"

int initialise_entree(struct Entree * entree, int nombre_motifs)
{
	int i;	
	entree->motifs = (int**)malloc(sizeof(int*)*nombre_motifs);
	for(i = 0; i < nombre_motifs ; i++)
	{
		entree->motifs[i] = (int*)calloc(TAILLE_IMAGE, sizeof(int));
	}
	
	entree->hauteur_image = HAUTEUR_IMAGE;
	entree->largeur_image = LARGEUR_IMAGE;
	entree->nombre_motifs = nombre_motifs;
	
	return 0;
}

int initialise_reseau(struct Reseau * reseau, struct Entree * entree)
{
	int i;
	reseau->nombreNeurone = TAILLE_IMAGE;
	reseau->entree = entree;	
	reseau->poids = (int**)calloc(TAILLE_IMAGE, sizeof(int*));
	reseau->seuil = (int*)calloc(TAILLE_IMAGE, sizeof(int));
	for (i = 0; i < TAILLE_IMAGE ; i++) 
	{
		reseau->seuil[i] = 0;
        reseau->poids[i] = (int*)calloc(TAILLE_IMAGE, sizeof(int));
    }
    reseau->sortie = (int*)calloc(TAILLE_IMAGE, sizeof(int));
   
   return 0; 
}
