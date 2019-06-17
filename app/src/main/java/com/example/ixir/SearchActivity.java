package com.example.ixir;

import android.Manifest;
import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.AsyncTask;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.recyclerview.extensions.ListAdapter;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.skyfishjy.library.RippleBackground;

import java.util.ArrayList;
import java.util.Hashtable;

public class SearchActivity extends AppCompatActivity {
    BluetoothManager btManager;
    BluetoothAdapter btAdapter;
    BluetoothLeScanner btScanner;
    ScanResult r;
    Button refresh;
    deviceAdapter adapter;
    LinearLayout bluetooth, list;
    RecyclerView recyclerView ;
    BluetoothDevice bleDevice;
    private Hashtable<BluetoothDevice, Integer> devices = new Hashtable<>();
    public ArrayList<BluetoothDevice> bleDevices = new ArrayList<BluetoothDevice>();
    private final static int REQUEST_ENABLE_BT = 1;
    private static final int PERMISSION_REQUEST_COARSE_LOCATION = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);


        bluetooth= findViewById(R.id.searchView);
        list= findViewById(R.id.listView);
        recyclerView = (RecyclerView) findViewById(R.id.recycler);
        refresh = findViewById(R.id.refresh);
        list.setVisibility(View.GONE);
        bluetooth.setVisibility(View.VISIBLE);
        final RippleBackground rippleBackground=(RippleBackground)findViewById(R.id.content);
    final ImageView imageView=(ImageView)findViewById(R.id.centerImage);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        getSupportActionBar().hide();
        rippleBackground.startRippleAnimation();

        btManager = (BluetoothManager)getSystemService(Context.BLUETOOTH_SERVICE);
        btAdapter = btManager.getAdapter();
        btScanner = btAdapter.getBluetoothLeScanner();



        startScanning();

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                stopScanning();
                int id = getResources().getIdentifier("com.example.ixir:drawable/" + "km", null, null);
                imageView.setImageResource(id);
                new Handler().postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        list.setVisibility(View.VISIBLE);
                    bluetooth.setVisibility(View.GONE);

                        deviceAdapter adapter = new deviceAdapter(bleDevices);
                        System.out.println(bleDevices);
                        // Attach the adapter to the recyclerview to populate items
                        recyclerView.setAdapter(adapter);
                        // Set layout manager to position the items

                    }
                }, 2000);
            }
        }, 10000);





        if (btAdapter != null && !btAdapter.isEnabled()) {
            Intent enableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableIntent,REQUEST_ENABLE_BT);
        }



        if (this.checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            final AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("This app needs location access");
            builder.setMessage("Please grant location access so this app can detect peripherals.");
            builder.setPositiveButton(android.R.string.ok, null);
            builder.setOnDismissListener(new DialogInterface.OnDismissListener() {
                @Override
                public void onDismiss(DialogInterface dialog) {
                    requestPermissions(new String[]{Manifest.permission.ACCESS_COARSE_LOCATION}, PERMISSION_REQUEST_COARSE_LOCATION);
                }
            });
            builder.show();
        }

        refresh.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int id = getResources().getIdentifier("com.example.ixir:drawable/" + "bluetooth", null, null);
                imageView.setImageResource(id);
                list.setVisibility(View.GONE);
                bluetooth.setVisibility(View.VISIBLE);
                startScanning();
                new Handler().postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        stopScanning();
                        int id = getResources().getIdentifier("com.example.ixir:drawable/" + "km", null, null);
                        imageView.setImageResource(id);
                        new Handler().postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                list.setVisibility(View.VISIBLE);
                                bluetooth.setVisibility(View.GONE);

                                deviceAdapter adapter = new deviceAdapter(bleDevices);
                                System.out.println(bleDevices);
                                // Attach the adapter to the recyclerview to populate items
                                recyclerView.setAdapter(adapter);
                                // Set layout manager to position the items

                            }
                        }, 2000);
                    }
                }, 10000);
            }
        });

        ItemClickSupport.addTo(recyclerView).setOnItemClickListener(
                new ItemClickSupport.OnItemClickListener() {
                    @Override
                    public void onItemClicked(RecyclerView recyclerView, int position, View v) {
                        BluetoothDevice device = bleDevices.get(position);
                       System.out.println(device.getName());
                        if (device == null)
                            return;

                       final Intent intent = new Intent(SearchActivity.this, DeviceServiceActivity.class);
                        intent.putExtra(DeviceServiceActivity.EXTRAS_DEVICE_NAME, device.getName());
                        intent.putExtra(DeviceServiceActivity.EXTRAS_DEVICE_ADDRESS, device.getAddress());
                        startActivity(intent);
                    }
                }
        );
    }


    private ScanCallback leScanCallback = new ScanCallback() {
        @Override
        public void onScanResult(int callbackType, ScanResult result) {

            final BluetoothDevice device = result.getDevice();
            // Try to get the name of the device...
            String deviceName = "";
            try {
                deviceName = result.getScanRecord().getDeviceName();
            } catch (NullPointerException e) {
                Log.e("debug", "Device-Name could not be read!");
            }
            // Get the RSSI of the device
            int rssi = result.getRssi();
            // Write the device in a table if it is not in there yet.
            if (!devices.containsKey(device)) {
                int entryId = View.generateViewId();
                devices.put(device, entryId);

                bleDevices.add(device);



            }
        }


    };




    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case PERMISSION_REQUEST_COARSE_LOCATION: {
                if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    System.out.println("coarse location permission granted");
                } else {
                    final AlertDialog.Builder builder = new AlertDialog.Builder(this);
                    builder.setTitle("Functionality limited");
                    builder.setMessage("Since location access has not been granted, this app will not be able to discover beacons when in the background.");
                    builder.setPositiveButton(android.R.string.ok, null);
                    builder.setOnDismissListener(new DialogInterface.OnDismissListener() {

                        @Override
                        public void onDismiss(DialogInterface dialog) {
                        }

                    });
                    builder.show();
                }
                return;
            }
        }
    }
    public void startScanning() {

        AsyncTask.execute(new Runnable() {
            @Override
            public void run() {
                btScanner.startScan(leScanCallback);

            }
        });
    }
    public void stopScanning() {
        AsyncTask.execute(new Runnable() {
            @Override
            public void run() {
                btScanner.stopScan(leScanCallback);
            }
        });
    }
}
