
#include "dinodeck_android.h"
#include "../../Dinodeck.h"
#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Dinodeck gDinodeck("Dinodeck");


/* External Java functions are implemented here.
*/

JNIEXPORT void JNICALL Java_com_dinodeck_dinodeck_DDRenderer_nativeClear(
    JNIEnv*, jobject obj)
{
    glClearColor(1, 0, 0, 0);
}

JNIEXPORT void JNICALL Java_com_dinodeck_dinodeck_DDRenderer_nativeUpdate(
    JNIEnv*, jobject obj, float dt)
{
    gDinodeck.Update(dt);
}

JNIEXPORT void JNICALL Java_com_dinodeck_dinodeck_DDRenderer_nativeResize(
    JNIEnv*, jobject obj, int width, int height, float dpiX, float dpiY)
{
    // This should be cleverly and nearly passed on to some engine or something
    gDinodeck.ResetRenderWindow(width, height);
}