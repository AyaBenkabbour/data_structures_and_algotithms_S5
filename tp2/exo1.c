#include<stdio.h>
#include<stdlib.h>
void ajout(int*tab,int NB_MAX,int pos,int key ); 
int main(void){
int pos,NB_MAX,key,i;
int *tab;

printf("saisir la taille max du tableau: ");
scanf("%d",&NB_MAX);
tab=malloc(NB_MAX*sizeof(int));  //création du tableau
for(i=0;i<NB_MAX;i++){           //remplissage du tableau
    printf("tab[%d]=",i);
    scanf("%d",(tab+i));            
}
printf("saisir la valeur qu'on veut ajouter au tableau:");
scanf("%d",&key);
printf("saisir la position:");
scanf("%d",&pos);
ajout(tab,NB_MAX,pos,key);
printf("le nouvel tableau est alors:\n");
for(i=0;i<NB_MAX+1;i++){
    printf("tab[%d]=%d\t",i,tab[i]);
}
return 0;
}
void ajout(int*tab,int NB_MAX,int pos,int key ){
int i;    
tab=realloc(tab,(NB_MAX+1)*sizeof(int));
for(i=NB_MAX;i>=pos+1;i--){
    tab[i]=tab[i-1];
}
tab[pos]=key;
}