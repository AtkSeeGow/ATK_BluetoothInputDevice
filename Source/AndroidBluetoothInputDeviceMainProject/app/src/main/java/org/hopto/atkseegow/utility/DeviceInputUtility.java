package org.hopto.atkseegow.utility;

import android.app.Activity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.hopto.atkseegow.bluetoothinputdevice.R;
import org.hopto.atkseegow.domain.ActionParsingCode;

public class DeviceInputUtility {
    private static StringBuilder stringBuilder = new StringBuilder();

    public static void InitializationButton(Activity activity){
        final Button mouseLeftClickButton = (Button)activity.findViewById(R.id.mouseLeftClickButton);
        mouseLeftClickButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.MouseLeftClick);
            }
        });

        final Button mouseRightClickButton = (Button)activity.findViewById(R.id.mouseRightClickButton);
        mouseRightClickButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.MouseRightClick);
            }
        });

        final Button arrowUpKeyButton = (Button)activity.findViewById(R.id.arrowUpKeyButton);
        arrowUpKeyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.ArrowUpKey);
            }
        });

        final Button arrowDownKeyButton = (Button)activity.findViewById(R.id.arrowDownKeyButton);
        arrowDownKeyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.ArrowDownKey);
            }
        });

        final Button arrowLeftKeyButton = (Button)activity.findViewById(R.id.arrowLeftKeyButton);
        arrowLeftKeyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.ArrowLeftKey);
            }
        });

        final Button arrowRightKeyButton = (Button)activity.findViewById(R.id.arrowRightKeyButton);
        arrowRightKeyButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.ArrowRightKey);
            }
        });

        final TextView inputTextView = (TextView)activity.findViewById(R.id.inputTextView);
        final Button sendButton = (Button)activity.findViewById(R.id.sendButton);
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(String.format("%s%s%s", ActionParsingCode.SendInputStartKey, inputTextView.getText().toString(), ActionParsingCode.SendInputEndKey));
            }
        });

        final Button backspaceButton = (Button)activity.findViewById(R.id.backspaceButton);
        backspaceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                BluetoothUtility.Write(ActionParsingCode.BackspaceKey);
            }
        });
    }

    public static void SingleFingerMoveMessage(int x,int y)
    {
        DeviceInputUtility.stringBuilder.append(ActionParsingCode.RelativeCoordinates).append(ActionParsingCode.CoordinateX).append(x).append(ActionParsingCode.CoordinateY).append(y).append(ActionParsingCode.CoordinateDataEnd);
        BluetoothUtility.Write(DeviceInputUtility.stringBuilder.toString());
        DeviceInputUtility.stringBuilder.delete(0, DeviceInputUtility.stringBuilder.length());
    }

    public static void TwoFingerMoveMessage(int x,int y)
    {
        DeviceInputUtility.stringBuilder.append(ActionParsingCode.Wheel).append(ActionParsingCode.CoordinateX).append(x).append(ActionParsingCode.CoordinateY).append(y).append(ActionParsingCode.CoordinateDataEnd);
        BluetoothUtility.Write(DeviceInputUtility.stringBuilder.toString());
        DeviceInputUtility.stringBuilder.delete(0, DeviceInputUtility.stringBuilder.length());
    }
}
