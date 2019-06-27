package com.example.ixir.sensors;

import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;

import java.util.HashMap;


public class BleSensors {

    private static HashMap<String, BleSensor<?>> SENSORS = new HashMap<String, BleSensor<?>>();

    static {
        final BleHeartRateSensor heartRateSensor = new BleHeartRateSensor();
        final BleAccelerometerSensor accelerometerSensor = new BleAccelerometerSensor();
        SENSORS.put(accelerometerSensor.getServiceUUID(), accelerometerSensor);
        SENSORS.put(heartRateSensor.getServiceUUID(), heartRateSensor);
    }

    public static BleSensor<?> getSensor(String uuid) {
        return SENSORS.get(uuid);
    }
}
