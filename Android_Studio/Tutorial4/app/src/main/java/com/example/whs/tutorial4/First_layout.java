package com.example.whs.tutorial4;

import android.app.Fragment;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * Created by WHS on 2017-02-19.
 */

public class First_layout extends Fragment{
    View v; // 뷰 객체 생성
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        v = inflater.inflate(R.layout.first_layout, container, false);
        return v;
    }
}
