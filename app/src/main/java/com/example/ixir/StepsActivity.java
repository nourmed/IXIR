package com.example.ixir;

import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.example.ixir.sensors.BleAccelerometerSensor;
import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

public class StepsActivity extends AppCompatActivity {
    private final static String TAG = StepsActivity.class.getSimpleName();

    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    private BluetoothGattService accService;
    private BluetoothGattCharacteristic accCharacteristic;
    private String deviceName;
    private String deviceAddress;
    private BleService bleService;
    private boolean isConnected = false;

    private BleSensor<?> accelerometerSensor;

    private BluetoothGattCharacteristic sensorCharacteristic;


    // Code to manage Service lifecycle.
    private final ServiceConnection serviceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName componentName, IBinder service) {
            bleService = ((BleService.LocalBinder) service).getService();
            if (!bleService.initialize()) {
                Log.e(TAG, "Unable to initialize Bluetooth");
                finish();
            }
            // Automatically connects to the device upon successful start-up initialization.
            bleService.connect(deviceAddress);


        }        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            bleService = null;
        }
    };


    private final BroadcastReceiver gattUpdateReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {


            final String action = intent.getAction();
            if (BleService.ACTION_GATT_CONNECTED.equals(action)) {
                isConnected = true;
                System.out.println("connected");

            } else if (BleService.ACTION_GATT_DISCONNECTED.equals(action)) {
                isConnected = false;
                System.out.println("disconnected");
            } else if (BleService.ACTION_GATT_SERVICES_DISCOVERED.equals(action)) {

                // Show all the supported services and characteristics on the user interface.

                // enableHeartRateSensor();
                enableAccelerometerSensor();
            } else if (BleService.ACTION_DATA_AVAILABLE.equals(action)) {
                //System.out.println(  intent.getStringExtra(BleService.EXTRA_SERVICE_UUID));
                //   System.out.println(intent.getStringExtra(BleService.EXTRA_TEXT));
                // System.out.println("data");
            }
        }
    };



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_steps);
    }

    @Override
    protected void onResume() {
        super.onResume();
        registerReceiver(gattUpdateReceiver, makeGattUpdateIntentFilter());
        if (bleService != null) {
            final boolean result = bleService.connect(deviceAddress);
            Log.d(TAG, "Connect request result=" + result);
        }
    }
    @Override
    protected void onPause() {
        super.onPause();
        unregisterReceiver(gattUpdateReceiver);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unbindService(serviceConnection);
        bleService = null;
    }

    private static IntentFilter makeGattUpdateIntentFilter() {
        final IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(BleService.ACTION_GATT_CONNECTED);
        intentFilter.addAction(BleService.ACTION_GATT_DISCONNECTED);
        intentFilter.addAction(BleService.ACTION_GATT_SERVICES_DISCOVERED);
        intentFilter.addAction(BleService.ACTION_DATA_AVAILABLE);
        return intentFilter;
    }


    private boolean enableAccelerometerSensor() {
        BluetoothGattCharacteristic characteristic= readcharacteristics(bleService.getSupportedGattServices());
        System.out.println("false");
        Log.d(TAG,"characteristic: " + characteristic);
        final BleSensor<?> sensor = BleSensors.getSensor("00002ff0-0000-1000-8000-00805f9b34fb");

        if (accelerometerSensor != null) {
            bleService.enableSensor(accelerometerSensor, false);
            System.out.println("1");
        }

        if (sensor == null) {
            bleService.readCharacteristic(characteristic);
            System.out.println("2");
            return true;
        }

        if (sensor == accelerometerSensor) {
            System.out.println("3");

            return true;
        }
        accelerometerSensor = sensor;
        bleService.enableSensor(sensor, true);

        System.out.println("4");

        return true;

    }

    public BluetoothGattCharacteristic readcharacteristics( List<BluetoothGattService> gattServices)
    {


        final ArrayList<BluetoothGattService> services;
        final HashMap<BluetoothGattService, ArrayList<BluetoothGattCharacteristic>> characteristics;
        services = new ArrayList<>(gattServices.size());
        characteristics = new HashMap<>(
                gattServices.size());
        for (BluetoothGattService gattService : gattServices) {
            final List<BluetoothGattCharacteristic> gattCharacteristics = gattService
                    .getCharacteristics();
            characteristics.put(gattService,
                    new ArrayList<>(
                            gattCharacteristics));
            services.add(gattService);





            if (gattService.getUuid().equals(
                    UUID.fromString(BleAccelerometerSensor.getServiceUUIDString()))) {
                accService = gattService;
                accCharacteristic = gattCharacteristics.get(0);

                sensorCharacteristic=accCharacteristic;

            }

        }
        return sensorCharacteristic;



    }


}
