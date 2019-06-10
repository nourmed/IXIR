package com.example.ixir;

import android.graphics.Color;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.widget.ImageView;

import com.hookedonplay.decoviewlib.DecoView;
import com.hookedonplay.decoviewlib.charts.SeriesItem;
import com.hookedonplay.decoviewlib.events.DecoEvent;

import java.util.ArrayList;
import java.util.List;

import lecho.lib.hellocharts.model.Axis;
import lecho.lib.hellocharts.model.AxisValue;
import lecho.lib.hellocharts.model.Line;
import lecho.lib.hellocharts.model.LineChartData;
import lecho.lib.hellocharts.model.PointValue;
import lecho.lib.hellocharts.model.Viewport;
import lecho.lib.hellocharts.view.LineChartView;

public class heartDataActivity extends AppCompatActivity {
    private DecoView heartView;
    private Toolbar toolbar;
    LineChartView lineChartView;
    String[] axisData = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept",
            "Oct", "Nov", "Dec"};
    int[] yAxisData = {50, 20, 15, 30, 20, 60, 15, 40, 45, 10, 90, 18};

    final private int COLOR_BLUE = Color.parseColor("#1D76D2");
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_heart_data);
       heartView =findViewById(R.id.heartView);
        final ImageView heartimg = findViewById(R.id.heart);

        getSupportActionBar().hide();
        toolbar =  findViewById(R.id.toolbar2);
        toolbar.setTitle("Santé cardiaque");
        toolbar.setBackgroundColor(Color.argb(255,175,27,63));
        heartView.addSeries(new SeriesItem.Builder(Color.argb(255, 218, 218, 218))
                .setRange(0, 100, 100)
                .setInitialVisibility(true)
                .setLineWidth(6f)
                .build());
        SeriesItem seriesItem1 = new SeriesItem.Builder(Color.argb(255, 175,27,63))
                .setRange(0, 100, 0)
                .setLineWidth(15f)
                .build();
        int series1Index = heartView.addSeries(seriesItem1);
        heartView.addEvent(new DecoEvent.Builder(DecoEvent.EventType.EVENT_SHOW, true)
                .setDelay(1000)
                .setDuration(2000)
                .build());
        heartView.executeReset();
        heartimg.setImageDrawable(null);
        heartimg.setVisibility(View.INVISIBLE);
        addAnimation(heartView, series1Index, 19, 100, heartimg, R.drawable.heart,COLOR_BLUE);
        heartView.addEvent(new DecoEvent.Builder(64)
                .setIndex(series1Index)
                .setDelay(1000)
                .setDuration(2000)
                .build());

        lineChartView = findViewById(R.id.chart);

        List yAxisValues = new ArrayList();
        List axisValues = new ArrayList();


        Line line = new Line(yAxisValues).setColor(Color.parseColor("#AF1B3F"));

        for (int i = 0; i < axisData.length; i++) {
            axisValues.add(i, new AxisValue(i).setLabel(axisData[i]));
        }

        for (int i = 0; i < yAxisData.length; i++) {
            yAxisValues.add(new PointValue(i, yAxisData[i]));
        }
        List lines = new ArrayList();
        lines.add(line);

        LineChartData data = new LineChartData();
        data.setLines(lines);
        Axis axis = new Axis();
        axis.setValues(axisValues);
        axis.setTextSize(16);
        axis.setTextColor(Color.parseColor("#1B1725"));
        data.setAxisXBottom(axis);
        Axis yAxis = new Axis();
        yAxis.setTextColor(Color.parseColor("#1B1725"));
        yAxis.setTextSize(16);
        data.setAxisYLeft(yAxis);
        lineChartView.setLineChartData(data);
        Viewport viewport = new Viewport(lineChartView.getMaximumViewport());
        viewport.top = 110;
        lineChartView.setMaximumViewport(viewport);
        lineChartView.setCurrentViewport(viewport);



    }
    private void addAnimation(final DecoView arcView,
                              int series, float moveTo, int delay,
                              final ImageView imageView, final int imageId,
                              final int color) {
        DecoEvent.ExecuteEventListener listener = new DecoEvent.ExecuteEventListener() {
            @Override
            public void onEventStart(DecoEvent event) {
                imageView.setImageDrawable(ContextCompat.getDrawable(heartDataActivity.this, imageId));

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
