
#include "Game.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

int main() {
   try {
      std::cout << "Creating game" << std::endl;
      auto game = std::make_unique<Game>("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
   
      std::cout << "Starting game loop" << std::endl;
      auto startLoop = std::chrono::system_clock::now();
      while (game->running()) {
         auto start = std::chrono::system_clock::now();
         game->handle_events();
         game->update();
         game->render();
         auto end = std::chrono::system_clock::now();
         auto duration = end - start;
         std::this_thread::sleep_for(std::chrono::milliseconds(16) - duration); //60 updates per second, 60Hz
      }
      auto endLoop = std::chrono::system_clock::now();
      auto durationLoop = endLoop - startLoop;
      std::cout << durationLoop << std::endl;
   } catch(std::runtime_error &e) {
      std::cout << e.what() << std::endl; //Catch any runtime errors, especially from constructor
   }
   return 0;
}

