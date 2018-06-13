#include "InputHandler.h"
#include "Game.h"
#include <iostream>
using namespace std;
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{


}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
if(m_keystates != 0)
{
if(m_keystates[key] == 1)
{
return true;
}
else
{
return false;
}
}
return false;
}

bool InputHandler::isPressed(SDL_Keycode key)
{
	if(event.type==SDL_KEYDOWN)
	{
		if(event.key.keysym.sym==key&&event.key.keysym.sym!=0)
		{
			event.key.keysym.sym=0;
			return true;
		}
		else return false;
	}
	else return false;
}
void InputHandler::update()
{
	m_keystates = SDL_GetKeyboardState(0);
	SDL_PollEvent( &event );

}

