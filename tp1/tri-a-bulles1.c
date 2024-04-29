#include<stdio.h>
int main(void) 
{
int n,i,j,o=0,aide,b[100];
printf("saisir la taille du tableau:\n");
scanf("%d",&n);
printf("saisir les donnés du tableau:\n");
for(i=0;i<n;i++){
    printf("b[%d]=",i);
    scanf("%d",&b[i]);
}
for(i=0;i<n;i++){ 
    for(j=0;j<n-1-i;j++){      //pour i=1 la dernière valeur que doit atteindre j+1 est n-1 donc j doit attaindre n-2 comme dernière valeur donc j va de 1 à n-2-i
        if(b[j]>b[j+1]){
            aide=b[j];
            b[j]=b[j+1];
            b[j+1]=aide;
        }
    }
}
printf("voici le nouvel ordre du tableau:\n");
for(i=0;i<n;i++){
    printf("b[%d]=%d\t",i,b[i]);
}
}
