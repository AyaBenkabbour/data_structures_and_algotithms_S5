
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int** creer_mat(int nbr_li,int nbr_col); //declaration des fonctions
void afficher_mat(int **mat,int nbr_li,int nbr_col );
int** addition_mat(int **mat1,int **mat2,int nbr_li,int nbr_col);
int** multiplication_mat(int **mat1,int **mat2,int nbr_li1,int nbr_col1,int nbr_li2,int nbr_col2);
int main(void) {
int n,i ,j,nbr_col,nbr_li;
int**mat,**add;
printf("saisir la taille de la matrice:\n");
printf("saisir le nombre de lignes\n");
scanf("%d",&nbr_li);
printf("saisir le nombre de colonnes\n");
scanf("%d",&nbr_col);
int **mat1,**mat2;
printf("la premiere matrice:\n");
mat1=creer_mat(nbr_li,nbr_col);
afficher_mat(mat1,nbr_li,nbr_col);
printf("la deuxième matrice:\n");
mat2=creer_mat(nbr_li,nbr_col);
afficher_mat(mat2,nbr_li,nbr_col);
printf("l'addition de ces deux matrices nous donne:\n");
add=addition_mat(mat1,mat2,nbr_li,nbr_col);
afficher_mat(add,nbr_li,nbr_col);
printf("la multiplication de ces deux matrices nous donne:\n");
mat=multiplication_mat(mat1,mat2,nbr_li,nbr_col,nbr_li,nbr_col);  
afficher_mat(mat,nbr_li,nbr_col);
return 0 ;
}
/*********************************************************************************************/
int** creer_mat(int nbr_li,int nbr_col){
int i,j,**mat;    
mat=(int**)malloc(nbr_li*sizeof(int*));     //allocation dynamique d'une matrice ( tableau de pointeurs)
for(i=0;i<nbr_li;i++){           
    mat[i]=(int*)malloc(nbr_col*sizeof(int)); // allocation dynamique d'un tableau d'entiers
}
for(i=0;i<nbr_li;i++){
  for(j=0;j<nbr_col;j++){
    mat[i][j]=rand();     //on affecte à chaque élément de la matrice une valeur aléatoire assigné par rand()
}}
return mat;             //la valeur de retour de la fonction est l'adresse du premier element de la matrice 
}


void afficher_mat(int **mat,int nbr_li,int nbr_col ){ //la matrice ne retourne aucune valeur,d'où le type de retour void
    int i,j;
    for(i=0;i<nbr_li;i++){                 
        for(j=0;j<nbr_col;j++){
         printf("%d\t",mat[i][j]);
         printf("\t");
        }
    printf("\n");
}
}
int** addition_mat(int **mat1,int **mat2,int nbr_li,int nbr_col){
    int i,j,**add;
    add=creer_mat(nbr_li,nbr_col); //création de la matrice add où 
    for(i=0;i<nbr_li;i++){          //on va stocker la matrice résultante de l'addition de mat1 et mat2
        for(j=0;j<nbr_col;j++){
            add[i][j]=mat1[i][j]+mat2[i][j];//on additionne chaque element de chacune des matrices         
        }
    }
return add; //la fonction retourne l'adresse de la matrice add q'on a créé 
}
int** multiplication_mat(int **mat1,int **mat2,int nbr_li1,int nbr_col1,int nbr_li2,int nbr_col2){
    int i,k,m,**mult;
    int nbr_li=nbr_li1, nbr_col=nbr_col2;
    mult=creer_mat(nbr_li,nbr_col);//création de la matrice add où on va stocker 
                                  //la matrice résultante de la multiplication de mat1 et mat2
    if(nbr_col1==nbr_li2){        // ceci est la condition pour que la multiplication de deux matrices soit juste 
        for(k=0;k<3;k++){
            for(m=0;m<3;m++){
                for(i=0;i<3;i++){
                     mult[k][m]+=mat1[k][i]*mat2[i][m]; //on effectur la multiplication sur chaque elmt de chacune des matrices
                }
            }    
        } 
     return mult;   //la fonction retourne l'adresse de la matrice mult q'on a créé 
    }  
    else printf("erreur! veuiller respecter la regle de multiplication de matrices");
    return 0;   

}

   