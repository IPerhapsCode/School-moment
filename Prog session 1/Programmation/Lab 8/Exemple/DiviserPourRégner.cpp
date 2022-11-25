#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <Windows.h>
#include <string>

#include "..\..\cvm 21.h"

using namespace std;

int main()
{
	const int S = 7;
	int T[S] = { 10,20,30,40,50,60,100 }, iMin, iMax, iMil;
	bool existe = false;

	int v = 60;

	iMin = 0;
	iMax = S - 1;
	
	while (iMax >= iMin)
	{
		iMil = (iMin + iMax) / 2;
		if (v == iMil)
		{
			existe = true;
			break;
		}
		else if (v < T[iMil])
			iMax = iMil - 1;
		else
			iMin = iMil + 1;
	} 

	

	_getch();
}