#ifndef DINODECK_H
#define DINODECK_H
#include <string>

// Dinodeck is the kernal of the engine and should have limited dependancies.
// It assumes access to OpenGL

class Dinodeck
{
private:
    std::string mName; // name of the game / project
    // Drawable area in pixels
    unsigned int mViewWidth;
    unsigned int mViewHeight;
public:
    Dinodeck(const std::string& name);
    ~Dinodeck();
    void Update(double deltaTime);
    const std::string& Name() const { return mName; }
    void SetName(const std::string& value) { mName = value; }
    unsigned int ViewWidth() const { return mViewWidth; }
    unsigned int ViewHeight() const { return mViewHeight; }
    void ResetRenderWindow(unsigned int width, unsigned int height);
};

#endif
