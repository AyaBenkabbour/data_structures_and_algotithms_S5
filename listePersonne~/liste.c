#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define faux 0
#define vrai 1
#include "liste.h"

//     initialisation de la liste
void initListe(Liste *li, int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
	li->premier = NULL;
	li->dernier = NULL;
	li->courant = NULL;
	li->nbElt = 0;
	li->type = type;
	li->afficher = afficher;
	li->comparer = comparer;
}

//		creation d'une liste
Liste *creerListe(int type, char *(*afficher)(Objet *), int (*comparer)(Objet *, Objet *))
{
	Liste *li = (Liste *)malloc(sizeof(Liste));
	initListe(li, type, afficher, comparer);
	return li;
}

//      verification si la liste est vide
booleen listeVide(Liste *li)
{
	return li->nbElt == 0;
}

//       nombre des elements de la liste
int nbElement(Liste *li)
{
	return li->nbElt;
}

//       ajouter en tete de la liste
static Element *creerElement()
{
	return (Element *)malloc(sizeof(Element)); // return new element
}

//       inserer l'element en tete de liste
void insererEnTeteDeListe(Liste *li, Objet *objet)
{
	Element *nouveau = creerElement();
	nouveau->reference = objet;
	nouveau->suivant = li->premier;
	li->premier = nouveau; // redifinition du premier element dans li
	if (li->dernier == NULL)
	{
		li->dernier = nouveau; // dernier element structure equivalent a le nouveau element creer car il ne contient rien
	}
	li->nbElt++;
}

//       inserer apres un element
static void insererApres(Liste *li, Element *precedent, Objet *objet)
{
	if (precedent == NULL)
	{
		insererEnTeteDeListe(li, objet);
	}
	else
	{
		Element *nouveau = creerElement();
		nouveau->reference = objet;
		nouveau->suivant = precedent->suivant;
		precedent->suivant = nouveau;
		if (precedent == li->dernier)
			li->dernier = nouveau;
		li->nbElt++;
	}
}
//       ajouter en fin de la liste
void insererEnFinDeliste(Liste *li, Objet *objet)
{
	insererApres(li, li->dernier, objet);
}

//       se positionner au debut de la liste
void ouvrirListe(Liste *li)
{
	li->courant = li->premier;
}

//       se positionner sur l element courant
static Element *elementCourant(Liste *li)
{
	Element *ptc = li->courant;
	if (li->courant != NULL)
	{
		li->courant = li->courant->suivant;
	}
	return ptc;
}

//       indication si on est en fin de liste
booleen finListe(Liste *li)
{
	return li->courant == NULL;
}

//       chercher un objet
Objet *chercherUnObjet(Liste *li, Objet *objetCherche)
{
	booleen trouve = faux;
	Objet *objet;
	ouvrirListe(li);
	while (!finListe(li) && !trouve)
	{
		objet = objetCourant(li);
		trouve = li->comparer(objetCherche, objet) == 0;
	}
	return trouve ? objet : NULL;
}

//       objet courant
Objet *objetCourant(Liste *li)
{
	Element *ptc = elementCourant(li);
	return ptc == NULL ? NULL : ptc->reference;
}

//       lister la liste
void listerListe(Liste *li)
{
	ouvrirListe(li);
	while (!finListe(li))
	{
		Objet *objet = objetCourant(li);
		printf("%s\n", li->afficher(objet));
	}
}

//       retrait en tete de liste
Objet *extraireEnTeteDeListe(Liste *li)
{
	Element *extrait = li->premier;
	if (!listeVide(li))
	{
		li->premier = li->premier->suivant;
		if (li->premier == NULL)
			li->dernier = NULL; // Liste devenue vide
		li->nbElt--;
	}
	return extrait != NULL ? extrait->reference : NULL;
}

//       retrait de l element qui suit l element suivant
static Objet *extraireApres(Liste *li, Element *precedent)
{
	if (precedent == NULL)
	{
		return extraireEnTeteDeListe(li);
	}
	Element *extrait = precedent->suivant;
	if (extrait != NULL)
	{
		precedent->suivant = extrait->suivant;
		if (extrait == li->dernier)
			li->dernier = precedent;
		li->nbElt--;
	}
	return extrait != NULL ? extrait->reference : NULL;
}

//       retrait en fin de liste
Objet *extraireEnFinDeListe(Liste *li)
{
	Objet *extrait;
	if (listeVide(li))
	{
		extrait = NULL;
	}
	else if (li->premier == li->dernier)
	{ // un seul element
		extrait = extraireEnTeteDeListe(li);
	}
	else
	{
		Element *ptc = li->premier;
		while (ptc->suivant != li->dernier)
			ptc = ptc->suivant;
		extrait = extraireApres(li, ptc);
	}
	return extrait;
}

//       retrait a partir de la reference
booleen extraireUnObjet(Liste *li, Objet *objet)
{
	Element *precedent = NULL;
	Element *ptc = NULL;
	booleen trouve = faux;

	ouvrirListe(li);
	while (!finListe(li) && !trouve)
	{
		precedent = ptc; // repere l element precedent
		ptc = elementCourant(li);
		trouve = (ptc->reference == objet) ? vrai : faux;
	}
	if (!trouve)
		return faux;

	Objet *extrait = extraireApres(li, precedent);
	return vrai;
}

//        detruire la liste
void detruireListe(Liste *li)
{
	ouvrirListe(li);
	while (!finListe(li))
	{
		Element *ptc = elementCourant(li);

		// free(ptc -> reference) ;  // si on veut detruire les objets
		free(ptc);
	}
	initListe(li, 0, afficher, comparer);
}

char *afficher(Objet *objet)
{
	return (char *)objet;
}
int comparer(Objet *objet1, Objet *objet2)
{
	return strcmp((char *)objet1, (char *)objet2);
}
