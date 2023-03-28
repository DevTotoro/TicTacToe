#include "Cell.h"

namespace TicTacToe
{
	SDL_Renderer* Cell::s_Renderer = nullptr;

	SDL_Color Cell::s_BackgroundColor = { 250, 235, 215, 255 };
	SDL_Color Cell::s_HoverColor = { 132, 155, 179, 255 };
	SDL_Color Cell::s_BorderColor = { 30, 30, 30, 255 };

	int Cell::s_Pad = 20;

	Cell::Cell()
	{
		m_Rect.w = CELL_SIZE;
		m_Rect.h = CELL_SIZE;
	}

	void Cell::SetPosition(int x, int y)
	{
		m_Rect.x = x;
		m_Rect.y = y;

		// X Points
		m_XPoints[0] = { m_Rect.x + s_Pad, m_Rect.y + s_Pad };
		m_XPoints[1] = { m_Rect.x + m_Rect.w - s_Pad, m_Rect.y + m_Rect.h - s_Pad };
		m_XPoints[2] = { m_Rect.x + m_Rect.w - s_Pad, m_Rect.y + s_Pad };
		m_XPoints[3] = { m_Rect.x + s_Pad, m_Rect.y + m_Rect.h - s_Pad };

		// O Points
		m_OPoints[0] = { m_Rect.x + s_Pad, m_Rect.y + s_Pad };
		m_OPoints[1] = { m_Rect.x + m_Rect.w - s_Pad, m_Rect.y + s_Pad };
		m_OPoints[2] = { m_Rect.x + m_Rect.w - s_Pad, m_Rect.y + m_Rect.h - s_Pad };
		m_OPoints[3] = { m_Rect.x + s_Pad, m_Rect.y + m_Rect.h - s_Pad };
		m_OPoints[4] = { m_Rect.x + s_Pad, m_Rect.y + s_Pad };
	}

	void Cell::Draw()
	{
		switch (m_State)
		{
		case TicTacToe::CellState::Empty:
			DrawEmpty();
			break;
		case TicTacToe::CellState::Hover:
			DrawHover();
			break;
		case TicTacToe::CellState::X:
			DrawEmpty();
			DrawX();
			break;
		case TicTacToe::CellState::O:
			DrawEmpty();
			DrawO();
			break;
		default:
			break;
		}
	}

	void Cell::DrawEmpty()
	{
		SDL_SetRenderDrawColor(s_Renderer, s_BackgroundColor.r, s_BackgroundColor.g, s_BackgroundColor.b, s_BackgroundColor.a);
		SDL_RenderFillRect(s_Renderer, &m_Rect);

		SDL_SetRenderDrawColor(s_Renderer, s_BorderColor.r, s_BorderColor.g, s_BorderColor.b, s_BorderColor.a);
		SDL_RenderDrawRect(s_Renderer, &m_Rect);
	}

	void Cell::DrawHover()
	{
		SDL_SetRenderDrawColor(s_Renderer, s_HoverColor.r, s_HoverColor.g, s_HoverColor.b, s_HoverColor.a);
		SDL_RenderFillRect(s_Renderer, &m_Rect);

		SDL_SetRenderDrawColor(s_Renderer, s_BorderColor.r, s_BorderColor.g, s_BorderColor.b, s_BorderColor.a);
		SDL_RenderDrawRect(s_Renderer, &m_Rect);
	}

	void Cell::DrawX()
	{
		SDL_SetRenderDrawColor(s_Renderer, s_BorderColor.r, s_BorderColor.g, s_BorderColor.b, s_BorderColor.a);

		SDL_RenderDrawLine(s_Renderer, m_XPoints[0].x, m_XPoints[0].y, m_XPoints[1].x, m_XPoints[1].y);
		SDL_RenderDrawLine(s_Renderer, m_XPoints[2].x, m_XPoints[2].y, m_XPoints[3].x, m_XPoints[3].y);
	}

	void Cell::DrawO()
	{
		SDL_SetRenderDrawColor(s_Renderer, s_BorderColor.r, s_BorderColor.g, s_BorderColor.b, s_BorderColor.a);

		SDL_RenderDrawLines(s_Renderer, m_OPoints, 5);
	}
}
