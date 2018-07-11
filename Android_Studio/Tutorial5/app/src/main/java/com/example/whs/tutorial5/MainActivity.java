package com.example.whs.tutorial5;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String[] items = {"망고 쥬스", "토마토 쥬스", "포도 쥬스"}; // 배열 생성
        ListAdapter adapter = new ImageAdapter(this, items); // 이미지어뎁터 클래스에 메인 액티비티를 자기자신을 매개변수로 하고 만든 배열도 매개변수로 한다
        ListView listView = (ListView) findViewById(R.id.listView); // id가 listView를 찾아 객체 생성
        listView.setAdapter(adapter); // listView에 어댑터 정보 출력

        listView.setOnItemClickListener(
                new AdapterView.OnItemClickListener() {
                    @Override
                    public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                        String item = String.valueOf(parent.getItemAtPosition(i));// 클릭된 문자열 정보를 저장
                        Toast.makeText(MainActivity.this, item, Toast.LENGTH_SHORT).show(); // 토스트메시지로 출력
                    }
                }
        );
    }
}
