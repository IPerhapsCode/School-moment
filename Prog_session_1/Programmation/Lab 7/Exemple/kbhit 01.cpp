#include <iostream>  // pour le cout
#include <conio.h>   // pour le _getch(), _kbhit()
#include <windows.h>

#include "../../cvm 21.h"

using namespace std;

/*

La fonction _kbhit()  -- keyboard hit

    - Lorsqu'un usager appuie sur les touches du clavier, celles-ci s'accumule automatiquement (� la file)
      dans le tampon d'input de votre programme et cette t�che est g�r�e par Windows.

    - Un appel � la fonction _getch() permet d'extraire le premier caract�re du tampon d'input. Si celui-ci
      est vide, la fonction restera bloqu�e en attente de pouvoir en extraire un.

    - L'utilit� de la fonction _kbhit() est de savoir � l'avance si, oui ou non, il y a au moins un caract�re dans le tampon
      d'input avant de tenter d'en extraire un avec la fonction _getch(), �vitant ainsi un blocage qui pourrait �tre non d�sir�.
      
    - Par exemple, dans certaines circonstances, si l'input est vide, au lieu de bloquer, il y a peut-�tre autre chose � faire en attendant.

            while (condition)
            {
                ...
        
                if ( _kbhit() )
                {
                    c = _getch();   // l'existance d'un caract�re dans le tampon est garantie.

                    // faire quelque chose avec c
                }
                else
                {
                    // faire autre chose en attendant qu'il y ait un input
                }

                ...
            }

*/

int main()
{
    // EXEMPLE #1 -- vider le tampon d'input

    // Il est souvent recommand� de vider le tampon d'input avant d'initier une s�rie de question-r�ponse,
    // de mani�re � nettoyer le tampon des caract�res accumul�s ant�rieurement.

    while (_kbhit())    // tant qu'il y a des caract�res dans le tampon
        _getch();       // retire le premier caract�re de la file du tampon


    // EXEMPLE #2 -- faire quelque chose en attendant un input

    bool quit = false;
    while (!quit)
    {
        while (!_kbhit())
        {
            cout << '*';
            Sleep(100);
        }

        switch (toupper(_getch()))
        {
            case ' ': clrscr();    break;  // appuyer sur ESPACE pour nettoyer l'�cran
            case 'Q': quit = true; break;  // appuyer sur Q pour quitter
        }
    }

    cout << "\n\n" << "FIN";
	_getch();
}