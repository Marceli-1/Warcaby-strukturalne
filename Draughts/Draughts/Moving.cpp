#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

char moving1[2];
char moving2[2];
int	kier;
int	kiermultiple = 0;
int a = 1;
int x{}, y{};
int X{}, Y{};
extern bool multiple = 0;

void multiple1(int x, int y) //bicie wielokrotne #
{
	wygrana();
	cout << x << y;
	if ((board[y - 1][x + 1] == 64) || (board[y - 1][x + 1] == 169)) //gora prawo
	{
		if ((board[y - 2][x + 2] == 0) && (x + 2 <= 7) && (y - 2 >= 0))
		{
			multiple = true;
			kiermultiple = 1;
		}
		else
		{
			multiple = false;
			kiermultiple = 0;
		}
	}
	else if ((board[y - 1][x - 1] == 64) || (board[y - 1][x - 1] == 169)) //gora lewo
	{
		if ((board[y - 2][x - 2] == 0) && (x - 2 >= 0) && (y - 2 >= 0))
		{
			multiple = true;
			kiermultiple = 2;
		}
		else
		{
			multiple = false;
			kiermultiple = 0;
		}
	}
	else
	{
		multiple = false;
		kiermultiple = 0;
	}
}

void multiple2(int x, int y) //bicie wielokrotne @
{
	if ((board[y + 1][x + 1] == 35) || (board[y + 1][x + 1] == 178)) //dol prawo
	{
		if ((board[y + 2][x + 2] == 0) && (x + 2 <= 7) && (y + 2 <= 7))
		{
			multiple = true;
			kiermultiple = 3;
		}
		else
		{
			multiple = false;
			kiermultiple = 0;
		}
	}
	else if ((board[y + 1][x - 1] == 35) || (board[y + 1][x - 1] == 178)) // dol lewo
	{
		if ((board[y + 2][x - 2] == 0) && (x - 2 >= 0) && (y + 2 <= 7))
		{
			multiple = true;
			kiermultiple = 4;
		}
		else
		{
			multiple = false;
			kiermultiple = 0;
		}
	}
	else
	{
		multiple = false;
		kiermultiple = 0;
	}
}	

void move()
{
	int x{}, y{};
again:
	moving1[0] = 0;
	moving1[1] = 0;
	kier = 0;
	system("cls");
	gameBoard();
	if (a == 1)
		cout << "Nacisnij ENTER" << endl;
	cin.clear();
	cin.sync();
	cin.ignore();

	if (multiple == 1)
		goto multiple;




	if (a % 2 == 0) // Kolejnosc ruchow
	{
		cout << "Ruch pionkow: " << "@" << endl;
	}
	else
		cout << "Ruch pionkow: " << "#" << endl;

	//Pobieranie lokacji pionka

	cout << "Wybierz pionek (np. D3):" << endl;
	cin >> moving1;

	if ((moving1[0] == 'A') || (moving1[0] == 'a'))
		x = 0;
	else if ((moving1[0] == 'B') || (moving1[0] == 'b'))
		x = 1;
	else if ((moving1[0] == 'C') || (moving1[0] == 'c'))
		x = 2;
	else if ((moving1[0] == 'D') || (moving1[0] == 'd'))
		x = 3;
	else if ((moving1[0] == 'E') || (moving1[0] == 'e'))
		x = 4;
	else if ((moving1[0] == 'F') || (moving1[0] == 'f'))
		x = 5;
	else if ((moving1[0] == 'G') || (moving1[0] == 'g'))
		x = 6;
	else if ((moving1[0] == 'H') || (moving1[0] == 'h'))
		x = 7;
	else
	{
		cout << "Blad! Wprowadz pole ponownie";
		Sleep(1000);
		goto again;
	}

	if (moving1[1] == '8')
		y = 0;
	else if (moving1[1] == '7')
		y = 1;
	else if (moving1[1] == '6')
		y = 2;
	else if (moving1[1] == '5')
		y = 3;
	else if (moving1[1] == '4')
		y = 4;
	else if (moving1[1] == '3')
		y = 5;
	else if (moving1[1] == '2')
		y = 6;
	else if (moving1[1] == '1')
		y = 7;
	else
	{
		cout << "Blad! Wprowadz pole ponownie";
		Sleep(1500);
		goto again;
	}

	if (a % 2 == 0) // Sprawdza czy wybrano 
					// pionka a nie puste pole
	{
		if (board[y][x] == 64) // @
			cout << "Dobrze! @" << endl;
		else if (board[y][x] == 169)
			cout << "Dobrze! Dama @" << endl;
		else

		{
			cout << "Wybrales zle pole!" << endl;
			Sleep(1500);
			goto again;
		}
	}
	else
	{
		if (board[y][x] == 35) // #
			cout << "Dobrze! #" << endl;
		else if (board[y][x] == 178)
			cout << "Dobrze! Dama #" << endl;
		else
		{
			cout << "Wybrales zle pole!" << endl;
			Sleep(1500);
			goto again;
		}
	}

	//cout << "y = " << y << " x = " << x << endl;

	// ************************************************************************************************
	//Przemieszczanie
	// ************************************************************************************************
	multiple:
	if (multiple == 1)
		{
			if (a % 2 == 0) // Kolejnosc ruchow
			{
				cout << "Ruch pionkow: " << "@" << endl;
			}
			else
				cout << "Ruch pionkow: " << "#" << endl;
			cout << "Musisz zbic kolejne piony!" << endl;
		}
	again2: //dobry kierunek bicia wielokrotnego
	cout << "Podaj kierunek w ktorym ma sie przemiescic:" << endl;
	cin.clear();
	cin.sync();
	if (kiermultiple == 0)
	{

		cout << "Gorny prawy: 1		Gorny lewy: 2" << endl;
		cout << "Dolny prawy: 3		Dolny lewy: 4" << endl;

		cin >> kier;

		if ((kier > 0) && (kier <= 4)){}
		else
			goto again;
	}
	else if (kiermultiple == 1)
	{
		cout << "Gorny prawy: 1" << endl;
		cin >> kier;
		if (kier != 1)
			goto again2;

	}
	else if (kiermultiple == 2)
	{
		cout << "Gorny lewy: 2" << endl;
		cin >> kier;
		if (kier != 2)
			goto again2;
	}
	else if (kiermultiple == 3)
	{
		cout << "Dolny prawy: 3" << endl;
		cin >> kier;
		if (kier != 3)
			goto again2;
	}
	else if (kiermultiple == 4)
	{
		cout << "Dolny lewy: 4" << endl;
		cin >> kier;
		if (kier != 4)
			goto again2;
	}

	if (a % 2 == 0) // Sprawdza czy damki 
	{
		if (board[y][x] == 169) // @ damka
		{
			int who = 2;
			switch (queen(x, y, kier, who))
			{
			case 0:
			{
				goto again;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				goto multiple;
			}
			}
		}

		else //poruszanie sie @
		{
			switch (kier)
			{
			case 1:
				{
				cout << "@ moga poruszac sie tylko w dol!" << endl;
				Sleep(1500);
				goto again;
				break;
				}
			case 2:
				{
				cout << "@ moga poruszac sie tylko w dol!" << endl;
				Sleep(1500);
				goto again;
				break;
				}
			case 3: //dol prawo
			{
				if ((x + 1) > 7 || (y + 1 > 7))
				{
					cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
					Sleep(1500);
					goto again;
				}

				if ((board[y + 1][x + 1] == 35) || (board[y + 1][x + 1] == 178))
				{
					if ((board[y + 2][x + 2] == 0) && (x + 2 <= 7) && (y + 2 <= 7))
					{
						board[y][x] = 0;
						board[y + 1][x + 1] = 0;
						board[y + 2][x + 2] = 64;
						y = y + 2;
						x = x + 2;
						multiple2(x, y);
						if (multiple == 1)
						{
							system("cls");
							gameBoard();
							goto multiple;
						}
						break;
					}
					else
					{
						cout << "Nie masz gdzie wyladowac po biciu!" << endl;
						Sleep(1500);
						goto again;
					}
				}
				else if ((board[y + 1][x + 1] == 64) || (board[y + 1][x + 1] == 169))
				{
					cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
					Sleep(1500);
					goto again;
				}
				else
				{

					board[y][x] = 0;
					board[y + 1][x + 1] = 64;
					break;
				}
			}
			case 4: //dol lewo
			{
				if ((x - 1) < 0  || (y + 1 > 7))
				{
					cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
					Sleep(1500);
					goto again;
				}
				if ((board[y + 1][x - 1] == 35) || (board[y + 1][x - 1] == 178))
				{
					if ((board[y + 2][x - 2] == 0) && (x - 2 >= 0) && (y + 2 <= 7)) //puste miejsce po biciu + nie wykracza poza tab
					{
						board[y][x] = 0;
						board[y + 1][x - 1] = 0;
						board[y + 2][x - 2] = 64;
						y = y + 2;
						x = x - 2;
						multiple2(x, y);
						if (multiple == 1)
						{
							system("cls");
							gameBoard();
							goto multiple;
						}
						break;
					}
					else
					{
						cout << "Nie masz gdzie wyladowac po biciu!" << endl;
						Sleep(1500);
						goto again;
					}
				}
				else if ((board[y + 1][x - 1] == 64) || (board[y + 1][x - 2] == 169))
				{
					cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
					Sleep(1500);
					goto again;
				}
				else
				{
					board[y][x] = 0;
					board[y + 1][x - 1] = 64;
					break;
				}
			}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (board[7][i] == 64)
				board[7][i] = 169;
		}
	}
	else
	// ************************************************************************************************
	// Pierwszy ruch gry tutaj
	// ************************************************************************************************
	{
		if (board[y][x] == 178) // # damka
		{
			int who = 1;
			queen(x, y, kier, who);
		}
		else //poruszanie sie #
		{
			switch (kier)
			{
			case 1: //gora prawo
			{
				if ((x + 1) > 7 || (y - 1 < 0))
				{
					cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
					Sleep(1500);
					goto again;
				}

				if ((board[y - 1][x + 1] == 64) || (board[y - 1][x + 1] == 169))
				{
					if ((board[y - 2][x + 2] == 0) && (x + 2 <= 7) && (y - 2 >= 0)) //puste miejsce po biciu + nie wykracza poza tab
					{
						board[y][x] = 0;
						board[y - 1][x + 1] = 0;
						board[y - 2][x + 2] = 35;
						y = y - 2;
						x = x + 2;

						multiple1(x, y);
						if (multiple == 1)
						{
							system("cls");
							gameBoard();
							goto multiple;
						}
						break;
					}
					else
					{
						cout << "Nie masz gdzie wyladowac po biciu!" << endl;
						Sleep(1500);
						goto again;
					}
				}
				else if ((board[y - 1][x + 1] == 35) || (board[y - 1][x + 1] == 178))
				{
					cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
					Sleep(1500);
					goto again;
				}
				else 
				{
					board[y][x] = 0;
					board[y - 1][x + 1] = 35;
					break;
				}
				}
			case 2: //gora lewo
				{
				if ((x - 1) < 0 || (y - 1 < 0))
					{
						cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
						Sleep(1500);
						goto again;
					}

				if ((board[y - 1][x - 1] == 64) || (board[y - 1][x - 1] == 169))
				{
					if ((board[y - 2][x - 2] == 0) && (x - 2 >= 0) && (y - 2 >= 0))
					{
						board[y][x] = 0;
						board[y - 1][x - 1] = 0;
						board[y - 2][x - 2] = 35;
						y = y - 2; 
						x = x - 2;
						multiple1(x, y);
						if (multiple == 1)
						{
							system("cls");
							gameBoard();
							goto multiple;
						}
						break;
					}
					else
					{
						cout << "Nie masz gdzie wyladowac po biciu!" << endl;
						Sleep(1500);
						goto again;
					}
				}
				else if ((board[y - 1][x - 1] == 35) || (board[y - 1][x - 1] == 178))
				{
					cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
					Sleep(1500);
					goto again;
				}
				else
				{
					board[y][x] = 0;
					board[y - 1][x - 1] = 35;
					break;
				}
				}
			case 3:
				{
					cout << "# moga poruszac sie tylko w gore!" << endl;
					Sleep(1500);
					goto again;
					break;
				}
			case 4:
				{
					cout << "# moga poruszac sie tylko w gore!" << endl;
					Sleep(1500);
					goto again;
					break;
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (board[0][i] == 35)
				board[0][i] = 178;
		}
	}
	system("cls");
	gameBoard();
	a++;
	wygrana();
}