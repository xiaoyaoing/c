#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <windows.h>
void DrawMap();
void PlayGame();
void IfWin();
int stage=0;
//0�յ� 1ǽ 4���� 5�� 3Ŀ�ĵ�  
int main()  //��ӡ�˵� 
{ 
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo;
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    SetConsoleCursorInfo(fd,&cinfo);
printf("                         \n                          \n                        \n           ������С��Ϸ          \n       WASD�������������ƶ�       \n         ��Enter����ؿ�        "
);  

    char ch;  //������Ϸ 
    ch = getch();
    if(ch==13){ 
    while (1)
    {   
        system("cls");
        DrawMap();
        PlayGame();
        IfWin();
        
    }
} return 0;
    
}

int map[11][12]={
{0,0,0,1,1,1,1,1,0,0,0,0},
{1,1,1,0,0,1,1,1,1,0,0,0},
{1,0,0,0,0,0,4,0,1,0,0,0},
{1,0,1,0,0,1,4,0,1,0,0,0},
{1,0,3,0,3,1,5,0,1,0,0,0},
{1,1,1,1,1,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
};

/*
int map[11][12]={
{0,0,0,1,1,1,1,1,0,0,0,0},
{1,1,1,1,0,0,0,1,0,0,0,0},
{1,3,3,1,4,4,0,1,0,0,0,0},
{1,0,3,3,4,0,0,1,1,1,1,1},
{1,0,5,1,0,1,0,1,0,0,0,1},
{1,0,0,4,0,0,0,0,0,4,0,1},
{1,0,0,1,1,1,1,1,1,1,3,1},
{1,1,1,1,0,0,0,0,0,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0},
};
*/

/*int map[11][12]={
{0,0,0,1,1,1,1,1,0,0,0,0},
{0,0,1,1,0,0,1,0,1,1,1,0},
{0,1,1,0,0,0,1,1,1,0,1,0},
{1,1,4,0,0,0,0,0,0,0,1,0},
{1,0,0,0,5,4,0,1,0,0,1,0},
{1,1,1,0,4,1,1,1,0,0,1,0},
{0,0,1,0,0,1,3,3,0,0,1,0},
{0,1,1,0,1,1,3,1,0,1,1,0},
{0,1,0,0,0,0,0,0,1,1,0,0},
{0,1,0,0,0,0,0,1,1,0,0,0},
{0,1,1,1,1,1,1,1,0,0,0,0},
};*/

void DrawMap()
{
    //������ά����  //0 ��ӡ�ո�  //1 ǽ   //3 Ŀ�ĵ�  
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //if  else  switch
            switch (map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 5:
                printf("��");  //5��
                break;
            case 7:     //4 + 3  ������Ŀ�ĵ���
                printf("��");
                break;
            case 8:     // 5 + 3  ����Ŀ�ĵص���   ��?
                printf("��");
                break;
            }
        }
        printf("\n");
    }
}
void IfWin(){
	int option=1;
	 for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {   if(map[i][j]==4){
        	option=0;
		}
	}
} if(option==1){
    system("cls");
    char txt[]="1.txt";
    txt[0]='1'+stage++;
    FILE *data;
    if((data=fopen(txt,"r"))==NULL)
    {
        printf("win");
        _getch();
        exit(0);
	}
    for(int i=0;i<11;i++)
        for(int k=0;k<12;k++)
        {
            fscanf(data,"%d",&map[i][k]);
        }
    fclose(data);
    main();
	
}
}
void PlayGame()
{
    int r, c;  //�˵��±�  //
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (map[i][j] == 5||map[i][j]==8)   
            {
                r = i;
                c = j;
            }
        }
    }

    char ch;  
    ch = getch();  
    
    switch (ch)
    {
    case 'W':  
    case 'w':
    case 72:
        if (map[r - 1][c] == 0|| map[r - 1][c] == 3) 
        {
            map[r - 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
        {
            if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
            {
                map[r - 2][c] += 4;
                map[r - 1][c] += 1;
                map[r][c] -= 5;
            }
        }



        break;

    case 'S':  
    case 's':
    case 80:
        if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
        {
            map[r + 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r + 1][c] == 4 || map[r+ 1][c] == 7)
        {
            if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
            {
                map[r + 2][c] += 4;
                map[r + 1][c] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'A':
    case 'a':
    case 75:
        if (map[r ][c - 1] == 0 || map[r ][c - 1] == 3)
        {
            map[r ][c - 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
        {
            if (map[r ][c - 2] == 0 || map[r ][c - 2] == 3)
            {
                map[r ][c - 2] += 4;
                map[r ][c - 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'D':
    case 'd':
    case 77:
        if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
        {
            map[r][c + 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
        {
            if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
            {
                map[r][c + 2] += 4;
                map[r][c + 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;
    }
}

