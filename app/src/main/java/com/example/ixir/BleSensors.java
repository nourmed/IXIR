package com.example.ixir;

import java.util.HashMap;


public class BleSensors {

    private static HashMap<String, BleSensor<?>> SENSORS = new HashMap<String, BleSensor<?>>();

    static {
        final BleHeartRateSensor heartRateSensor = new BleHeartRateSensor();


        SENSORS.put(heartRateSensor.getServiceUUID(), heartRateSensor);
    }

    public static BleSensor<?> getSensor(String uuid) {
        return SENSORS.get(uuid);
    }
}
