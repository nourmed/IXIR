package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

public class BleBodyTempSensor extends BleSensor<float[]> {
    @Override
    public String getName() {
        return "Body Temperature";
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
    public String getDatayUUID() {
        return null;
    }

    @Override
    public String getDatazUUID() {
        return null;
    }

    @Override
    public String getConfigUUID() {
        return
                "00002902-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataString() {
        return null;
    }

    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {
        return null;
    }
}
