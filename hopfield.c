#include "hopfield.h"

const char motifApprendre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
        {{		 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     "},

         {		 "          ",
                 "          ",
                 "          ",
                 "          ",
                 "          ",
                 "0000000000",
                 "          ",
                 "          ",
                 "          ",
                 "          "},

         {		 "          ",
                 "  000000  ",
                 "  0    0  ",
                 "  0    0  ",
                 "  0    0  ",
                 "  000000  ",
                 "          ",
                 "          ",
                 "          ",
                 "          "},


         {		 "  00   00 ",
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

const char sortieDesireeAppr[NB_MOTIF][4] =
{
	{ 1,0,0,0},
	{ 0,1,0,0},
	{ 0,0,1,0},
	{ 0,0,0,1}
};

/*Motif à reconnaitre */

const char motifReconnaitre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
        {{		 "    0     ",
                 "          ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     ",
                 "    0     "},

         {		 "          ",
                 "          ",
                 "          ",
                 "          ",
                 "          ",
                 "0000 00000",
                 "          ",
                 "          ",
                 "          ",
                 "          "},

         {		 "          ",
                 "  000000  ",
                 "  0    0  ",
                 "  000000  ",
                 "  0    0  ",
                 "  000000  ",
                 "          ",
                 "          ",
                 "          ",
                 "          "},

         {		 "00   00   ",
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

const char sortieDesireeTest[NB_MOTIF][4] =
{
	{ 1,0,0,0},
	{ 0,1,0,0},
	{ 0,0,1,0},
	{ 0,0,0,1}
};

float randomFloat()
{
    return (float)rand() / (float)RAND_MAX;
}

int initialise_entree(Entree *entree, int nombre_motifs) {
    int i;
    entree->motifs = (int **) malloc(sizeof(int *) * nombre_motifs);
    for (i = 0; i < nombre_motifs; i++) {
        entree->motifs[i] = (int *) calloc(TAILLE_IMAGE, sizeof(int));
    }
    entree->sortiesDesirees = (float **) malloc(sizeof(float *) * nombre_motifs);
    for (i = 0; i < nombre_motifs; i++) {
        entree->sortiesDesirees[i] = (float *) calloc(nombre_motifs, sizeof(float));
    }
    entree->hauteur_image = HAUTEUR_IMAGE;
    entree->largeur_image = LARGEUR_IMAGE;
    entree->nombre_motifs = nombre_motifs;

    return 0;
}

int initialise_reseau(Reseau *reseau, Entree *entree) {
    int i,j;
    reseau->nombreNeurone = entree->nombre_motifs;
    reseau->entree = entree;
    reseau->poids = (float **) calloc(entree->nombre_motifs, sizeof(float *));
    reseau->biais = (float *) calloc(entree->nombre_motifs, sizeof(float));
    reseau->seuil = (int *) calloc(entree->nombre_motifs, sizeof(int));
    for (i = 0; i < entree->nombre_motifs; i++) {
        reseau->seuil[i] = 0;
        reseau->poids[i] = (float *) calloc(TAILLE_IMAGE, sizeof(float));
        reseau->biais[i] = randomFloat();
        for(j = 0; j< TAILLE_IMAGE; j++)
			reseau->poids[i][j] = randomFloat();
    }
    reseau->sortie = (float *) calloc(entree->nombre_motifs, sizeof(float));

    return 0;
}

void conversion_binaire(Entree * entree, int appr) {
    int n, x, y, i;

    for (n = 0; n < entree->nombre_motifs; n++) {
        for (x = 0; x < entree->largeur_image; x++) {
            for (y = 0; y < entree->hauteur_image; y++) {
				if(appr == 1)
				{
					switch (motifApprendre[n][x][y]) {
						case ' ':
							entree->motifs[n][x] = -1;
							break;
						case '0':
							entree->motifs[n][x] = 1;
							break;
						default:
							entree->motifs[n][x] = -1;
							break;
					}
				}
				else
				{
					switch (motifReconnaitre[n][x][y]) {
						case ' ':
							entree->motifs[n][x] = -1;
							break;
						case '0':
							entree->motifs[n][x] = 1;
							break;
						default:
							entree->motifs[n][x] = -1;
							break;
					}
				}
            }
        }
        for(i = 0; i < entree->nombre_motifs; i++)
        if(appr)
		{
			entree->sortiesDesirees[n][i] = sortieDesireeAppr[n][i];
		}
		else
		{
			entree->sortiesDesirees[n][i] = sortieDesireeTest[n][i];
		}
    }

}


void calcul_noeud(struct Reseau * reseau, int motif)
{
	int n, x;
	float tmp = 0;
	for (n = 0; n < reseau->nombreNeurone; n++)
	{
		tmp = 0;
		for (x = 0; x < TAILLE_IMAGE; x++)
		{
			tmp += (float)reseau->entree->motifs[motif][x] * reseau->poids[n][x];
		}
		tmp += reseau->biais[n];
		reseau->sortie[n] = sigmoid(tmp);
		printf("Sortie du noeud n°%d : %f  pour l'entree : %d Desire : %f\n", n, reseau->sortie[n], motif, reseau->entree->sortiesDesirees[motif][n]);
	}
}

void calcul_noeud_unique(struct Reseau * reseau, int neuronne, int motif)
{
	int x;
	float tmp = 0;
	for (x = 0; x < TAILLE_IMAGE; x++)
	{
		tmp += (float)reseau->entree->motifs[motif][x] * reseau->poids[neuronne][x];
	}
	tmp += reseau->biais[neuronne];
	reseau->sortie[neuronne] = sigmoid(tmp);
	//printf("Sortie du noeud n°%d : %f  pour l'entree : %d Desire : %f\n", neuronne, reseau->sortie[neuronne], motif, reseau->entree->sortiesDesirees[motif][neuronne]);
}

float seuil(float tmp){
	if(tmp > 0){
		return 1;
	}else if(tmp < 0)
	{
		return -1;
	}
	else
	{
		return tmp;
	}
}

float sigmoid(float x)
{
     float exp_value;
     float return_value;

     /*** Exponential calculation ***/
     exp_value = exp((double) -x);

     /*** Final sigmoid value ***/
     return_value = 1 / (1 + exp_value);

     return return_value;
}

//Modification des poids avec la loi de Hebb
void apprentissageHebb(Reseau * reseau, int iteration)
{
	int index_neuronne = 0, index_entree = 0;
	float vitesse = 0.5;
	int index_motif = 0;
	int nbIter = 0;
	float erreur;
	float erreurGlob = 0;
	do
	{
		for(index_neuronne=0; index_neuronne < reseau->nombreNeurone; index_neuronne++)
		{
			calcul_noeud_unique(reseau, index_neuronne, index_motif);
			nbIter += 1;
			erreurGlob = 0;
			erreur = reseau->entree->sortiesDesirees[index_motif][index_neuronne]-reseau->sortie[index_neuronne];
			//printf("%f\n", erreur);
			if( fabs(erreur) > 0.2 )
			{
				for(index_entree=0; index_entree < TAILLE_IMAGE; index_entree++)
				{
					//printf("Old : %f", reseau->poids[index_neuronne][index_entree]);
					reseau->poids[index_neuronne][index_entree] += (vitesse * reseau->entree->motifs[index_motif][index_entree] * erreur);
					//printf("New : %f\n", reseau->poids[index_neuronne][index_entree]);
				}
				reseau->biais[index_neuronne] += erreur * vitesse;
				erreurGlob += (erreur * erreur);
				index_motif += 1;
				//printf("Motif corrige : %d\n", index_motif);
				if(index_motif == 4)
					index_motif = 0;
			}
			else
			{
				if(index_neuronne == 3)
				{
					index_motif += 1;
					printf("Motif simple : %d\n", index_motif);
					if(index_motif == 4)
						index_motif = 0;
				}
			}
		}
	}while(nbIter < iteration);
}


void set_entree(Reseau *reseau, Entree *nouvelleEntree) {
	reseau->entree = nouvelleEntree;
}

void libere_entree(Entree * entree){
  free(entree);
}

void libere_reseau(Reseau * reseau){
    free(reseau);
}
