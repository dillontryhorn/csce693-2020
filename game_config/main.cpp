
#include "Game.hpp"

#include <iostream>
#include <memory>

int main() {
   // use the configuration info available in the config.lua script
   int xpos = SDL_WINDOWPOS_CENTERED, ypos = SDL_WINDOWPOS_CENTERED, width = 800, height = 600;
   bool fullscreen = false;
   
   lua_State *L = luaL_newstate();
   luaL_openlibs( L );
   luaL_dofile( L, "config.lua" );

   lua_getglobal( L, "xpos" );
   if( !lua_isnil( L, -1 ) )
      xpos = lua_tointeger( L, -1 );

   lua_getglobal( L, "ypos" );
   if( !lua_isnil( L, -1 ) )
      ypos = lua_tointeger( L, -1 );

   lua_getglobal( L, "width" );
   if( !lua_isnil( L, -1 ) )
      width = lua_tointeger( L, -1 );

   lua_getglobal( L, "height" );
   if( !lua_isnil( L, -1 ) )
      height = lua_tointeger( L, -1 );
      
   lua_getglobal( L, "fullscreen" );
   if( !lua_isnil( L, -1 ) )
      fullscreen = lua_toboolean( L, -1 );

   std::cout << "Creating game" << std::endl;
<<<<<<< HEAD
   auto game = std::make_unique<Game>("1st Game", xpos, ypos, width, height, fullscreen);
=======
   // read Lua script to determine initial window size infomation
   auto game = std::make_unique<Game>("1st Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
>>>>>>> 7e4312ab39ea1c608616940e119fd11f79b23f06

   std::cout << "Starting game loop" << std::endl;
   while (game->running()) {
      game->handle_events();
      game->update();
      game->render();
   }

   return 0;
}
