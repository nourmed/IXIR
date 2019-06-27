package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

public class BleBodyTempSensor extends BleSensor<Float[]> {
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
    protected Float[] parse(BluetoothGattCharacteristic c) {
        return null;
    }
}
