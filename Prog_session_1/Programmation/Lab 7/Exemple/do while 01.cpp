#include <iostream>
#include <iomanip>
#include <conio.h>

#include "../../cvm 21.h"

using namespace std;

/*

L'INSTRUCTION DO .. WHILE POUR LA R�P�TITION D'INSTRUCTIONS

	A) L'instruction DO .. WHILE permet de r�p�ter (1 � N fois) les instructions de son bloc {}

		do
		{
			instruction(s)
		}
		while (condition) ;

		- La condition est une expression bool�enne pour d�cider s'il faut ex�cuter � nouveau le bloc d'instructions {}
		- Notez que le bloc d'instructions {} est avant la condition
		- Attention au point virgule obligatoire apr�s la condition


	B) S�quence d'ex�cution du DO .. WHILE

		1) ex�cuter le bloc {}

		2) �valuer la condition

			   true  ==> retour � 1)

			   false ==> sortir du DO .. WHILE

*/


int main()
{

// EXEMPLE #1 -- une r�p�tition FOR et son �quivalent DO .. WHILE

// a) soit une r�p�tition for

	for (int i = 0; i < 3; ++i)
	{
		cout << "boucle #" << i << endl;
	}
	cout << endl;

// b) et son �quivalent do .. while

	{
		int i = 0;
		if (i < 3)
			do
			{
				cout << "boucle #" << i << endl;
				++i;
			}
			while (i < 3) ;
	}
	cout << endl;


// EXEMPLE #2 -- validation d'une question (O/N)

	int x, y;
	char r�ponse;

	cout << "Aimez-vous les vacances (O/N) ? ";
	x = wherex();
	y = wherey();

	do
	{
		r�ponse = toupper(_getch());
		cout << r�ponse;
		gotoxy(x, y);
	} while (r�ponse != 'O' && r�ponse != 'N');

	cout << "\n\n" << "J'en prends note...";


	_getch();
}