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

		inline void SetState(CellState state) { if (m_State != CellState::X && m_State != CellState::O) m_State = state; }
		
		inline void Reset() { m_State = CellState::Empty; }

		// Should be called before any Cell is drawn
		inline static void SetRenderer(SDL_Renderer* renderer) { s_Renderer = renderer; }

		inline bool Contains(int x, int y) const { return x >= m_Rect.x && x <= m_Rect.x + m_Rect.w && y >= m_Rect.y && y <= m_Rect.y + m_Rect.h; }

		// Operator overloading
		inline bool operator==(const Cell& other) const { return m_State == other.m_State; }
		inline bool operator==(const CellState& state) const { return m_State == state; }

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
