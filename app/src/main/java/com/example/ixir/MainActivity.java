package com.example.ixir;

import android.content.Intent;
import android.os.Handler;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.agrawalsuneet.svgloaderspack.loaders.SVGLoader;

public class MainActivity extends AppCompatActivity {

    SVGLoader svgView; Button play;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide();
        getWindow().setStatusBarColor(ContextCompat.getColor(this, R.color.background_pink));
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                final Intent intent = new Intent(MainActivity.this,ChoiceActivity.class);
                startActivity(intent);
            }
        }, 2000);
      /*  play= findViewById(R.id.playpauseBtn);
        svgView = findViewById(R.id.svg_loader);
        svgView.setListener(new SVGLoader.AnimationListener() {
            @Override
            public void onAnimationEnd() {
                Toast.makeText(getBaseContext(), "Animation end", Toast.LENGTH_SHORT).show();
            }
        });*/

    /*    play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                svgView.startAnimation();
                svgView.endAnimation();
            }
        });*/


        //to stop loading call endAnimation()

    }
}
