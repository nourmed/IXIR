package com.example.ixir;

import android.content.Intent;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class purshaseActivity extends AppCompatActivity {
    Button Buy;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_purshase);
        getSupportActionBar().hide();
        getWindow().setStatusBarColor(ContextCompat.getColor(this, R.color.background_blue_dark));
        Buy = findViewById(R.id.buy);

        Buy.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        final Intent intent = new Intent(purshaseActivity.this, thakyouActivity.class);
                        startActivity(intent);
                    }
                }
        );
    }
}
