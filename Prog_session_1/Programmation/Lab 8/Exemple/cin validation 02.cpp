#include <iostream>
#include <conio.h>
#include <string>

#include "../../cvm 21.h"

using namespace std;


int main()
{
	// EXEMPLE #1 -- LIRE UNE NOTE JUSQU'� TEMPS QU'ELLE SOIT VALIDE

	bool valide;
	double note;
	string erreur;
	size_t x = 10, y = 10;

	clrscr();
	gotoxy(x,y); cout << "Entrez une note ? : ";
	x = wherex();

	valide = false;
	do
	{
		cin.ignore(cin.rdbuf()->in_avail());		// vider le tampon du cin

		gotoxy(x,y);								// se repositionner
		clreoscr();									// nettoyer l'�cran
		cin >> note;								// lire la note

		// Validations des erreurs possibles

		if (cin.fail())														// ATTENTION: v�rifier d'abord si le "cin" n'a pas �t� en mesure d'extraire une note, i.e. un "double" ici
		{
			erreur = "ERREUR: Vous devez entrer un nombre seulement !";
			cin.clear();													// ATTENTION: ici le cin est dans l'�tat "fail == true", il faut obligatoirement le remettre en �tat de marche avec cin.clear()
		}
		else if (note < 0)													// ici la variable note est consultable car le cin a fonctionn�: cin.fail() == false
		{
			erreur = "ERREUR: Vous devez entrer un nombre >= 0 !";
		}
		else if (note > 100)												// autre cas possible d'erreur
		{
			erreur = "ERREUR: Vous devez entrer un nombre <= 100 !";
		}
		else																// pas d'erreur
			valide = true;

		gotoxy(0,0);														// astuce pour replacer la fen�tre � la premi�re ligne

		if (!valide)
		{
			gotoxy(10,29); cout << erreur; _getch();
		}

	} while (!valide);

	gotoxy(10, 20); cout << "la note est " << note << "  BRAVO !"; _getch();
}