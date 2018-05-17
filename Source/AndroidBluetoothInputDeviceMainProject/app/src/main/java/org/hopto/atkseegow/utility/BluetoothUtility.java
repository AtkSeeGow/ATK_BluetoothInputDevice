package org.hopto.atkseegow.utility;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import org.hopto.atkseegow.domain.ActionParsingCode;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

public class BluetoothUtility {
    private static BluetoothSocket bluetoothSocket = null;
    private static InputStream inputStream = null;
    private static OutputStream outputStream = null;

    public static void Initialization(BluetoothDevice bluetoothDevice, BluetoothAdapter bluetoothAdapter) {
        bluetoothAdapter.cancelDiscovery();

        try {
            BluetoothUtility.bluetoothSocket = bluetoothDevice.createRfcommSocketToServiceRecord(UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"));

            if (BluetoothUtility.bluetoothSocket.isConnected())
                BluetoothUtility.bluetoothSocket.close();

            BluetoothUtility.bluetoothSocket.connect();

            BluetoothUtility.inputStream = bluetoothSocket.getInputStream();
            BluetoothUtility.outputStream = bluetoothSocket.getOutputStream();

        } catch (IOException connectException) {
        }
    }

    public static Boolean IsConnect(){
        return BluetoothUtility.bluetoothSocket != null && BluetoothUtility.bluetoothSocket.isConnected();
    }

    public static void Write(String target) {
        try {
            BluetoothUtility.outputStream.write(target.getBytes("UTF-8"));
        } catch (IOException e) {
        }
    }
}
