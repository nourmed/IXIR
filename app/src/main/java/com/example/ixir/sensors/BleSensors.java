package com.example.ixir.sensors;

import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;

import java.util.HashMap;


public class BleSensors {

    private static HashMap<String, BleSensor<?>> SENSORS = new HashMap<String, BleSensor<?>>();

    static {
        final BleHeartRateSensor heartRateSensor = new BleHeartRateSensor();
        final BleAccelerometerSensor accelerometerSensor = new BleAccelerometerSensor();
        final BleTempratureSensor ambiantTempSensor = new BleTempratureSensor();
        final BleHumiditySensor HumiditySensor = new BleHumiditySensor();
        final BleBodyTempSensor bodyTempSensor = new BleBodyTempSensor();
        final BleUvSensor  UvSensor= new BleUvSensor();

        SENSORS.put(bodyTempSensor.getServiceUUID(), bodyTempSensor);
        SENSORS.put(UvSensor.getServiceUUID(), UvSensor);
        SENSORS.put(HumiditySensor.getServiceUUID(), HumiditySensor);
        SENSORS.put(accelerometerSensor.getServiceUUID(), accelerometerSensor);
        SENSORS.put(heartRateSensor.getServiceUUID(), heartRateSensor);
        SENSORS.put(ambiantTempSensor.getServiceUUID(), ambiantTempSensor);
    }

    public static BleSensor<?> getSensor(String uuid) {
        return SENSORS.get(uuid);
    }
}
