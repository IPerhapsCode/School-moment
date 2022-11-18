#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

/*

	L'INSTRUCTION WHILE POUR LA RÉPÉTITION D'INSTRUCTIONS

	A) L'instruction WHILE permet de répéter (0 à N fois) les instructions de son bloc {}

		while (condition)
		{
			instruction(s)
		}

		- La condition est une expression booléenne pour décider s'il faut exécuter le bloc d'instructions {}
		- Notez que la condition est avant le bloc d'instructions {}


	B) Séquence d'exécution du WHILE

		1) évaluer la condition

			   true  ==> exécuter le bloc {}
					 ==> retour à 1)

			   false ==> sortir du WHILE

		- Notez que la condition pourrait être fausse dès le départ évitant même une fois l'exécution du bloc {}

*/


int main()
{

// EXEMPLE #1 -- une répétition FOR et son équivalent WHILE

// a) soit une répétition for

	for (int i = 0; i < 3; ++i)
	{
		cout << "boucle #" << i << endl;
	}
	cout << endl;

// b) et son équivalent while

	{
		int i = 0;
		while (i < 3)
		{
			cout << "boucle #" << i << endl;
			++i;
		}
	}
	cout << endl;


//  EXEMPLE #2 -- Calculer la factorielle de n

	uint64_t fact = 1, n = 10;

	cout << n << "! = ";
	while (n > 1)
	{
		fact *= n--;	// fact = fact * n--;
	}
	cout << fact << endl << endl;


// EXEMPLE #3 -- Calculer la puissance de b exposant e

	uint64_t puissance = 1, b = 2, e = 8;

	cout << b << " exposant " << e << " = ";  
	while (e-- >= 1)
	{
		puissance *= b;
	}
	cout << puissance << endl;


	_getch();
}