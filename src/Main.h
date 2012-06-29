#ifndef MAIN_H
#define MAIN_H

struct SDL_Surface;
union SDL_Event;

class Main
{
private:
	SDL_Surface*	mSurface;
	double 			mDeltaTime;
	bool 			mRunning;

	void OnEvent(SDL_Event* event);
	void OnUpdate();
public:
	int Execute();
	bool Reset();
	Main() : mSurface(0), mDeltaTime(0), mRunning(true) {}
};
#endif
