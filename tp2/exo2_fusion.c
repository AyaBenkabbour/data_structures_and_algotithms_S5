#include <stdio.h>
#include <stdlib.h>
int* fusionner(int *tab1,int *tab2,int n1,int n2);
void trier(int *tab,int n);
int main(void)
{
    int n1,n2, i;
    int *tab1,*tab2,*tab;
    printf("saisir la taille max du tableau 1: ");
    scanf("%d", &n1);
    tab1=(int*) malloc(n1 * sizeof(int)); // création du premier tableau 
    printf("saisir les données du premier tableau (trié): ");
    for (i = 0; i < n1; i++)
    {                                       // remplissage du premier tableau
        printf("tab1[%d]=", i);
        scanf("%d", (tab1 + i));
    }
    printf("saisir la taille max du tableau 2: ");
    scanf("%d", &n2);
    tab2=(int*) malloc(n2 * sizeof(int)); // création du deuxième tableau 
    printf("saisir les données du deuxième tableau (trié): ");
    for (i = 0; i < n2; i++)
    {                                       // remplissage du deuxième tableau
        printf("tab[%d]=", i);
        scanf("%d", (tab2 + i));
    }
    tab=fusionner(tab1,tab2,n1,n2); //appel à la fonction fusionner() qui retourne l'adresse 
                                    //du premier elmt du tableau résultat
    printf("le tableau fusionné est alors:\n");
    for (i = 0; i < n1+n2; i++)
    {
        printf("tab[%d]=%d\t", i,*(tab+i));
    }
    trier(tab,n1+n2);
    printf("le tableau après tri:\n");
    for (i = 0; i < n1+n2; i++)
    {
        printf("tab[%d]=%d\t", i,*(tab+i));
    }
    return 0;
}

int* fusionner(int *tab1,int *tab2,int n1,int n2){
    int *tab,i,j;
    tab=(int*)malloc((n1+n2)*sizeof(int));
    for(i=0;i<n1;i++){
        *(tab+i)=*(tab1+i);
    }
    for(i=n1,j=0;i<n1+n2;i++,j++){
        *(tab+i)=*(tab2+j);
    }
    return tab;
}

void trier(int *tab,int n){
    int i,j,aide;
    for(i=0;i<n;i++){ 
    for(j=0;j<n-1-i;j++){      
        if(tab[j]>tab[j+1]){
            aide=tab[j];
            tab[j]=tab[j+1];
            tab[j+1]=aide;
        }
    }
}
}