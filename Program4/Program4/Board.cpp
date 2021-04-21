#include "pch.h"
#include "Board.h"


Board::Board(int s, int nM) : size(s), numMines(nM)
{
	board = new int*[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size];
		for (int j = 0; j < size; j++)
			board[i][j] = INIT;
	}
}

Board::Board(const Board& b)
{
	board = new int*[b.size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[b.size];
		for (int j = 0; j < size; j++)
			board[i][j] = b.GetCell(i, j);
	}
}

Board::~Board()
{
	for (int i = 0; i < size; i++)
		delete[] board[i];
	delete[] board;
}
