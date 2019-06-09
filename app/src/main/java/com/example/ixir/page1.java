package com.example.ixir;
import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.SnapHelper;
import android.support.v7.widget.Toolbar;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.GridView;
import android.widget.ImageView;

import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.charts.SeriesItem;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.util.ArrayList;
import java.util.List;

public class page1 extends Fragment {
    private View view;
    final private int COLOR_BLUE = Color.parseColor("#1D76D2");
    private DecoView arcView;
    private DecoView KmView, calView;
    private GridView gridView;
    private Toolbar toolbar;


    private List<Item> List = new ArrayList<>();
    private RecyclerView RecyclerView;
    private RecyclerViewHorizontalListAdapter Adapter;



    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.fragment_1, container, false);
        arcView = view.findViewById(R.id.StepsView);
        KmView = view.findViewById(R.id.kmView);
        calView = view.findViewById(R.id.calView);
        final ImageView imgView =  view.findViewById(R.id.steps);
        final ImageView kmimgView =  view.findViewById(R.id.kmimg);
        final ImageView calimgView =  view.findViewById(R.id.cal);
        toolbar = (Toolbar) view.findViewById(R.id.toolbar);
        toolbar.inflateMenu(R.menu.menu_main);
        toolbar.setTitle("Ixir");
        toolbar.setTitleTextColor(Color.argb(255,1,140,193));




// first steps circle progress bar

        arcView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(6f)
                .build());
        SeriesItem seriesItem1 = new SeriesItem.Builder(Color.argb(180, 48, 188, 237))
                .setRange(0, 100, 0)
                .setLineWidth(15f)
                .build();
        int series1Index = arcView.addSeries(seriesItem1);
        arcView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        arcView.executeReset();
        imgView.setImageDrawable(null);
        imgView.setVisibility(View.INVISIBLE);
        addAnimation(arcView, series1Index, 19, 100, imgView, R.drawable.footprint, COLOR_BLUE);
        arcView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series1Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());


//      Second circle KM

        KmView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(3f)
                .build());
        SeriesItem seriesItem2 = new SeriesItem.Builder(Color.argb(200, 239, 111, 168))
                .setRange(0, 100, 0)
                .setLineWidth(14f)
                .build();
        int series2Index = KmView.addSeries(seriesItem2);
        KmView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        KmView.executeReset();
        kmimgView.setImageDrawable(null);
        kmimgView.setVisibility(View.INVISIBLE);
        addAnimation(KmView, series2Index, 19, 50, kmimgView, R.drawable.km, COLOR_BLUE);
        KmView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series1Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());

// rd progress circle calories


        calView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(3f)
                .build());
        SeriesItem seriesItem3 = new SeriesItem.Builder(Color.argb(200, 239, 111, 168))
                .setRange(0, 100, 0)
                .setLineWidth(14f)
                .build();
        int series3Index = calView.addSeries(seriesItem3);
        calView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        calView.executeReset();
        calimgView.setImageDrawable(null);
        calimgView.setVisibility(View.INVISIBLE);
        addAnimation(calView, series3Index, 19, 50, calimgView, R.drawable.caloriescol, COLOR_BLUE);
        calView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series3Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());


     // grid layout with images and text underneath


      // CustumGridViewAdapter adapterViewAndroid = new CustumGridViewAdapter(getContext(), gridViewString, gridViewImageId);
      //  gridView=(GridView)view.findViewById(R.id.gv);
      //  gridView.setAdapter(adapterViewAndroid);

       RecyclerView = view.findViewById(R.id.idRecyclerViewHorizontalList);
        // add a divider after each item for more clarity
        RecyclerView.addItemDecoration(new DividerItemDecoration(getContext(), LinearLayoutManager.HORIZONTAL));
        Adapter = new RecyclerViewHorizontalListAdapter(List, getContext());
        LinearLayoutManager horizontalLayoutManager = new LinearLayoutManager(getContext(), LinearLayoutManager.HORIZONTAL, false);
        RecyclerView.setLayoutManager(horizontalLayoutManager);
        RecyclerView.setAdapter(Adapter);
        populategroceryList();
        return view;


    }

    private void populategroceryList(){
        Item item1 = new Item("Cardiologie", R.drawable.cardiaque);
       Item item2 = new Item("Activités Sportives",  R.drawable.sport);
       Item item3 = new Item("Nutrition Et Hydratation",  R.drawable.food);
       Item item4 = new Item( "Sommeil", R.drawable.sleep);
        List.add(item1);
      List.add(item2);
        List.add(item3);
        List.add(item4);
        Adapter.notifyDataSetChanged();
    }
    @Override
    public void onCreateOptionsMenu(Menu menu,
                                    MenuInflater inflater) {
        inflater.inflate(R.menu.menu_main, menu);

        super.onCreateOptionsMenu(menu, inflater);
    }


    // method used to
    private void addAnimation(final DecoView arcView,
                              int series, float moveTo, int delay,
                              final ImageView imageView, final int imageId,
                              final int color) {
        DecoEvent.ExecuteEventListener listener = new DecoEvent.ExecuteEventListener() {
            @Override
            public void onEventStart(DecoEvent event) {
                imageView.setImageDrawable(ContextCompat.getDrawable(getActivity(), imageId));

                showAvatar(true, imageView);


            }

            @Override
            public void onEventEnd(DecoEvent event) {
                showAvatar(false, imageView);


            }

        };

        arcView.addEvent(new DecoEvent.Builder(moveTo)
                .setIndex(series)
                .setDelay(delay)
                .setDuration(5000)
                .setListener(listener)
                .build());
    }
    private void showAvatar(boolean show, View view) {
        AlphaAnimation animation = new AlphaAnimation(show ? 0.0f : 1.0f, show ? 1.0f : 0.0f);
        animation.setDuration(10000000);
        animation.setFillAfter(true);
        view.startAnimation(animation);
    }
}