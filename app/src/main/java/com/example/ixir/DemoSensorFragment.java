package com.example.ixir;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MenuItem;

import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;

import static android.content.Context.BIND_AUTO_CREATE;


public abstract class DemoSensorFragment extends Fragment {
    private final static String TAG = DemoSensorFragment.class.getSimpleName();

    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    public static final String EXTRAS_SENSOR_UUID = "SERVICE_UUID";

    private BleService bleService;
    private String serviceUuid;
    private String deviceAddress;
    private final ServiceConnection serviceConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName componentName, IBinder service) {
            bleService = ((BleService.LocalBinder) service).getService();
            if (!bleService.initialize()) {
                Log.e(TAG, "Unable to initialize Bluetooth");
                getActivity().finish();
            }
            // Automatically connects to the device upon successful start-up initialization.
            bleService.connect(deviceAddress);
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            bleService = null;
            //TODO: show toast
            getActivity().finish();
        }
    };
    // Handles various events fired by the Service.
    // ACTION_GATT_CONNECTED: connected to a GATT server.
    // ACTION_GATT_DISCONNECTED: disconnected from a GATT server.
    // ACTION_GATT_SERVICES_DISCOVERED: discovered GATT services.
    // ACTION_DATA_AVAILABLE: received data from the device.  This can be a result of read
    //                        or notification operations.
    private final BroadcastReceiver gattUpdateReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            final String action = intent.getAction();
            if (BleService.ACTION_GATT_DISCONNECTED.equals(action)) {
                //TODO: show toast
                getActivity().finish();
            } else if (BleService.ACTION_GATT_SERVICES_DISCOVERED.equals(action)) {
                final BleSensor<?> sensor = BleSensors.getSensor(serviceUuid);
                bleService.enableSensor(sensor, true);
            } else if (BleService.ACTION_DATA_AVAILABLE.equals(action)) {
                final BleSensor<?> sensor = BleSensors.getSensor(serviceUuid);
                final String text = intent.getStringExtra(BleService.EXTRA_TEXT);
                onDataRecieved(sensor, text);
            }
        }
    };

    // Code to manage Service lifecycle.


    public abstract void onDataRecieved(BleSensor<?> sensor, String text);

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        ((AppCompatActivity)getActivity()).getSupportActionBar().hide();
        if (getArguments() != null) {
            deviceAddress = getArguments().getString("adress");
            serviceUuid = getArguments().getString("service");
            System.out.println("testing:"+ serviceUuid+" "+deviceAddress);
        }


        final Intent gattServiceIntent = new Intent(getActivity(), BleService.class);
        getActivity().bindService(gattServiceIntent, serviceConnection, BIND_AUTO_CREATE);
    }

    @Override
    public void onResume() {
        super.onResume();

       getActivity().registerReceiver(gattUpdateReceiver, makeGattUpdateIntentFilter());
        if (bleService != null) {
            final boolean result = bleService.connect(deviceAddress);
            Log.d(TAG, "Connect request result=" + result);
        }
    }

    @Override
    public void onPause() {
        super.onPause();
        getActivity().unregisterReceiver(gattUpdateReceiver);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        getActivity().unbindService(serviceConnection);
        bleService = null;
    }


    private static IntentFilter makeGattUpdateIntentFilter() {
        final IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(BleService.ACTION_GATT_SERVICES_DISCOVERED);
        intentFilter.addAction(BleService.ACTION_GATT_DISCONNECTED);
        intentFilter.addAction(BleService.ACTION_DATA_AVAILABLE);
        return intentFilter;
    }
}
