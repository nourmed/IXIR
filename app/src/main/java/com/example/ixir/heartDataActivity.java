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
import android.os.IBinder;
import android.support.design.widget.TabLayout;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.content.ContextCompat;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.widget.ImageView;

import com.example.ixir.sensors.BleAccelerometerSensor;
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

public class heartDataActivity extends AppCompatActivity {
    private Toolbar toolbar;
    private TabLayout tabLayout;
    private ViewPager viewPager;
    private String deviceName;
    private String deviceAddress;
    private BleService bleService;
    private final static String TAG = heartDataActivity.class.getSimpleName();
    private boolean isConnected = false;
    private BleSensor<?> heartRateSensor;
    private BluetoothGattCharacteristic heartRateCharacteristic;
    private String service;
    private BluetoothGattCharacteristic sensorCharacteristic;
    private BluetoothGattService heartRateService;
    MesureFragment mesureFragment;
    statisticsFragment statisf;
    DemoSensorFragment sens;
    private Bundle bundle;
    public static final String EXTRA_SERVICE_UUID = "SERVICE_UUID";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    // Code to manage Service lifecycle.


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_heart_data);

        toolbar =
                findViewById(R.id.toolbar2);
        toolbar.setTitle("My Heart");
        toolbar.setBackgroundColor(Color.argb(255, 175, 27, 63));




        viewPager =  findViewById(R.id.viewpager);
      mesureFragment= new MesureFragment();
      statisf= new statisticsFragment();

        getSupportActionBar().hide();





        final Intent intent = getIntent();

    /**    service="0000180d-0000-1000-8000-00805f9b34fb";
     // Sets up UI references.
        bundle = new Bundle();
        bundle.putString("service", service);
        bundle.putString("adress", deviceAddress);
        // Sets up UI references.

        System.out.println(deviceAddress);
      mesureFragment.setArguments(bundle);
        //statisf.setArguments(bundle);**/
        setViewPager(viewPager);
        tabLayout = (TabLayout) findViewById(R.id.tabs);
        tabLayout.setupWithViewPager(viewPager);

    }
    @Override
    protected void onResume() {
        super.onResume();


    }
    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

    }


    private void setViewPager(ViewPager viewPager) {
        ViewPagerAdapter adapter = new ViewPagerAdapter(getSupportFragmentManager());

        adapter.addFragment(mesureFragment, "Mesurements");
        adapter.addFragment(statisf, "Statistics");
        viewPager.setAdapter(adapter);
    }

    class ViewPagerAdapter extends FragmentPagerAdapter {
        private final List<Fragment> mFragmentList = new ArrayList<>();
        private final List<String> mFragmentTitleList = new ArrayList<>();

        public ViewPagerAdapter(FragmentManager manager) {
            super(manager);
        }

        @Override
        public Fragment getItem(int position) {
            return mFragmentList.get(position);
        }

        @Override
        public int getCount() {
            return mFragmentList.size();
        }

        public void addFragment(Fragment fragment, String title) {
            mFragmentList.add(fragment);
            mFragmentTitleList.add(title);
        }

        @Override
        public CharSequence getPageTitle(int position) {
            return mFragmentTitleList.get(position);
        }
    }
    }

