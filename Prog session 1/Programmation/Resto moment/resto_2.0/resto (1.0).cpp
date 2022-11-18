/*
	Version		: 1.0
	Description	: Programme qui calcule les taxes d'un montant inscrit dans une variable,
				  et affiche les d�tails des taxes et le total tax�
*/

#include <iostream>  // pour le cout
#include <conio.h>   // pour le _getch()

using namespace std;

int main ()
{
	// CONSTANTES
	const double TVQ = 0.09975, TPS = 0.05;

	// VARIABLES
	double totalAvantTaxe, tps, tvq, totalApresTaxe;

	// INPUT
	totalAvantTaxe = 100.00;

	// TRAITEMENTS
	tvq = totalAvantTaxe * TVQ;
	tps = totalAvantTaxe * TPS;
	totalApresTaxe = totalAvantTaxe + tvq + tps;

	// OUTPUT
	cout << endl;
	cout << "Montant sans les taxes : " << totalAvantTaxe << " $" ;
	cout << endl << endl;
	cout << "   tps : " << tps << " $";
	cout << endl << endl;
	cout << "   tvq : " << tvq << " $";
	cout << endl << endl;
	cout << "Montant avec les taxes : " << totalApresTaxe << " $";
	cout << endl;
	_getch();
}