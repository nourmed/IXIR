package com.example.ixir;


import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.annotation.NonNull;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.design.widget.BottomNavigationView;
import android.util.Log;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.TextView;

import com.example.ixir.adapters.fragment_adapter;
import com.example.ixir.fragments.page1;
import com.example.ixir.fragments.page2;
import com.example.ixir.fragments.page3;
import com.example.ixir.fragments.page4;
import com.example.ixir.fragments.page5;
import com.example.ixir.sensors.BleSensor;


public class firstActivity extends AppCompatActivity {

    private final static String TAG = DeviceServicesActivity.class.getSimpleName();

    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";

    private TextView connectionState;
    private TextView dataField;
    private TextView heartRateField;
    private TextView intervalField;
    private Button demoButton;

    private ExpandableListView gattServicesList;


    private String deviceName;
    private String deviceAddress;
    private BleService bleService;
    private boolean isConnected = false;

    private BleSensor<?> activeSensor;
    private BleSensor<?> heartRateSensor;


    // Code to manage Service lifecycle.
    private final ServiceConnection serviceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName componentName, IBinder service) {
            bleService = ((BleService.LocalBinder) service).getService();
            if (!bleService.initialize()) {
                Log.e(TAG, "Unable to initialize Bluetooth");
                finish();
            }
            // Automatically connects to the device upon successful start-up initialization.
            bleService.connect(deviceAddress);
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {
            bleService = null;
        }
    };



    ViewPager viewPager;
    BottomNavigationView navigation;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first);
        getSupportActionBar().hide();
        navigation = findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);

        viewPager = findViewById(R.id.viewpager);
        setupFm(getSupportFragmentManager(), viewPager);
        viewPager.setCurrentItem(0);
        viewPager.setOnPageChangeListener(new PageChange());


        // Connecting to the BLE Device and discovering the characteristics



        final Intent intent = getIntent();
        deviceName = intent.getStringExtra(EXTRAS_DEVICE_NAME);
        deviceAddress = intent.getStringExtra(EXTRAS_DEVICE_ADDRESS);

        // Sets up UI references.


        final Intent gattServiceIntent = new Intent(this, BleService.class);
        bindService(gattServiceIntent, serviceConnection, BIND_AUTO_CREATE);



















    }

    public static void setupFm(FragmentManager fragmentManager, ViewPager viewPager){
        fragment_adapter Adapter = new fragment_adapter(fragmentManager);

        Adapter.add(new page1(), "Page One");
        Adapter.add(new page2(), "Page Two");
        Adapter.add(new page3(), "Page Three");

        Adapter.add(new page4(), "Page Four");

        Adapter.add(new page5(), "Page Five");

        viewPager.setAdapter(Adapter);
    }

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.navigation_dashboard:
                    viewPager.setCurrentItem(0);
                    return true;
                case R.id.navigation_community:
                    viewPager.setCurrentItem(1);
                    return true;
                case R.id.navigation_tips:
                    viewPager.setCurrentItem(2);
                    return true;
                case R.id.navigation_challenges:
                    viewPager.setCurrentItem(3);
                    return true;
                case R.id.navigation_notifications:
                    viewPager.setCurrentItem(4);
                    return true;
            }
            return false;
        }
    };


    public class PageChange implements ViewPager.OnPageChangeListener {

        @Override
        public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {
        }

        @Override
        public void onPageSelected(int position) {

            switch (position) {
                case 0:
                    navigation.setSelectedItemId(R.id.navigation_dashboard);
                    break;
                case 1:
                    navigation.setSelectedItemId(R.id.navigation_community);
                    break;
                case 2:
                    navigation.setSelectedItemId(R.id.navigation_tips);
                    break;
                case 3:
                    navigation.setSelectedItemId(R.id.navigation_challenges);
                    break;
                case 4:
                    navigation.setSelectedItemId(R.id.navigation_notifications);
                    break;

            }
        }

        @Override
        public void onPageScrollStateChanged(int state) {

        }
    }
}