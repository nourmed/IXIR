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
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.ixir.adapters.RecyclerViewHorizontalListAdapter;
import com.example.ixir.sensors.BleAccelerometerSensor;
import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;
import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

import static android.content.Context.BIND_AUTO_CREATE;

public class statisticsFragment extends Fragment {

    private View view;
    final private int COLOR_BLUE = Color.parseColor("#1D76D2");
    private DecoView arcView;
    private DecoView KmView, calView;
    private GridView gridView;
    private Toolbar toolbar;
    String     DeviceName;
    String     DeviceAdress;
    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    public static final String EXTRAS_STEP_COUNT = "STEP_COUNT";
    private float[] prev = {0f,0f,0f};
    private float[] acceleroData;
    float number;
    int series1Index;
    private int stepCount = 0;
    private static final int ABOVE = 1;
    private static final int BELOW = 0;
    private static int CURRENT_STATE = 0;
    private static int PREVIOUS_STATE = BELOW;
    private BleSensor<?> accelerometerSensor;
    private BleSensor<?> accelerometerYSensor;
    String deviceName;

    private BleService bleService;
    private boolean isConnected = false;
    private static final int N_SAMPLES = 200;
    private static java.util.List<Float> x;
    private static List<Float> y;
    private static List<Float> z;
    private float[] values;
    private TensorflowClassifier classifier;
    private long streakStartTime;
    private long streakPrevTime;
    private String[] labels = {"Downstairs", "Jogging", "Sitting", "Standing", "Upstairs", "Walking"};
    ImageView imgView;
    TextView counter;
    List<BluetoothGattCharacteristic> gattCharacteristic;
    private BluetoothGattService heartRateService;
    private BluetoothGattService accService;
    private BluetoothGattCharacteristic accCharacteristic;
    private BleSensor<?> heartRateSensor;
    private BluetoothGattCharacteristic heartRateCharacteristic;

    private BluetoothGattCharacteristic sensorCharacteristic;

    private List<Item> List = new ArrayList<>();
    public List<String> L;
    private android.support.v7.widget.RecyclerView RecyclerView;
    private RecyclerViewHorizontalListAdapter Adapter;
    private float[] results;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View fragments = inflater.inflate(R.layout.fragmentstatistique, container, false);


        return fragments;
    }
  }