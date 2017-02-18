package com.example.whs.tutorial3;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private String[] items = {"망고 쥬스", "토마토 쥬스", "포도 쥬스"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button listButton = (Button) findViewById(R.id.listButton); // 레이아웃에 존재하는 버튼 이름을 찾아 객체 생성
        listButton.setOnClickListener(new View.OnClickListener(){ // 해당 객체를 클릭할 경우 호출
            @Override
            public void onClick(View v){ // 클릭 함수
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this); //
                builder.setTitle("리스트"); // 팝업창의 제목
                builder.setItems(items, new DialogInterface.OnClickListener(){ // 팝업창의 목록 출력
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i){ // 만약 팝업창 목록을 클릭할 때
                        Toast.makeText(getApplicationContext(),items[i],Toast.LENGTH_LONG).show();
                        // 화면 검은 창 흰 글씨로 하단 중앙에 원하는 메시지를 잠깐 출력
                        // Toast.makeText(?, 출력할 배열, 출력 시간).show()
                    }
                });
                AlertDialog alertDialog = builder.create(); // 알람 다이얼  객체 생성
                alertDialog.show(); // 출력
            }
        });

        Button exitButton = (Button) findViewById(R.id.exitButton);
        exitButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);//메인액티비티에 종속
                builder.setMessage("정말로 종료하시겠습니까?");
                builder.setTitle("종료 알림창")
                        .setCancelable(true) // 팝업창이 뜬 상태에서 setCancelable을 적용 안하거나 True를 하면 팝업창 이외의 부분을 누르면 팝업창이 종료한다
                        .setPositiveButton("Yes", new DialogInterface.OnClickListener(){
                            @Override
                            public void onClick(DialogInterface dialog, int i){
                                finish();
                            }
                        })
                        .setNegativeButton("No", new DialogInterface.OnClickListener(){
                            @Override
                            public void onClick(DialogInterface dialog, int i){
                                dialog.cancel();
                            }
                        });
                AlertDialog alert = builder.create();
                alert.setTitle("종료 알림창");
                alert.show();
            }
        });
    }
}
