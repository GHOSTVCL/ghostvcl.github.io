#ifndef __INPUT_H__
#define __INPUT_H__

#include "Module.h"
//Todo 1: Include the SDL_gamecontroller.h


//#define NUM_KEYS 352
#define NUM_MOUSE_BUTTONS 5
//#define LAST_KEYS_PRESSED_BUFFER 50

struct SDL_Rect;

enum EventWindow
{
	WE_QUIT = 0,
	WE_HIDE = 1,
	WE_SHOW = 2,
	WE_COUNT
};

enum KeyState
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

//Todo 2: Create an Struct and name it Game Controller with a variable float of the different controllers you’re gonna use.Ex : joystick1_x.


class Input : public Module
{

public:

	Input();

	// Destructor
	virtual ~Input();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();

	// Called before quitting
	bool CleanUp();

	// Check key states (includes mouse and joy buttons)
	KeyState GetKey(int id) const
	{
		return keyboard[id];
	}

	KeyState GetMouseButtonDown(int id) const
	{
		return mouseButtons[id - 1];
	}

	// Check if a certain window event happened
	bool GetWindowEvent(EventWindow ev);

	// Get mouse / axis position
	void GetMousePosition(int &x, int &y);
	void GetMouseMotion(int& x, int& y);

//Todo 3: Create a variable named controllers from the struct GameControllerand another variable named sdl_controller from the typedef struct named SDL_GameController* in the public class input.h


private:
	bool windowEvents[WE_COUNT];
	KeyState*	keyboard;
	KeyState mouseButtons[NUM_MOUSE_BUTTONS];
	int	mouseMotionX;
	int mouseMotionY;
	int mouseX;
	int mouseY;
};

#endif // __INPUT_H__