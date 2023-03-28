#pragma once
#include <SDL.h>

#include "Cell.h"

constexpr auto GRID_SIZE = 3;

namespace TicTacToe
{
	class Grid
	{
	public:
		Grid(SDL_Renderer* renderer, int offset = 0);

		void Draw();

	private:
		Cell m_Cells[GRID_SIZE][GRID_SIZE];
	};
}
