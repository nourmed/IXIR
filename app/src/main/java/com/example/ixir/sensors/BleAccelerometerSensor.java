package com.example.ixir.sensors;

import android.bluetooth.BluetoothGattCharacteristic;
import android.util.Log;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import static android.bluetooth.BluetoothGattCharacteristic.FORMAT_FLOAT;
import static android.bluetooth.BluetoothGattCharacteristic.FORMAT_SINT8;

public class BleAccelerometerSensor extends BleSensor<float[]> {
    BleAccelerometerSensor() {
        super();
    }
    @Override
    public String getName() {
        return "accelerometer";
    }

    @Override
    public String getServiceUUID() {
        return "00002ff0-0000-1000-8000-00805f9b34fb";
    }

    public static String getServiceUUIDString() {
        return "00002ff0-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getDataUUID() {
        return "00002ff1-0000-1000-8000-00805f9b34fb";
    }

    public String getDatayUUID() {
        return "00002ff2-0000-1000-8000-00805f9b34fb";
    }

    public String getDatazUUID() {
        return "00002ff3-0000-1000-8000-00805f9b34fb";
    }

    @Override
    public String getConfigUUID() {
        return "00002902-0000-1000-8000-00805f9b34fb";
    }


    @Override
    public String getCharacteristicName(String uuid) {
        if ("00002ff1-0000-1000-8000-00805f9b34fb".equals(uuid))
            return getName() ;
        return super.getCharacteristicName(uuid);
    }

    @Override
    public String getDataString() {

        final float[] data = getData();

        return data[0]+"";

    }
    @Override
    public boolean onCharacteristicRead(BluetoothGattCharacteristic c) {
        super.onCharacteristicRead(c);


        return true;
    }

    @Override
    protected float[] parse(BluetoothGattCharacteristic c) {


         float[] values;
            values=new float[3];
   byte[] data= c.getValue();
        float f1 = ByteBuffer.wrap(data).order(ByteOrder.LITTLE_ENDIAN).getFloat();


       // final byte[] data = getValue();
      //  float f1=  ByteBuffer.wrap(x).order(ByteOrder.LITTLE_ENDIAN).getFloa‌​t();
       // Float x = c.getFloatValue(FORMAT_FLOAT, 0);
     /*  Float y = c.getFloatValue(FORMAT_FLOAT, 1);
        Float z = -1 * c.getFloatValue(FORMAT_FLOAT, 2);*/



               values[0] = (float) f1;
            /*  values[1] = (float) y;
                values[2] = (float) z;*/

        return values;
    }

    public static String coordinatesToString(Float coordinates) {
        return coordinates+"";
    }
}