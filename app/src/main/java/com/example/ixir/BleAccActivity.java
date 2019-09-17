package com.example.ixir;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class BleAccActivity extends AppCompatActivity {
    public static final String EXTRAS_DEVICE_NAME = "DEVICE_NAME";
    public static final String EXTRAS_DEVICE_ADDRESS = "DEVICE_ADDRESS";
    public static final String EXTRAS_STEP_COUNT = "STEP_COUNT";

    String deviceName;
    String deviceAddress;
    String stepCount;
    long steps;
    float km;
    TextView stepView, kmView, calView;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.acc_related_layout);
        getSupportActionBar().hide();

        stepView= findViewById(R.id.st);

        kmView= findViewById(R.id.distance);
        calView=findViewById(R.id.cals);






        final Intent intent = getIntent();
        deviceName = intent.getStringExtra(EXTRAS_DEVICE_NAME);
        deviceAddress = intent.getStringExtra(EXTRAS_DEVICE_ADDRESS);
        stepCount= intent.getStringExtra(EXTRAS_STEP_COUNT);
        System.out.println("step count"+deviceName);

        if (stepCount!=null)
        {steps= Long.parseLong(stepCount);
      km= getDistanceRun(steps);}
        else
        { steps=0;}


       stepView.setText(steps+ " pas");
        kmView.setText(km+ " km.");
    }

    public float getDistanceRun(long steps){
        float distance = (float)(steps*74)/(float)100000;
        return distance;
    }
}
