#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{

	const char HASHTAG = '#';

	char voy_a;
	char voy_e;
	char voy_i;
	char voy_o;
	char voy_u;
	char voy_y;

	voy_a = 'a';
	voy_e = '\145';
	voy_i = '\x69';
	voy_o = 111;
	voy_u = 0165;
	voy_y = 0x79;
	//Voir dans la table ASCII à la fin du manuel pour la traduction des chiffres

	cout << "Exemple" << HASHTAG << '1' << "les voyalles :";
	cout << voy_a << "," << voy_e << "," << voy_i << "," << voy_o << "," << voy_u << "," << voy_y << endl;

	cout << '1' << endl << 467 << endl << 0x3d << endl << '\x76' << endl;

	_getch();
}

