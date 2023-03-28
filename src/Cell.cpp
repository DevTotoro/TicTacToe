#include "Cell.h"

namespace TicTacToe
{
	SDL_Renderer* Cell::s_Renderer = nullptr;

	SDL_Color Cell::s_BackgroundColor = { 230, 230, 230, 255 };
	SDL_Color Cell::s_BorderColor = { 30, 30, 30, 255 };

	Cell::Cell()
	{
		m_Rect.w = CELL_SIZE;
		m_Rect.h = CELL_SIZE;
	}

	void Cell::Draw()
	{
		SDL_SetRenderDrawColor(s_Renderer, s_BackgroundColor.r, s_BackgroundColor.g, s_BackgroundColor.b, s_BackgroundColor.a);
		SDL_RenderFillRect(s_Renderer, &m_Rect);

		SDL_SetRenderDrawColor(s_Renderer, s_BorderColor.r, s_BorderColor.g, s_BorderColor.b, s_BorderColor.a);
		SDL_RenderDrawRect(s_Renderer, &m_Rect);
	}
}
