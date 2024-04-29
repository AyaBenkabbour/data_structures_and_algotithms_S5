#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
    int n, i, max, tab[2000000];
    printf("saisir la taille du tableau:\n");
    scanf("%d", &n);

    /*user input for testing
    printf("saisir les données du tableau:\n");
    for(i=0;i<n;i++){
        printf("tab[%d]=",i);
        scanf("%d",&tab[i]);
    }
    */
    // les valeurs assignés par rand()
    for (i = 0; i < n; i++)
    {
        tab[i] = rand();
    }
    max = tab[0];
    for (i = 1; i < n; i++)
    {
        if (max < tab[i])
        {
            max = tab[i];
        }
    }
    printf("max=%d", max);
    return 0;
}
