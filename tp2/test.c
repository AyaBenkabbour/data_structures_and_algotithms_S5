#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *s;
int i,n;
s=(char*)malloc(sizeof(s));
printf("veuiller enter le mot\n");
scanf("%s",s);
int l=strlen(s);
printf("la longueur de la chaine:%d\n",l);
return 0;    
}