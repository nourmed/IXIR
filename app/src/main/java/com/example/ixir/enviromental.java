
package com.example.ixir;

import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class enviromental extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_enviromental);
      Fragment fragment=new enviromentalFragment();
        getSupportActionBar().hide();
    }
}
