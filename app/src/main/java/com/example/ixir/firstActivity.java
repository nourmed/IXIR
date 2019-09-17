package com.example.ixir;


import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.graphics.Color;
import android.os.IBinder;
import android.support.annotation.NonNull;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.design.widget.BottomNavigationView;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
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

    private final static String TAG = firstActivity.class.getSimpleName();

    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    Bundle bundle;
    public static final String EXTRA_SERVICE_UUID = "SERVICE_UUID";
    private ExpandableListView gattServicesList;


   String deviceName;
     String deviceAddress;
     String service ;
    private BleService bleService;
    private boolean isConnected = false;












    final private int COLOR_Pink = Color.parseColor("#FFE32963");
    ViewPager viewPager;
    BottomNavigationView navigation;
    Fragment fragment1;
    Fragment fragment2;
    Fragment fragment3;
    Fragment fragment4;
    Fragment fragment5;
    Fragment mf;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first);

        getWindow().setStatusBarColor(COLOR_Pink);
        getSupportActionBar().hide();
        navigation = findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);
        fragment1=new page1();
        mf= new MesureFragment();
        fragment2=new page2();
        fragment3=new page3();
        fragment4=new page4();
        fragment5=new page5();


        viewPager = findViewById(R.id.viewpager);
        setupFm(getSupportFragmentManager(),fragment1,fragment2,fragment3,fragment4,fragment5, viewPager);
        viewPager.setCurrentItem(0);
        viewPager.setOnPageChangeListener(new PageChange());


        // Connecting to the BLE Device and discovering the characteristics




        final Intent intent = getIntent();
        deviceName = intent.getStringExtra(EXTRAS_DEVICE_NAME);
        deviceAddress = intent.getStringExtra(EXTRAS_DEVICE_ADDRESS);
        service = intent.getStringExtra(EXTRA_SERVICE_UUID);
System.out.println("a"+deviceName+"b"+deviceAddress);
        // Sets up UI references.
        bundle = new Bundle();

        bundle.putString("adress", deviceAddress);
        // Sets up UI references.
        bundle.putString("service","00002ff0-0000-1000-8000-00805f9b34fb");
        System.out.println(deviceName+deviceAddress);
        fragment1.setArguments(bundle);

       mf.setArguments(bundle);


    }

    public static void setupFm(FragmentManager fragmentManager,Fragment f1,Fragment f2,Fragment f3,Fragment f4,Fragment f5, ViewPager viewPager){
        fragment_adapter Adapter = new fragment_adapter(fragmentManager);

        Adapter.add(f1, "Page One");
        Adapter.add(f2, "Page Two");
        Adapter.add(f3, "Page Three");

        Adapter.add(f4, "Page Four");

        Adapter.add(f5, "Page Five");

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