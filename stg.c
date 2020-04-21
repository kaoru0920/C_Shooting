//�V���[�e�B���O�Q�[��
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

  //������
  end_flag = 0;
  tmp_x = 0;
  bline_y = 19;
  gunshot_mode = 0;
  game_mode = 1;
  high_score = 0;
  player_speed_controller = 2;
  while (end_flag <= 1)
  {
    //���j���[���
    mscrIni();
    sbarIni();
    gotoXY(20, 6);
    setColor(0x17);
    printf("�V���[�e�B���O�@�Q�[��");
    gotoXY(17, 19);
    setColor(0x17);
    printf("Enter�L�[�ŃQ�[�����J�n���܂�");
    setColor(0x17);
    gotoXY(62, 14);
    printf("---------------------");
    gotoXY(62, 16);
    printf("��/��:��Փx�ύX");
    gotoXY(62, 18);
    printf("Enter:�Q�[���X�^�[�g");
    gotoXY(62, 20);
    printf("ESC:�I��");
    gotoXY(25, 17);
    switch (game_mode)
    {
    case 0:
      printf("<�@�ȁ@�P�@>");
      break;
    case 1:
      printf("<�@���@�ʁ@>");
      break;
    case 2:
      printf("<�@����@>");
      break;
    }
    gotoXY(62, 0);
    switch (game_mode)
    {
    case 0:
      printf("�ȁ@�P�̃X�R�A");
      break;
    case 1:
      printf("���@�ʂ̃X�R�A");
      break;
    case 2:
      printf("����̃X�R�A");
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
          printf("<�@�ȁ@�P�@>");
          break;
        case 1:
          printf("<�@���@�ʁ@>");
          break;
        case 2:
          printf("<�@����@>");
          break;
        }
        gotoXY(62, 0);
        switch (game_mode)
        {
        case 0:
          printf("�ȁ@�P�̃X�R�A");
          break;
        case 1:
          printf("���@�ʂ̃X�R�A");
          break;
        case 2:
          printf("����̃X�R�A");
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
    //�J�E���g�_�E��
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
    //�Q�[��������
    mscrIni();
    sbarIni();
    if (GetAsyncKeyState(VK_ESCAPE) != 0)
      ;
    high_score = past_score[game_mode][5];
    tmp_lock_1 = 0;
    gotoXY(62, 0);
    setColor(0x17);
    printf("�Q�[�����[�h:");
    if (game_mode == 0)
    {
      printf("�ȁ@�P");
    }
    if (game_mode == 1)
    {
      printf("���@��");
    }
    if (game_mode == 2)
    {
      printf("���");
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
    //�Ֆʏ�����
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
    //�{�[�_�[���C��������
    gotoXY(0, bline_y);
    for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
         generic_control_variable_1++)
    {
      setColor(0x17);
      printf("=");
      matrix_box[generic_control_variable_1][bline_y] =
          5; //�{�[�_�[���C�������蔻���5
    }
    gotoXY(62, 12);
    setColor(0x17);
    printf("---------------------");
    gotoXY(62, 14);
    printf("ESC:���U���g");
    gotoXY(62, 16);
    printf("��/��:�ړ� SPACE:�ˌ�");
    gotoXY(62, 18);
    printf("�ړ�+TAB:1�}�X�ړ�");
    gotoXY(62, 20);
    printf("CTRL:�ˌ����[�h�ؑ�");
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
        //�v���C���[����
        direction_p = 0;
        precision_shooting_switch = 0;
        if (GetAsyncKeyState(VK_LEFT) != 0)
          direction_p = 1; //������(���L�[)
        if (GetAsyncKeyState(VK_TAB) != 0)
        {
          precision_shooting_switch = 1;
        }
        if (GetAsyncKeyState(VK_RIGHT) != 0)
          direction_p = 2; //�E�����i���L�[�j
        if (GetAsyncKeyState(VK_TAB) != 0)
        {
          precision_shooting_switch = 1;
        }
        if (airframe_lock == 0) //�e���ː���
        {
          if (GetAsyncKeyState(VK_SPACE) != 0)
            launch_trigger = 1; //�e���ˁi�X�y�[�X�L�[�j
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
            horizontal_axis_p--;                //�������ړ�
            if (precision_shooting_switch == 1) //�����ˌ����[�h
            {
              direction_m = 1;
            }
            break;
          case 2:
            horizontal_axis_p++;                //�E�����ړ�
            if (precision_shooting_switch == 1) //�����ˌ����[�h
            {
              direction_m = 2;
            }
            break;
          }
          //���]����
          if (horizontal_axis_p > 60)
          {
            horizontal_axis_p = 0; //���ɔ��]����
          }
          if (horizontal_axis_p < 0)
          {
            horizontal_axis_p = 60; //�E�ɔ��]����
          }
          if (direction_p != 0)
          {
            // �O�����ꏊ������
            if (tmp_x != 61)
            {
              gotoXY(tmp_x, vertical_axis_p);
              setColor(0x11);
              printf("#");
            }
          }
        }
        //�v���C���[�\��
        gotoXY(horizontal_axis_p, 20);
        setColor(0x17);
        printf("A");
        //�e���ˈʒu�w��
        switch (gunshot_mode)
        //���[�h�ύX����rapid_fire_controller(==0)�������K�{
        {
        case 0:
          //�t���I�[�g
          if (launch_trigger == 1)
          {
            shot_location_x = horizontal_axis_p;
            matrix_box[shot_location_x][bline_y - 1] = 3; //�ړ���e�}�X;
            gotoXY(shot_location_x, bline_y - 1);
            setColor(0x17);
            printf("*");
            launch_trigger = 0;
            current_score = current_score + 1;
            rapid_fire_use_rate = rapid_fire_use_rate + 5;
          }
          break;
        case 2:
          //�P��
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
            matrix_box[shot_location_x][bline_y - 1] = 3; //�ړ���e�}�X;
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
          // 3�_�o�[�X�g
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
            matrix_box[shot_location_x][bline_y - 1] = 3; //�ړ���e�}�X;
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
      //�e�ړ�����(1)
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        for (generic_control_variable_2 = 0; generic_control_variable_2 < 21;
             generic_control_variable_2++)
        {
          if (matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] ==
              3) //�����̒e�}�X���ړ�������
          {
            matrix_box[generic_control_variable_1][generic_control_variable_2] =
                0;
            matrix_box[generic_control_variable_1]
                      [generic_control_variable_2 - 1] = 4; //�ړ��O�e�}�X��4
          }
        }
      }
      //�e�ړ�����(2)
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
                3; //�ړ���G�}�X��1
            gotoXY(generic_control_variable_1,
                   generic_control_variable_2 + 1); //�ړ��O�e�}�X�폜
            setColor(0x11);
            printf("*");
            gotoXY(generic_control_variable_1,
                   generic_control_variable_2); //�ړ���e�}�X��������
            setColor(0x17);
            printf("*");
          }
        }
      }
      //�e�����蔻�菈��
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
      //�e����
      for (generic_control_variable_1 = 0; generic_control_variable_1 < 61;
           generic_control_variable_1++)
      {
        if(matrix_counter[generic_control_variable_1]==1){
          matrix_counter[generic_control_variable_1]=0;
          matrix_box[generic_control_variable_1][0] = 0;
          gotoXY(generic_control_variable_1, 0); //�ړ��O�e�}�X�폜
          setColor(0x11);
          printf("*");
        }
        if (matrix_box[generic_control_variable_1][0] == 3)
        {
          matrix_counter[generic_control_variable_1]=1;
        }
      }
      //�G�ړ�����(1)
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
              end_flag = 1; //�{�[�_�[���C���̏�ɓG�������畉���t���O�𗧂Ă�
            }
            if (matrix_box[generic_control_variable_1]
                          [generic_control_variable_2] ==
                1) //�����̓G�}�X���ړ�������
            {
              matrix_box[generic_control_variable_1]
                        [generic_control_variable_2] = 0;
              matrix_box[generic_control_variable_1]
                        [generic_control_variable_2 + 1] = 2; //�ړ��O�G�}�X��2
            }
          }
        }
      }
      //�G�ړ�����(2)
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
                            [generic_control_variable_2] = 1; //�ړ���G�}�X��1
                  gotoXY(generic_control_variable_1,
                         generic_control_variable_2 - 1); //�ړ��O�G�}�X�폜
                  setColor(0x11);
                  printf("@");
                  gotoXY(generic_control_variable_1,
                         generic_control_variable_2); //�ړ���G�}�X��������
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
        //�G�\��
        pop_location_x = rand() % 61;
        matrix_box[pop_location_x][0] = 1;
        gotoXY(pop_location_x, 0);
        setColor(0x17);
        printf("@");
      }
      //�X�R�A���E����
      if (current_score > 9999999)
      {
        current_score = 9999999;
      }
      if (high_score > 9999999)
      {
        high_score = 9999999;
      }
      //���\��
      gotoXY(62, 2);
      setColor(0x17);
      printf("�n�C�X�R�A:");
      printf("%7dP", high_score);
      gotoXY(62, 4);
      printf("�X�R�A:    ");
      printf("%7dP", current_score);
      gotoXY(62, 6);
      printf("�g�p��: ");
      printf("%7.0f%%", gun_use_rate);
      gotoXY(62, 8);
      printf("���:");
      if (gun_status == 0)
      {
        setColor(0x17);
        printf("�g�p�@");
      }
      if (gun_status == 1)
      {
        setColor(0x17);
        printf("�댯�@�@");
      }
      if (gun_status == 2)
      {
        setColor(0x17);
        printf("�g�p�s��");
      }
      gotoXY(62, 10);
      setColor(0x17);
      printf("�ˌ����[�h:");
      if (gunshot_mode == 0)
      {
        printf("�A�ˁ@");
      }
      if (gunshot_mode == 2)
      {
        printf("�P���@");
      }
      if (gunshot_mode == 1)
      {
        printf("3�_�o");
      }
      gotoXY(82, 20);
      //�i�s�㏈��
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
    //���ʓ���ւ�����
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
    //���U���g���
    mscrIni();
    sbarIni();
    setColor(0x17);
    gotoXY(62, 0);
    switch (game_mode)
    {
    case 0:
      printf("�ȁ@�P�̃X�R�A");
      break;
    case 1:
      printf("���@�ʂ̃X�R�A");
      break;
    case 2:
      printf("����̃X�R�A");
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
    printf("����:%7dP", current_score);
    if (past_score[game_mode][5] == current_score)
    {
      gotoXY(24, 16);
      printf("�n�C�X�R�A�ł�!");
    }
    gotoXY(62, 12);
    printf("---------------------");
    gotoXY(62, 14);
    printf("Enter:���j���[");
    gotoXY(62, 16);
    printf("ESC:�I��");
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
//�J�[�\���ړ�
void gotoXY(int x, int y)
{
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  return;
}
//�����F�ݒ�
void setColor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  return;
}
//���C���X�N���[��������
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
//�T�C�h�o�[������
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