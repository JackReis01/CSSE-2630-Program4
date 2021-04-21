#pragma once
#include "Board.h"
#include <stdlib.h>
#include <vcclr.h>  

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

const int CELLSIZE = 20;

class MineSweeper
{
private:
	static const int EASY = 10, MID = 16, HARD = 25;
	static const int EASY_MINE = 10, MID_MINE = 40, HARD_MINE = 100;
	static const int TIME_MULTIPLIER = 10;

	gcroot<Panel^> panel;
	gcroot<Drawing::Bitmap^> zero, one, two, three, four, five, six, seven, eight, mine, flag, closed;

	bool bombed, win;
	int difficulty;
	int boardSize;
	int numMines;
	int time;
	Board* mines;
	Board* game;

	// randomly place mines on the "mines" board
	void PlaceMines();

	// count the number of adjacent mines
	int AdjacentMineCount(int row, int col) const;

	// check the game against mines board to see whether all mines are correctly marked
	void CheckWin();

public:
	// initialize the board and randomly put n mines on the board
	// level 1: 10*10, n = 10, time = 100s
	// level 2: 16*16, n = 40, time = 400s
	// level 3: 25*25, n = 100, time = 1000s
	MineSweeper(int level, Panel^ drawingPanel);

	// destructor
	~MineSweeper() { delete mines; delete game; }

	// mark there is a bomb in (row, col).
	void Mark(int row, int col);

	// reveal the (row, col) cell.
	// if there is a mine, lose the game;
	// otherwise, recursively mark the cell(s).
	void Reveal(int row, int col);

	// show the game board
	void Show() const;

	// show all the mines
	void ShowMines() const;

	// get the number of remaining mines
	int GetNumMines() const { return numMines; }

	// get the time
	int GetTime() const { return time; }

	// whether the user revealed a mine
	bool IsBombed() const { return bombed; }

	// whether the user wins the game
	bool Won() const { return win; }
};