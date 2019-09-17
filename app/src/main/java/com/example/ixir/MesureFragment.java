package com.example.ixir;

import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.graphics.Color;
import android.os.Bundle;
import android.os.IBinder;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.content.ContextCompat;
import android.support.v4.view.ViewPager;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.ImageView;

import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;
import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.charts.SeriesItem;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

import lecho.lib.hellocharts.model.Axis;
import lecho.lib.hellocharts.model.AxisValue;
import lecho.lib.hellocharts.model.Line;
import lecho.lib.hellocharts.model.LineChartData;
import lecho.lib.hellocharts.model.PointValue;
import lecho.lib.hellocharts.model.Viewport;
import lecho.lib.hellocharts.view.LineChartView;

import static android.content.Context.BIND_AUTO_CREATE;

public class MesureFragment extends DemoSensorFragment {
    private DecoView heartView;
    private String DeviceName;
    private String DeviceAdress;
    LineChartView lineChartView;
    String[] axisData = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept",
            "Oct", "Nov", "Dec"};
    int[] yAxisData = {50, 20, 15, 30, 20, 60, 15, 40, 45, 10, 90, 18};
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
        View fragmentm = inflater.inflate(R.layout.fragmentmesure, container, false);

        /** get device name and device address from heartDataActivity via Bundle**/
        if (getArguments() != null) {
            DeviceName = getArguments().getString("name");
            DeviceAdress = getArguments().getString("adress");
            System.out.println("testing:"+DeviceName+" "+DeviceAdress);
        }
        else
            System.out.println("nothing");

        System.out.println("device is:"+DeviceName+" "+DeviceAdress);
        /** set up UI ith circular progress circle and chart **/
        heartView = fragmentm.findViewById(R.id.heartView);
          heartimg = fragmentm.findViewById(R.id.heart);
        heartView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(6f)
                .build());
        seriesItem1 = new SeriesItem.Builder(Color.argb(255, 175, 27, 63))
                .setRange(0, 100, 0)
                .setLineWidth(15f)
                .build();
         series1Index = heartView.addSeries(seriesItem1);
        heartView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        heartView.executeReset();
        heartimg.setImageDrawable(null);
        heartimg.setVisibility(View.INVISIBLE);

        lineChartView = fragmentm.findViewById(R.id.chart);

        List yAxisValues = new ArrayList();
        List axisValues = new ArrayList();


        Line line = new Line(yAxisValues).setColor(Color.parseColor("#AF1B3F"));

        for (int i = 0; i < axisData.length; i++) {
            axisValues.add(i, new AxisValue(i).setLabel(axisData[i]));
        }

        for (int i = 0; i < yAxisData.length; i++) {
            yAxisValues.add(new PointValue(i, yAxisData[i]));
        }
        List lines = new ArrayList();
        lines.add(line);

        LineChartData data = new LineChartData();
        data.setLines(lines);
        Axis axis = new Axis();
        axis.setValues(axisValues);
        axis.setTextSize(16);
        axis.setTextColor(Color.parseColor("#1B1725"));
        data.setAxisXBottom(axis);
        Axis yAxis = new Axis();
        yAxis.setTextColor(Color.parseColor("#1B1725"));
        yAxis.setTextSize(16);
        data.setAxisYLeft(yAxis);
        lineChartView.setLineChartData(data);
        Viewport viewport = new Viewport(lineChartView.getMaximumViewport());
        viewport.top = 110;
        lineChartView.setMaximumViewport(viewport);
        lineChartView.setCurrentViewport(viewport);









        return fragmentm;
    }
    private void addAnimation(final DecoView arcView,
                              int series, float moveTo, int delay,
                              final ImageView imageView, final int imageId,
                              final int color) {
        DecoEvent.ExecuteEventListener listener = new DecoEvent.ExecuteEventListener() {
            @Override
            public void onEventStart(DecoEvent event) {
                imageView.setImageDrawable(ContextCompat.getDrawable(getContext(), imageId));

                showAvatar(true, imageView);


            }

            @Override
            public void onEventEnd(DecoEvent event) {
                showAvatar(false, imageView);


            }

        };

        arcView.addEvent(new DecoEvent.Builder(moveTo)
                .setIndex(series)
                .setDelay(delay)
                .setDuration(5000)
                .setListener(listener)
                .build());
    }

    private void showAvatar(boolean show, View view) {
        AlphaAnimation animation = new AlphaAnimation(show ? 0.0f : 1.0f, show ? 1.0f : 0.0f);
        animation.setDuration(10000000);
        animation.setFillAfter(true);
        view.startAnimation(animation);
    }


    @Override
    public void onDataRecieved(BleSensor<?> sensor, String text) {
        if (sensor instanceof BleHeartRateSensor) {
            final BleHeartRateSensor heartSensor = (BleHeartRateSensor) sensor;
            float[] values = heartSensor.getData();
            System.out.println(values);
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