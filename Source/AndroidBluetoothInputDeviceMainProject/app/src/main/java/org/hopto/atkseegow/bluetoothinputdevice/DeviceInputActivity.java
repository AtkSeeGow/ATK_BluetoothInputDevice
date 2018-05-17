package org.hopto.atkseegow.bluetoothinputdevice;

import android.annotation.SuppressLint;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Handler;
import android.view.MotionEvent;
import android.view.View;

import org.hopto.atkseegow.domain.ActionParsingCode;
import org.hopto.atkseegow.utility.BluetoothUtility;
import org.hopto.atkseegow.utility.DeviceInputUtility;
import org.hopto.atkseegow.utility.IntentUtility;

public class DeviceInputActivity extends AppCompatActivity {
    private final Handler handler = new Handler();

    private View linearLayout;
    private final Runnable runnable = new Runnable() {
        @SuppressLint("InlinedApi")
        @Override
        public void run() {
            linearLayout.setSystemUiVisibility(View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                    | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                    | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                    | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION);
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_device_input);

        linearLayout = findViewById(R.id.linearLayout);
        handler.postDelayed(runnable, 300);

        if(!BluetoothUtility.IsConnect())
            IntentUtility.RedirectTo(this, DeviceConnectActivity.class, true);

        DeviceInputUtility.InitializationButton(this);
    }

    public boolean onTouchEvent(MotionEvent event) {
        int pointerCount = event.getPointerCount();
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
                BluetoothUtility.Write(ActionParsingCode.TouchScreen);
                break;
            case MotionEvent.ACTION_MOVE:
                if (pointerCount == 1)
                    DeviceInputUtility.SingleFingerMoveMessage((int) (event.getX()), (int) (event.getY()));
                else if (pointerCount == 2)
                    DeviceInputUtility.TwoFingerMoveMessage((int) (event.getX(0)), (int) (event.getY(0)));
                else
                    BluetoothUtility.Write(ActionParsingCode.LeaveScreen);
                break;
            case MotionEvent.ACTION_UP:
                BluetoothUtility.Write(ActionParsingCode.LeaveScreen);
                break;
        }

        return super.onTouchEvent(event);
    }
}
