/*
	Version		: 2.0
	Description	: Programme qui calcule les taxes d'un montant lu au clavier,
				  et affiche les détails des taxes et le total taxé
	Ajouts		: Le montant avant les taxes est lu avec un cin
				: Les résultats sont affichés avec une présision à 2 décimales.
*/

#include <iostream>  // pour le cout et le cin
#include <conio.h>   // pour le _getch()
#include <iomanip>	 // pour les manipulateurs : fixed , setprecision()

using namespace std; // Pour ne pas être obligé d'écrire std::cout

int main ()
{
	// CONSTANTES
	const double TVQ = 0.09975, TPS = 0.05;

	// VARIABLES
	double totalAvantTaxe, tps, tvq, totalApresTaxe;

	// INPUT
	cout << "Quel est le montant ? : ";
	cin >> totalAvantTaxe;

	// TRAITEMENTS
	tvq = totalAvantTaxe * TVQ;
	tps = totalAvantTaxe * TPS;
	totalApresTaxe = totalAvantTaxe + tvq + tps;

	// OUTPUT
	cout << fixed << setprecision(2);
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