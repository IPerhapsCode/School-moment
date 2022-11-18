#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

/*

	L'INSTRUCTION WHILE POUR LA R�P�TITION D'INSTRUCTIONS

	A) L'instruction WHILE permet de r�p�ter (0 � N fois) les instructions de son bloc {}

		while (condition)
		{
			instruction(s)
		}

		- La condition est une expression bool�enne pour d�cider s'il faut ex�cuter le bloc d'instructions {}
		- Notez que la condition est avant le bloc d'instructions {}


	B) S�quence d'ex�cution du WHILE

		1) �valuer la condition

			   true  ==> ex�cuter le bloc {}
					 ==> retour � 1)

			   false ==> sortir du WHILE

		- Notez que la condition pourrait �tre fausse d�s le d�part �vitant m�me une fois l'ex�cution du bloc {}

*/


int main()
{

// EXEMPLE #1 -- une r�p�tition FOR et son �quivalent WHILE

// a) soit une r�p�tition for

	for (int i = 0; i < 3; ++i)
	{
		cout << "boucle #" << i << endl;
	}
	cout << endl;

// b) et son �quivalent while

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