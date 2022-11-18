#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	bool reponse;

	reponse = true;
	cout << reponse << endl;

	reponse = false;
	cout << reponse << endl;

	cout << boolalpha; //pour afficher true or false
	cout << noboolalpha; //pour afficher 1 ou 0

	_getch();


}