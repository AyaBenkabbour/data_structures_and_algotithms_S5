#include<stdio.h>
#include<stdlib.h>
int recherche(int t[],int x, int keyy);
int main(void) {
int taille,key,k,i,n,tab[]={1,7,8,9,12,15,18,22,30,31};
taille=sizeof(tab)/sizeof(tab[0]);
printf("saisir l'element quon cherche:\n");
scanf("%d",&key);
k=recherche(tab,taille,key);
printf("l'indice de l'element quon cherche est : %d\n",k);
return 0;
}
int recherche(int t[],int x, int keyy){
int first, last,r,i;
last=x-1;
first=0;
r=0;
while(r==0){
i=(last+first)/2;
if(keyy==t[i]){
    r=1;
    }
else{ if(keyy>t[i]){
    first=i+1;
    r=0;
    }
else {
    last=i-1;
    r=0;}
}}
return i;
}













// printf("saisir la taille du tableau:\n");
// scanf("%d",&n);

// //user input for testing
// printf("saisir les données du tableau:\n");
// for(i=0;i<n;i++){
//     printf("tab[%d]=",i);
//     scanf("%d",&tab[i]);
// }  




// printf("saisir l'element quon cherche:\n");
// scanf("%d",&key);