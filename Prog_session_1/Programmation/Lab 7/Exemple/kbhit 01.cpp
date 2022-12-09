#include <iostream>  // pour le cout
#include <conio.h>   // pour le _getch(), _kbhit()
#include <windows.h>

#include "../../cvm 21.h"

using namespace std;

/*

La fonction _kbhit()  -- keyboard hit

    - Lorsqu'un usager appuie sur les touches du clavier, celles-ci s'accumule automatiquement (à la file)
      dans le tampon d'input de votre programme et cette tâche est gérée par Windows.

    - Un appel à la fonction _getch() permet d'extraire le premier caractère du tampon d'input. Si celui-ci
      est vide, la fonction restera bloquée en attente de pouvoir en extraire un.

    - L'utilité de la fonction _kbhit() est de savoir à l'avance si, oui ou non, il y a au moins un caractère dans le tampon
      d'input avant de tenter d'en extraire un avec la fonction _getch(), évitant ainsi un blocage qui pourrait être non désiré.
      
    - Par exemple, dans certaines circonstances, si l'input est vide, au lieu de bloquer, il y a peut-être autre chose à faire en attendant.

            while (condition)
            {
                ...
        
                if ( _kbhit() )
                {
                    c = _getch();   // l'existance d'un caractère dans le tampon est garantie.

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

    // Il est souvent recommandé de vider le tampon d'input avant d'initier une série de question-réponse,
    // de manière à nettoyer le tampon des caractères accumulés antérieurement.

    while (_kbhit())    // tant qu'il y a des caractères dans le tampon
        _getch();       // retire le premier caractère de la file du tampon


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
            case ' ': clrscr();    break;  // appuyer sur ESPACE pour nettoyer l'écran
            case 'Q': quit = true; break;  // appuyer sur Q pour quitter
        }
    }

    cout << "\n\n" << "FIN";
	_getch();
}