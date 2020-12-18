#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :   NASSIRI               Prénom :    Louis                      */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compléter code ici pour tableau
	int idx;

	if (rep->nb_elts < MAX_ENREG) {
		*(rep->tab + rep->nb_elts) = enr; // on definie le dernier element de la liste avec enr
		rep->nb_elts++;                   // on a donc un element en plus
		rep->est_trie = false;            // la liste n'est pas triee
		modif = true;                     // on a effectue une modification
		return(OK);
	}
	else {
		return(ERROR);
	}


	
	
#else
#ifdef IMPL_LIST
	bool inserted = false;
	if (rep->nb_elts == 0) {          //si le repertoire est vide
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}
	}
	else {               // si il n'est pas vide on ajoute a la bonne  place
		int i = 0;
		while ((i < rep->nb_elts) && (est_sup(enr, (GetElementAt(rep->liste, i)->pers)))) {
			i++;
		} // on augmente un compteur tant qu'on est dans la liste et que enr est superieur à l'element compteur de la liste
		InsertElementAt(rep->liste, i, enr); //on insere donc l elment a l empacement compteur, ainsi deja classe
		rep->nb_elts++;                      // on augmente de 1 le nombre d'element
		modif = true;                        // on a modifie
		rep->est_trie = true;                 // la liste est triee
		return(OK);
	}



#endif
	
#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1)	{	/* s'il y a au moins un element ds le tableau et que l'indice pointe a l'interieur */
		if (indice<=rep->nb_elts) {
			for (int i = 0; i < rep->nb_elts; i++) {
				*(rep->tab + i) = *(rep->tab + i + 1);
			}
		}
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}
	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr) {
	printf("%s, %s, %s", enr.nom,enr.prenom,enr.tel);
	

} /* fin affichage_enreg */


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr) {
	printf(" |%-30s|%-30s|%-20s\n", enr.nom, enr.prenom, enr.tel);
	// comme fonction affichage_enreg, mais avec présentation alignées des infos
} /* fin affichage_enreg */



  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2) {
	// code à compléter ici
	if (strcmp(enr1.nom, enr2.nom) > 0) {		//si 1er supérieur au 2e = on renvoie true // compare en code ASCII
		return (true);
	}
	else {
		return(false);
	}
	if (strcmp(enr1.nom, enr2.nom) > 0) {		//on arrive ici uniquement si les noms de famille sont égaux
		return (true);
	}
	else {
		return(false);
	}
}
 

/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep) {
	Enregistrement tmp;
#ifdef IMPL_TAB		//code pour le tableau
	for (int i = 0; i < rep->nb_elts-1; i++) {				//double boucle afin de trier correctement l'ensenmble du répertoire
		for (int j = 0; i < rep->nb_elts - i - 1; j++) {
			if (est_sup(*(rep->tab + j),*(rep->tab + j + 1))) {
				tmp = *(rep->tab + j + 1);
				*(rep->tab + j + 1) = *(rep->tab + j);
				*(rep->tab + j) = tmp;
			}
		}
	}
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind) {
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin=rep->nb_elts-1;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles on place la chaine recherchee et la chaine lue dans le tableau,
							afin de les convertir en majuscules et les comparer */
	char tmp_nom2[MAX_NOM]; 
	bool trouve = false;		
	strncpy_s(tmp_nom, _countof(tmp_nom), nom, _TRUNCATE);

#ifdef IMPL_TAB
	while ((i <= ind_fin) && (!trouve)) {
		strncpy_s(tmp_nom2, _countof(tmp_nom2), rep->tab[i].nom, _TRUNCATE);
		for (unsigned i = 0; i < strlen(tmp_nom); i++) {
			tmp_nom[i] = toupper(tmp_nom[i]);
		}
		for (unsigned i = 0; i < strlen(tmp_nom2); i++) {
			tmp_nom2[i] = toupper(tmp_nom2[i]);
		}
		if (strcmp(tmp_nom, tmp_nom2) == 0) {
			trouve = true;
		}
		else {
			i++;
		}
	}
	
#else
#ifdef IMPL_LIST
		ind_fin = rep->nb_elts - 1;
	strcpy_s(tmp_nom, _countof(tmp_nom), nom);
	for (int j = 0; j < (int)strlen(tmp_nom); j++) {	// Conversion en majuscules
		if (tmp_nom[j] >= 97) { tmp_nom[j] -= 32; }
	}

	while (i <= ind_fin && trouve == false) {
		strcpy_s(tmp_nom2, _countof(tmp_nom2), GetElementAt(rep->liste, i)->pers.nom);
		for (int j = 0; j < (int)strlen(tmp_nom2); j++) {	// Conversion en majuscules
			if (tmp_nom2[j] >= 97) { tmp_nom2[j] -= 32; }
		}
		if (strlen(tmp_nom) == strlen(tmp_nom2)) {
			int j = 0;
			while (tmp_nom[j] == tmp_nom2[j] && j < (int)strlen(tmp_nom)) {
				j++;
			}
			if (j == (int)strlen(tmp_nom)) {
				trouve = true;
			}
		}
		i++;
	}
	i--;
#endif
#endif

	return((trouve) ? i : -1);		//si trouve vrai = on renvoie i, si faux = on renvoie -1
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s) {			//ajouter une personne : a,a,11;puis rechercher par téléphone : 1a1 ; il en sort a,a,11 = le a n'a pas été pris en compte
	int j = 0;
	for (int i = 0; i < (int)strlen(s)+1; i++) {
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == '\0') {
			s[j] = s[i];
			j++;
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */

#ifdef IMPL_TAB
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");
	if (err == 0) {
		for (int i = 0; i < rep->nb_elts; i++) {
			fputs("\n", fic_rep);
			fputs(rep->tab[i].nom, fic_rep);
			fputs(";", fic_rep);
			fputs(rep->tab[i].prenom, fic_rep);
			fputs(";", fic_rep);
			fputs(rep->tab[i].tel, fic_rep);
		}
		fclose(fic_rep);
	}
	else {
		return ERROR;
	}
#else
#ifdef IMPL_LIST
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");
	if (err == 0) {
		for (int i = 0; i < rep->nb_elts; i++) {
			fputs(GetElementAt(rep->liste, i)->pers.nom, fic_rep);
			fputs(";", fic_rep);
			fputs(GetElementAt(rep->liste, i)->pers.prenom, fic_rep);
			fputs(";", fic_rep);
			fputs(GetElementAt(rep->liste, i)->pers.tel, fic_rep);
			fputs("\n", fic_rep);
		}
		fclose(fic_rep);
	}
	else {
		return ERROR;
	}
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)		//carabistouille
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
				Enregistrement nouveau;
				if (lire_champ_suivant(buffer, &idx, nouveau.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, nouveau.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, nouveau.tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
				InsertElementAt(rep->liste, num_rec, nouveau);
#endif
#endif
			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */