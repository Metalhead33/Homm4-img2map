extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
#include <iostream>
#include <SFML/Graphics.hpp> //For SFML

sf::Image* glob_img;

int ImportImage(lua_State* state)
{
    // The number of function arguments will be on top of the stack.
    int args = lua_gettop(state);
    std::string path = lua_tostring(state, -1);
    glob_img = new sf::Image;
    if(!glob_img->loadFromFile(path))
    {
        lua_pushboolean(state,false);
    }
    lua_pushboolean(state,true);
    return 1;
}

int CatchColour(lua_State* state)
{
    int args = lua_gettop(state);
    sf::Color i = glob_img->getPixel((unsigned int)lua_tonumber(state,1),(unsigned int)lua_tonumber(state,2));
    lua_pushnumber(state,i.r);
    lua_pushnumber(state,i.g);
    return 2;
}

int main()
{
  lua_State *state = lua_open();
  luaL_openlibs(state);
  lua_register(state, "ImportImage", ImportImage);
  lua_register(state, "CatchColour", CatchColour);
  luaL_dofile(state,"h4map.lua");
  lua_close(state);
  return 0;
}
