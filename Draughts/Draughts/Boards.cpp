#include <iostream>
#include "Header.h"

using namespace std;

unsigned char board[8][8] = //lokacja pionkow i pol gry
{
	{64, 00 ,64, 00 ,64, 00 ,64, 00},
	{00 ,64, 00 ,64, 00 ,64, 00, 64},
	{64, 00 ,64, 00 ,64, 00 ,64, 00},
	{00, 00, 00, 00, 00, 00, 00, 00},
	{00, 00, 00, 00, 00, 00, 00, 00},
	{00, 35, 00, 35, 00, 35, 00, 35},
	{35, 00, 35, 00, 35, 00, 35, 00},
	{00, 35, 00, 35, 00, 35, 00, 35},
};

void gameBoard() // Drukuje pelna szachownice wraz z pionkami
{
	unsigned char upright = 191;
	unsigned char leftdown = 192;
	unsigned char downcentre = 193;
	unsigned char upcentre = 194;
	unsigned char leftcentre = 195;
	unsigned char updown = 196;
	unsigned char centre = 197;

	unsigned char rightdown = 217;
	unsigned char upleft = 218;
	unsigned char stick = 179;
	unsigned char rightcentre = 180;

	cout << " " << upleft << updown << updown << updown;
	for (int i = 0; i < 7; i++)
	{
		cout << upcentre << updown << updown << updown;
	}
	cout << upright << endl;

	int j = 8; // nr szachownicy
	for (int k = 0; k < 7; k++)
	{
		cout << j << stick;
		for (int i = 0; i < 8; i++)
		{
			cout << " " << board[k][i] << " " << stick;
		}
		cout << endl;

		cout << " " << leftcentre << updown << updown << updown;
		for (int i = 0; i < 7; i++)
		{
			cout << centre << updown << updown << updown;
		}
		cout << rightcentre << endl;
		j--;
	}

	cout << "1" << stick;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << board[7][i] << " " << stick;
	}
	cout << endl;

	cout << " " << leftdown << updown << updown << updown;
	for (int i = 0; i < 7; i++)
	{
		cout << downcentre << updown << updown << updown;
	}
	cout << rightdown << endl;

	cout << "   A   B   C   D   E   F   G   H" << endl << endl;
}

//Funkcja sprawdzajaca lokacje pionkow i pol gry
void checkBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

int wygrana() //0 - gra trwa,  1 - wygraly #, 2 - remis, 3 - wygraly @
{
	int down{}; //#
	int up{};	//@

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			if ((board[i][j] == 35) || (board[i][j] == 178))
				down++;
			if ((board[i][j] == 64) || (board[i][j] == 169))
				up++;
		}
	}

	if (down == 0)
		return 3;
	else if (up == 0)
		return 1;
	else
		return 0;
}