package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

public class BleUvSensor extends BleSensor<float[]> {
    @Override
    public String getName() {
        return "UV sensor";
    }

    @Override
    public String getServiceUUID() {
        return "0000181A-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataUUID() {
        return "00002A76-0000-1000-8000-00805f9b34fb";
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
        return "00002902-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataString() {
        final float[] data = getData();
        return "UV=" + data[0] ;
    }

    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {

        byte[] value =  c.getValue();

        final float[] values = getData();
        values[0]= (float) value[0];

        return values;
    }
}
