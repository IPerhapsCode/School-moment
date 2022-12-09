#include <iostream>
#include <iomanip>
#include <conio.h>

#include "../../cvm 21.h"

using namespace std;

/*

L'INSTRUCTION DO .. WHILE POUR LA RÉPÉTITION D'INSTRUCTIONS

	A) L'instruction DO .. WHILE permet de répéter (1 à N fois) les instructions de son bloc {}

		do
		{
			instruction(s)
		}
		while (condition) ;

		- La condition est une expression booléenne pour décider s'il faut exécuter à nouveau le bloc d'instructions {}
		- Notez que le bloc d'instructions {} est avant la condition
		- Attention au point virgule obligatoire après la condition


	B) Séquence d'exécution du DO .. WHILE

		1) exécuter le bloc {}

		2) évaluer la condition

			   true  ==> retour à 1)

			   false ==> sortir du DO .. WHILE

*/


int main()
{

// EXEMPLE #1 -- une répétition FOR et son équivalent DO .. WHILE

// a) soit une répétition for

	for (int i = 0; i < 3; ++i)
	{
		cout << "boucle #" << i << endl;
	}
	cout << endl;

// b) et son équivalent do .. while

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
	char réponse;

	cout << "Aimez-vous les vacances (O/N) ? ";
	x = wherex();
	y = wherey();

	do
	{
		réponse = toupper(_getch());
		cout << réponse;
		gotoxy(x, y);
	} while (réponse != 'O' && réponse != 'N');

	cout << "\n\n" << "J'en prends note...";


	_getch();
}