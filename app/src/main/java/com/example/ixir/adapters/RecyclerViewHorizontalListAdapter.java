package com.example.ixir.adapters;

import android.content.Context;
import android.content.Intent;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.ixir.Item;
import com.example.ixir.R;
import com.example.ixir.heartDataActivity;

import java.util.List;

public class RecyclerViewHorizontalListAdapter extends RecyclerView.Adapter<RecyclerViewHorizontalListAdapter.GroceryViewHolder>{
    private List<Item> horizontalGrocderyList;
    Context context;

    public RecyclerViewHorizontalListAdapter(List<Item> horizontalGrocderyList, Context context){
        this.horizontalGrocderyList= horizontalGrocderyList;
        this.context = context;
    }

    @Override
    public GroceryViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        //inflate the layout file
        View groceryProductView = LayoutInflater.from(parent.getContext()).inflate(R.layout.grid_view_layout, parent, false);
        GroceryViewHolder gvh = new GroceryViewHolder(groceryProductView);
        return gvh;
    }


    @Override
    public void onBindViewHolder(GroceryViewHolder holder, final int position) {
        holder.imageView.setImageResource(horizontalGrocderyList.get(position).getProductImage());
        holder.txtview.setText(horizontalGrocderyList.get(position).getProductName());
        holder.imageView.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {

                    Intent i=new Intent ( context , heartDataActivity.class );
                    context.startActivity(i);
            }
        });
    }






    @Override
    public int getItemCount() {
        return horizontalGrocderyList.size();
    }

    public class GroceryViewHolder extends RecyclerView.ViewHolder {
        ImageView imageView;
        TextView txtview;
        public GroceryViewHolder(View view) {
            super(view);
            imageView=view.findViewById(R.id.img);
            txtview=view.findViewById(R.id.txt);
        }
    }
}