#include "hopfield.h"

int initialise_entree(Entree * entree, int nombre_motifs);
{
	int i;	
	entree->motif = (int**)malloc(sizeof(int*)*nombre_motifs);
	for(i = 0; i < nombres_motifs ; i++)
	{
		entree->motif[i] = (int*)calloc(TAILLE_IMAGE, sizeof(int));
	}
	
	entree->hauteur_image = HAUTEUR_IMAGE;
	entree->largeur_image = LARGEUR_IMAGE;
	entree->nombre_motifs = nombre_motifs;	
}

int initialise_reseau(Reseau * reseau, Entree * entree)
{
	int i;
	int nombreNeurone = TAILLE_IMAGE;
	reseau->entree = entree;	
	reseau->poids = (int**)calloc(TAILLE_IMAGE, sizeof(int*));
	reseau->seuil = (int*)calloc(TAILLE_IMAGE, sizeof(int));
	for (i = 0; i < TAILLE_IMAGE ; i++) 
	{
		reseau->seuil[i] = 0;
        reseau->poids[i] = (int*)calloc(TAILLE_IMAGE, sizeof(int));
    }
    reseau->sortie = (int*)calloc(TAILLE_IMAGE, sizeof(int));
}
