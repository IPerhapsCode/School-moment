#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
#include <string>
#include <conio.h>
#include "..\..\cvm 21.h"

using namespace std;

int main()
{
	const int personnes = 3, epiceries = 2, aliments = 4;

	const string aliments[aliments] = { "pain", "lait," "gateau", "beigne" };

	const double prix[epiceries][aliments] = { {3.55, 5.35, 8.75, 6.45}, {5.55, 3.35, 7.75, 8.45} };

	int commandes[personnes][aliments] = { {6,5,3,1},{3,6,2,2},{3,4,3,6} };

	double factures[personnes][epiceries] = { {},{},{} };

	for (int p = 0; p < personnes; ++p)
		for (int e = 0; e < epiceries; ++e)
			for (int a = 0; a < aliments; ++a)
				factures[p][e] += commandes[p][a] * prix[e][a];

}