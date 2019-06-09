package com.example.ixir;


import android.support.annotation.NonNull;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.design.widget.BottomNavigationView;
import android.view.MenuItem;


public class firstActivity extends AppCompatActivity {

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