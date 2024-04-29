#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char* multichar(char*s,int n);
int main(){
char *s, *ch;
int i,n;
s=(char*)malloc(sizeof(s));
printf("veuiller enter le mot\n");
scanf("%s",s);
int l=strlen(s);
printf("veuiller enter le nombre de répetitions:\n");
scanf("%d",&n);

ch=(char*)malloc(l*n*sizeof(s));
ch=multichar(s,n);
printf("le most après:%s\n",ch);
return 0;    
}
char* multichar(char*s,int n){
int i,j;
int l=strlen(s);
char* nouvelle_chaine;
nouvelle_chaine=(char*)malloc(n*l*sizeof(char));
for(i=0;i<l;i++){
    for(j=0;j<n;j++){
        nouvelle_chaine[n*i+j]=s[l-1-i];
    }
}
nouvelle_chaine[n*l]='\0';
return nouvelle_chaine;
}