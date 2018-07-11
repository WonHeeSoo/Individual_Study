package com.example.whs.tutorial5;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

/**
 * Created by WHS on 2017-02-19.
 */

public class ImageAdapter extends ArrayAdapter<String> {

    ImageAdapter(Context context, String[] items){ // 이미지 어댑터 생성자, items를 받음
        super(context, R.layout.image_layout, items); // 아까만든 이미지 레이아웃을 받는다
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater imageInflater = LayoutInflater.from(getContext()); //레이아웃인플레터를 이용해 레이아웃을 불러준다
        View view = imageInflater.inflate(R.layout.image_layout, parent, false); // 뷰 객체를 생성한다. 이미지 레이아웃을
        String item = getItem(position); // 하나의 객체를 정해준다
        TextView textView = (TextView) view.findViewById(R.id.textView); // 텍스트 뷰는 있는 것을 가져온다
        ImageView imageView = (ImageView) view.findViewById(R.id.imageView); // 이미지 또한 있는 것을 가져온다
        textView.setText(item); // 텍스트 뷰에는 가져온 아이템을 넣어준다
        imageView.setImageResource(R.mipmap.cTi3w); // 아까전에 설정했던 mipmap의 이미지를 넣어준다.
        return view;
    }
}
