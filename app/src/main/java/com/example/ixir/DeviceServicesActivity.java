/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.ixir;

import android.app.Activity;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.TextView;


import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

/**
 * For a given BLE device, this Activity provides the user interface to connect, display data,
 * and display GATT services and characteristics supported by the device.  The Activity
 * communicates with {@code BleService}, which in turn interacts with the
 * Bluetooth LE API.
 */
public class DeviceServicesActivity extends Activity {
    private final static String TAG = DeviceServicesActivity.class.getSimpleName();

    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";




    private BluetoothGattService heartRateService;
    private BluetoothGattCharacteristic heartRateCharacteristic;

    private TextView connectionState;
    private TextView dataField;
    private TextView heartRateField;
    private TextView intervalField;
    private Button demoButton;

    private ExpandableListView gattServicesList;
    private String deviceName;
    private String deviceAddress;
    private BleService bleService;
    private boolean isConnected = false;

    private BleSensor<?> accelerometerSensor;
    private BleSensor<?> heartRateSensor;




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


        }


        @Override
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
                displayGattServices(bleService.getSupportedGattServices());
                enableHeartRateSensor();
                enableAccelerometerSensor();
            } else if (BleService.ACTION_DATA_AVAILABLE.equals(action)) {

                System.out.println("data");
            }
        }
    };


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.gatt_services_characteristics);

        final Intent intent = getIntent();
        deviceName = intent.getStringExtra(EXTRAS_DEVICE_NAME);
        deviceAddress = intent.getStringExtra(EXTRAS_DEVICE_ADDRESS);

        // Sets up UI references.


        final Intent gattServiceIntent = new Intent(this, BleService.class);
        bindService(gattServiceIntent, serviceConnection, BIND_AUTO_CREATE);



    }
    private void displayGattServices(List<BluetoothGattService> gattServices) {
        if (gattServices == null)
        {System.out.println("no services");
            return;}

       System.out.println(gattServices);


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


    private boolean enableHeartRateSensor() {

        BluetoothGattCharacteristic characteristic= readcharacteristics(bleService.getSupportedGattServices());
        System.out.println("false");
        Log.d(TAG,"characteristic: " + characteristic);
        final BleSensor<?> sensor = BleSensors.getSensor(characteristic
                .getService()
                .getUuid()
                .toString());

        if (heartRateSensor != null) {
            bleService.enableSensor(heartRateSensor, false);
            System.out.println("1");
        }

        if (sensor == null) {
            bleService.readCharacteristic(characteristic);
            System.out.println("2");
            return true;
        }

        if (sensor == heartRateSensor) {
            System.out.println("3");

            return true;
        }
        heartRateSensor = sensor;
        bleService.enableSensor(sensor, true);

        System.out.println("4");



        return true;
    }


    private boolean enableAccelerometerSensor() {
        BluetoothGattCharacteristic characteristic= readcharacteristics(bleService.getSupportedGattServices());
        System.out.println("false");
        Log.d(TAG,"characteristic: " + characteristic);
        final BleSensor<?> sensor = BleSensors.getSensor(characteristic
                .getService()
                .getUuid()
                .toString());

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
                    UUID.fromString(BleHeartRateSensor.getServiceUUIDString()))) {
                heartRateService = gattService;
                heartRateCharacteristic = gattCharacteristics.get(0);
                System.out.println(heartRateCharacteristic);

            }

        }
        return heartRateCharacteristic;



    }
}



