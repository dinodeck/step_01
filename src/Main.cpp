#include "Main.h"
#include <stdio.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <gl/gl.h>
#endif
#include "SDL/SDL.h"
#include "Dinodeck.h"

 Main::Main() :
    mSurface(0),
    mRunning(true),
    mDinodeck(NULL)
{
    mDinodeck = new Dinodeck("Dinodeck");
}

Main::~Main()
{
    delete mDinodeck;
}

void Main::OnEvent(SDL_Event* event)
{
    switch(event->type)
    {
        case SDL_QUIT:
        {
            mRunning = false;
        } break;

        case SDL_KEYDOWN:
        {
            if(event->key.keysym.sym == SDLK_ESCAPE)
            {
                printf("Stopped looping because escape pressed.\n");
                mRunning = false;
            }
            else if(event->key.keysym.sym == SDLK_F2)
            {
                printf("F2 pressed.\n");
                mDinodeck->SetName("Change Change");
                ResetRenderWindow(1280, 720);
            }

        } break;
    }
}

bool Main::ResetRenderWindow(unsigned int width, unsigned int height)
{
    const char* name = mDinodeck->Name().c_str();
    SDL_WM_SetCaption(name, name);

    // SDL handles this surface memory, so it can be called multiple times without issue.
    if((mSurface = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
    {
        printf("Error initializing graphics: %s\n", SDL_GetError());
        return false;
    }

    mDinodeck->ResetRenderWindow(width, height);

    SDL_WarpMouse(width/2, height/2);
    return true;
}

int Main::Execute()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
    	printf("SDL Failed to init");
        return false;
    }

    // Allow the game pads to be polled.
    SDL_JoystickEventState(SDL_IGNORE);
    SDL_EnableUNICODE(1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,     32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,  	8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 	8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    bool result = ResetRenderWindow
                  (
                      mDinodeck->ViewWidth(),
                      mDinodeck->ViewHeight()
                  );
    if(!result)
    {
        return -1;
    }

    unsigned int thisTime = 0;
    unsigned int lastTime = 0;
    unsigned int framesPerSecond = 60;
    unsigned int millisecondsPerFrame = 1000 / framesPerSecond;
    unsigned int fpsTicks = 0;

    SDL_Event event;

    while(mRunning)
    {
        // Calculate delta time
        thisTime = SDL_GetTicks(); // returns in milliseconds
        double deltaTime = static_cast<double>((thisTime - lastTime) / 1000); // convert to seconds
        lastTime = thisTime;

        while(SDL_PollEvent(&event))
        {
            OnEvent(&event);
        }

        mDinodeck->Update(deltaTime);

		fpsTicks = SDL_GetTicks() - fpsTicks;
        if (fpsTicks < millisecondsPerFrame)
        {
            SDL_Delay(millisecondsPerFrame - fpsTicks);
        }
    	SDL_GL_SwapBuffers();
    }

    SDL_Quit();

	return 0;
}

int main(int argc, char *argv[])
{
	Main main;
 	return main.Execute();
}
