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

	void Grid::Reset()
	{
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				m_Cells[i][j].Reset();
	}

	bool Grid::CheckWin()
	{
		// Check rows
		for (int i = 0; i < GRID_SIZE; i++)
			if (m_Cells[i][0] == m_Cells[i][1] && m_Cells[i][1] == m_Cells[i][2] && m_Cells[i][0] != CellState::Empty)
				return true;

		// Check columns
		for (int i = 0; i < GRID_SIZE; i++)
			if (m_Cells[0][i] == m_Cells[1][i] && m_Cells[1][i] == m_Cells[2][i] && m_Cells[0][i] != CellState::Empty)
				return true;

		// Check diagonals
		if (m_Cells[0][0] == m_Cells[1][1] && m_Cells[1][1] == m_Cells[2][2] && m_Cells[0][0] != CellState::Empty)
			return true;
		if (m_Cells[0][2] == m_Cells[1][1] && m_Cells[1][1] == m_Cells[2][0] && m_Cells[0][2] != CellState::Empty)
			return true;

		return false;
	}

	bool Grid::CheckDraw()
	{
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				if (m_Cells[i][j] == CellState::Empty || m_Cells[i][j] == CellState::Hover)
					return false;

		return true;
	}

	void Grid::UpdateHover(int mouseX, int mouseY)
	{
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				m_Cells[i][j].SetState(m_Cells[i][j].Contains(mouseX, mouseY) ? CellState::Hover : CellState::Empty);
	}

	void Grid::UpdateClick(int mouseX, int mouseY, bool& xTurn)
	{
		for (int i = 0; i < GRID_SIZE; i++)
			for (int j = 0; j < GRID_SIZE; j++)
				if (m_Cells[i][j].Contains(mouseX, mouseY))
				{
					m_Cells[i][j].SetState(xTurn ? CellState::X : CellState::O);
					xTurn = !xTurn;
				}
	}
}
