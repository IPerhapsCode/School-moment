#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//Constante
	const int largeur = 120;
	const string TITRE = "420-C11-VM -- Laboratoire 2";
	const string text1 = "entier	= ";
	const string text2 = "entierCourt	= ";
	const string text3 = "entierlong	= ";
	const string text4 = "sansSigne	= ";
	const string text5 = "carac	= ";
	const string text6 = "reel	= ";
	const string text7 = "reelDouble	= ";

	//Variables
	unsigned int largeurTITRE = TITRE.size();
	unsigned int largeurtext1 = text1.size();
	unsigned int largeurtext2 = text2.size();
	unsigned int largeurtext3 = text3.size();
	unsigned int largeurtext4 = text4.size();
	unsigned int largeurtext5 = text5.size();
	unsigned int largeurtext6 = text6.size();
	unsigned int largeurtext7 = text7.size();
	int x;
	int y;
	char carac = 65;
	int entier = 75000;
	short entierCourt = -42;
	long entierLong = 57000;
	string nom = "";
	string prenom = "";
	string numeroGroupe = "";
	float reel = 123.456;
	double reelDouble = 12.0123456789;
	unsigned int sansSigne = 54321;

	//Output Titre
	cout << setw(largeur/2 + largeurTITRE/2) << right << TITRE << endl << endl;

	//Input
	cout << "Taper votre pr\x82nom : ";
	cin >> prenom;
	cout << "Taper votre nom : ";
	cin >> nom;
	cout << "Taper votre num" << '\202' << "ro de groupe : ";
	cin >> numeroGroupe;

	//Output
	x = 8;
	cout << endl << "Essai du cadrage à gauche et de la notation en virgule flottante:" << endl;
	cout << setw(x) << left << entier << " " << entierCourt << " " << entierLong << " " << sansSigne << " " << carac << endl;
	cout << fixed << setprecision(2) << setw(x) << reel << " " << reelDouble << endl << endl;

	x = 12;
	y = 15;
	cout << "Essai du cadrage à droite et de la notation scientifique:" << endl;
	cout << setw(x) << right << entier << " " << entierCourt << " " << entierLong << " " << sansSigne << " " << carac << endl;
	cout << scientific << setprecision(5) << setw(y) << reel << " " << reelDouble << endl << endl;

	x = 10;
	cout << "Essai de mise en page : " << "\n";
	cout << hex;
	cout << setw(x / 2 + largeurtext1) << right << "entier	= " << entier << endl;
	cout << setw(x / 2 + largeurtext2) << "entierCourt = " << entierCourt << endl;
	cout << setw(x / 2 + largeurtext3) << "entierLong	= " << entierLong << endl;
	cout << setw(x / 2 + largeurtext4) << "sansSigne	= " << sansSigne << endl;
	cout << setw(x / 2 + largeurtext5) << "carac	= " << carac << endl;
	cout << dec;
	cout << fixed << setprecision(3) << setw(x / 2 + largeurtext6) << "reel	= " << reel << endl;
	cout << setw(x / 2 + largeurtext7) << "reelDouble	= " << reelDouble << endl << endl;

	cout << "Salut " << prenom << " " << nom << " du groupe " << numeroGroupe << " !";


		_getch();
}
