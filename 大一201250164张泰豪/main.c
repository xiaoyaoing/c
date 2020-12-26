#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "map.c"
//#include <conic.h>

int map_number = 1;
//该变量表示地图序号；
int print_number = 0;
//该变量表示该页已经输出了多少行字符；
int x,y;
//x,y表示人所在的坐标；
int x_past,y_past;
//x_past,y_past表示上一步人所在的坐标（用于撤销）；
int block[20][20];
//运行时的区块；
int block_past[20][20];
//block_past表示上一步的区块（用于撤销）；
int width_of_block,length_of_block;
//表示有效区块的长、宽；
int block_flags[10][2];
//储存终点坐标；
int num_blocks_flags = 0;
//储存终点数目；

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
    //全屏44行；
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
    printf("暂  停\n");
    for (int i=0;i<length_of_block - 7;i++)
    {
        printf(" ");
    }
    printf("-按WASD键以继续-");
    for (int i=0;i<print_number / 2;i++)
    {
        printf("\n");
    }
}

void game_print_judge(int temp)
{
    //□是箱子,■是墙;●是人;
    //1为墙，0为初始化区域，2为箱子，
    //3为终点，4为人，5为可走区域;
    switch(temp)
    {
        case 1:
            printf("■");
            break;
        case 2:
            printf("□");
            break;
        case 3:
            printf("☆");
            break;
        case 4:
            printf("●");
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
    printf("    ■■■      ■■    ■    ■    ■  ■      ■■    ■      ■\n");
    printf("    ■    ■  ■    ■  ■    ■    ■  ■    ■    ■  ■■    ■\n");
    printf("    ■    ■  ■    ■    ■■      ■  ■    ■    ■  ■  ■  ■\n");
    printf("    ■■■    ■    ■    ■■    ■  ■  ■  ■■■■  ■  ■  ■\n");
    printf("    ■    ■  ■    ■    ■■    ■  ■  ■  ■    ■  ■  ■  ■\n");
    printf("    ■    ■  ■    ■  ■    ■  ■  ■  ■  ■    ■  ■    ■■\n");
    printf("    ■■■      ■■    ■    ■  ■  ■  ■  ■    ■  ■      ■\n");
    //宽70格；
    printf("\n");
    printf("\n");
    printf("                           欢迎游玩！！！\n\n");
    printf("    1.开始游戏\n");
    printf("    2.继续游戏\n");
    printf("    3.制作人员\n");
    printf("    --按动键盘数字键以操作--");
    char game_start_num = 0;
    //读取键盘操作；
    
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
            printf("    游戏规则说明：\n");
            printf("    在地图中，你将会看到四种图标：\n");
            printf("        ■ 表示墙壁，不可通过；\n");
            printf("        □ 表示箱子，一次可推动一个箱子；\n");
            printf("        ☆ 表示终点，需将所有箱子推至终点以过关；\n"); 
            printf("        ● 表示你自己，可被控制；\n");
            printf("    全程使用键盘W A S D键控制;\n");
            printf("    按R键以重置游戏，按ECS键以暂停游戏,按退格键以撤销(支持撤销一次)\n");
            printf("    不要调整窗口大小！不要调整窗口大小！！不要调整窗口大小！！！\n");
            printf("    (记得切换输入法中英文哦~)\n\n");
            printf("    玩得愉快~               ————Little-Bla-ck\n\n");
            printf("                         --按任意键以继续--\n");
            
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
                SetSize(length_of_block*2+1,print_number+1);//print_number需要重置；
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
            SetSize(length_of_block*2+1,print_number+1);//print_number需要重置；
            game_print();
            keybored_control();
            map_number++;
            for(int i=0;i<3-map_number;i++)
            {
                block_start();
                SetSize(length_of_block*2+1,print_number+1);//print_number需要重置；
                game_print();
                keybored_control();
                map_number++;
            }
            Finish();
            break;
        case 3:
            printf("\n\n\n\n\n");
            printf("    制作人员：Little-Bla-ck\n");
            printf("    联系我：\n    QQ:1173198173\n    E-mail:201250164@smail.nju.edu.cn\n");
            printf("    My blog: https://Little-Bla-ck.github.io\n");
            printf("    Thanks for playing!!!\n");
            printf("    --按任意键以返回--");
            printf("\n\n\n\n");
            if((int)getch())
            {
                game_start();
            }
    }
}

void game_print()
{
    //printf("第%d关：\n",map_number);
    //加了这个会很抖呜呜呜，血和泪的教训；
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
            {//前面不是可走区域（5）；
                if(block[x-1][y] == 2 && (block[x-2][y] == 5 || block[x-2][y] == 3))
                {//走的方向有箱子；
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
                    //填走过的空；
                    x = x - 1;
                    block[x][y] = 4;
                    //人往前走；
                    block[x-1][y] = 2;
                    //箱子往前走；
                }
                else
                {

                }
            }
            else
            {//走的方向可以走；
                block[x-1][y] = 4;
                //走过去；
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
                //填走过的空；
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
                {//走的方向有箱子
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
                    //填走过的空；
                    x = x + 1;
                    block[x][y] = 4;
                    //人往前走；
                    block[x+1][y] = 2;
                    //箱子往前走；
                }
                else
                {

                }
            }
            else
            {//走的方向可以走；
                block[x+1][y] = 4;
                //走过去；
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
                //填走过的空；
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
                {//走的方向有箱子
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
                    //填走过的空；
                    y = y - 1;
                    block[x][y] = 4;
                    //人往前走；
                    block[x][y-1] = 2;
                    //箱子往前走；
                }
                else
                {

                }
            }
            else
            {//走的方向可以走；
                block[x][y-1] = 4;
                //走过去；
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
                //填走过的空；
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
                {//走的方向有箱子
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
                    //填走过的空；
                    y = y + 1;
                    block[x][y] = 4;
                    //人往前走；
                    block[x][y+1] = 2;
                    //箱子往前走；
                }
                else
                {

                }
            }
            else
            {//走的方向可以走；
                block[x][y+1] = 4;
                //走过去；
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
                //填走过的空；
            }
            game_save();
            game_print();
        }
//=====================================================//
		if(key_control == 'r')
        //重开；
        {
            block_start();
            game_save();
            game_print();
        }
//=====================================================//

        if((int)key_control == 27)
        //暂停；
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
    printf("\n\n     恭喜！！！您已通关！！！\n\n\n");
    printf("    制作人员：Little-Bla-ck\n");
    printf("    联系我：\n    QQ:1173198173\n    E-mail:201250164@smail.nju.edu.cn\n");
    printf("    My blog: https://Little-Bla-ck.github.io\n");
    printf("    Thanks for playing!!!\n");
    printf("\n\n\n\n");
    system("pause");
}