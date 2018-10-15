#define LARGEUR_IMAGE 20
#define HAUTEUR_IMAGE 20

#define TAILLE_IMAGE LARGEUR_IMAGE*HAUTEUR_IMAGE

typedef struct Entree
{
	int ** motif;

	int largeur_image;
	int hauteur_image;
} entree;


int initialise_entree(Entree entree);

