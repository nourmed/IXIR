package com.example.ixir;

import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.Context;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.ImageView;

import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleHumiditySensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleTempratureSensor;
import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.charts.SeriesItem;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.util.ArrayList;
import java.util.List;

import lecho.lib.hellocharts.model.Axis;
import lecho.lib.hellocharts.model.AxisValue;
import lecho.lib.hellocharts.model.Line;
import lecho.lib.hellocharts.model.LineChartData;
import lecho.lib.hellocharts.model.PointValue;
import lecho.lib.hellocharts.model.Viewport;
import lecho.lib.hellocharts.view.LineChartView;


public class enviromentalFragment extends DemoSensorFragment {

    private String DeviceName;
    private String DeviceAdress;
    LineChartView lineChartView;
    String[] axisData = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept",
            "Oct", "Nov", "Dec"};
    float[] yAxisData = {};

    private BleService bleService;
    final private int COLOR_BLUE = Color.parseColor("#1D76D2");
    private final static String TAG = heartDataActivity.class.getSimpleName();
    private boolean isConnected = false;
    private BleSensor<?> heartRateSensor;
    private BluetoothGattCharacteristic heartRateCharacteristic;
    private float number;
    private BluetoothGattCharacteristic sensorCharacteristic;
    private BluetoothGattService heartRateService;
    private SeriesItem seriesItem1;
    private Bundle bundle;
    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    ImageView heartimg;
    int series1Index;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View fragmentm = inflater.inflate(R.layout.fragment_enviromental, container, false);
        ((AppCompatActivity)getActivity()).getSupportActionBar().hide();

        /** get device name and device address from heartDataActivity via Bundle**/
        if (getArguments() != null) {
            DeviceName = getArguments().getString("name");
            DeviceAdress = getArguments().getString("adress");
            System.out.println("testing:"+DeviceName+" "+DeviceAdress);
        }
        else
            System.out.println("nothing");

        System.out.println("device is:"+DeviceName+" "+DeviceAdress);




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