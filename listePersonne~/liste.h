#ifndef LISTE_H
#define LISTE_H

typedef void Objet;

//    element de la liste
typedef struct element{
	Objet* reference;
	struct element* suivant;
} Element;


//    la Liste
typedef struct{
	Element* premier;                 // premier element
	Element* dernier;				  // dernier
	Element* courant;				  // en cours 
	int nbElt;                        // nombre d'element
	int type;                         // 0 : simple , 1 : croissant , 2 : decroissant
	char* (*afficher) (Objet*);
	int (*comparer) (Objet*, Objet*);
} Liste;


//     initialisation de la liste
void initListe (Liste* li, int type, char*(*afficher)(Objet*), int (*comparer)(Objet*, Objet*));

//		creation d'une liste
Liste* creerListe(int type, char* (*afficher)(Objet*), int(*comparer)(Objet*, Objet*));
//       inserer l'element en tete de liste 
void insererEnTeteDeListe(Liste*li, Objet* objet);

//     type booleen
typedef int booleen;

//       nombre des elements de la liste
int nbElement(Liste* li);

//       ajouter en tete de la liste
static Element* creerElement();

//       inserer apres un element
static void insererApres(Liste* li, Element* precedent, Objet* objet);

//       ajouter en fin de la liste
void insererEnFinDeliste(Liste* li, Objet* objet);

//       se positionner au debut de la liste
void ouvrirListe(Liste* li);

//       indication si on est en fin de liste 
booleen finListe(Liste* li);

//       chercher un objet
Objet * chercherUnObjet(Liste* li, Objet* objetCherche);

//       objet courant
Objet* objetCourant (Liste* li);

//       lister la liste
void listerListe (Liste* li);

//       indication si la liste est vide
booleen listeVide(Liste* li);

//       se positionner sur l element courant
static Element* elementCourant(Liste* li);

//       retrait en tete de liste 
Objet* extraireEnTeteDeListe (Liste* li);

//       retrait de l element qui suit l element suivant
static Objet* extraireApres(Liste* li, Element* precedent);

//       retrait en fin de liste
Objet* extraireEnFinDeListe (Liste* li);

//       retrait a partir de la reference 
booleen extraireUnObjet(Liste* li, Objet* objet);

//        detruire la liste
void detruireListe(Liste* li);


int comparer(Objet* objet1, Objet* objet2);
char* afficher (Objet* objet);

#endif
