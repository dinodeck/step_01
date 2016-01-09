#ifndef MAIN_H
#define MAIN_H
#include <string>

struct SDL_Surface;
union SDL_Event;
class Dinodeck;

class Main
{
private:
	SDL_Surface*   mSurface;
	bool           mRunning;
    Dinodeck*       mDinodeck;

	void OnEvent(SDL_Event* event);
	bool ResetRenderWindow(unsigned int width, unsigned int height);
public:
	int Execute();
	bool Reset();
	Main();
	~Main();
};
#endif
