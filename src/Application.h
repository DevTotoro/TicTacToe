#pragma once
#include <SDL.h>
#include <memory>

#include "Grid.h"

constexpr auto PAD = 10;

namespace TicTacToe
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		bool m_Running = true;
		bool m_XTurn = true;
		bool m_GameOver = false;

		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;

		std::unique_ptr<Grid> m_Grid = nullptr;

		SDL_Color m_BackgroundColor{ 30, 30, 30, 255 };

		void PollEvents();
		void Update();
		void Render();

		void Reset();
	};
}
