/*
 * MenuState.h
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#ifndef MENUSTATE_H_
#define MENUSTATE_H_


#include "MenuState.h"

#include <vector>

class MainMenuState : public MenuState
{
	int menuSelect;
	bool changed;
public:
	MainMenuState()
	{
		changed=true;
		menuSelect=1;

	}
virtual void update();
virtual void render();
virtual bool onEnter();
virtual bool onExit();
virtual ~MainMenuState()
{

}
virtual std::string getStateID() const { return s_menuID; }
private:
virtual void setCallbacks(const std::vector<Callback>& callbacks);
// call back functions for menu items

static const std::string s_menuID;

};

#endif /* MENUSTATE_H_ */
