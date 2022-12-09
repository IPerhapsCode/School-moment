#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

#include "../cvm 21.h"

using namespace std;

int main()
{

	//Constante 
	const string TITRE = "HYDRO-QU\220BEC";
	const double TPS = 0.05;
	const double TVQ = 0.09975;
	const double TARIFPARJOUR = 0.42238;
	const double TARIF_1 = 0.06319;
	const double TARIF_2 = 0.09749;

	//Variables
	string prenom;
	string nom;
	unsigned int nbKwHres;
	unsigned int nbJour;
	double prix_1 = 0;
	double prix_2 = 0;
	double nbKwHres2 = 0;
	
	int x, x2, x3, x4, x5, x6, x7;
	int y = 120/2;

	//Affichage titre 
	cout << right << setw(y + TITRE.size() / 2) << TITRE << "\n\n\n\n";
	
	//User input
	x = 40;
	cout << left << setw(x) << "Quel est votre pr\x82nom " << ": ";
	getline(cin, prenom);
	cout << "\n" << setw(x) << "Quel est votre nom " << ": ";
	getline(cin, nom);
	cout << "\n\n" << setw(x) <<  "Quelle est votre consommation en kWh " << ": ";
	cin >> nbKwHres;
	cout << "\n" << setw(x) << "Sur combien de jours " << ": ";
	cin >> nbJour;
	cout << "\n\n" << right << setw(y) << "Appuyez sur une touche pour continuer";
	_getch();
	clrscr();

	//Affichage facture
	x = 22, x2 = 6, x3 = 51, x4 = 18, x5 = 15, x6 = 41, x7 = 39;
	if(nbKwHres>40*nbJour)
	{
		double prix_1 = TARIF_1 * 40 * nbJour;
		double prix_2 = (nbKwHres - 40 * nbJour) * TARIF_2;
		double nbKwHres2 = 40 * nbJour;
	}
	else 
	{
		double prix_1 = TARIF_1 * nbKwHres;
		double prix_2 = 0;
		double nbKwHres2 = nbKwHres;
	}
	//Variables Part 2
	double redevance = nbJour * TARIFPARJOUR;
	double tps = (prix_1 + prix_2) * TPS;
	double tvq = (prix_1 + prix_2) * TVQ;
	double totalFacture = prix_1 + prix_2 + tps + tvq;

	cout << right << setw(y + TITRE.size() / 2) << TITRE << "\n\n\n\n";
	cout << left << "FACTURE D'\x90LECTRICIT\220 DE : " << prenom << " " << nom << "\n\n\n";
	cout << "REDEVANCE D'ABONNEMENT:" << setw(x) << right << setprecision(2) << redevance << setw(x2) << left << setprecision(5) << " $" << nbJour << " jour(s) x " << TARIFPARJOUR << " $" << "\n\n\n";
	cout << setw(x3) << "CONSOMMATION:" << nbKwHres << " kWh" << "\n\n";
	cout << "  Les 40 premiers kWh\x5cjour:" << setw(x4) << right << setprecision(2) << prix_1 << setw(x2) << left << " $" << nbKwHres2 << " kWh x " << setprecision(5) << TARIF_1 << " $" << "\n\n";
	cout << "  Le reste de la consommation:" << setw(x5) << right << setprecision(2) << prix_2 << setw(x2) << left << " $" << nbKwHres - 40 * nbJour << " kWh x " << setprecision(5) << TARIF_2 << " $" << "\n\n\n";
	cout << "TPS:";
	
	_getch();
}

