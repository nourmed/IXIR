package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;

import static android.bluetooth.BluetoothGattCharacteristic.FORMAT_SINT8;

public class BleAccelerometerSensor extends BleSensor<float[]> {

    @Override
    public String getName() {
        return "accelerometer";
    }

    @Override
    public String getServiceUUID() {
        return "00002FF0-0000-1000-8000-00805f9b34fb";
    }

    public String getServiceUUIDString() {
        return "00002FF0-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataUUID() {
        return "00002FF1-0000-1000-8000-00805f9b34fb";
    }

    public String getDataYUUID() {
        return "00002FF2-0000-1000-8000-00805f9b34fb";
    }

    public String getDataZUUID() {
        return "00002FF3-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getConfigUUID() {
        return "00002902-0000-1000-8000-00805f9b34fb";
    }


    @Override
    public String getCharacteristicName(String uuid) {
        if ("00002FF1-0000-1000-8000-00805f9b34fb".equals(uuid))
            return getName() + " X axis ";
        return super.getCharacteristicName(uuid);
    }

    @Override
    public String getDataString() {
        final float[] data = getData();
        return coordinatesToString(data);

    }


    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {


                /*
                 * The accelerometer has the range [-2g, 2g] with unit (1/64)g.
                 *
                 * To convert from unit (1/64)g to unit g we divide by 64.
                 *
                 * (g = 9.81 m/s^2)
                 *
                 * The z value is multiplied with -1 to coincide
                 * with how we have arbitrarily defined the positive y direction.
                 * (illustrated by the apps accelerometer image)
                 */
                Integer x = c.getIntValue(FORMAT_SINT8, 0);
                Integer y = c.getIntValue(FORMAT_SINT8, 1);
                Integer z = -1 * c.getIntValue(FORMAT_SINT8, 2);

                double scaledX = x / 64.0;
                double scaledY = y / 64.0;
                double scaledZ = z / 64.0;
                final float[] values = getData();
                values[0] = (float) scaledX;
                values[1] = (float) scaledY;
                values[2] = (float) scaledZ;

        return values;
    }

    public static String coordinatesToString(float[] coordinates) {
        return String.format("x=%+.6f\ny=%+.6f\nz=%+.6f",
                coordinates[0], coordinates[1], coordinates[2]);
    }
}