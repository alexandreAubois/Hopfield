#define LARGEUR_IMAGE 10
#define HAUTEUR_IMAGE 10

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

/*Motif à apprendre */
char motifApprendre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
{{"    00    ",
  "   0000   ",
  "  00  00  ",
  "  0    0  ",
  " 00    00 ",
  " 00000000 ",
  " 00000000 ",
  " 00    00 ",
  " 00    00 ",
  " 00    00 "},

 {"0000000000",
  "0000000000",
  "00      00",
  "00        ",
  "00        ",
  "00    0000",
  "00      00",
  "00      00",
  "0000000000",
  "0000000000"},

 {"00      00",
  "000    000",
  "000    000",
  "0000  0000",
  "0000000000",
  "000 00 000",
  "000    000",
  "000    000",
  "000    000",
  "000    000"},


 {"  00   00 ",
  " 0000 0000",
  " 000000000",
  " 000000000",
  " 000000000",
  "  0000000 ",
  "  0000000 ",
  "   00000  ",
  "    000   ",
  "     0    ",
}};

/*Motif à reconnaitre */

char motifReconnaitre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
{{"  00      ",
  "   000    ",
  "  00  00  ",
  "   0    0 ",
  " 00     00",
  " 00000000 ",
  "  00000000",
  " 00    00 ",
  " 00    000",
  "000    00 "},

 {" 00000000 ",
  "0000000000",
  "00      00",
  "000       ",
  "00000     ",
  "00  000000",
  "00   00   ",
  "0     0000",
  "0000000000",
  " 00000000 "},

 {"00      00",
  "0000000000",
  "000    000",
  "0000  0000",
  "0000  0000",
  "000    000",
  "0000000000",
  "000    000",
  "000   000 ",
  "000  000  "},


 {" 00  00   ",
  " 0000 0000",
  "  00000000",
  " 00000000 ",
  "00000000  ",
  "  0000000 ",
  "   0000000",
  "   00000  ",
  "   000    ",
  "   0      ",
}};



int initialise_entree(Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(Reseau * reseau, Entree * entree);//guillaume

void affiche_reseau(Reseau * reseau);//guilaume

void conversion_binaire(Reseau * reseau);//alex

void calcul_poids(Reseau * reseau);//alex

void set_entree(Reseau * reseau, Entree * entree);//guillaume

void get_sortie(Reseau * reseau, int * sortie);//alex

void iteration_suivante(Reseau * reseau, int indice);//marion
