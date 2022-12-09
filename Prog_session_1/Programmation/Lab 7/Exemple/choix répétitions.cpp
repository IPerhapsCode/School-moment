#include <iostream>	// pour le cout
#include <conio.h>	// pour le _getch()

using namespace std;

int main()
{
	// SUGGESTION: COMMENT CHOISIR L'INSTRUCTION DE R�P�TITION AD�QUATEMENT: FOR(),  WHILE(),  DO..WHILE()

	bool condition = false;

	// 1) Si le nombre N de r�p�titions est connues d'avance, c'est probablement l'instruction for() qui devrait �tre utilis�e

	for ( ; condition ; )		// [0 � N] r�p�titions
	{
		
	}



	// 2) Si le nombre de r�p�titions est inconnues d'avance, c'est probablement l'instruction :
	

	// a) while() si aucune r�p�tition est un cas possible [0 � ..]
	
	while (condition)
	{

	}


	// b) do..while() si au moins une r�p�tition est n�c�ssaire [1 � ..]
	
	do
	{

	}
	while (condition);

	
	
	// REMARQUE: c'est aussi une question de pr�f�rence, car ces 3 instructions de r�p�titions sont facilement interchangeables � l'�criture

	_getch();
}