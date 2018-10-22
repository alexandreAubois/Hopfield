#include <stdlib.h>

#define LARGEUR_IMAGE 20
#define HAUTEUR_IMAGE 20
#define NB_MOTIF 4

#define TAILLE_IMAGE LARGEUR_IMAGE*HAUTEUR_IMAGE

typedef struct Entree
{
	int ** motifs;
	int largeur_image;
	int hauteur_image;
	int nombre_motifs;

} entree;

typedef struct Reseau
{
		struct Entree * entree;
		int ** poids;
		int * seuil;
		int * sortie;
		int nombreNeurone;
} reseau;

int initialise_entree(struct Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(struct Reseau * reseau, struct Entree * entree);//guillaume

void affiche_reseau(struct Reseau * reseau);//guilaume

void conversion_binaire(struct Entree * entree);//alex

void calcul_poids(struct Reseau * reseau);//alex

void set_entree(struct Reseau * reseau, struct Entree * entree);//guillaume

void iteration_suivante(struct Reseau * reseau, int indice);//marion
