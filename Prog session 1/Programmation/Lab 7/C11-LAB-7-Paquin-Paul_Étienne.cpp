#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <string>
#include <Windows.h>

#include "../cvm 21.h"

using namespace std;

int main()
{
//Variables et constantes
string mdp = " ";
string mdpv = " ";
string c = " ";
unsigned int y = 30, x = 120, p = 0;
unsigned int px, py;
const int LENGTH = 4;
const char BOX = '/';
const unsigned int PAD = 4;
const unsigned int WAIT = 1000;
const unsigned int y1 = 30, x1 = 120;
const string EV = "\x90 C R A N  V E R R O U I L L \x90";
const string ASK1 = "Entrer votre mot de passe (4 caract\x8ares) :";
const string ASK2 = "Taper votre mot de passe encore une fois :";
const string ASK3 = "Recommencez, vous devez entrer le m\x88me mot deux fois :";
const string ASK4 = "Mot de passe :";
const string m = "xxxx";
const string r = "*";
const string BYE = "A U  R E V O I R";

//Demande du mot de passe (simplifier le code trop de r�p�tition)

while (_kbhit())
_getch();

gotoxy((x1 - ASK1.size()) / 2, y1 / 2);
cout << ASK1;
for (int i = 0; i < 3; ++i)
{
	switch (i)
	{
		case 1: gotoxy((x1 - ASK2.size()) / 2, y1 / 2);
			cout << ASK2;
			break;
		case 2: gotoxy((x1 - ASK3.size()) / 2, y1 / 2);
			cout << ASK3; 
			i = 0;
			mdp = "";
			mdpv = "";
			break;
	}
	gotoxy((x1 - m.size()) / 2, (y1 + 4) / 2);
	px = wherex();
	py = wherey();
	cout << m;
	gotoxy(px, py);
	for (int a = 0; a < 4; ++a)
	{
		if (i == 0)
		{
			c = _getch();
			mdp = mdp + c;
		}
		else if(i == 1)
		{
			c = _getch();
			mdpv = mdpv + c;
		}
		cout << "*";
	}
	clrscr();
	if (mdp == mdpv)
		i = 3;
}

//�cran de mise en veille
cout << left;
while (_kbhit())
	_getch();
srand(time(0));
do
{
	x = rand() % 120;
	y = rand() % 30;
	if (x >= 120 - EV.size() - 2 * PAD)
		x = 120 - EV.size() - 2 * PAD - 1;
	else if (x == 0)
		x = 1;
	if (y >= 25)
		y = 24;
	else if (y == 0)
		y = 1;
	if (p == 0)
	{
		x = (120 - EV.size() - 2 * PAD) / 2;
		y = 10;
		++p;
	}
	for (int o = 0; o < 5; ++o)
	{
		if (o == 0)
			;
		else
			y = ++y;
		gotoxy(x, y);
		switch (o)
		{
		case 0:
		case 4:	for (int i = 0; i < (EV.size() + 2 * PAD); ++i)
			cout << BOX;
			break;
		case 1:
		case 3: cout << setw(EV.size() + 2 * PAD - 1) << BOX << BOX; break;
		case 2: cout << BOX << "   " << EV << "   " << BOX; break;
		}
	}
	Sleep(WAIT);
	clrscr();
} while (!_kbhit());
_getch();
clrscr();

//Demande du mot de passe pr�c�dement enregistrer (M�me chose r�p�tition de code)fuck
mdpv = " ";

gotoxy((x1 - ASK4.size()) / 2, y1 / 2);
cout << ASK4;
gotoxy((x1 - m.size()) / 2, (y1 + 4) / 2);
px = wherex();
py = wherey();
while (mdpv != mdp)
{
	if (mdpv != " ")
		gotoxy(px, py);
	cout << m;
	gotoxy(px, py);
	for (int i = 0; i < LENGTH; ++i)
	{
		if (i < 1)
			mdpv = _getch();
		else
		{
			c = _getch();
			mdpv = mdpv + c;
		}
		cout << "*";
	}
}
gotoxy((x1 - BYE.size()) / 2, y1 / 2 + 5);
cout << BYE;
Sleep(WAIT * 2);
}
