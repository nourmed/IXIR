package com.example.ixir;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.ViewFlipper;


public class page2 extends Fragment {

    ViewFlipper v_flipper;
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_2, container, false);
        int images[]= {R.drawable.aventure, R.drawable.parachute, R.drawable.run};
        v_flipper= view.findViewById(R.id.v_flipper)  ;
        for (int i =0; i< images.length; i++)
        { flipperImages(images[i]);}




        return view;
    }
    public void flipperImages (int image) {
        ImageView imageview= new ImageView(getContext());
        imageview.setBackgroundResource(image);
        v_flipper.addView(imageview);
        v_flipper.setFlipInterval(4000);
        v_flipper.setAutoStart(true);
        v_flipper.setOutAnimation(getContext(),android.R.anim.slide_out_right);
    }
}