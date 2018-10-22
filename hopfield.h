#define LARGEUR_IMAGE 20
#define HAUTEUR_IMAGE 20

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

int initialise_entree(Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(Reseau * reseau, Entree * entree);//guillaume

void affiche_reseau(Reseau * reseau);//guilaume

void conversion_binaire(Reseau * reseau);//alex

void calcul_poids(Reseau * reseau);//alex

void set_entree(Reseau * reseau, Entree * entree);//guillaume

void get_sortie(Reseau * reseau, int * sortie);//alex

void iteration_suivante(Reseau * reseau, int indice);//marion
