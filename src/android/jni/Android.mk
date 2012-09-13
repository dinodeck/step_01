
#Bigyama JNI make file
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := bigyama
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := ../../DancingSquid.cpp bigyama_android.cpp
LOCAL_LDLIBS    := -llog -lGLESv1_CM
APP_STL         := stlport_static

include $(BUILD_SHARED_LIBRARY)
