#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	string texte_1, texte_2;
	bool r�sultat;

	texte_1 = "Bonjour";
	texte_2 = "bonjour";

	cout << boolalpha;

	r�sultat = texte_1 != texte_2;
	cout << r�sultat << endl;

	r�sultat = texte_1 > texte_2;
	cout << r�sultat << endl;

	_getch();

}