#include <iostream>	// pour le cout
#include <conio.h>	// pour le _getch()

using namespace std;

int main()
{
	// SUGGESTION: COMMENT CHOISIR L'INSTRUCTION DE RÉPÉTITION ADÉQUATEMENT: FOR(),  WHILE(),  DO..WHILE()

	bool condition = false;

	// 1) Si le nombre N de répétitions est connues d'avance, c'est probablement l'instruction for() qui devrait être utilisée

	for ( ; condition ; )		// [0 à N] répétitions
	{
		
	}



	// 2) Si le nombre de répétitions est inconnues d'avance, c'est probablement l'instruction :
	

	// a) while() si aucune répétition est un cas possible [0 à ..]
	
	while (condition)
	{

	}


	// b) do..while() si au moins une répétition est nécéssaire [1 à ..]
	
	do
	{

	}
	while (condition);

	
	
	// REMARQUE: c'est aussi une question de préférence, car ces 3 instructions de répétitions sont facilement interchangeables à l'écriture

	_getch();
}