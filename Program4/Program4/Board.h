#pragma once

// initial value of each cell
const int INIT = 9;
// invalid query of cell value
const int INVALID = -3;

class Board
{
private:
	int size;
	int numMines;
	// a dynamic 2D array. 
	// 0-8: number of adjacent mines, -1: marked, 9: untouched, -2: flagged
	int **board;

public:
	// initialize the board to a 2D dynamic array
	// every cell's initial value is 9
	Board(int s, int nM);

	// copy a board
	Board(const Board & b);

	// destructor of board: destructor the dynamic 2D array
	~Board();

	// get cell value at (row, col)
	int GetCell(int row, int col) const
	{
		if (row >= 0 && col >= 0 && row < size && col < size)
			return board[row][col];
		else
			return INVALID;
	}

	// set cell value at (row, col)
	void SetCell(int row, int col, int value) { if (row >= 0 && col >= 0) board[row][col] = value; }

};
