package com.example.ixir;

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
        play= findViewById(R.id.playpauseBtn);
        svgView = findViewById(R.id.svg_loader);
        svgView.setListener(new SVGLoader.AnimationListener() {
            @Override
            public void onAnimationEnd() {
                Toast.makeText(getBaseContext(), "Animation end", Toast.LENGTH_SHORT).show();
            }
        });

        play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                svgView.startAnimation();
                svgView.endAnimation();
            }
        });


        //to stop loading call endAnimation()

    }
}
