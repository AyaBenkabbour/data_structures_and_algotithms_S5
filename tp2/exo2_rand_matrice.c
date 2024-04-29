#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int** creer_mat(int nbr_li,int nbr_col); //declaration de la fonction
int main(void) {
int n,i ,j,nbr_col,nbr_li;
int**mat;
printf("saisir la taille de la matrice:\n");
printf("saisir le nombre de lignes\n");
scanf("%d",&nbr_li);
printf("saisir le nombre de colonnes\n");
scanf("%d",&nbr_col);
mat=creer_mat(nbr_li,nbr_col);       
return 0 ;
}
int** creer_mat(int nbr_li,int nbr_col){
int i,j,**mat;    
mat=(int**)malloc(nbr_li*sizeof(int*));     //allocation dynamique d'un tableau de pointeurs
for(i=0;i<nbr_li;i++){           
    mat[i]=(int*)malloc(nbr_col*sizeof(int)); // allocation dynamique d'un tableau d'entiers
}
for(i=0;i<nbr_li;i++){
  for(j=0;j<nbr_col;j++){
    mat[i][j]=rand();                   //les valeurs assignés par rand()
}}
return mat;             //la valeur de retour de la fonction est l'adresse du premier element de la matrice 
}

/*********************************************************************************************/
void afficher_mat(int **mat,int nbr_li,int nbr_col ){
    int i,j;
    for(i=0;i<nbr_li;i++){                 
        for(j=0;j<nbr_col;j++){
         printf("mat[%d][%d]=%d\t",i,j,mat[i][j]);
         printf("\t");
        }
    printf("\n");
}
}
/*********************************************************************************************/
int** addition_mat(int **mat1,int **mat2,int nbr_li,int nbr_col){
    int i,j,**add;
    add=creer_mat(nbr_li,nbr_col);
    for(i=0;i<nbr_li;i++){
        for(j=0;j<nbr_col;j++){
            add[i][j]=mat1[i][j]+mat2[i][j];           
        }
    }
return add;
}
/*********************************************************************************************/
int** multiplication_mat(int **mat1,int **mat2,int nbr_li1,int nbr_col1,int nbr_li2,int nbr_col2){
    int i,k,m,**mult;
    int nbr_li, nbr_col;
    mult=creer_mat(nbr_li,nbr_col);
    if(nbr_col1==nbr_li2){
        for(k=0;k<3;k++){
            for(m=0;m<3;m++){
                for(i=0;i<3;i++){
                     mult[k][m]+=mat1[k][i]*mat2[i][m];
                }
            }    
        } 
     return mult;
    }  
    else printf("erreur! veuiller respecter la regle de multiplication de matrices")  ; 

}
/*********************************************************************************************/
   