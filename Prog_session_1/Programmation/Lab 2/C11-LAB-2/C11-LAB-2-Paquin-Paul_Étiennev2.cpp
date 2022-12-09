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
	cout << "Essai du cadrage \x85 gauche et de la notation à virgule flottante : " << endl;
	cout << setw(x) << left << entier;
	cout << setw(x) << left << entierCourt;
	cout << setw(x) << left << entierLong;
	cout << setw(x) << left << sansSigne;
	cout << setw(x) << left << carac << endl;
	cout << setw(x) << setprecision(y) << fixed << left << reel;
	cout << setw(x) << setprecision(y) << left << reelDouble << endl << endl;

	x = 12;
	cout << "Essai du cadrage \x85 droite et de la notation scientifique: " << endl;
	cout << setw(x) << right << entier;
	cout << setw(x) << right << entierCourt;
	cout << setw(x) << right << entierLong; 
	cout << setw(x) << right << sansSigne;
	cout << setw(x) << right << carac << endl;
	x = 15;
	y = 5;
	cout << setw(x) << right << setprecision(y) << scientific << reel;
	cout << setw(x) << right << setprecision(y) << reelDouble << endl << endl;

	x = 10;
	y = 3;
	cout << "Essai de mise en page: " << endl;
	cout << hex;
	cout << setw(2*x) << right << "entier";
	cout << setw(x) << right << "=" << entier << endl;
	cout << setw(2*x) << right << "entierCourt";
	cout << setw(x) << right << "=" << entierCourt << endl;
	cout << setw(2*x) << right << "entierLong";
	cout << setw(x) << right << "=" << entierLong << endl;
	cout << setw(2*x) << right << "sansSigne";
	cout << setw(x) << right << '=' << sansSigne << endl;
	cout << setw(2*x) << right << "carac";
	cout << setw(x) << right << '=' << carac << endl;
	cout << dec;
	cout << setw(2*x) << right << "reel";
	cout << setw(x) << right << setprecision(y) << fixed << "=" << reel << endl;
	cout << setw(2*x) << right << "reelDouble";
	cout << setw(x) << right << setprecision(y) << fixed << "=" << reelDouble << endl << endl;

	cout << "Salut " << prenom << " " << nom << " du groupe " << numeroGroupe << " !";


	_getch();
}
