#ifndef HOPFIELD_H
#define HOPFIELD_H

#define LARGEUR_IMAGE 10
#define HAUTEUR_IMAGE 10
#define NB_MOTIF 4
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAILLE_IMAGE LARGEUR_IMAGE*HAUTEUR_IMAGE

typedef struct Entree
{
	int ** motifs;
	int largeur_image;
	int hauteur_image;
	int nombre_motifs;
	float ** sortiesDesirees;
} Entree;

typedef struct Reseau
{
		struct Entree * entree;
		float ** poids;
		int * seuil;
		float * biais;
		float * sortie;
		int nombreNeurone;
} Reseau;

/*Motif à apprendre */
extern const char motifApprendre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE];

/*Motif à reconnaitre */
extern const char motifReconnaitre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE];

extern const char sortieDesireeAppr[NB_MOTIF][4];

extern const char sortieDesireeTest[NB_MOTIF][4];

float randomFloat();

int initialise_entree(Entree * entree, int nombre_motifs);//guillaume

int initialise_reseau(Reseau * reseau, Entree * entree);//guillaume

void libere_entree(Entree * entree, int nombre_motifs);

void libere_reseau(Reseau * reseau, Entree *entree);

float seuil(float tmp);

float sigmoid(float x);

void affiche_reseau(Reseau * reseau);//guilaume

void apprentissage(Reseau * reseau);

void conversion_binaire(Entree * entree, int appr);//alex

void calcul_poids(Reseau * reseau);//alex

void set_entree(Reseau * reseau, Entree * nouvelleEntree);

void calcul_noeud(Reseau * reseau, int motif);//alex

void calcul_noeud_unique(struct Reseau * reseau, int neuronne, int motif);

void apprentissageHebb(Reseau * reseau, int iteration);



#endif
