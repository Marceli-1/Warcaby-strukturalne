#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;



int queen(int x, int y, int kier, int who) //0 - blad, 1 - ruch wykonany, 2 - bicie wielokrotne
{
	if (who == 1) // ruch damki #
	{
		switch (kier)
		{
		case 1: //gora prawo
		{
			if ((x + 1) > 7 || (y - 1 < 0))
			{
				cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
				Sleep(1500);
				return 0;
				break;
			}

			if ((board[y - 1][x + 1] == 64) || (board[y - 1][x + 1] == 169))
			{
				if ((board[y - 2][x + 2] == 0) && (x + 2 <= 7) && (y - 2 >= 0)) //puste miejsce po biciu + nie wykracza poza tab
				{
					board[y][x] = 0;
					board[y - 1][x + 1] = 0;
					board[y - 2][x + 2] = 178;
					y = y - 2;
					x = x + 2;

					multiple1(x, y);
					if (multiple == 1)
					{
						system("cls");
						gameBoard();
						return 2;
						break;
					}
					else
					{
						return 1;
						break;
					}
				}
				else
				{
					cout << "Nie masz gdzie wyladowac po biciu!" << endl;
					Sleep(1500);
					return 0;
					break;
				}
			}
			else if ((board[y - 1][x + 1] == 35) || (board[y - 1][x + 1] == 178))
			{
				cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
			else
			{
				board[y][x] = 0;
				board[y - 1][x + 1] = 178;
				return 1;
				break;
			}
		}
		case 2: //gora lewo
		{
			if ((x - 1) < 0 || (y - 1 < 0))
			{
				cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
				Sleep(1500);
				return 0;
				break; 
			}

			if ((board[y - 1][x - 1] == 64) || (board[y - 1][x - 1] == 169))
			{
				if ((board[y - 2][x - 2] == 0) && (x - 2 >= 0) && (y - 2 >= 0))
				{
					board[y][x] = 0;
					board[y - 1][x - 1] = 0;
					board[y - 2][x - 2] = 178;
					y = y - 2;
					x = x - 2;
					multiple1(x, y);
					if (multiple == 1)
					{
						system("cls");
						gameBoard();
						return 2;
						break;
					}
					else {
						return 1;
						break;
					}
					
				}
				else
				{
					cout << "Nie masz gdzie wyladowac po biciu!" << endl;
					Sleep(1500);
					return 0;
					break;
				}
			}
			else if ((board[y - 1][x - 1] == 35) || (board[y - 1][x - 1] == 178))
			{
				cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
			else
			{
				board[y][x] = 0;
				board[y - 1][x - 1] = 178;
				return 1;
				break;
			}
		}

			case 3: //dol prawo
				{
						if ((x + 1) > 7 || (y + 1 > 7))
						{
							cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
							Sleep(1500);
							return 0;
							break;
						}

						if ((board[y + 1][x + 1] == 64) || (board[y + 1][x + 1] == 169))
						{
							if ((board[y + 2][x + 2] == 0) && (x + 2 <= 7) && (y + 2 <= 7))
							{
								board[y][x] = 0;
								board[y + 1][x + 1] = 0;
								board[y + 2][x + 2] = 178;
								y = y + 2;
								x = x + 2;
								multiple2(x, y);
								if (multiple == 1)
								{
									system("cls");
									gameBoard();
									return 2;
									break;
								}
								else {
									return 1;
									break;
								}
							}
							else
							{
								cout << "Nie masz gdzie wyladowac po biciu!" << endl;
								Sleep(1500);
								return 0;
								break;
							}
						}
						else if ((board[y + 1][x + 1] == 35) || (board[y + 1][x + 1] == 178))
						{
							cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
							Sleep(1500);
							return 0;
							break;
						}
						else
						{

							board[y][x] = 0;
							board[y + 1][x + 1] = 178;
							return 1;
							break;
						}
					}
					case 4: //dol lewo
					{
						if ((x - 1) < 0 || (y + 1 > 7))
						{
							cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
							Sleep(1500);
							return 0;
							break;
						}
						if ((board[y + 1][x - 1] == 64) || (board[y + 1][x - 1] == 169))
						{
							if ((board[y + 2][x - 2] == 0) && (x - 2 >= 0) && (y + 2 <= 7)) //puste miejsce po biciu + nie wykracza poza tab
							{
								board[y][x] = 0;
								board[y + 1][x - 1] = 0;
								board[y + 2][x - 2] = 178;
								y = y + 2;
								x = x - 2;
								multiple2(x, y);
								if (multiple == 1)
								{
									system("cls");
									gameBoard();
									return 2;
									break;
								}
								else
								{
									return 1;
									break;
								}	
							}
							else
							{
								cout << "Nie masz gdzie wyladowac po biciu!" << endl;
								Sleep(1500);
								return 0;
								break;
							}
						}
						else if ((board[y + 1][x - 1] == 35) || (board[y + 1][x - 2] == 178))
						{
							cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
							Sleep(1500);
							return 0;
							break;
						}
						else
						{
							board[y][x] = 0;
							board[y + 1][x - 1] = 178;
							return 1;
							break;
						}
					}
		}
	}


	else if (who == 2) // ruch damki @
	{
	switch (kier)
	{
	case 1: //gora prawo
	{
		if ((x + 1) > 7 || (y - 1 < 0))
		{
			cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
			Sleep(1500);
			return 0;
			break;
		}

		if ((board[y - 1][x + 1] == 35) || (board[y - 1][x + 1] == 178))
		{
			if ((board[y - 2][x + 2] == 0) && (x + 2 <= 7) && (y - 2 >= 0)) //puste miejsce po biciu + nie wykracza poza tab
			{
				board[y][x] = 0;
				board[y - 1][x + 1] = 0;
				board[y - 2][x + 2] = 169;
				y = y - 2;
				x = x + 2;

				multiple1(x, y);
				if (multiple == 1)
				{
					system("cls");
					gameBoard();
					return 2;
					break;
				}
				else
				{
					return 1;
					break;
				}
			}
			else
			{
				cout << "Nie masz gdzie wyladowac po biciu!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
		}
		else if ((board[y - 1][x + 1] == 64) || (board[y - 1][x + 1] == 169))
		{
			cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
			Sleep(1500);
			return 0;
			break;
		}
		else
		{
			board[y][x] = 0;
			board[y - 1][x + 1] = 169;
			return 1;
			break;
		}
	}
	case 2: //gora lewo
	{
		if ((x - 1) < 0 || (y - 1 < 0))
		{
			cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
			Sleep(1500);
			return 0;
			break;
		}

		if ((board[y - 1][x - 1] == 35) || (board[y - 1][x - 1] == 178))
		{
			if ((board[y - 2][x - 2] == 0) && (x - 2 >= 0) && (y - 2 >= 0))
			{
				board[y][x] = 0;
				board[y - 1][x - 1] = 0;
				board[y - 2][x - 2] = 169;
				y = y - 2;
				x = x - 2;
				multiple1(x, y);
				if (multiple == 1)
				{
					system("cls");
					gameBoard();
					return 2;
				}
				else {
					return 1;
					break;
				}

			}
			else
			{
				cout << "Nie masz gdzie wyladowac po biciu!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
		}
		else if ((board[y - 1][x - 1] == 64) || (board[y - 1][x - 1] == 169))
		{
			cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
			Sleep(1500);
			return 0;
			break;
		}
		else
		{
			board[y][x] = 0;
			board[y - 1][x - 1] = 169;
			return 1;
			break;
		}
	}

	case 3: //dol prawo
	{
		if ((x + 1) > 7 || (y + 1 > 7))
		{
			cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
			Sleep(1500);
			return 0;
			break;
		}

		if ((board[y + 1][x + 1] == 35) || (board[y + 1][x + 1] == 178))
		{
			if ((board[y + 2][x + 2] == 0) && (x + 2 <= 7) && (y + 2 <= 7))
			{
				board[y][x] = 0;
				board[y + 1][x + 1] = 0;
				board[y + 2][x + 2] = 169;
				y = y + 2;
				x = x + 2;
				multiple2(x, y);
				if (multiple == 1)
				{
					system("cls");
					gameBoard();
					return 2;
					break;
				}
				else {
					return 1;
					break;
				}
			}
			else
			{
				cout << "Nie masz gdzie wyladowac po biciu!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
		}
		else if ((board[y + 1][x + 1] == 64) || (board[y + 1][x + 1] == 169))
		{
			cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
			Sleep(1500);
			return 0;
			break;
		}
		else
		{
			board[y][x] = 0;
			board[y + 1][x + 1] = 169;
			return 1;
			break;
		}
	}
	case 4: //dol lewo
	{
		if ((x - 1) < 0 || (y + 1 > 7))
		{
			cout << "Blad! Pionek moze poruszac sie tylko po planszy!" << endl;
			Sleep(1500);
			return 0;
			break;
		}
		if ((board[y + 1][x - 1] == 35) || (board[y + 1][x - 1] == 178))
		{
			if ((board[y + 2][x - 2] == 0) && (x - 2 >= 0) && (y + 2 <= 7)) //puste miejsce po biciu + nie wykracza poza tab
			{
				board[y][x] = 0;
				board[y + 1][x - 1] = 0;
				board[y + 2][x - 2] = 169;
				y = y + 2;
				x = x - 2;
				multiple2(x, y);
				if (multiple == 1)
				{
					system("cls");
					gameBoard();
					return 2;
					break;
				}
				else
				{
					return 1;
					break;
				}
			}
			else
			{
				cout << "Nie masz gdzie wyladowac po biciu!" << endl;
				Sleep(1500);
				return 0;
				break;
			}
		}
		else if ((board[y + 1][x - 1] == 64) || (board[y + 1][x - 2] == 169))
		{
			cout << "Nie mozesz chodzic po wlasnych pionkach!" << endl;
			Sleep(1500);
			return 0;
			break;
		}
		else
		{
			board[y][x] = 0;
			board[y + 1][x - 1] = 169;
			return 1;
			break;
		}
	}
	}
	}
	else
		return 0;
}