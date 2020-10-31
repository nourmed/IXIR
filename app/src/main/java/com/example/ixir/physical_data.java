package com.example.ixir;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.ixir.sensors.BleHumiditySensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleTempratureSensor;
import com.skyfishjy.library.RippleBackground;


public class physical_data extends DemoSensorFragment {


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View fragmentm = inflater.inflate(R.layout.fragment_physical_data, container, false);



        return fragmentm;
    }


    @Override
    public void onDataRecieved(BleSensor<?> sensor, String text) {
        if (sensor instanceof BleHumiditySensor) {
            final BleHumiditySensor humSensor = (BleHumiditySensor) sensor;
            float[] values = humSensor.getData();
            System.out.println(values);
            if (sensor instanceof BleTempratureSensor) {
                final BleTempratureSensor tempSensor = (BleTempratureSensor) sensor;
                float[] temp = tempSensor.getData();
                System.out.println(temp);


            }
        }
    }

    @Override
    public void onResume() {
        super.onResume();

    }

    @Override
    public void onPause() {
        super.onPause();

    }

    @Override
    public void onDestroy() {
        super.onDestroy();

    }
}
