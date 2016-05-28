package com.dinodeck.dinodeck;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.SystemClock;
import android.view.Window;
import android.view.WindowManager;
import java.lang.System;

// Dinodeck activity
public class DDActivity extends Activity
{
    private static DDGLSurfaceView mGLView = null;
    private Handler mUpdateTimeHandler = new Handler();
    private long mLastTimeCount;
    private float mDeltaTime;
    private Runnable mUpdateTimeTask = new Runnable()
    {
        public void run()
        {
            if (mGLView != null)
            {
                mGLView.updateUI();
            }
            mUpdateTimeHandler.postDelayed(this, 500);

            update();
        }
    };
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        mGLView = null;
        mLastTimeCount = System.currentTimeMillis();

       // Bundle extras = this.getIntent().getExtras();

        // requiredScreenOrientation = ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE;
        // if(requiredScreenOrientation >= 0)
        // {
        //     setRequestedOrientation(requiredScreenOrientation);
        // }


        this.getWindow().addFlags(
            WindowManager.LayoutParams.FLAG_FULLSCREEN |
            WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus)
    {
        super.onWindowFocusChanged(hasFocus);
        if(!hasFocus)
        {
            return;
        }
        // if (requiredScreenOrientation>=0)
        // {
        //     setRequestedOrientation(requiredScreenOrientation);
        // }

        if(mGLView == null)
        {
            createGLView();
        }

        if (mGLView != null)
        {
            mGLView.gainedFocus();
        }

        startTimer();
    }

    public float deltaTime()
    {
        return mDeltaTime;
    }

    public void update()
    {
        long currentTimeCount = System.currentTimeMillis();
        mDeltaTime = (currentTimeCount - mLastTimeCount) / 1000.0f;
        mLastTimeCount = currentTimeCount;
    }

    void createGLView()
    {
        mGLView = new DSGLSurfaceView(this, this);
        mGLView.setZOrderOnTop(false);
        setContentView(mGLView);
    }

    public void startTimer()
    {
        mUpdateTimeHandler.removeCallbacks(mUpdateTimeTask);
        mUpdateTimeHandler.postDelayed(mUpdateTimeTask, 500);
    }

    public void stopTimer()
    {
        mUpdateTimeHandler.removeCallbacks(mUpdateTimeTask);
    }

    static
    {
        System.loadLibrary("dinodeck");
    }
}


