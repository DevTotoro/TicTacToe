#pragma once
#include <SDL.h>

constexpr auto CELL_SIZE = 100;

namespace TicTacToe
{
	class Cell
	{
	public:
		Cell();

		void Draw();

		inline void SetPosition(int x, int y) { m_Rect.x = x; m_Rect.y = y; }

		// Should be called before any Cell is drawn
		inline static void SetRenderer(SDL_Renderer* renderer) { s_Renderer = renderer; }

	private:
		static SDL_Renderer* s_Renderer;

		static SDL_Color s_BackgroundColor, s_BorderColor;

		SDL_Rect m_Rect;
	};
}
