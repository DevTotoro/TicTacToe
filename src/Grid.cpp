#include "Grid.h"

namespace TicTacToe
{
	Grid::Grid(SDL_Renderer* renderer, int offset)
	{
		Cell::SetRenderer(renderer);

		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				m_Cells[i][j].SetPosition((i * CELL_SIZE) + offset, (j * CELL_SIZE) + offset);
	}

	void Grid::Draw()
	{
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				m_Cells[i][j].Draw();
	}
}
