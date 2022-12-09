#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "../cvm 21.h"

using namespace std;

int main()
{
	//Constante 
	const double DOLLAR = 1.31674;
	const double EURO = 1.31357;
	const double BAHT = 0.03597;
	const double ROUPIE = 0.01657;
	const double COURONNE = 0.017666;

	//Variables
	char deviseInitiale;
	char deviseConvertion;
	char deviseMInitiale;
	char deviseMConvertion;
	double montantInitial;
	double convertionI;
	double convertionF;

	int x, x2;

	//UserInput
	x = 24, x2 = 26, cout << fixed << left;
	cout << "Entrez le montant \x85 convertir  : ";
	cin >> montantInitial;
	cout << "\n\n" << "Entrez la devise de ce montant :" << "\n\n";
	cout << setw(x) << "    $ -> Dollar" << "(Canada)" << "\n";
	cout << setw(x) << "    D -> Dollar" << "(\x90tats-unis)" << "\n";
	cout << setw(x) << "    E -> Euro" << "(Union Europ\202enne)" << "\n";
	cout << setw(x) << "    B -> Baht" << "(Tha\x8blande)" << "\n";
	cout << setw(x) << "    R -> Roupie" << "(Inde)" << "\n";
	cout << setw(x) << "    C -> Couronne" << setw(x2) << "(Danemark)" << "Votre choix : ";

	deviseInitiale = _getch();
	deviseMInitiale = toupper(deviseInitiale);
	cout << deviseMInitiale;
	
	cout << "\n\n" << "Entrez la devise dans laquelle on fera la conversion :" << "\n\n";
	cout << setw(x) << "    $ -> Dollar" << "(Canada)" << "\n";
	cout << setw(x) << "    D -> Dollar" << "(\x90tats-unis)" << "\n";
	cout << setw(x) << "    E -> Euro" << "(Union Europ\202enne)" << "\n";
	cout << setw(x) << "    B -> Baht" << "(Tha\x8blande)" << "\n";
	cout << setw(x) << "    R -> Roupie" << "(Inde)" << "\n";
	cout << setw(x) << "    C -> Couronne" << setw(x2) << "(Danemark)" << "Votre choix : ";

	deviseConvertion = _getch();
	deviseMConvertion = toupper(deviseConvertion);
	cout << deviseMConvertion << "\n\n\n";

	//Calcul
	if (deviseMInitiale == 'D') //68=D
		convertionI = montantInitial * DOLLAR;
	else if (deviseMInitiale == 'E') //69=E
		convertionI = montantInitial * EURO;
	else if (deviseMInitiale == 'B') //66=B
		convertionI = montantInitial * BAHT;
	else if (deviseMInitiale == 'R') //82=R
		convertionI = montantInitial * ROUPIE;
	else if (deviseMInitiale == 'C') //67=C
		convertionI = montantInitial * COURONNE;
	else
	{
		convertionI = montantInitial;
		deviseMInitiale = '$'; //36=$
	}

	if (deviseMConvertion == 'D')
		convertionF = convertionI / DOLLAR;
	else if (deviseMConvertion == 'E')
		convertionF = convertionI / EURO;
	else if (deviseMConvertion == 'B')
		convertionF = convertionI / BAHT;
	else if (deviseMConvertion == 'R')
		convertionF = convertionI / ROUPIE;
	else if (deviseMConvertion == 'C')
		convertionF = convertionI / COURONNE;
	else
	{
		convertionF = convertionI;
		deviseMConvertion = '$';
	}

	//Output
	cout << setprecision(2);
	cout << setw(x) << "Montant initial  :" << montantInitial << " " << deviseMInitiale << "\n\n";
	cout << setw(x) << "Montant converti :" << convertionF << " " << deviseMConvertion;

	_getch();
}