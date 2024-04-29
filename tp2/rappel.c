#include<stdio.h>
static int a;
int main()
{ void fct(void) ;
   int n ;
   for ( n=1 ; n<=5 ; n++) fct() ;


a=12;
printf ("appel numéro : %d\n", a) ;
return 0;
}
void fct(void)
{int i=0 ;
 i=i+1 ;
   printf ("appel numéro : %d\n", i) ;
   
}
