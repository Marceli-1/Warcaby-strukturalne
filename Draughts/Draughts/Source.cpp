#include <iostream>
#include <Windows.h> //sleep
#include <stdlib.h> //cls
#include "Header.h"
using namespace std;


void menu()
{
	cout << "		WARCABY		" << endl << endl << endl;
	cout << "						" << endl;
	cout << "		ZASADY GRY		" << endl << endl;

	cout << "Pionki poruszaja sie wylacznie przed siebie" << endl;
	cout << "Damki moga poruszac sie i bic do tylu" << endl;
	cout << "Osoba ktora nie posiada pionkow na szachownicy przegrywa" << endl;
	Sleep(5000);
	system("cls");
}


int main()
{
	menu();

	//Board();

	while (wygrana() == 0)
	{
		move();
	}

	//0 - gra trwa,  1 - wygraly #, 2 - remis, 3 - wygraly @
	if (wygrana() == 3)
		cout << "Wygraly @!";
	else if (wygrana() == 1)
		cout << "Wygraly #!";
	else if (wygrana() == 2)
		cout << "Remis!";
}