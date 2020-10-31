package com.example.ixir;

import android.content.Intent;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class ChoiceActivity extends AppCompatActivity {
    Button purshase;
    Button app;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_choice);
        getSupportActionBar().hide();
        getWindow().setStatusBarColor(ContextCompat.getColor(this, R.color.background_blue_dark));
        purshase = findViewById(R.id.purshase);
        app = findViewById(R.id.app);
        purshase.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        final Intent intent = new Intent(ChoiceActivity.this, purshaseActivity.class);
                        startActivity(intent);
                    }
                }
        );
        app.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        final Intent intent = new Intent(ChoiceActivity.this,firstActivity.class);
                        startActivity(intent);
                    }
                }
        );
    }
}
