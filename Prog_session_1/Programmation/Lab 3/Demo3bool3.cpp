#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	string texte_1, texte_2;
	bool résultat;

	texte_1 = "Bonjour";
	texte_2 = "bonjour";

	cout << boolalpha;

	résultat = texte_1 != texte_2;
	cout << résultat << endl;

	résultat = texte_1 > texte_2;
	cout << résultat << endl;

	_getch();

}