#include "Application.h"

namespace TicTacToe
{
	Application::Application()
	{
		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
			return;
		}

		m_Window = SDL_CreateWindow(
			"Tic Tac Toe",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			(GRID_SIZE * CELL_SIZE) + 2 * PAD, (GRID_SIZE * CELL_SIZE) + 2 * PAD,
			SDL_WINDOW_SHOWN
		);
		if (m_Window == nullptr)
		{
			SDL_Log("Unable to create window: %s", SDL_GetError());
			return;
		}

		m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
		if (m_Renderer == nullptr)
		{
			SDL_Log("Unable to create renderer: %s", SDL_GetError());
			return;
		}

		// Initialize Grid
		m_Grid = std::make_unique<Grid>(m_Renderer, PAD);
	}

	Application::~Application()
	{
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			PollEvents();
			Update();
			Render();
		}
	}

	void Application::PollEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_Running = false;
				break;
			}
		}
	}

	void Application::Update()
	{
	}

	void Application::Render()
	{
		SDL_SetRenderDrawColor(m_Renderer, m_BackgroundColor.r, m_BackgroundColor.g, m_BackgroundColor.b, m_BackgroundColor.a);
		SDL_RenderClear(m_Renderer);

		m_Grid->Draw();

		SDL_RenderPresent(m_Renderer);
	}
}
