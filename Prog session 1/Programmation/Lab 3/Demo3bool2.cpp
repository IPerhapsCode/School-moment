#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	int x = 10, y = 20, z = 10;
	bool response;

	cout << boolalpha;

	response = 5 < 7;
	cout << response << endl;

	response = x != y;
	cout << response << endl;

	response = x == z;
	cout << response << endl;

	response = x > y;
	cout << response << endl;

	response = x < z;
	cout << response << endl;

	response = x <= z;
	cout << response << endl;

	response = (x * y) <= z * z; //mettre des parenth�se si pas sur de la priorit� des oper�ations
	cout << response << endl;

	response = response == false;
	cout << response << endl;


	_getch();

}