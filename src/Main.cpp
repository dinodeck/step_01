#include "Main.h"
#include <stdio.h>
#include <gl/gl.h>
#include "SDL/SDL.h"


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

        } break;
    }
}

int Main::Execute()
{
	int viewWidth = 640;
    int viewHeight = 360;

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

    SDL_WM_SetCaption("1-Game Loop", "1-Game Loop");

    if((mSurface = SDL_SetVideoMode(viewWidth, viewHeight, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
    {
        return false;
    }

    SDL_WarpMouse(viewWidth/2, viewHeight/2);

    // Setups an orthographic view, should be handled by renderer.
    glClearColor(0, 0, 0, 0);
    glViewport(0, 0, viewWidth, viewHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, viewWidth, viewHeight, 0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0f);

    // Enabled blending
  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable( GL_BLEND );

    unsigned int thisTime = 0;
    unsigned int lastTime = 0;
    unsigned int frames_per_second = 60;
    unsigned int fpsTicks = 0;

    SDL_Event event;

    while(mRunning)
    {
        // Calculate delta time
        thisTime = SDL_GetTicks(); // returns in milliseconds
        mDeltaTime = static_cast<double>((thisTime - lastTime) / 1000); // convert to seconds
        lastTime = thisTime;

        while(SDL_PollEvent(&event))
        {
            OnEvent(&event);
        }

    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        OnUpdate();

		fpsTicks = SDL_GetTicks() - fpsTicks;
        if (fpsTicks < 1000 / frames_per_second)
        {
            SDL_Delay((1000 / frames_per_second) - fpsTicks);
        }
    	SDL_GL_SwapBuffers();
    }
	return 0;
}

void Main::OnUpdate()
{
	// Game code goes here.
}

int main(int argc, char *argv[])
{
	Main main;
	printf("Hello word!");
 	return main.Execute();
}