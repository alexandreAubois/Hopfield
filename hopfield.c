#include "hopfield.h"

const char motifApprendre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
        {{			 "    00    ",
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

const char motifReconnaitre[NB_MOTIF][LARGEUR_IMAGE][HAUTEUR_IMAGE] =
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

int initialise_entree(Entree *entree, int nombre_motifs) {
    int i;
    entree->motifs = (int **) malloc(sizeof(int *) * nombre_motifs);
    for (i = 0; i < nombre_motifs; i++) {
        entree->motifs[i] = (int *) calloc(TAILLE_IMAGE, sizeof(int));
    }
    entree->hauteur_image = HAUTEUR_IMAGE;
    entree->largeur_image = LARGEUR_IMAGE;
    entree->nombre_motifs = nombre_motifs;

    return 0;
}

int initialise_reseau(Reseau *reseau, Entree *entree) {
    int i;
    reseau->nombreNeurone = entree->nombre_motifs;
    reseau->entree = entree;
    reseau->poids = (int **) calloc(entree->nombre_motifs, sizeof(int *));
    reseau->seuil = (int *) calloc(entree->nombre_motifs, sizeof(int));
    for (i = 0; i < entree->nombre_motifs; i++) {
        reseau->seuil[i] = 0;
        reseau->poids[i] = (int *) calloc(TAILLE_IMAGE, sizeof(int));
    }
    reseau->sortie = (int *) calloc(entree->nombre_motifs, sizeof(int));

    return 0;
}

void conversion_binaire(Entree * entree) {
    int n, x, y;

    for (n = 0; n < entree->nombre_motifs; n++) {
        for (x = 0; x < entree->largeur_image; x++) {
            for (y = 0; y < entree->hauteur_image; y++) {
                switch (motifApprendre[n][x][y]) {
                    case ' ':
                        entree->motifs[n][x] = -1;
                        break;

                    case '0':
                        entree->motifs[n][x ] = 1;
                        break;

                    default:
                        entree->motifs[n][x ] = -1;
                        break;
                }
            }
        }
    }

}

void affiche_reseau(Reseau *reseau) {
    int i, j;

    for (i = 0; i < reseau->entree->largeur_image; i++) {
        for (j = 0; j < reseau->entree->hauteur_image; j++) {
            switch (reseau->sortie[i * LARGEUR_IMAGE + j]) {
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
		printf("Sortie du noeud n°%d : %d\n", n, reseau->sortie[n]);
	}
}

int iteration_suivante(Reseau * reseau, int indice)
{
	int j,somme,resu, sortie, changer= 0;

	//Pour chaque neurone
	for(j = 0; j < reseau->nombreNeurone; j++){
		//Calcul de l'entrée pondérée
		resu = reseau->poids[indice][j] * reseau->sortie[j];
		somme = somme + resu;
	}
	//Seuillage
	if(somme > 0){
		sortie = 1;
	}
	else if (somme < 0){
		sortie =  -1;
	}
	//Si l'entrée pondérée = 0, la sortie ne change pas;
	else if(somme == 0){
		sortie = reseau->sortie[indice];
	}

	if(reseau->sortie[indice] != sortie){
		reseau->sortie[indice] = sortie;
		changer = 1;
	}

	return changer;
}

int seuil(int tmp){
	if(tmp >= 0){
		return 1;
	}else{
		return -1;
	}
}

void apprentissage(Reseau * reseau){

}

void set_entree(Reseau *reseau, Entree *nouvelleEntree) {

}
