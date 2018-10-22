#define LARGEUR_IMAGE 10
#define HAUTEUR_IMAGE 10
#define NB_MOTIF 4
#include <stdlib.h>

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
  "00     000",
  "0       00",
  "0000000000",
  " 00000000 "},

 {"00      00",
  "0000000000",
  "000    000",
  "0000  0000",
  "0000000000",
  "000    000",
  "000    000",
  "0000000000",
  "000    000",
  " 000  000 "},


 {"00   00   ",
  " 0000 0000",
  " 000000000",
  " 000000000",
  " 0000  000",
  "  0000000 ",
  "  0000000 ",
  "   00000  ",
  "      000 ",
  "     0    ",
}};



int initialise_entree(struct Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(struct Reseau * reseau, struct Entree * entree);//guillaume

void affiche_reseau(struct Reseau * reseau);//guilaume

void conversion_binaire(struct Entree * entree);//alex

void calcul_poids(struct Reseau * reseau);//alex

void iteration_suivante(struct Reseau * reseau, int indice);//marion

void set_entree(struct Reseau * reseau, struct Entree * nouvelleEntree);
