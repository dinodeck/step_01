
#include "bigyama_android.h"
#include "../../DancingSquid.h"
#include <jni.h>
#include <android/log.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

DancingSquid gDancingSquid("Dancing Squid");


/* External Java functions are implemented here.
*/

JNIEXPORT void JNICALL Java_com_bigyama_dancingsquid_DSRenderer_nativeClear(
    JNIEnv*, jobject obj)
{
    glClearColor(1, 0, 0, 0);
}

JNIEXPORT void JNICALL Java_com_bigyama_dancingsquid_DSRenderer_nativeUpdate(
    JNIEnv*, jobject obj, float dt)
{
    gDancingSquid.Update(dt);
}

JNIEXPORT void JNICALL Java_com_bigyama_dancingsquid_DSRenderer_nativeResize(
    JNIEnv*, jobject obj, int width, int height, float dpiX, float dpiY)
{
    // This should be cleverly and nearly passed on to some engine or something
    gDancingSquid.ResetRenderWindow(width, height);
}