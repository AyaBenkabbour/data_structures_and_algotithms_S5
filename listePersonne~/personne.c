#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personne.h"

//        creer une personne
Personne *creerPersonne(char *nom, char *prenom)
{
	Personne *p = (Personne *)malloc(sizeof(Personne));
	strcpy(p->nom, nom);
	strcpy(p->prenom, prenom);
	return p;
}

//        ecrire une personne
char *ecrirePersonne(Objet *objet)
{
	Personne *p = (Personne *)objet; // casting
	char *output = (char *)malloc(sizeof(Personne));
	snprintf(output, sizeof(Personne), "%s %s\n", p->nom, p->prenom); // stocks nom et prenom inside of output
	return output;													  // et les affiche en meme temps
}

//        comparer deux personnes
int comparerPersonne(Objet *objet1, Objet *objet2)
{
	Personne *p1 = (Personne *)objet1;
	Personne *p2 = (Personne *)objet2;
	return strcmp(p1->nom, p2->nom);
}
