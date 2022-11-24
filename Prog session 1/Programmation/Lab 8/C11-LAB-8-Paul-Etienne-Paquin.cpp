#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "..\cvm 21.h"

using namespace std;

int main()
{
	const string inputquote = "Entez une date (JJ/MM/AAAA) : ";
	const string bye = "A U  R E V O I R !";
	const string nomJourSemaine[7] = { "Dimanche","Lundi", "Mardi", "Mercredi", "Jeudi","Vendredi","Samedi" };
	const string abJourSemaine[7] = { "Di","Lu", "Ma", "Me","Je", "Ve", "Sa" };
	const string nomMois[12] = { "Janvier", "F\x82vrier" , "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "D\202cembre" };
	const int compteMois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int nbJourSemaine = 7;
	int nbMois = 12;
	int sa = 7;
	int jourSemaine;
	int jourSemaineMois;
	int premierDuMois;
	int nbTotalJoursEcoules;
	int erreurx = 8, erreury = 29;
	int inputx = 8, inputy = 1;
	int affichagex = 8, affichagey = 3;
	int sizeinputquote = inputquote.size();
	int jour, mois, annee;
	char out;
	int x = 119, y = 2, yfin= 29;
	int bruhx;
	int colonne;
	int espace = 10;
	int centre = 6 * espace + 2;
	int z;
	int q;
	char operateur1, operateur2;
	char reponse;
	char reponse2;
	char fill = '_';
	char fill2 = ' ';
	bool date;

	do
	{
		//Vérification date et erreurs possibles
		nbTotalJoursEcoules = 0;
		premierDuMois = 0;
		jourSemaineMois = 0;
		jourSemaine = 0;
		date = false;
		z = 0;
		q = 0;
		out = 'N';
		clrscr();
		cout << "\n" << right << setw(sizeinputquote + inputx) << inputquote;
		do
		{
			cin.ignore(cin.rdbuf()->in_avail());
			gotoxy(inputx + sizeinputquote, inputy);
			clreoscr();

			cin >> jour >> operateur1 >> mois >> operateur2 >> annee;

			gotoxy(erreurx, erreury);

			if (cin.fail())
			{
				cout << "Vous devez entrer des nombres seulement";
				cin.clear();
				_getch();
			}
			else if (operateur1 != '-' && operateur1 != '/')
			{
				cout << "Vous devez utiliser le s\x82parateur '/' ou '-' seulement";
				_getch();
			}
			else if (operateur1 != operateur2)
			{
				cout << "Vous devez utiliser le m\x88me s\x82parateur";
				_getch();
			}
			else if (1 > jour || jour > 31)
			{
				cout << "Le jour doit \x88tre entre 1 et 31 inclusivement";
				_getch();
			}
			else if (1 > mois || mois > nbMois)
			{
				cout << "Le mois est erron\x82 (doit \x88tre entre 1 et 12 inclusivement)";
				_getch();
			}
			else if (1901 > annee || annee > 2099)
			{
				cout << "L'ann\202e est erron\202e (de 1901 \x85 2099 seulement)";
				_getch();
			}
			else if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30)
			{
				cout << "Ce mois ne compte que 30 jours";
				_getch();
			}
			else if (mois == 2 && jour > 28)
			{
				string fevrier = "Le mois de f\x82vrier ne peut compter plus de 2";
				char c = '0';
				if (annee % 4 != 0)
					c = '8';
				else if (annee % 4 == 0 && jour != 29)
					c = '9';
				if (c != '0')
				{
					cout << fevrier + c << " jours";
					_getch();
				}
				else
					date = true;
			}
			else
				date = true;
		} while (date == false);
		clrscr();

		//Jour de la semaine
		for (int i = 0; i < mois - 1; i++)
			nbTotalJoursEcoules += compteMois[i];
	
		if (annee % 4 == 0 && mois > 2)
			++nbTotalJoursEcoules;

		nbTotalJoursEcoules += jour;

		jourSemaine = (nbTotalJoursEcoules + (annee - 1900) + (annee - 1901) / 4) % 7;

		//Premier jour du mois

		premierDuMois += nbTotalJoursEcoules - jour + 1;

		jourSemaineMois = (premierDuMois + (annee - 1900) + (annee - 1901) / 4) % 7;

		//Deamnde pour calendrier et nouvelle date
		gotoxy(affichagex, affichagey);
		cout << "Le " << jour << operateur1 << mois << operateur2 << annee << " est un : " << nomJourSemaine[jourSemaine];
		gotoxy(affichagex, 3 + affichagey);
		cout << "Voulez-vous voir le calendier complet du mois (O/N) ? ";

		do
		{
			reponse = toupper(_getch());
			if (reponse == '\r')
				;
			else
				cout << reponse << "\b";
		} while (reponse != 'O' && reponse != 'N');

		//Affichage calendrier
		if (reponse == 'O')
		{
			clrscr();
			gotoxy((x - (nomMois[mois - 1].size() + 5)) / 2, y);
			cout << nomMois[mois - 1] << " " << annee;

			cout << left;
			gotoxy((x - centre) / 2, y + 3);
			bruhx = wherex() - (espace -2);
			for (int i = 0; i <= nbJourSemaine-1; ++i)
			{
				cout << setw(espace) << abJourSemaine[i];
			}

			cout << setfill(fill);
			gotoxy((x - centre) / 2, y + 4);
			cout << setw(centre) << "";

			gotoxy(bruhx, y + 7);
			for (int i = 0; i <= jourSemaineMois; ++i)
				++z;
			cout << setfill(fill2) << right << setw(z * espace) << 1;

			q = compteMois[mois - 1];
			if (mois == 2 && annee % 4 == 0)
				++q;

			colonne = jourSemaineMois + 1;

			for (int i = 2; i <= q; ++i)
			{	
				if (colonne >= sa)
				{
					int a = wherey() + 2;
					gotoxy(bruhx, a);
					colonne = 0;
				}
				cout << setw(espace) << i;
				++colonne;
			}
		}
		gotoxy(erreurx, erreury);
		cout << "Voulez-vous traiter une autre date (O/N) ? ";
		do
		{
			out = toupper(_getch());
			if (out == '\r')
				;
			else
				cout << out << "\b";
		} while (out != 'O' && out != 'N');
	}
	while (out == 'O');

	//Bye
	clrscr();
	gotoxy((x - bye.size()) / 2, yfin / 2);
	cout << bye;
	Sleep(1000);

}