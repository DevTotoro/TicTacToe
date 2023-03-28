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

		void Reset();

		bool CheckWin();
		bool CheckDraw();

		void UpdateHover(int mouseX, int mouseY);
		void UpdateClick(int mouseX, int mouseY, bool& xTurn);

	private:
		Cell m_Cells[GRID_SIZE][GRID_SIZE];
	};
}
