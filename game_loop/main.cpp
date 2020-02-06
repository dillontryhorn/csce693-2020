
#include "Game.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

int main() {

   std::cout << "Creating game" << std::endl;
   try {
      auto game = std::make_unique<Game>("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
   
      std::cout << "Starting game loop" << std::endl;
      while (game->running()) {
         game->handle_events();
         game->update();
         game->render();
         std::this_thread::sleep_for(std::chrono::duration<float>(1.0f/60.0f)); //60 frames per second
      }
   } catch(std::runtime_error &e) {
      std::cout << e.what() << std::endl;
   }
   
   return 0;
}

