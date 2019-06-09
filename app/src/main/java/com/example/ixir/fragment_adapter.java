package com.example.ixir;


import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;

import java.util.ArrayList;
import java.util.List;

public class fragment_adapter  extends FragmentPagerAdapter {
        private List<android.support.v4.app.Fragment> Fragment = new ArrayList<>(); //Fragment List
        private List<String> NamePage = new ArrayList<>(); // Fragment Name List
        public fragment_adapter(FragmentManager manager) {
            super(manager);
        }
        public void add(Fragment Frag, String Title) {
            Fragment.add(Frag);
            NamePage.add(Title);
        }
        @Override
        public Fragment getItem(int position) {
            return Fragment.get(position);
        }
        @Override
        public CharSequence getPageTitle(int position) {
            return NamePage.get(position);
        }
        @Override
        public int getCount() {
            return 5;
        }
    }