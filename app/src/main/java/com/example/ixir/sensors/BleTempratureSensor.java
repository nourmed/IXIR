package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

public class BleTempratureSensor extends BleSensor<float[]> {
    private final static String TAG = BleHeartRateSensor.class.getSimpleName();


    @Override
    public String getName() {
        return null;
    }

    @Override
    public String getServiceUUID() {
        return null;
    }

    @Override
    public String getDataUUID() {
        return null;
    }

    @Override
    public String getConfigUUID() {
        return null;
    }

    @Override
    public String getDataString() {
        return null;
    }

    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {
        return new float[0];
    }
}
