#ifndef MAIN_H
#define MAIN_H
#include <string>

struct SDL_Surface;
union SDL_Event;

class Main
{
private:
	std::string		mName;
	SDL_Surface*	mSurface;
	double 			mDeltaTime;
	bool 			mRunning;
	int 			mViewWidth;
    int 			mViewHeight;

	void OnEvent(SDL_Event* event);
	void OnUpdate();
	bool ResetRenderWindow();
public:
	int Execute();
	bool Reset();
	Main() : mName("Dancing Squid"), mSurface(0), mDeltaTime(0), mRunning(true), mViewWidth(640), mViewHeight(360) {}
};
#endif
