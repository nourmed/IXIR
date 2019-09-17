package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

public class BleTempratureSensor extends BleSensor<float[]> {
    private final static String TAG = BleHeartRateSensor.class.getSimpleName();


    @Override
    public String getName() {
        return " ambiant temperature";
    }

    @Override
    public String getServiceUUID() {
        return "0000181A-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataUUID() {
        return "00002A6E-0000-1000-8000-00805f9b34fb";
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
        final float[] data = getData();
        return "Temperature=" + data[0] ;
    }

    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {
        byte[] value =  c.getValue();

        final float[] values = getData();
        values[0]= (float) value[0];

        return values;
    }
}
