#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <string>

#include "../cvm 21.h"

using namespace std;

int main()
{
	unsigned int N = 1;
	unsigned int E = 1;
	double max = 1;
	unsigned int W1, W2, W3, W4;

	cout << fixed << right;

	srand(int(time(0)));

	for(int u = 1 ; u <= 7 ; ++u)
	{ 
		unsigned int F = 0, F1 = 0, F2 = 0, F3 = 0, F4 = 0, F5 = 0, F6 = 0;
		unsigned int Ftot;
		double P1 = 0, P2 = 0, P3 = 0, P4 = 0, P5 = 0, P6 = 0;
		double Ptot;

		E = u;
		if (u > 1)
		{
			max = pow(10, u-1);
			N = N + max;
		}
		for (int i = 1; i <= max; ++i)
		{

			F = rand() % 6 + 1;
			switch (F)
			{
			case 1: ++F1; break;
			case 2: ++F2; break;
			case 3: ++F3; break;
			case 4: ++F4; break;
			case 5: ++F5; break;
			case 6: ++F6; break;
			}
			if (i == max)
			{
				P1 = (F1 / max) * 100;
				P2 = (F2 / max) * 100;
				P3 = (F3 / max) * 100;
				P4 = (F4 / max) * 100;
				P5 = (F5 / max) * 100;
				P6 = (F6 / max) * 100;

				W1 = 4, W2 = 13, W3 = 16, W4 = 14;
				Ftot = F1 + F2 + F3 + F4 + F5 + F6;
				Ptot = P1 + P2 + P3 + P4 + P5 + P6;

				cout << setprecision(0) << "\n" << "Exp\x82rience al\x82" << "atoire avec " << max << " lancer";
				if (max > 1)
					cout << "s";

				cout << setprecision(2);
				cout << "\n\n\n"	<< setw(W1) << "Face"	<< setw(W2) << "Fr\x82quence"		<< setw(W3) << "Distribution";
				cout << "\n\n"		<< setw(W1) << "1"		<< setw(W2) << F1					<< setw(W4) << P1 << " %";
				cout << "\n"		<< setw(W1) << "2"		<< setw(W2) << F2					<< setw(W4) << P2 << " %";
				cout << "\n"		<< setw(W1) << "3"		<< setw(W2) << F3					<< setw(W4) << P3 << " %";
				cout << "\n"		<< setw(W1) << "4"		<< setw(W2) << F4					<< setw(W4) << P4 << " %";
				cout << "\n"		<< setw(W1) << "5"		<< setw(W2) << F5					<< setw(W4) << P5 << " %";
				cout << "\n"		<< setw(W1) << "6"		<< setw(W2) << F6					<< setw(W4) << P6 << " %";
				cout << "\n"								<< setw(W1 + W2) << "--------"		<< setw(W3) << "--------";
				cout << "\n"								<< setw(W1 + W2) << Ftot			<< setw(W4) << Ptot << " %";

				cout << "\n\n\n" << "Statistiques cumulatives apr\x8as " << E << " exp\x82rience";
				if (E > 1)
					cout << "s";

				cout << "\n\n" << " ==> " << N << " lancer";
				if (N > 1)
					cout << "s";

				if (u < 7)
					cout << "\n\n\n\n\n\n" << "Appuyez sur une touche pour effectuer l'exp\x82rience suivante ...";
				else
					cout << "\n\n\n\n\n\n" << "A U  R E V O I R  !";
			}
		}
		_getch();
		clrscr();
	}
}