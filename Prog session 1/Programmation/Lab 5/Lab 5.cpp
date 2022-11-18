#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "../cvm 21.h"

using namespace std;

int main()
{
	//Constante
	const double PRIX_8x11R = 0.031;
	const double PRIX_8x11RV = 0.06;
	const double PRIX_11x17R = 0.061;
	const double PRIX_11x17RV = 0.1;
	const double PRIX_PAPIER_1 = 0.0205;
	const double PRIX_PAPIER_2 = 0.06734;
	const double PRIX_PAPIER_3 = 0.12294;
	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.1;
	const double PRIX_PERFORER = 0.003;
	const double TPS = 0.05;
	const double TVQ = 0.09975;
	
	
	//Variable
	int nbOri;
	int nbExe;
	char formatPapier;
	char typePapier;
	char typeImpression = 'R';
	char aPerforer;
	char typeFaconnage = '5';

	int nbImpR = 0;
	int nbImpRV;
	int reste;
	double coutR;
	double coutRV;

	double prix_papier;
	double coutPapier;

	double coutFaconnage;
	double perforation;
	double prix;

	double coutProduction;
	double coutTotal;

	int x, x2, x3, x4;

	//User input
	x = 36, x2 = 8, x3 = 34, x4 = 17;
	cout << left << fixed;
	cout << setw(x) << "Nombre d'originaux" << ": ";
	cin >> nbOri;

	cout << setw(x) << "Nombre d'exmplaires \205 reproduire" << ": ";
	cin >> nbExe;

	cout << "\n" << "Format du papier :" << "\n";
	cout << setw(x2) << "" << "1. 8\xabx11" << "\n";
	cout << setw(x2) << "" << "2. 8\xabx14" << "\n";
	cout << setw(x2) << "" << setw(x3) << "3. 11x17" << right << setw(x4) << "Votre choix : ";
	formatPapier = toupper(_getch());
	cout << formatPapier << "\n\n";

	if (nbOri>1)
	{
		cout << "Type d'impression :" << "\n";
		cout << left << setw(x2) << "" << "R. recto" << "\n";
		cout << setw(x2) << "" << setw(x3) << "V. recto - verso" << right << setw(x4) << "Votre choix : ";
		typeImpression = toupper(_getch());
		cout << typeImpression << "\n\n";
	}

	cout << "Type de papier :" << "\n";
	cout << left << setw(x2) << "" << "1. Repro + gris" << "\n";
	cout << setw(x2) << "" << "2. Rolland \202volution glacier" << "\n";
	cout << setw(x2) << "" << setw(x3) << "3. Wausau royal, fibre texte \202tain" << right << setw(x4) << "Votre choix : ";
	typePapier = toupper(_getch());
	cout << typePapier << "\n\n";

	cout << "Voulez-vous des documents perfor\202s ? (0/N)" << setw(x4) << "Votre choix : ";
	aPerforer = toupper(_getch());
	cout << aPerforer;

	if (nbOri > 1)
	{
		cout << "\n\n" << "Type de fa\207onnage :" << "\n";
		cout << left << setw(x2) << "" << "1. Broche en coin" << "\n";
		cout << setw(x2) << "" << "2. Encoller avec ruban" << "\n";
		cout << setw(x2) << "" << "3. Tablettes" << "\n";
		cout << setw(x2) << "" << "4. Broche \205 dos de cheval" << "\n";
		cout << setw(x2) << "" << setw(x3) << "5. Aucun" << right << setw(x4) << "Votre choix : ";
		typeFaconnage = toupper(_getch());
		cout << typeFaconnage;
	}

	cout << "\n\n\n" << "Appuyez sur une touche pour continuer ...";
	_getch();
	clrscr();

	//Op�ration NbPages + Prix impression
	reste = (nbOri * nbExe) % 2;
	if (typeImpression == 'R' && formatPapier != '3')
	{
		nbImpR = nbExe * nbOri;
		nbImpRV = 0;
		coutR = nbImpR * PRIX_8x11R;
	}
	if (typeImpression == 'V' && formatPapier != '3')
	{
		nbImpR = reste * nbExe;
		nbImpRV = ((nbOri - reste)  * nbExe )/2;
	}
	if (typeImpression == 'R' && formatPapier == '3')
	{
		nbImpR = ((nbOri + reste) * nbExe) / 2;
		nbImpRV = 0;
	}
	if (typeImpression == 'V' && formatPapier == '3')
	{
		reste = (nbOri) % 4;
		nbImpR = (reste % 3) * nbExe;
		if(reste == 0)
			nbImpRV = (nbOri * nbExe) / 4;
		else
			nbImpRV = ((nbOri - (reste % 3) + (4 % reste)) * nbExe) / 4;
	}
	switch (formatPapier)
	{
		case '1':
		case '2': coutR = nbImpR * PRIX_8x11R; coutRV = nbImpRV * PRIX_8x11RV; break;
		case '3': coutR = nbImpR * PRIX_11x17R; coutRV = nbImpRV * PRIX_11x17RV; break;
	}

	//Op�ration Prix du Papier
	switch (typePapier)
	{
		case '1': prix_papier = PRIX_PAPIER_1; break;
		case '2': prix_papier = PRIX_PAPIER_2; break;
		case '3': prix_papier = PRIX_PAPIER_3; break;
	}
	if (formatPapier == '1')
		prix_papier = prix_papier / 2;

	coutPapier = prix_papier * (nbImpRV + nbImpR);

	//Op�ration Fa�onnage
	if (aPerforer == 'O')
		perforation = PRIX_PERFORER * (nbImpRV + nbImpR);
	else
		perforation = 0;

	if (formatPapier == '1' || '2')
		switch (typeFaconnage)
		{
			case '2': prix = PRIX_ENCOLLER; break;
			case '4': prix = 0; break;
		}
	if (formatPapier == '3')
		switch (typeFaconnage)
		{
			case '2': prix = 0; break;
			case '4': prix = PRIX_DOSCHEVAL; break;
		}

	switch (typeFaconnage)
	{
		case '1': prix = PRIX_BROCHE; break;
		case '3': prix = PRIX_TABLETTE; break;
		case '5': prix = 0; break;
	}

	coutFaconnage = prix * nbExe + perforation;

	//Affichage facture
	x = 37, x2 = 23, coutProduction = coutR + coutRV + coutPapier + coutFaconnage, coutTotal = coutProduction + coutProduction * (TPS + TVQ);
	cout << fixed << setprecision(2) << "\n\n\n\n" << "FACTURE";
	cout << "\n\n\n" << left << setw(x) << "  Co\226t des impressions recto :" << right << setw(x2) << coutR << " $";
	cout << "\n" << left << setw(x) << "  Co\226t des impressions recto-verso :" << right << setw(x2) << coutRV << " $";
	cout << "\n\n" << left << setw(x) << "  Co\226t du papier :" << right << setw(x2) << coutPapier << " $";
	cout << "\n" << left << setw(x) << "  Co\226t du fa\207onnage :" << right << setw(x2) << coutFaconnage << " $";
	cout << "\n" << setw(x + x2) << "----------" << "--";
	cout << "\n\n" << left << setw(x) << "  Co\226t de production :" << right << setw(x2) << coutProduction << " $";
	cout << "\n" << setw(x + x2) << "==========" << "==";
	cout << "\n\n" << left << setw(x) << "Co\226t total:" << right << setw(x2) << coutTotal << " $";

	_getch();
}