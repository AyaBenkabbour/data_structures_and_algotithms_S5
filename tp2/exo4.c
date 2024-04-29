#include<stdio.h>
#include<stdlib.h>

void suite_U(int n);
int main(){
int n;

printf("saisir le nonbre de termes de la suite (U)n voulu:\n");
scanf("%d",&n);
suite_U(n);

}
void suite_U(int n){
int i;
unsigned long long int *U;
U=(unsigned long long int*)malloc(n*sizeof(unsigned long long int));  //allocation de la mémoire pour un tableau de n elements
*U=1;           //premier element de la suite  U
for(i=0;i<n;i++){               
    *(U+i+1)=(3)*(*(U+i))*(*(U+i))+(2)*(*(U+i))+1;
}
for(i=0;i<n;i++){   //affichage des n premiers termes de la suite U
    printf("U(%d)=%llu\n",i,*(U+i));
}
}