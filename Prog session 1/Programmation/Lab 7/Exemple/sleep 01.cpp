#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>	// Sleep()

#include "../../cvm 21.h"

using namespace std;

/*

	L'INSTRUCTION SLEEP(millisecondes)

	Permet de mettre le programme en pause d'exécution

	Sleep(200);

*/


int main()
{
	// Exemple #1:

	for (int t = 10; t > 0; --t)
	{
		cout << t << endl;
		Sleep(1000);
	}
	cout << "Bonne ann\202e !!!" << endl;
	Sleep(2000);
	clrscr();


	// Exemple #2:
	const string BANG = "Bang !";
	int x, y, t;

	t = 10;
	while (t-- > 0)
	{
		x = rand() % (120 - BANG.size());
		y = rand() % 30;
		gotoxy(x, y);
		cout << BANG;
		Sleep(500);
		gotoxy(x, y);
		clreol();
	}

	cout << "FIN";
	_getch();
}