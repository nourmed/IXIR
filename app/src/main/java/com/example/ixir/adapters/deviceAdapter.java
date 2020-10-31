package com.example.ixir.adapters;

import android.bluetooth.BluetoothDevice;
import android.content.Context;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.ixir.R;

import java.util.ArrayList;

public class deviceAdapter extends  RecyclerView.Adapter<deviceAdapter.ViewHolder> {


    private ArrayList<BluetoothDevice> mbledevices;

    public deviceAdapter(ArrayList<BluetoothDevice> bledevices) {
          mbledevices=bledevices;
    }


    @Override
    public deviceAdapter.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        Context context = parent.getContext();
        LayoutInflater inflater = LayoutInflater.from(context);

        // Inflate the custom layout
        View contactView = inflater.inflate(R.layout.activity_device, parent, false);

        // Return a new holder instance
        ViewHolder viewHolder = new ViewHolder(contactView);
        return viewHolder;
    }



    @Override
    public void onBindViewHolder(deviceAdapter.ViewHolder viewHolder, int position) {
        // Get the data model based on position
        BluetoothDevice bledevice = mbledevices.get(position);

        // Set item views based on your views and data model
        TextView textView = viewHolder.nameTextView;
        textView.setText(bledevice.getName());

    }

    // Returns the total count of items in the list
    @Override
    public int getItemCount() {
        return mbledevices.size();
    }




    public class ViewHolder extends RecyclerView.ViewHolder {
        // Your holder should contain a member variable
        // for any view that will be set as you render a row
        public TextView nameTextView;


        // We also create a constructor that accepts the entire item row
        // and does the view lookups to find each subview
        public ViewHolder(View itemView) {
            // Stores the itemView in a public final member variable that can be used
            // to access the context from any ViewHolder instance.
            super(itemView);

            nameTextView = (TextView) itemView.findViewById(R.id.device);
            nameTextView.setTextSize(20);
            nameTextView.setTextAlignment(View.TEXT_ALIGNMENT_CENTER);
        }

    }


}
