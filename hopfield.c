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

void conversion_binaire(struct Entree * entree)
{
	int n, x, y;

	for (n = 0; n < entree->nombre_motif; n++) {
		for (x = 0; x < entree->largeur_image; x++) {
			for (y = 0; y < entree->hauteur_image; y++) {
				switch (MOTIF[n][x][y]) {
					case ' ':
					entree->motif[n][x*LARGEUR_IMAGE+y] = -1;
					break;

					case '0':
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

void affiche_reseau(struct Reseau * reseau)
{
	int i,j;

	for (i=0; i<reseau->entree->largeur_image; i++) {
		for (j=0; j<reseau->entree->hauteur_image; j++) {
			switch (reseau->sortie[i*LARGEUR_IMAGE+j])
			{
				case -1:
					printf("O");
					break;
				case 1:
					printf(" ");
					break;
		}
		printf("\n");
	}
	printf("\n");
}

void calcul_noeud(struct Reseau * reseau)
{
	int n, x, y, tmp;
	for (n = 0; n < reseau->nombreNeurone; n++) {
		for (x = 0; x < TAILLE_IMAGE; x++){
			for (y = 0; y < TAILLE_IMAGE; y++) {
					tmp += reseau->entree->motifs[n][x] * reseau->poids[n][y];
			}
		}
		reseau->sortie[n] = seuil(tmp);
		printf("Sortie du noeud n°%d : %d\n", reseau->sortie);
	}
}

int seuil(int tmp){
	if(tmp > 0){
		return 1;
	}else{
		return -1;
	}
}

void apprentissage(struct Reseau * reseau){

}
