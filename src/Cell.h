#pragma once
#include <SDL.h>

constexpr auto CELL_SIZE = 100;

namespace TicTacToe
{
	enum class CellState
	{
		Empty = 0,
		Hover,
		X,
		O
	};

	class Cell
	{
	public:
		Cell();

		void SetPosition(int x, int y);

		void Draw();

		inline void SetState(CellState state)
		{
			if (m_State != CellState::X && m_State != CellState::O)
				m_State = state;
		}

		// Should be called before any Cell is drawn
		inline static void SetRenderer(SDL_Renderer* renderer) { s_Renderer = renderer; }

	private:
		static SDL_Renderer* s_Renderer;

		static SDL_Color s_BackgroundColor, s_BorderColor, s_HoverColor;

		static int s_Pad;

		SDL_Rect m_Rect;

		CellState m_State = CellState::Empty;

		SDL_Point m_XPoints[4]{ {0, 0} };
		SDL_Point m_OPoints[5]{ {0, 0} };

		void DrawEmpty();
		void DrawHover();
		void DrawX();
		void DrawO();
	};
}
