#include <stdio.h>
#include <stdlib.h>


//Fonction retournant un entier exposant d'un autre
int expo(float a, int n){
    int i;
    int e = 1;
    for (i = 0; i < n; i++){
        e = e * a;
    }
    return e;
}

// Fonction calculant le determinant
float determinant(int dim, float M[dim][dim]){
    int colMatrice, j;
    int i = 0;
    float det = 0;
    if(dim == 1){
        return M[0][0];
    }else{
        dim--; // Decrementation de la dimension de la matrice pour le calcul du mineur
        float mineur[dim][dim]; // Le mineur de M

        for(colMatrice = 0; colMatrice < dim + 1; colMatrice++){ // Pour parcourir les colonne de M

            //Construction du mineur de M selon le colonne J
            for (i = 1; i < dim + 1; i++){
                for (j = 0; j < dim + 1; j++){
                    if (j != colMatrice){
                        if (j > colMatrice){
                            mineur[i - 1][j - 1] = M[i][j];
                        }else{
                            mineur[i - 1][j] = M[i][j];
                        }
                    }
                }
            }
            //Expression recursive calculant le determinant
            det = det + expo(-1,colMatrice) * M[0][colMatrice]*determinant(dim, mineur);
        }
        return det;
    }
}

// La fonction main
int main(void) {
    int choix;
    // Construction et remplissage de la matrice
    do{
        printf("======================================================================.\n");
        printf("CE PROGRAMME CALCUL LE DETERMINANT D'UNE MATRICE SAISIE AU CLAVIER.\n");
        printf("======================================================================.\n");
        int n = getDim();
        float A[n][n];
        int i, j;
        printf("\n");
        for(i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                printf("Entrer l'element de %d ligne et de la %d colonne : ", i, j);
                scanf("%f", &A[i][j]);
            }
        }
        printf("\nLe determinant de votre matrice est : %.2f", determinant(n, A));

        printf("\n\n======================================================================.\n");
        printf("\nTaper q pour quiter le programme.\n");
        printf("Taper n'importe quoi pour recommencer.\n");
        printf("\nVoulez-vous continuer : ");
        clean_stdin();
        scanf("%d", &choix);
        clean_stdin();
        system("cls");
    }while(choix != 0);

    system("cls");
    printf("\n\nAU REVOIR  !.\n\n\n\n\n\n\n\n");
    return 0;
}


int getDim(){ //demande a l'utilisateur un entier positif comme dimension de la matrice
    int dim;
    int essaie = 0;
    do{
        if (essaie == 0){
            printf("\nEnter la dimension de la matrice : ");
            essaie++;
        }else{
            printf("\nVous devez entrer un entier positif\nEnter la dimension de la matrice : ");
        }
    }while (((scanf("%d", &dim)!=1) && clean_stdin()) || dim < 0);
    return dim;
}

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
