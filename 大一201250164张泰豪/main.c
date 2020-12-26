#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "map.c"
//#include <conic.h>

int map_number = 1;
//�ñ�����ʾ��ͼ��ţ�
int print_number = 0;
//�ñ�����ʾ��ҳ�Ѿ�����˶������ַ���
int x,y;
//x,y��ʾ�����ڵ����ꣻ
int x_past,y_past;
//x_past,y_past��ʾ��һ�������ڵ����꣨���ڳ�������
int block[20][20];
//����ʱ�����飻
int block_past[20][20];
//block_past��ʾ��һ�������飨���ڳ�������
int width_of_block,length_of_block;
//��ʾ��Ч����ĳ�����
int block_flags[10][2];
//�����յ����ꣻ
int num_blocks_flags = 0;
//�����յ���Ŀ��

void game_print_judge(int temp);

void block_start();

void game_start();

void game_print();

int win_or_lose();

void keybored_control();

void SetSize(int width,int height);

void Backspace();

void game_save();

void Finish();

int main()
{
    //ȫ��44�У�
    game_start();
    
    
    /*
    block_start();
    SetSize(length_of_block*2+1,print_number+1);
    game_print();
    keybored_control();
    system("pause");
    */
}

void Pause()
{
    for (int i=0;i<(print_number+1)/2;i++)
    {
        printf("\n");
    }
    for (int i=0;i<length_of_block - 2;i++)
    {
        printf(" ");
    }
    printf("��  ͣ\n");
    for (int i=0;i<length_of_block - 7;i++)
    {
        printf(" ");
    }
    printf("-��WASD���Լ���-");
    for (int i=0;i<print_number / 2;i++)
    {
        printf("\n");
    }
}

void game_print_judge(int temp)
{
    //��������,����ǽ;������;
    //1Ϊǽ��0Ϊ��ʼ������2Ϊ���ӣ�
    //3Ϊ�յ㣬4Ϊ�ˣ�5Ϊ��������;
    switch(temp)
    {
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
            break;
        case 4:
            printf("��");
            break;
        case 5:
            printf("  ");
            break;
        case 0:
            printf("  ");
            break;
    }
}

void block_start()
{
    num_blocks_flags = 0;
    switch(map_number)
    {
        case 1:
            for(int i = 0; i < width_of_map1 ; i++)
            {
                for(int j = 0; j < length_of_map1 ; j++)
                {
                    block[i][j] = map1[i][j];
                    if(map1[i][j] == 3)
                    {
                        block_flags[num_blocks_flags][0] = i;
                        block_flags[num_blocks_flags][1] = j;
                        num_blocks_flags++;
                    }
                }
            }
            length_of_block = length_of_map1;
            width_of_block = width_of_map1;
            x = 4;
            y = 6;
            print_number = width_of_block;
            break;

        case 2:
            for(int i = 0; i < width_of_map2 ; i++)
            {
                for(int j = 0; j < length_of_map2 ; j++)
                {
                    block[i][j] = map2[i][j];
                    if(map2[i][j] == 3)
                    {
                        block_flags[num_blocks_flags][0] = i;
                        block_flags[num_blocks_flags][1] = j;
                        num_blocks_flags++;
                    }
                }
            }
            length_of_block = length_of_map2;
            width_of_block = width_of_map2;
            x = 4;
            y = 2;
            print_number = width_of_block;
            break;

        case 3:
            for(int i = 0; i < width_of_map3 ; i++)
            {
                for(int j = 0; j < length_of_map3 ; j++)
                {
                    block[i][j] = map3[i][j];
                    if(map3[i][j] == 3)
                    {
                        block_flags[num_blocks_flags][0] = i;
                        block_flags[num_blocks_flags][1] = j;
                        num_blocks_flags++;
                    }
                }
            }
            length_of_block = length_of_map3;
            width_of_block = width_of_map3;
            x = 4;
            y = 4;
            print_number = width_of_block;
            break;

        /*
        case 4:
            for(int i = 0; i < width_of_map4 ; i++)
            {
                for(int j = 0; j < length_of_map4 ; j++)
                {
                    block[i][j] = map4[i][j];
                    if(map4[i][j] == 3)
                    {
                        block_flags[num_blocks_flags][0] = i;
                        block_flags[num_blocks_flags][1] = j;
                        num_blocks_flags++;
                    }
                }
            }
            length_of_block = length_of_map4;
            width_of_block = width_of_map4;
            x = 0;
            y = 0;
            print_number = width_of_block;
            break;
        */
    }
}

void game_start()
{
    SetSize(70,15);
    printf("    ������      ����    ��    ��    ��  ��      ����    ��      ��\n");
    printf("    ��    ��  ��    ��  ��    ��    ��  ��    ��    ��  ����    ��\n");
    printf("    ��    ��  ��    ��    ����      ��  ��    ��    ��  ��  ��  ��\n");
    printf("    ������    ��    ��    ����    ��  ��  ��  ��������  ��  ��  ��\n");
    printf("    ��    ��  ��    ��    ����    ��  ��  ��  ��    ��  ��  ��  ��\n");
    printf("    ��    ��  ��    ��  ��    ��  ��  ��  ��  ��    ��  ��    ����\n");
    printf("    ������      ����    ��    ��  ��  ��  ��  ��    ��  ��      ��\n");
    //��70��
    printf("\n");
    printf("\n");
    printf("                           ��ӭ���棡����\n\n");
    printf("    1.��ʼ��Ϸ\n");
    printf("    2.������Ϸ\n");
    printf("    3.������Ա\n");
    printf("    --�����������ּ��Բ���--");
    char game_start_num = 0;
    //��ȡ���̲�����
    
    while(1)
    {
        game_start_num = getch();
        if(game_start_num == '1' || game_start_num == '2' || game_start_num == '3')
        {
            Sleep(20);
            break;
        }
    }
    switch((int)game_start_num - 48)
    {
        case 1:
            
            printf("\n");
            printf("    ��Ϸ����˵����\n");
            printf("    �ڵ�ͼ�У��㽫�ῴ������ͼ�꣺\n");
            printf("        �� ��ʾǽ�ڣ�����ͨ����\n");
            printf("        �� ��ʾ���ӣ�һ�ο��ƶ�һ�����ӣ�\n");
            printf("        �� ��ʾ�յ㣬�轫�������������յ��Թ��أ�\n"); 
            printf("        �� ��ʾ���Լ����ɱ����ƣ�\n");
            printf("    ȫ��ʹ�ü���W A S D������;\n");
            printf("    ��R����������Ϸ����ECS������ͣ��Ϸ,���˸���Գ���(֧�ֳ���һ��)\n");
            printf("    ��Ҫ�������ڴ�С����Ҫ�������ڴ�С������Ҫ�������ڴ�С������\n");
            printf("    (�ǵ��л����뷨��Ӣ��Ŷ~)\n\n");
            printf("    ������~               ��������Little-Bla-ck\n\n");
            printf("                         --��������Լ���--\n");
            
            while(1)
            {
                if((int)getch())
                {
                    Sleep(20);
                    break;
                }
            }
            
            while(map_number<=3)
            {
                block_start();
                SetSize(length_of_block*2+1,print_number+1);//print_number��Ҫ���ã�
                game_print();
                keybored_control();
                map_number++;
            }
            Finish();
            break;
        case 2:
            block_start();
            FILE *fp;
	        fp = fopen("C:\\Coding\\project\\Boxman\\data.bat","r");
            for(int i=0;i<width_of_block;i++)
            {
                for(int j=0;j<length_of_block;j++)
                {
                    fscanf(fp,"%d ",&block[i][j]);
                }
            }
            fscanf(fp,"%d %d",&x,&y);
            SetSize(length_of_block*2+1,print_number+1);//print_number��Ҫ���ã�
            game_print();
            keybored_control();
            map_number++;
            for(int i=0;i<3-map_number;i++)
            {
                block_start();
                SetSize(length_of_block*2+1,print_number+1);//print_number��Ҫ���ã�
                game_print();
                keybored_control();
                map_number++;
            }
            Finish();
            break;
        case 3:
            printf("\n\n\n\n\n");
            printf("    ������Ա��Little-Bla-ck\n");
            printf("    ��ϵ�ң�\n    QQ:1173198173\n    E-mail:201250164@smail.nju.edu.cn\n");
            printf("    My blog: https://Little-Bla-ck.github.io\n");
            printf("    Thanks for playing!!!\n");
            printf("    --��������Է���--");
            printf("\n\n\n\n");
            if((int)getch())
            {
                game_start();
            }
    }
}

void game_print()
{
    //printf("��%d�أ�\n",map_number);
    //���������ܶ������أ�Ѫ����Ľ�ѵ��
    for(int i=0;i<width_of_block;i++)
    {
        for(int j=0;j<length_of_block;j++)
        {
            game_print_judge(block[i][j]);
        }
        printf("\n");
    }
}

int win_or_lose()
{
    int win = 1;
    for(int i=0;i<num_blocks_flags;i++)
    {
        if(block[block_flags[i][0]][block_flags[i][1]] != 2)
        {
            win = 0;
        }
    }
    return win;
}

void keybored_control()
{
	char key_control;
	while(1) 
	{
        Sleep(20);
        if(win_or_lose() == 1)
        {
            printf("You win!\n");
            break;
        }
		key_control = getch();
		if(key_control == 'w')
        {
            Backspace();
            if(block[x-1][y] != 5 && block[x-1][y] != 3)
            {//ǰ�治�ǿ�������5����
                if(block[x-1][y] == 2 && (block[x-2][y] == 5 || block[x-2][y] == 3))
                {//�ߵķ��������ӣ�
                    for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                    //���߹��Ŀգ�
                    x = x - 1;
                    block[x][y] = 4;
                    //����ǰ�ߣ�
                    block[x-1][y] = 2;
                    //������ǰ�ߣ�
                }
                else
                {

                }
            }
            else
            {//�ߵķ�������ߣ�
                block[x-1][y] = 4;
                //�߹�ȥ��
                for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                x--;
                //���߹��Ŀգ�
            }
            game_save();
            game_print();
        }
//=====================================================//
		if(key_control == 's')
        {
            Backspace();
            if(block[x+1][y] != 5 && block[x+1][y] != 3)
            {
                if(block[x+1][y] == 2 && (block[x+2][y] == 5 || block[x+2][y] == 3))
                {//�ߵķ���������
                    for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                    //���߹��Ŀգ�
                    x = x + 1;
                    block[x][y] = 4;
                    //����ǰ�ߣ�
                    block[x+1][y] = 2;
                    //������ǰ�ߣ�
                }
                else
                {

                }
            }
            else
            {//�ߵķ�������ߣ�
                block[x+1][y] = 4;
                //�߹�ȥ��
                for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                x++;
                //���߹��Ŀգ�
            }
            game_save();
            game_print();
        }
//=====================================================//
		if(key_control == 'a')
		{
            Backspace();
            if(block[x][y-1] != 5 && block[x][y-1] != 3)
            {
                if(block[x][y-1] == 2 && (block[x][y-2] == 5 || block[x][y-2] == 3))
                {//�ߵķ���������
                    for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                    //���߹��Ŀգ�
                    y = y - 1;
                    block[x][y] = 4;
                    //����ǰ�ߣ�
                    block[x][y-1] = 2;
                    //������ǰ�ߣ�
                }
                else
                {

                }
            }
            else
            {//�ߵķ�������ߣ�
                block[x][y-1] = 4;
                //�߹�ȥ��
                for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                y--;
                //���߹��Ŀգ�
            }
            game_save();
            game_print();
        }
//=====================================================//
		if(key_control == 'd')
		{
            Backspace();
            if(block[x][y+1] != 5 && block[x][y+1] != 3)
            {
                if(block[x][y+1] == 2 && (block[x][y+2] == 5 || block[x][y+2] == 3))
                {//�ߵķ���������
                    for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                    //���߹��Ŀգ�
                    y = y + 1;
                    block[x][y] = 4;
                    //����ǰ�ߣ�
                    block[x][y+1] = 2;
                    //������ǰ�ߣ�
                }
                else
                {

                }
            }
            else
            {//�ߵķ�������ߣ�
                block[x][y+1] = 4;
                //�߹�ȥ��
                for(int i=0;i<num_blocks_flags;i++)
                    {
                        if(x == block_flags[i][0] && y == block_flags[i][1])
                        {
                            block[x][y] = 3;
                            break;
                        }
                        else
                        {
                            block[x][y] = 5;
                        }
                    }
                y++;
                //���߹��Ŀգ�
            }
            game_save();
            game_print();
        }
//=====================================================//
		if(key_control == 'r')
        //�ؿ���
        {
            block_start();
            game_save();
            game_print();
        }
//=====================================================//

        if((int)key_control == 27)
        //��ͣ��
        {
            Pause();
            while(1)
            {
                if((int)getch())
                {
                    break;
                }
            }
        }
//=====================================================//
        if((int)key_control == 8)
        {
            for(int i=0;i<width_of_block;i++)
            {
                for(int j=0;j<length_of_block;j++)
                {
                    game_print_judge(block_past[i][j]);
                    block[i][j] = block_past[i][j];
                }
                printf("\n");
            }
            x = x_past;
            y = y_past;
            game_save();
        }
	}
}

void SetSize(int width,int height)
{
    char cmd[64];
    sprintf(cmd,"mode con cols=%d lines=%d",width,height);
    system(cmd);
}

void Backspace()
{
    for(int i = 0; i < width_of_map1 ; i++)
    {
        for(int j = 0; j < length_of_map1 ; j++)
        {
            block_past[i][j] = block[i][j]; 
        }
    }
    x_past = x;
    y_past = y;
}

void game_save()
{
    const char* file = "data.bat";
    remove(file);
    FILE *fp;
	fp = fopen("C:\\Coding\\project\\Boxman\\data.bat","w");
    for(int i=0;i<width_of_block;i++)
    {
        for(int j=0;j<length_of_block;j++)
        {
            fprintf(fp,"%d ",block[i][j]);
        }
    }
    fprintf(fp,"%d %d",x,y);
    fclose(fp);
}

void Finish()
{
    SetSize(70,15);
    printf("\n\n     ��ϲ����������ͨ�أ�����\n\n\n");
    printf("    ������Ա��Little-Bla-ck\n");
    printf("    ��ϵ�ң�\n    QQ:1173198173\n    E-mail:201250164@smail.nju.edu.cn\n");
    printf("    My blog: https://Little-Bla-ck.github.io\n");
    printf("    Thanks for playing!!!\n");
    printf("\n\n\n\n");
    system("pause");
}