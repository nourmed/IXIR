package com.example.ixir.fragments;
import android.bluetooth.BluetoothDevice;
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
import android.os.Handler;
import android.os.IBinder;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.ixir.AcclerometerActivity;
import com.example.ixir.BleAccActivity;
import com.example.ixir.BleService;
import com.example.ixir.DemoSensorFragment;
import com.example.ixir.DeviceServicesActivity;
import com.example.ixir.Item;
import com.example.ixir.ItemClickSupport;
import com.example.ixir.R;
import com.example.ixir.SearchActivity;
import com.example.ixir.TensorflowClassifier;
import com.example.ixir.adapters.RecyclerViewHorizontalListAdapter;
import com.example.ixir.adapters.deviceAdapter;
import com.example.ixir.enviromental;
import com.example.ixir.firstActivity;
import com.example.ixir.heartDataActivity;
import com.example.ixir.physical;
import com.example.ixir.sensors.BleAccelerometerSensor;
import com.example.ixir.sensors.BleHeartRateSensor;
import com.example.ixir.sensors.BleSensor;
import com.example.ixir.sensors.BleSensors;
import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.charts.SeriesItem;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.UUID;

public class page1 extends DemoSensorFragment {
    private final static String TAG = firstActivity.class.getSimpleName();
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
    private static List<Float> x;
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

    private BluetoothGattCharacteristic sensorCharacteristic;
    private BluetoothGattCharacteristic heartRateCharacteristic;
    private List<Item> List = new ArrayList<>();
    public List<String> L;
    private RecyclerView RecyclerView;
    private RecyclerViewHorizontalListAdapter Adapter;
    private float[] results;
    String   deviceAddress;
    String serviceUuid;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.fragment_1, container, false);
        L= new ArrayList<>();
        x = new ArrayList<>();
        y = new ArrayList<>();
        z = new ArrayList<>();
        counter = view.findViewById(R.id.stepCounter);
        acceleroData= new float[3];
        values=new float[6];



        arcView = view.findViewById(R.id.stepsView);
     /*   KmView = view.findViewById(R.id.kmView);
        calView = view.findViewById(R.id.calView);*/
        imgView =  view.findViewById(R.id.steps);
     /*   final ImageView kmimgView =  view.findViewById(R.id.kmimg);
        final ImageView calimgView =  view.findViewById(R.id.cal);*/
        toolbar = (Toolbar) view.findViewById(R.id.toolbar);
        toolbar.inflateMenu(R.menu.menu_main);
        toolbar.setTitle("Ixir");
        toolbar.setTitleTextColor(Color.argb(255,48,188,237));




// first steps circle progress bar

        arcView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(6f)
                .build());
        SeriesItem seriesItem1 = new SeriesItem.Builder(Color.argb(180, 227, 41, 99))
                .setRange(0, 10000, 0)
                .setLineWidth(15f)
                .build();
         series1Index = arcView.addSeries(seriesItem1);
        arcView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        arcView.executeReset();
        imgView.setImageDrawable(null);
        imgView.setVisibility(View.INVISIBLE);


        arcView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getContext(), BleAccActivity.class);
                intent.putExtra(BleAccActivity.EXTRAS_DEVICE_NAME, DeviceName);
                intent.putExtra(BleAccActivity.EXTRAS_DEVICE_ADDRESS, DeviceAdress);
                intent.putExtra(BleAccActivity.EXTRAS_STEP_COUNT, stepCount + "");
                startActivity(intent);


            }
        });
//      Second circle KM
/*
        KmView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(3f)
                .build());
        SeriesItem seriesItem2 = new SeriesItem.Builder(Color.argb(200, 254, 147, 140))
                .setRange(0, 100, 0)
                .setLineWidth(14f)
                .build();
        int series2Index = KmView.addSeries(seriesItem2);
        KmView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        KmView.executeReset();
        kmimgView.setImageDrawable(null);
        kmimgView.setVisibility(View.INVISIBLE);
        addAnimation(KmView, series2Index, 19, 50, kmimgView, R.drawable.km, COLOR_BLUE);
        KmView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series1Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());

// rd progress circle calories


        calView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(3f)
                .build());
        SeriesItem seriesItem3 = new SeriesItem.Builder(Color.argb(200, 239, 111, 168))
                .setRange(0, 100, 0)
                .setLineWidth(14f)
                .build();
        int series3Index = calView.addSeries(seriesItem3);
        calView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        calView.executeReset();
        calimgView.setImageDrawable(null);
        calimgView.setVisibility(View.INVISIBLE);
        addAnimation(calView, series3Index, 19, 50, calimgView, R.drawable.callo, COLOR_BLUE);
        calView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series3Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());*/


     // grid layout with images and text underneath


      // CustumGridViewAdapter adapterViewAndroid = new CustumGridViewAdapter(getContext(), gridViewString, gridViewImageId);
      //  gridView=(GridView)view.findViewById(R.id.gv);
      //  gridView.setAdapter(adapterViewAndroid);

       RecyclerView = view.findViewById(R.id.idRecyclerViewHorizontalList);
        // add a divider after each item for more clarity
        RecyclerView.addItemDecoration(new DividerItemDecoration(getContext(), LinearLayoutManager.HORIZONTAL));
        Adapter = new RecyclerViewHorizontalListAdapter(List, getContext());
        LinearLayoutManager horizontalLayoutManager = new LinearLayoutManager(getContext(), LinearLayoutManager.HORIZONTAL, false);
        RecyclerView.setLayoutManager(horizontalLayoutManager);
        RecyclerView.setAdapter(Adapter);
        populategroceryList();


      /*  RecyclerView.getChildAt(0).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(getActivity(), heartDataActivity.class);
                i.putExtra(DeviceServicesActivity.EXTRAS_DEVICE_NAME, DeviceName);
                i.putExtra(DeviceServicesActivity.EXTRAS_DEVICE_ADDRESS, DeviceAdress);

                startActivity(i);
            }
        });*/
        if (getArguments() != null) {
             deviceAddress = getArguments().getString("adress");
           serviceUuid = "00002ff0-0000-1000-8000-00805f9b34fb";
            System.out.println("testing:"+serviceUuid+" "+deviceAddress);
        }


        ItemClickSupport.addTo(RecyclerView).setOnItemClickListener(
                new ItemClickSupport.OnItemClickListener() {
                        @Override
                    public void onItemClicked(RecyclerView recyclerView, int position, View v) {
                        Item icon = List.get(position);
                        // System.out.println(device.getName());
                            if (icon == null)
                             return;
                        System.out.println("item:  "+icon.getProductName());

                        if (icon.getProductName().equals("Cardiology"))
                        {
                            final Intent intent = new Intent(getActivity(),heartDataActivity.class);

                            startActivity(intent);
                        }

                            if (icon.getProductName().equals("Enviroment"))
                            {
                                final Intent intent = new Intent(getActivity(), enviromental.class);
                                startActivity(intent);
                            }
                            if (icon.getProductName().equals("Physical health"))
                            {
                                final Intent intent = new Intent(getActivity(), physical.class);
                                startActivity(intent);
                            }}




                }

        );



        classifier = new TensorflowClassifier(getContext());






        return view;


    }

    private void populategroceryList(){
        Item item1 = new Item("Cardiology", R.drawable.cardiaque);
       Item item2 = new Item("Enviroment",  R.drawable.enviroment);
       Item item3 = new Item("Physical health",  R.drawable.physicalhealth);
       Item item4 = new Item( "Sleep", R.drawable.sleep);
        List.add(item1);
      List.add(item2);
        List.add(item3);
        List.add(item4);


        Adapter.notifyDataSetChanged();
        for (int i=0; i<4;i++)
        {


        }

    }
    @Override
    public void onCreateOptionsMenu(Menu menu,
                                    MenuInflater inflater) {
        inflater.inflate(R.menu.menu_main, menu);

        super.onCreateOptionsMenu(menu, inflater);
    }


    // method used to
    private void addAnimation(final DecoView arcView,
                              int series, float moveTo, int delay,
                              final ImageView imageView, final int imageId,
                              final int color) {
        DecoEvent.ExecuteEventListener listener = new DecoEvent.ExecuteEventListener() {
            @Override
            public void onEventStart(DecoEvent event) {
                imageView.setImageDrawable(ContextCompat.getDrawable(getActivity(), imageId));

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
        final String characteristic_UUID=      sensor.getDataUUID();
        final String Service_UUId= sensor.getServiceUUID();



                final BleAccelerometerSensor accelero = (BleAccelerometerSensor) sensor;
                float[] values = accelero.getData();


            // System.out.println("liste:= "+L.get(0)+"  "+L.get(1)+"   "+L.get(2));
            if (characteristic_UUID.equals("00002ff1-0000-1000-8000-00805f9b34fb")) {
                acceleroData[0] = values[0];

            }
            if (characteristic_UUID.equals("00002ff2-0000-1000-8000-00805f9b34fb")) {
                acceleroData[1] = values[0];

            }
            if (characteristic_UUID.equals("00002ff3-0000-1000-8000-00805f9b34fb")) {
                acceleroData[2] = values[0];

            }
            x.add(acceleroData[0]);
            y.add(acceleroData[1]);
            z.add(acceleroData[2]);

            System.out.println("acc0" + acceleroData[0] + "   acc1:" + acceleroData[1] + "    accel2:" + acceleroData[2]);
            prev = lowPassFilter(acceleroData, prev);
            float R = (float) Math.sqrt(prev[0] * prev[0] + prev[1] * prev[1] + prev[2] * prev[2]);
            System.out.print("R:= " + R);
            if (R > 10.5f) {
                CURRENT_STATE = ABOVE;
                if (PREVIOUS_STATE != CURRENT_STATE) {
                    streakStartTime = System.currentTimeMillis();
                    if ((streakStartTime - streakPrevTime) <= 250f) {
                        streakPrevTime = System.currentTimeMillis();
                        return;
                    }
                    streakPrevTime = streakStartTime;
                    //  Log.d("STATES:", "" + streakPrevTime + " " + streakStartTime);
                    stepCount++;
                    System.out.print("steps:= " + stepCount);
                    values = activityPrediction();
                    counter.setText(2000 + " pas");
                    arcView.addEvent(new DecoEvent.Builder(stepCount)
                            .setIndex(series1Index)
                            .setDelay(1000)
                            .setDuration(2000)
                            .build());



                }
                PREVIOUS_STATE = CURRENT_STATE;
            } else if (R < 10.5f) {
                CURRENT_STATE = BELOW;
                PREVIOUS_STATE = CURRENT_STATE;
                //   System.out.println("no step");
            }

//System.out.println("Steps="+stepCount);

        }



    @Override
    public void onResume() {
        super.onResume();
        addAnimation(arcView, series1Index, 2000, 100, imgView, R.drawable.footprint, R.color.PINKi);


       // prev = lowPassFilter(,prev);


    }
    @Override
    public void onPause() {
        super.onPause();

    }

    @Override
    public void onDestroy() {
        super.onDestroy();

    }






    private float[] lowPassFilter(float[] input, float[] prev) {
        float ALPHA = 0.1f;
        if(input == null || prev == null) {
            return null;
        }
        for (int i=0; i< input.length; i++) {
            prev[i] = prev[i] + ALPHA * (input[i] - prev[i]);
        }
        return prev;
    }
    private float[] activityPrediction() {
        if (x.size() == N_SAMPLES && y.size() == N_SAMPLES && z.size() == N_SAMPLES) {
            List<Float> data = new ArrayList<>();
            data.addAll(x);
            data.addAll(y);
            data.addAll(z);
            System.out.println(data);
            results = classifier.predictProbabilities(toFloatArray(data));



            x.clear();
            y.clear();
            z.clear();
        }
        return results;
    }
    private static float round(float d, int decimalPlace) {
        BigDecimal bd = new BigDecimal(Float.toString(d));
        bd = bd.setScale(decimalPlace, BigDecimal.ROUND_HALF_UP);
        return bd.floatValue();
    }
    private float[] toFloatArray(List<Float> list) {
        int i = 0;
        float[] array = new float[list.size()];

        for (Float f : list) {
            array[i++] = (f != null ? f : Float.NaN);
        }
        return array;
    }
}