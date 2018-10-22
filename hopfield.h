#ifndef HOPFIELD_H
#define HOPFIELD_H

#define LARGEUR_IMAGE 10
#define HAUTEUR_IMAGE 10
#define NB_MOTIF 4
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_IMAGE LARGEUR_IMAGE*HAUTEUR_IMAGE

typedef struct Entree
{
	int ** motifs;
	int largeur_image;
	int hauteur_image;
	int nombre_motifs;

} Entree;

typedef struct Reseau
{
		struct Entree * entree;
		int ** poids;
		int * seuil;
		int * sortie;
		int nombreNeurone;
} Reseau;

/*Motif à apprendre */
extern const char motifApprendre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE];

/*Motif à reconnaitre */
extern const char motifReconnaitre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE];



int initialise_entree(Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(Reseau * reseau, Entree * entree);//guillaume

int seuil(int tmp);
void affiche_reseau(Reseau * reseau);//guilaume

void apprentissage(Reseau * reseau);

void conversion_binaire(Entree * entree);//alex

void calcul_poids(Reseau * reseau);//alex

int iteration_suivante(Reseau * reseau, int indice);//marion

void set_entree(Reseau * reseau, Entree * nouvelleEntree);

void conversion_binaire(Entree * entree);//alex

void calcul_noeud(Reseau * reseau);//alex

int iteration_suivante(Reseau * reseau, int indice);//marion

#endif
