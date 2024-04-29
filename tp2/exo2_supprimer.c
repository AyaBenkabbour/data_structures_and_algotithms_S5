#include<stdio.h>
#include<stdlib.h>
void supp(int*tab,int NB_MAX,int pos); 
int main(void){
int pos,NB_MAX,i;
int *tab;

printf("saisir la taille max du tableau: ");
scanf("%d",&NB_MAX);
tab=malloc(NB_MAX*sizeof(int));  //création du tableau
for(i=0;i<NB_MAX;i++){           //remplissage du tableau
    printf("tab[%d]=",i);
    scanf("%d",(tab+i));            
}
printf("saisir la position de la valeur qu'on veut supprimer du tableau:");
scanf("%d",&pos);
supp(tab,NB_MAX,pos);
printf("le nouvel tableau est alors:\n");
for(i=0;i<NB_MAX-1;i++){
    printf("tab[%d]=%d\t",i,tab[i]);
}
return 0;
}
void supp(int*tab,int NB_MAX,int pos){
int i;    
for(i=pos;i<NB_MAX-1;i++){
    tab[i]=tab[i+1];
}
}