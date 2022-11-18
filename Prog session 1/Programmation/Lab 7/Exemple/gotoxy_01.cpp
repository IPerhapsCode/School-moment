#include <iostream>
#include <iomanip>
#include <conio.h>

#include "../../cvm 21.h"

using namespace std;

/*

LA CONSOLE

- Par d�faut, la fen�tre de la console fait 120 caract�res de large (x) par 30 lignes de haut (y)

- La fen�tre de la console offre un syst�me de coordonn�es (x,y) pour positionner le curseur
	- la coordonn�e du coin sup�rieur gauche est (0,0)
	- la coordonn�e du coin inf�rieur droit est (119,29)


LA FONCTION: gotoxy(x,y)

- Cette fonction permet de repositionner le curseur � la coordonn�e (x,y)


LES FONCTIONS: wherex() et wherey()

- Ces fonctions retournent respectivement la position en x et en y o� se trouve le curseur.


*/


int main()
{
	// EXEMPLE #1
	gotoxy(0, 29);
	cout << setw(120) << "(119,29) <\xc4\xc4\xc4\xc4 \xdb";

	gotoxy(0, 0);
	cout << "\xdb \xc4\xc4\xc4\xc4> (0,0)";

	
	// EXEMPLE #2
	const size_t X = 120, Y = 30;	// largeur et hauteur de la fen�tre
	size_t x, y;

	string titre = "Placer ce texte au milieu de la console !";

	x = (X - titre.size()) / 2;
	y = Y / 2;

	gotoxy(x, y);
	cout << titre;

	x = wherex(); // position en x actuel ==> imm�diatement apr�s le '!'
	y = wherey(); // position en y actuel ==> n'a pas chang�

	gotoxy(39, y+5);
	cout << "Le point d'exclamation est en position: " << "(" << x-1 << "," << y << ")";

	_getch();
}