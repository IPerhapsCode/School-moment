#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "..\cvm 21.h"

using namespace std;

int main()
{	
	//Modification possibles au jeu
	const int nbCouleur = 6;
	const int nbEssais = 10;
	const int lengthPassword = 4;
	const string win = " Bravo, vous avez gagn\202 !  :) ";
	const string fail = " Vous avez perdu !  :( ";
	const string titre = "JEU DES COULEURS";
	const string reglage = "R\220GLAGES DE LA PARTIE";
	const string couleurs[nbCouleur] = { "(R)ouge", "(V)ert", "(B)leu", "(J)aune", "(M)auve", "(C)yan" };
	const char lettres[nbCouleur] = { 'R', 'V', 'B', 'J', 'M', 'C' };

	//Variables simples
	char input[lengthPassword] = {};
	char debug = 'a';
	char eval;
	bool cheat = false;
	bool output;
	int largeur = 120;
	int espace = 8;
	int x, x2;
	int y;
	int good, bad, verif, essai = 0;

	//Affichage menu des r�glages de la partie
	cout << "\n" << right << setw((largeur + titre.size()) / 2) << titre;
	cout << "\n\n\n" << setw((largeur + reglage.size()) / 2) << reglage;
	cout << "\n\n\n" << setw(espace) << " " << "Activer le mode en d\202bogage ? (O/N) : ";

	//Debug?
	while (debug != 'O' && debug != 'N')
	{
		debug = toupper(_getch());
		
		if (debug == 'O')
		{
			cheat = true;
			cout << debug;
		}
		else if (debug == 'N')
			cout << debug;
	}

	//Password and related variables
	srand(time(0));
	char password[lengthPassword] = {};
	char dummy[lengthPassword] = {};
	for (int i = 0; i < lengthPassword; ++i)
	{
		password[i] = lettres[rand()%nbCouleur];
		dummy[i] = password[i];
	}

	//Jeu affichage
	int espaceBase = 9, espaceN = 5, espaceE = 2*lengthPassword, espaceEB = 6, espaceGood = 18, bufferEval = 4, bufferSecret = 5; //N�cessaire � l'affichage 
	clrscr();
	cout << "\n" << right << setw((largeur + titre.size()) / 2) << titre;
	cout << "\n\n\n\n" << setw(espaceBase) << " ";
	for (int i = 0; i < nbCouleur; ++i) //Nom des couleurs
	{
		cout << couleurs[i];
		if (i != nbCouleur - 1)
			cout << " , ";
	}
	cout << "\n\n\n" << setw(espaceBase) << " " << left << setw(espaceN) << "#" << setw(espaceE + espaceEB) << "Essais" << setw(espaceGood) << "Bien plac\202e(s)" << "Mal plac\202e(s)" << "\n\n" << right;
	y = wherey();
	for (int i = 0; i < nbEssais; ++i) //Nombre d'essais
		cout << setw(espaceBase) << i+1 << ")" << "\n";
	if (cheat == true) //Is debug enabled?
	{
		gotoxy(largeur / 2, y + nbEssais + bufferSecret);
		cout << "Code Secret : ";
		for (int i = 0; i < lengthPassword; ++i)
			cout << password[i] << " ";
	}

	//Input/Essais
	do
	{
		//Variable qui doivent �tre la m�me valeur au d�but de chaque loop
		x = espaceBase + espaceN;
		eval = 'a';
		good = 0;
		bad = 0;
		verif = 0;
		gotoxy(x, y + essai);
		clreol();
		do
		{
			output = false;
			input[verif] = toupper(_getch());
			for (int test = 0; test < nbCouleur; ++test) //Regarde si c'est une lettre accept�
			{
				if (input[verif] == lettres[test])
				{
					output = true;
					break;
				}
			}
			if (output == true) //Affichage couleur choisi
			{
				cout << input[verif] << " ";
				++verif;
			}
			else if (input[verif] == '\x8' && verif != 0) //Backspace
			{
				cout << "\b \b" << "\b \b";
				--verif;
			}
		} 
		while (verif < lengthPassword);

		//�valution des lettres bien et mal plac�es s'il y en a 
		gotoxy(0, y + nbEssais + bufferEval);
		clreol();
		cout << " \220valuer ? (O/N) : ";

		while (eval != 'O' && eval != 'N') //Was your input right?
		{
			eval = toupper(_getch());
		}
		cout << eval;
		if (eval == 'O')
		{
			for (int i = 0; i < lengthPassword; ++i) //Makes sure the password is still the same
			{
				password[i] = dummy[i];
			}
			for (int i = 0; i < lengthPassword; ++i) //Check 1 for good placement and letter
			{
				for (int v = 0; v < lengthPassword; ++v) 
				{
					if (input[i] == password[v] && i == v)
					{
						++good;
						password[v] = '&';
						input[i] = '%';
						break;
					}
				}

			}
			for (int i = 0; i < lengthPassword; ++i) //Check 2 for bad placement and good letter
			{
				for (int v = 0; v < lengthPassword; ++v)
				{
					if (input[i] == password[v])
					{
						++bad;
						password[v] = 'a';
						break;
					}
				}
			}
			for (int i = 5; i > 3; --i) //Affichage des lettres bien et mal position�es
			{
				if (i == 5)
				{
					x = espaceBase + espaceN + espaceE + espaceEB + i;
					gotoxy(x, y + essai);
					cout << good;
				}
				else
				{
					x = espaceBase + espaceN + espaceE + espaceEB + espaceGood + i;
					gotoxy(x, y + essai);
					cout << bad;
				}
			}
			++essai;
		}
		//V�rifie si le code secret a �t� trouv�
		if (good == lengthPassword)
			break;
	}
	while (essai < nbEssais);

	//Affichage du message de fin
	gotoxy(0, y + nbEssais + bufferEval);
	clreol();
	if (good == lengthPassword)
		cout << win;
	else
		cout << fail;
	_getch();
}