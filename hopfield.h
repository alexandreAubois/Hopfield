#define LARGEUR_IMAGE 20
#define HAUTEUR_IMAGE 20

#define TAILLE_IMAGE LARGEUR_IMAGE*HAUTEUR_IMAGE

typedef struct Entree
{
	int ** motif;
	int largeur_image;
	int hauteur_image;
	int nombre_motif;

} entree;

typedef struct Reseau
{
		struct Entree * entree;
		int ** poids;
		int ** sortie;
		int nombreNeurone;
		int * etatNeurones;
} reseau;

int initialise_entree(Entree * entree, int nombre_motifs);

int initialise_reseau(Reseau * reseau, Entree * entree);

void affiche_reseau(Reseau * reseau);

void convertion_binaire(Reseau * reseau);

void calcul_poids(Reseau * reseau);

void set_entree(Reseau * reseau, Entree * entree);

void get_sortie(Reseau * reseau, int * sortie);

void iteration_suivante(Reseau * reseau, int indice);
