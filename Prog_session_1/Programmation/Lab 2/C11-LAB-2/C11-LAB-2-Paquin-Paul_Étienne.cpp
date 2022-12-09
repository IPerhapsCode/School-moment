#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	
	//Constantes
	string TITRE = "420-C11-VM -- Laboratoire 2";
	int largeurTITRE = TITRE.size();
	char voy_é = 130;
	

	//Variables 
	string nom = "";
	string numeroGroupe = "";
	string prenom = "";
	
	int entier = 75000;
	short entierCourt = -42;
	long entierLong = 57000;
	unsigned int sansSigne = 54321;
	char carac = 65;
	float reel = 123.456;
	double reelDouble = 12.0123456789;

	short x;
	short y;
	short x1;

	//Titre
	cout << setw((120-largeurTITRE)/2 + largeurTITRE) << right << TITRE << endl << endl;

	//UserInput
	cout << "Taper votre Pr" << voy_é << "nom: ";
	cin >> prenom;
	cout << "Taper votre nom : ";
	cin >> nom;
	cout << "Taper votre num\x82ro de groupe : ";
	cin >> numeroGroupe;
	cout << endl;

	//Traitement
	x = 8;
	y = 2;
	cout << "Essai du cadrage \x85 gauche et de la notation \x85 virgule flottante : " << endl;
	cout << left << setprecision(y) << fixed;
	cout << setw(x) << entier << setw(x) << entierCourt << setw(x) << entierLong << setw(x) << sansSigne << setw(x) << carac << endl;
	cout << setw(x) << reel << setw(x) << reelDouble << endl << endl;

	x = 12;
	x1 = 15;
	y = 5;
	cout << "Essai du cadrage \x85 droite et de la notation scientifique: " << endl;
	cout << right << setprecision(y) << scientific;
	cout << setw(x) << entier << setw(x) << entierCourt << setw(x) << entierLong << setw(x) << sansSigne << setw(x) << carac << endl;
	cout << setw(x1) << reel << setw(x1) << reelDouble << endl << endl;

	x = 16;
	x1 = 10;
	y = 3;
	cout << "Essai de mise en page: " << endl;
	cout << hex << left << fixed << setprecision(y);
	cout << "	" << setw(x) << "entier" << "= " << entier << endl;
	cout << "	" << setw(x) << "entierCourt" << "= " << entierCourt << endl;
	cout << "	" << setw(x) << "entierLong" << "= " << entierLong << endl;
	cout << "	" << setw(x) << "sansSigne" << "= " << sansSigne << endl;
	cout << "	" << setw(x) << "carac" << "= " << carac << endl;
	cout << dec << "	" << setw(x) << "reel" << "= " << setw(x1) << right << reel << endl;
	cout << "	" << setw(x) << left << "reelDouble" << "= " << setw(x1) << right << reelDouble << endl << endl;

	cout << "Salut " << prenom << " " << nom << " du groupe " << numeroGroupe << " !";


	_getch();
}
