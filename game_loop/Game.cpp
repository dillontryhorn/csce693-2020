
#include "Game.hpp"
#include <iostream>

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
   Uint32 flags{};
   if (fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
   }

   if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      std::cout << "Subsystems initialized..." << std::endl;
      window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
      if (window) {
         std::cout << "Window created..." << std::endl;
      }
      else {
         SDL_Quit(); //Window or renderer not created but SDL initialized
         throw std::runtime_error("SDL window could not be created.");
      }
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer) {
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         std::cout << "Renderer created..." << std::endl;
      }
      else {
         SDL_DestroyWindow(window);
         SDL_Quit(); //Window created and SDL initialized but no renderer
         throw std::runtime_error("SDL renderer could not be created.");
      }
      is_running = true;
   } else {
      is_running = false;
      throw std::runtime_error("SDL could not be initialized."); //SDL not initialized
   }
}

Game::~Game()
{
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   std::cout << "Game cleaned..." << std::endl;
}

void Game::handle_events()
{
   SDL_Event event;
   SDL_PollEvent(&event);
   switch (event.type) {
      case SDL_QUIT:
         is_running = false;
         break;
      default:
         break;
   }
}

void Game::update()
{
   counter++;
   std::cout << counter << std::endl;
}

void Game::render()
{
   SDL_RenderClear(renderer);
   // this is where we would add stuff to render
   SDL_RenderPresent(renderer);
}

