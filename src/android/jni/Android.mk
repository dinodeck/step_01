
#dinodeck JNI make file
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := dinodeck
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := ../../Dinodeck.cpp dinodeck_android.cpp
LOCAL_LDLIBS    := -llog -lGLESv1_CM
APP_STL         := stlport_static

include $(BUILD_SHARED_LIBRARY)
