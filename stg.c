//シューティングゲーム
//Ver.1.1.1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoXY(int x, int y);
void setColor(int color);
void mscrIni();
void sbarIni();

int main(void)
{
  int matrix_box[61][21] = {0};
  int past_score[4][6] = {0};
  int matrix_counter[61]={0};
  int generic_control_variable_1, generic_control_variable_2;
  int horizontal_axis_p, vertical_axis_p;
  int pop_location_x, shot_location_x;
  int direction_p, direction_m;
  int current_score, high_score;
  int player_speed_controller, enemy_speed_controller, rapid_fire_controller;
  int acceleration_counter, time_counter;
  int bline_y;
  int end_flag;
  int launch_trigger;
  int tmp_x;
  int tmp_key;
  int tmp_lock_1;
  int tmp_lock_2;
  int tmp_score;
  int game_mode;
  int gunshot_mode;
  int airframe_lock;
  int precision_shooting_switch;
  int gun_status;
  double gun_use_rate;
  double use_rate_limit;
  double rapid_fire_use_rate;

  //初期化
  end_flag = 0;
  tmp_x = 0;
  bline_y = 19;
  gunshot_mode = 0;
  game_mode = 1;
  high_score = 0;
  player_speed_controller = 2;
  while (end_flag <= 1)
  {
    //メニュー画面
    mscrIni();
    sbarIni();
    gotoXY(20, 6);
    setColor(0x17);
    printf("シューティング　ゲーム");
    gotoXY(17, 19);
    setColor(0x17);
    printf("Enterキーでゲームを開始します");
    setColor(0x17);
    gotoXY(62, 14);
    printf("---------------------");
    gotoXY(62, 16);
    printf("←/→:難易度変更");
    gotoXY(62, 18);
    printf("Enter:ゲームスタート");
    gotoXY(62, 20);
    printf("ESC:終了");
    gotoXY(25, 17);
    switch (game_mode)
    {
    case 0:
      printf("<　簡　単　>");
      break;
    case 1:
      printf("<　普　通　>");
      break;
    case 2:
      printf("<　難しい　>");
      break;
    }
    gotoXY(62, 0);
    switch (game_mode)
    {
    case 0:
      printf("簡　単のスコア");
      break;
    case 1:
      printf("普　通のスコア");
      break;
    case 2:
      printf("難しいのスコア");
      break;
    }
    gotoXY(62, 2);
    printf("1st:%7dP", past_score[game_mode][5]);
    gotoXY(62, 3);
    printf("2nd:%7dP", past_score[game_mode][4]);
    gotoXY(62, 4);
    printf("3rd:%7dP", past_score[game_mode][3]);
    gotoXY(62, 5);
    printf("4th:%7dP", past_score[game_mode][2]);
    gotoXY(62, 6);
    printf("5th:%7dP", past_score[game_mode][1]);
    gotoXY(82, 20);
    tmp_key = 1;
    tmp_lock_1 = 0;
    tmp_lock_2 = 0;
    if (GetAsyncKeyState(VK_ESCAPE) != 0)
      ;
    if (GetAsyncKeyState(VK_LEFT) != 0)
      ;
    if (GetAsyncKeyState(VK_RIGHT) != 0)
      ;
    if (GetAsyncKeyState(VK_RETURN) != 0)
    {
      tmp_key = 1;
    }
    while (tmp_key != 0)
    {
      tmp_key = 0;
      if (GetAsyncKeyState(VK_RETURN) != 0)
      {
        tmp_key = 1;
      }
    }
    do
    {
      if (tmp_key == 1)
      {
        gotoXY(25, 17);
        tmp_key = 2;
        switch (game_mode)
        {
        case 0:
          printf("<　簡　単　>");
          break;
        case 1:
          printf("<　普　通　>");
          break;
        case 2:
          printf("<　難しい　>");
          break;
        }
        gotoXY(62, 0);
        switch (game_mode)
        {
        case 0:
          printf("簡　単のスコア");
          break;
        case 1:
          printf("普　通のスコア");
          break;
        case 2:
          printf("難しいのスコア");
          break;
        }
        gotoXY(62, 2);
        printf("1st:%7dP", past_score[game_mode][5]);
        gotoXY(62, 3);
        printf("2nd:%7dP", past_score[game_mode][4]);
        gotoXY(62, 4);
        printf("3rd:%7dP", past_score[game_mode][3]);
        gotoXY(62, 5);
        printf("4th:%7dP", past_score[game_mode][2]);
        gotoXY(62, 6);
        printf("5th:%7dP", past_score[game_mode][1]);
      }
      gotoXY(82, 20);

      tmp_key = 0;
      if (GetAsyncKeyState(VK_ESCAPE) != 0)
      {
        end_flag = 2;
        break;
      }
      if (GetAsyncKeyState(VK_RIGHT) != 0)
      {
        if (tmp_lock_1 == 0)
        {
          game_mode++;
          tmp_key = 1;
          if (game_mode > 2)
          {
            game_mode = 0;
          }
          tmp_lock_1 = 1;
        }
      }
      else
      {
        tmp_lock_1 = 0;
      }
      if (GetAsyncKeyState(VK_LEFT) != 0)
      {
        if (tmp_lock_2 == 0)
        {
          game_mode--;
          tmp_key = 1;
          if (game_mode < 0)
          {
            game_mode = 2;
          }
          tmp_lock_2 = 1;
        }
      }
      else
      {
        tmp_lock_2 = 0;
      }
    } while (GetAsyncKeyState(VK_RETURN) == 0);
    if (end_flag == 2)
    {
      break;
    }
    //カウントダウン
    mscrIni();
    sbarIni();
    setColor(0x17);
    gotoXY(28, 10);
    printf("Ready?");
    Sleep(500);
    mscrIni();
    setColor(0x17);
    gotoXY(29, 10);
    printf("Go!");
    Sleep(1000);
    //ゲーム初期化
    mscrIni();
    sbarIni();
    if (GetAsyncKeyState(VK_ESCAPE) != 0)
      ;
    high_score = past_score[game_mode][5];
    tmp_lock_1 = 0;
    gotoXY(62, 0);
    setColor(0x17);
    printf("ゲームモード:");
    if (game_mode == 0)
    {
      printf("簡　単");
    }
    if (game_mode == 1)
    {
      printf("普　通");
    }
    if (game_mode == 2)
    {
      printf("難しい");
    }
    if (game_mode == 0)
    {
      use_rate_limit = 1000;
      enemy_speed_controller = 50;
    }
    if (game_mode == 1)
    {
      use_rate_limit = 500;
      enemy_speed_controller = 30;
    }
    if (game_mode == 2)
    {
      use_rate_limit = 250;
      enemy_speed_controller = 20;
    }
    end_flag = 0;
    time_counter = 0;
    horizontal_axis_p = 30;
    vertical_axis_p = 20;
    rapid_fire_controller = 0;
    rapid_fire_use_rate = 0;
    airframe_lock = 0;
    current_score = 0;
    direction_m = 0;
    precision_shooting_switch = 0;
    //盤面初期化
    for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
         generic_control_variable_1++)
    {
      for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
           generic_control_variable_2++)
      {
        gotoXY(generic_control_variable_1, generic_control_variable_2);
        setColor(0x11);
        printf("@");
      }
    }
    for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
         generic_control_variable_1++)
    {
      for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
           generic_control_variable_2++)
      {
        matrix_box[generic_control_variable_1][generic_control_variable_2] = 0;
      }
    }
    //ボーダーライン初期化
    gotoXY(0, bline_y);
    for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
         generic_control_variable_1++)
    {
      setColor(0x17);
      printf("=");
      matrix_box[generic_control_variable_1][bline_y] =
          5; //ボーダーライン当たり判定は5
    }
    gotoXY(62, 12);
    setColor(0x17);
    printf("---------------------");
    gotoXY(62, 14);
    printf("ESC:リザルト");
    gotoXY(62, 16);
    printf("←/→:移動 SPACE:射撃");
    gotoXY(62, 18);
    printf("移動+TAB:1マス移動");
    gotoXY(62, 20);
    printf("CTRL:射撃モード切替");
    if (GetAsyncKeyState(VK_CONTROL) != 0)
      ;
    if (GetAsyncKeyState(VK_TAB) != 0)
      ;
    if (GetAsyncKeyState(VK_SPACE) != 0)
      ;
    while (end_flag == 0)
    {
      if (current_score >= high_score)
      {
        high_score = current_score;
      }
      if (rapid_fire_use_rate >= use_rate_limit - 1)
      {
        airframe_lock = 100;
        rapid_fire_controller == use_rate_limit;
      }
      if (airframe_lock > 0)
      {
        airframe_lock--;
      }
      if (time_counter % player_speed_controller == 0)
      {
        //プレイヤー操作
        direction_p = 0;
        precision_shooting_switch = 0;
        if (GetAsyncKeyState(VK_LEFT) != 0)
          direction_p = 1; //左方向(←キー)
        if (GetAsyncKeyState(VK_TAB) != 0)
        {
          precision_shooting_switch = 1;
        }
        if (GetAsyncKeyState(VK_RIGHT) != 0)
          direction_p = 2; //右方向（→キー）
        if (GetAsyncKeyState(VK_TAB) != 0)
        {
          precision_shooting_switch = 1;
        }
        if (airframe_lock == 0) //弾発射制限
        {
          if (GetAsyncKeyState(VK_SPACE) != 0)
            launch_trigger = 1; //弾発射（スペースキー）
        }
        if (GetAsyncKeyState(VK_ESCAPE) != 0)
          end_flag = 1;
        if (GetAsyncKeyState(VK_CONTROL) != 0)
        {
          if (tmp_lock_1 == 0)
          {
            rapid_fire_controller = 0;
            tmp_lock_1 = 1;
            gunshot_mode++;
            if (gunshot_mode > 2)
            {
              gunshot_mode = 0;
            }
          }
        }
        else
        {
          tmp_lock_1 = 0;
        }
        tmp_x = horizontal_axis_p;
        if (direction_p != direction_m)
        {
          switch (direction_p)
          {
          case 0:
            direction_m = 0;
            break;
          case 1:
            horizontal_axis_p--;                //左方向移動
            if (precision_shooting_switch == 1) //精密射撃モード
            {
              direction_m = 1;
            }
            break;
          case 2:
            horizontal_axis_p++;                //右方向移動
            if (precision_shooting_switch == 1) //精密射撃モード
            {
              direction_m = 2;
            }
            break;
          }
          //反転処理
          if (horizontal_axis_p > 60)
          {
            horizontal_axis_p = 0; //左に反転処理
          }
          if (horizontal_axis_p < 0)
          {
            horizontal_axis_p = 60; //右に反転処理
          }
          if (direction_p != 0)
          {
            // 前居た場所を消す
            if (tmp_x != 61)
            {
              gotoXY(tmp_x, vertical_axis_p);
              setColor(0x11);
              printf("#");
            }
          }
        }
        //プレイヤー表示
        gotoXY(horizontal_axis_p, 20);
        setColor(0x17);
        printf("A");
        //弾発射位置指定
        switch (gunshot_mode)
        //モード変更時はrapid_fire_controller(==0)初期化必須
        {
        case 0:
          //フルオート
          if (launch_trigger == 1)
          {
            shot_location_x = horizontal_axis_p;
            matrix_box[shot_location_x][bline_y - 1] = 3; //移動後弾マス;
            gotoXY(shot_location_x, bline_y - 1);
            setColor(0x17);
            printf("*");
            launch_trigger = 0;
            current_score = current_score + 1;
            rapid_fire_use_rate = rapid_fire_use_rate + 5;
          }
          break;
        case 2:
          //単発
          if (rapid_fire_controller == 1)
          {
            if (launch_trigger == 0)
            {
              rapid_fire_controller = 0;
            }
            launch_trigger = 0;
          }
          if (launch_trigger == 1)
          {
            shot_location_x = horizontal_axis_p;
            matrix_box[shot_location_x][bline_y - 1] = 3; //移動後弾マス;
            gotoXY(shot_location_x, bline_y - 1);
            setColor(0x17);
            printf("*");
            launch_trigger = 0;
            rapid_fire_controller = 1;
            current_score = current_score + 5;
            rapid_fire_use_rate = rapid_fire_use_rate + 5;
          }
          break;
        case 1:
          // 3点バースト
          if (rapid_fire_controller == 3)
          {
            if (launch_trigger == 0)
            {
              rapid_fire_controller = 0;
            }
            launch_trigger = 0;
          }
          if (launch_trigger == 1 ||
              rapid_fire_controller > 0 && rapid_fire_controller < 3)
          {
            shot_location_x = horizontal_axis_p;
            matrix_box[shot_location_x][bline_y - 1] = 3; //移動後弾マス;
            gotoXY(shot_location_x, bline_y - 1);
            setColor(0x17);
            printf("*");
            launch_trigger = 0;
            rapid_fire_controller++;
            current_score = current_score + 3;
            rapid_fire_use_rate = rapid_fire_use_rate + 5;
          }
          break;
        }
        if (rapid_fire_use_rate > use_rate_limit)
        {
          rapid_fire_use_rate = use_rate_limit;
        }
        if (rapid_fire_use_rate != 0)
        {
          gun_use_rate = (rapid_fire_use_rate / use_rate_limit) * 100;
        }
        else
        {
          gun_use_rate = 0;
        }
        if (gun_use_rate >= 80)
        {
          gun_status = 1;
        }
        else
        {
          gun_status = 0;
        }
        if (airframe_lock > 0)
        {
          gun_status = 2;
        }
      }
      //弾移動処理(1)
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
             generic_control_variable_2++)
        {
          if (matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] ==
              3) //既存の弾マスを移動させる
          {
            matrix_box[generic_control_variable_1][generic_control_variable_2] =
                0;
            matrix_box[generic_control_variable_1]
                      [generic_control_variable_2 - 1] = 4; //移動前弾マスは4
          }
        }
      }
      //弾移動処理(2)
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0;
             generic_control_variable_2 < bline_y + 1;
             generic_control_variable_2++)
        {
          if (matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] == 4)
          {
            matrix_box[generic_control_variable_1][generic_control_variable_2] =
                3; //移動後敵マスは1
            gotoXY(generic_control_variable_1,
                   generic_control_variable_2 + 1); //移動前弾マス削除
            setColor(0x11);
            printf("*");
            gotoXY(generic_control_variable_1,
                   generic_control_variable_2); //移動後弾マス書き込み
            setColor(0x17);
            printf("*");
          }
        }
      }
      //弾当たり判定処理
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
             generic_control_variable_2++)
        {
          if (matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] == 1 &
              matrix_box[generic_control_variable_1]
                        [generic_control_variable_2 + 1] == 3)
          {
            matrix_box[generic_control_variable_1][generic_control_variable_2] =
                0;
            matrix_box[generic_control_variable_1]
                      [generic_control_variable_2 + 1] = 0;
            setColor(0x11);
            gotoXY(generic_control_variable_1, generic_control_variable_2);
            printf("@");
            gotoXY(generic_control_variable_1, generic_control_variable_2 + 1);
            printf("*");
            current_score = current_score + 100;
          }
        }
      }
      //弾消滅
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        if(matrix_counter[generic_control_variable_1]==1){
          matrix_counter[generic_control_variable_1]=0;
          matrix_box[generic_control_variable_1][0] = 0;
          gotoXY(generic_control_variable_1, 0); //移動前弾マス削除
          setColor(0x11);
          printf("*");
        }
        if (matrix_box[generic_control_variable_1][0] == 3)
        {
          matrix_counter[generic_control_variable_1]=1;
        }
      }
      //敵移動処理(1)
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
             generic_control_variable_2++)
        {
          if (time_counter % enemy_speed_controller == 0)
          {
            if (matrix_box[generic_control_variable_1]
                          [generic_control_variable_2] == 1 &
                matrix_box[generic_control_variable_1]
                          [generic_control_variable_2 + 1] == 5)
            {
              end_flag = 1; //ボーダーラインの上に敵が来たら負けフラグを立てる
            }
            if (matrix_box[generic_control_variable_1]
                          [generic_control_variable_2] ==
                1) //既存の敵マスを移動させる
            {
              matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] = 0;
              matrix_box[generic_control_variable_1]
                        [generic_control_variable_2 + 1] = 2; //移動前敵マスは2
            }
          }
        }
      }
      //敵移動処理(2)
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0;
             generic_control_variable_2 < bline_y + 1;
             generic_control_variable_2++)
        {
          for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
               generic_control_variable_1++)
          {
            for (generic_control_variable_2 = 0;
                 generic_control_variable_2 < bline_y + 1;
                 generic_control_variable_2++)
            {
              if (time_counter % enemy_speed_controller == 0)
              {
                if (matrix_box[generic_control_variable_1]
                              [generic_control_variable_2] == 2)
                {
                  matrix_box[generic_control_variable_1]
                            [generic_control_variable_2] = 1; //移動後敵マスは1
                  gotoXY(generic_control_variable_1,
                         generic_control_variable_2 - 1); //移動前敵マス削除
                  setColor(0x11);
                  printf("@");
                  gotoXY(generic_control_variable_1,
                         generic_control_variable_2); //移動後敵マス書き込み
                  setColor(0x17);
                  printf("@");
                }
              }
            }
          }
        }
      }
      if (time_counter % enemy_speed_controller == 0)
      {
        //敵表示
        pop_location_x = rand() % 61;
        matrix_box[pop_location_x][0] = 1;
        gotoXY(pop_location_x, 0);
        setColor(0x17);
        printf("@");
      }
      //スコア限界処理
      if (current_score > 9999999)
      {
        current_score = 9999999;
      }
      if (high_score > 9999999)
      {
        high_score = 9999999;
      }
      //情報表示
      gotoXY(62, 2);
      setColor(0x17);
      printf("ハイスコア:");
      printf("%7dP", high_score);
      gotoXY(62, 4);
      printf("スコア:    ");
      printf("%7dP", current_score);
      gotoXY(62, 6);
      printf("使用率: ");
      printf("%7.0f%%", gun_use_rate);
      gotoXY(62, 8);
      printf("状態:");
      if (gun_status == 0)
      {
        setColor(0x17);
        printf("使用可　");
      }
      if (gun_status == 1)
      {
        setColor(0x17);
        printf("危険　　");
      }
      if (gun_status == 2)
      {
        setColor(0x17);
        printf("使用不可");
      }
      gotoXY(62, 10);
      setColor(0x17);
      printf("射撃モード:");
      if (gunshot_mode == 0)
      {
        printf("連射　");
      }
      if (gunshot_mode == 2)
      {
        printf("単発　");
      }
      if (gunshot_mode == 1)
      {
        printf("3点バ");
      }
      gotoXY(82, 20);
      //進行後処理
      Sleep(20);
      if (rapid_fire_use_rate > 0)
      {
        rapid_fire_use_rate--;
      }
      if (rapid_fire_use_rate > 0)
      {
        if (direction_p == 0)
        {
          rapid_fire_use_rate--;
        }
      }
      current_score = current_score + 2;
      time_counter++;
      if (time_counter > 100)
      {
        time_counter = 0;
      }
    }
    //順位入れ替え処理
    past_score[game_mode][0] = current_score;
    for (generic_control_variable_1 = 0; generic_control_variable_1 < 5;
         generic_control_variable_1++)
    {
      if (past_score[game_mode][generic_control_variable_1] >=
          past_score[game_mode][generic_control_variable_1 + 1])
      {
        tmp_score = past_score[game_mode][generic_control_variable_1 + 1];
        past_score[game_mode][generic_control_variable_1 + 1] =
            past_score[game_mode][generic_control_variable_1];
        past_score[game_mode][generic_control_variable_1] = tmp_score;
      }
    }
    past_score[game_mode][0] = 0;
    //リザルト画面
    mscrIni();
    sbarIni();
    setColor(0x17);
    gotoXY(62, 0);
    switch (game_mode)
    {
    case 0:
      printf("簡　単のスコア");
      break;
    case 1:
      printf("普　通のスコア");
      break;
    case 2:
      printf("難しいのスコア");
      break;
    }
    gotoXY(62, 2);
    printf("1st:%7dP", past_score[game_mode][5]);
    gotoXY(62, 3);
    printf("2nd:%7dP", past_score[game_mode][4]);
    gotoXY(62, 4);
    printf("3rd:%7dP", past_score[game_mode][3]);
    gotoXY(62, 5);
    printf("4th:%7dP", past_score[game_mode][2]);
    gotoXY(62, 6);
    printf("5th:%7dP", past_score[game_mode][1]);
    gotoXY(25, 8);
    printf("結果:%7dP", current_score);
    if (past_score[game_mode][5] == current_score)
    {
      gotoXY(24, 16);
      printf("ハイスコアです!");
    }
    gotoXY(62, 12);
    printf("---------------------");
    gotoXY(62, 14);
    printf("Enter:メニュー");
    gotoXY(62, 16);
    printf("ESC:終了");
    gotoXY(82, 20);
    if (GetAsyncKeyState(VK_RETURN) != 0)
      ;
    if (GetAsyncKeyState(VK_ESCAPE) != 0)
    {
      tmp_key = 1;
    }
    while (tmp_key != 0)
    {
      tmp_key = 0;
      if (GetAsyncKeyState(VK_ESCAPE) != 0)
      {
        tmp_key = 1;
      }
    }
    do
    {
      tmp_key = 0;
      if (GetAsyncKeyState(VK_RETURN) != 0)
      {
        tmp_key = 1;
        end_flag = 0;
      }
      if (GetAsyncKeyState(VK_ESCAPE) != 0)
      {
        tmp_key = 1;
        end_flag = 2;
      }
    } while (tmp_key == 0);
  }
  return 0;
}
//カーソル移動
void gotoXY(int x, int y)
{
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  return;
}
//文字色設定
void setColor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  return;
}
//メインスクリーン初期化
void mscrIni()
{
  int generic_control_variable_1;
  int generic_control_variable_2;
  for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
       generic_control_variable_1++)
  {
    for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
         generic_control_variable_2++)
    {
      gotoXY(generic_control_variable_1, generic_control_variable_2);
      setColor(0x11);
      printf("@");
    }
  }
}
//サイドバー初期化
void sbarIni()
{
  int generic_control_variable_1;
  int generic_control_variable_2;
  for (generic_control_variable_1 = 62; generic_control_variable_1 < 83;
       generic_control_variable_1++)
  {
    for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
         generic_control_variable_2++)
    {
      gotoXY(generic_control_variable_1, generic_control_variable_2);
      setColor(0x11);
      printf("@");
    }
  }
}