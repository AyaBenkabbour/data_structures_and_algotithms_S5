#include <stdio.h>
#include <stdlib.h>
void inverser(int tab[], int NB_MAX);
int main(void)
{
    int NB_MAX, i;
    int *tab;
    printf("saisir la taille max du tableau: ");
    scanf("%d", &NB_MAX);
    tab = malloc(NB_MAX * sizeof(int)); // création du tableau
    for (i = 0; i < NB_MAX; i++)
    { // remplissage du tableau
        printf("tab[%d]=", i);
        scanf("%d", (tab + i));
    }
    inverser(tab, NB_MAX);
    printf("le tableau inversé est alors:\n");
    for (i = 0; i < NB_MAX; i++)
    {
        printf("tab[%d]=%d\t", i, tab[i]);
    }
    return 0;
}
void inverser(int tab[],int NB_MAX){
int i,*p,aide;
for(p=tab,i=0;i<NB_MAX/2;p++,i++){
   *p=aide;
   *p=*(tab+NB_MAX-1-i);
   *(tab+NB_MAX-1-i)=aide;

}
}















    
// void inverser(int tab[],int NB_MAX){  //avec deux pointeurs
// int i,*p,*q,aide;
// for(p=tab,q=tab+NB_MAX-1;p<q;p++,q--){
//    *p=aide;
//    *p=*q;
//    *q=aide;

// }
// }

// void inverser(int tab[], int NB_MAX)   //avec tableau simple
// {
//     int i, aide;
//     for (i = 0; i < NB_MAX / 2; i++)
//     {
//         tab[i] = aide;
//         tab[i] = tab[NB_MAX - 1 - i];
//         tab[NB_MAX - 1 - i] = aide;
//     }
// }