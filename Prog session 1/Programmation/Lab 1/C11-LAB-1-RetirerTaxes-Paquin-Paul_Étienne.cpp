/*

Auteur		: Paul-�tienne Paquin
Description	: Programme qui calcule le montant non tax� � partir d'un montant tax�.
Input		: Le montant non tax� est inscrit dans la variable totalAvantTaxes. Les taux de taxes TVQ et TPS.
Output		: Les d�tails des taxes tps et tvq, et le total tax� totalApresTaxes.
Version		: 1.0

*/

#include <iostream>  // pour le cout
#include <conio.h>   // pour le _getch()

using namespace std;

int main()
{
	// CONSTANTES
	const double TVQ = 0.09975, TPS = 0.05; // taux de taxes

	// VARIABLES
	double totalAvantTaxes, tps, tvq, totalApresTaxes;

	// INPUT
	//totalAvantTaxes = 100;
	totalApresTaxes = 114.975;

	// TRAITEMENTS
	totalAvantTaxes = totalApresTaxes / (1+ TVQ + TPS);
	tvq = totalAvantTaxes * TVQ;
	tps = totalAvantTaxes * TPS;

	// OUTPUT
	cout << endl;
	cout << "Montant avec les taxes : " << totalApresTaxes << " $" ;
	cout << endl << endl;
	cout << "   tps : " << tps << " $";
	cout << endl << endl;
	cout << "   tvq : " << tvq << " $";
	cout << endl << endl;
	cout << "Montant sans les taxes : " << totalAvantTaxes << " $";
	cout << endl;


	_getch();
}