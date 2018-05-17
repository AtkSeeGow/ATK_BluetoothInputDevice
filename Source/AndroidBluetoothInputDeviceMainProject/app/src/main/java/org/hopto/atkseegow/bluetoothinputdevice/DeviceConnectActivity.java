package org.hopto.atkseegow.bluetoothinputdevice;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.support.v7.app.AppCompatActivity;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

import org.hopto.atkseegow.utility.BluetoothUtility;
import org.hopto.atkseegow.utility.WebViewUtility;

import java.util.Set;

public class DeviceConnectActivity extends AppCompatActivity {
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
        setContentView(R.layout.activity_device_connect);

        linearLayout = findViewById(R.id.linearLayout);
        handler.postDelayed(runnable, 300);

        WebViewUtility.Initialization(this);

        final Spinner bluetoothDeviceSpinner = (Spinner) findViewById(R.id.bluetoothDeviceSpinner);
        final Button connectButton = (Button) findViewById(R.id.connectButton);
        final BluetoothAdapter bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        if (!bluetoothAdapter.isEnabled()) {
            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBtIntent, 0);
            DeviceConnectActivity.this.finish();
        }

        Set<BluetoothDevice> pairedDevices = bluetoothAdapter.getBondedDevices();
        ArrayAdapter<String> bluetoothDeviceItems = new ArrayAdapter<String>(this, R.layout.spinner_style);
        bluetoothDeviceItems.setDropDownViewResource(R.layout.spinner_style_dropdown);
        if (pairedDevices.size() > 0)
            for (BluetoothDevice device : pairedDevices) {
                bluetoothDeviceItems.add(device.getName());
            }

        bluetoothDeviceSpinner.setAdapter(bluetoothDeviceItems);

        bluetoothDeviceSpinner.setOnItemSelectedListener(
                new Spinner.OnItemSelectedListener() {
                    public void onItemSelected(AdapterView adapterView, View view, int position, long id) {
                    }

                    public void onNothingSelected(AdapterView arg0) {
                        Toast.makeText(DeviceConnectActivity.this, "Connect Log is Null", Toast.LENGTH_LONG).show();
                    }
                }
        );

        connectButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Activity activity = (Activity)view.getContext();

                for (BluetoothDevice bluetoothDevice : bluetoothAdapter.getBondedDevices()) {
                    if (bluetoothDevice.getName().equals(bluetoothDeviceSpinner.getSelectedItem().toString())) {
                        BluetoothUtility.Initialization(bluetoothDevice, bluetoothAdapter);

                        Intent intent = new Intent();
                        intent.setClass(activity, DeviceInputActivity.class);
                        startActivity(intent);
                    }
                }
            }
        });
    }
}
