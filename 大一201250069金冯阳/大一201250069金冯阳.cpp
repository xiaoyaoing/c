
#include <stdio.h>
#include <stdlib.h>
void PrintStage();
void StageInitialize();
void Menu();
int IfFlag(int X, int Y);
int Stage, PlayerX, PlayerY, BoxNumber=1,RightBox,MaxX,MaxY;
char KDR;
int FlagX[5],FlagY[5];
char StageN[11][13] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                       { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }};
char Stage1[6][12] = { { ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' ', ' ' },
                      { 'X', 'X', 'X', ' ', ' ', 'X', 'X', 'X', 'X' },
                      { 'X', ' ', ' ', ' ', ' ', ' ', 'O', ' ', 'X' },
                      { 'X', ' ', 'X', ' ', ' ', 'X', 'O', ' ', 'X' },
                      { 'X', ' ', '+', ' ', '+', 'X', 'P', ' ', 'X' },
                      { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };

char Stage2[8][12] = { { ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' '},
                       { 'X', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
                       { 'X', '+', '+', 'X', 'O', 'O', ' ', 'X', ' ', ' ', ' ', ' '},
                       { 'X', ' ', '+', '+', 'O', ' ', ' ', 'X', 'X', 'X', 'X', 'X'},
                       { 'X', ' ', 'P', 'X', ' ', 'X', ' ', 'X', ' ', ' ', ' ', 'X'},
                       { 'X', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', 'O', ' ', 'X'},
                       { 'X', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '+', 'X'},
                       { 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X'} };
                       
char Stage3[11][11] = { {' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', 'X', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X'},
                        {' ', 'X', 'X', ' ', ' ', 'X', 'X', 'X', ' ', ' ', 'X'},
                        {'X', 'X', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
                        {'X', ' ', ' ', ' ', 'P', 'O', ' ', 'X', ' ', ' ', 'X'},
                        {'X', 'X', 'X', ' ', 'O', 'X', 'X', 'X', ' ', ' ', 'X'},
                        {' ', ' ', 'X', ' ', ' ', 'X', '+', '+', ' ', ' ', 'X'},
                        {' ', 'X', 'X', ' ', 'X', 'X', '+', 'X', ' ', 'X', 'X'},
                        {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' '},
                        {' ', 'X', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' '},
                        {' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' '} };
void Menu()
{
    printf("这是一个推箱子游戏。\n通过WASD进行移动\n请输入想游玩的关卡（1~3)\n");
    if (scanf_s("%d", &Stage))
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        StageInitialize();
        PrintStage();
    }
}
void StageInitialize()
{
    if (Stage == 1)  //dwwaaawasddddssawwdwwaaassaaawwddsdsawwwdss
    {
        BoxNumber = 2;
        PlayerX = 7;
        PlayerY = 5;
        FlagX[0] = 3;
        FlagX[1] = 5;
        FlagY[0] = 5;
        FlagY[1] = 5;
        MaxX = 9;
        MaxY = 6;
        for (int i = 1; i <= MaxY; i++)
        {
            for (int j = 1; j <= MaxX; j++)
                StageN[i-1][j-1]=Stage1[i-1][j-1];
        }       
        RightBox = 0;
    }
    if (Stage == 2)  
    {
        BoxNumber = 5;
        PlayerX = 3;
        PlayerY = 5;
        FlagX[0] = 2;
        FlagY[0] = 3;
        FlagX[1] = 3;
        FlagY[1] = 3;
        FlagX[2] = 3;
        FlagY[2] = 4;
        FlagX[3] = 4;
        FlagY[3] = 4;
        FlagX[4] = 11;
        FlagY[4] = 7;
        MaxX = 12;
        MaxY = 8;
        for (int i = 1; i <= MaxY; i++)
        {
            for (int j = 1; j <= MaxX; j++)
                StageN[i - 1][j - 1] = Stage2[i - 1][j - 1];
        }
        RightBox = 0;
    }
    if (Stage == 3)  
    {
        BoxNumber = 3;
        PlayerX = 5;
        PlayerY = 5;
        FlagX[0] = 7;
        FlagY[0] = 7;
        FlagX[1] = 7;
        FlagY[1] = 8;
        FlagX[2] = 8;
        FlagY[2] = 7;
        MaxX = 11;
        MaxY = 11;
        for (int i = 1; i <= MaxY; i++)
        {
            for (int j = 1; j <= MaxX; j++)
                StageN[i - 1][j - 1] = Stage3[i - 1][j - 1];
        }
        RightBox = 0;
    }
}
void PrintStage()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 1; i <= MaxY; i++)
    {
        for (int j = 1; j <= MaxX; j++)
            printf("%c", StageN[i - 1][j - 1]);
        printf("\n");
    }
}
int IfFlag(int X,int Y)
{
    int m = 0;
    for (int i = 1; i <= BoxNumber; i++)
    {
        if (FlagX[i - 1] == X && FlagY[i - 1] == Y) m=1;
    }
    return m;
}
void KeyPressW()
{
    if(PlayerY>1)
    {       
        if (StageN[PlayerY-2][PlayerX - 1] == ' ')
            {               
                StageN[PlayerY-2][PlayerX - 1] = 'P';
                if(IfFlag(PlayerX,PlayerY)) 
                    StageN[PlayerY - 1][PlayerX - 1] = '+';
                else StageN[PlayerY - 1][PlayerX - 1] = ' ';
                PlayerY -= 1;
            }
        else if (StageN[PlayerY - 2][PlayerX - 1] == '+')
        {
            StageN[PlayerY - 2][PlayerX - 1] = 'p';
            if (IfFlag(PlayerX, PlayerY)) 
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerY -= 1;
        }
        else if (StageN[PlayerY - 2][PlayerX - 1] == 'O' || StageN[PlayerY - 2][PlayerX - 1] == '*')
        {
            if (PlayerY > 2)
            {
                if (StageN[PlayerY - 3][PlayerX - 1] != 'X' && StageN[PlayerY - 3][PlayerX - 1] != 'O' && StageN[PlayerY - 3][PlayerX - 1] != '*')
                {
                    if (IfFlag(PlayerX, PlayerY - 2))
                    {
                        StageN[PlayerY - 3][PlayerX - 1] = '*';  
                        RightBox += 1;
                    }
                    else StageN[PlayerY - 3][PlayerX - 1] = 'O';
                    if (IfFlag(PlayerX, PlayerY - 1))
                    {
                        StageN[PlayerY - 2][PlayerX - 1] = 'p';
                        RightBox -= 1;
                    }
                    else StageN[PlayerY - 2][PlayerX - 1] = 'P';
                    if (IfFlag(PlayerX, PlayerY)) 
                        StageN[PlayerY - 1][PlayerX - 1] = '+';
                    else StageN[PlayerY - 1][PlayerX - 1] = ' ';
                    PlayerY -= 1;
                }
            }
        }
    }
    PrintStage();
}
void KeyPressS()
{
    if (PlayerY < MaxY)
    {
        if (StageN[PlayerY][PlayerX - 1] == ' ')
        {
            StageN[PlayerY][PlayerX - 1] = 'P';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerY += 1;
        }
        else if (StageN[PlayerY][PlayerX - 1] == '+')
        {
            StageN[PlayerY][PlayerX - 1] = 'p';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerY += 1;
        }
        else if (StageN[PlayerY][PlayerX - 1] == 'O' || StageN[PlayerY][PlayerX - 1] == '*')
        {
            if (PlayerY < MaxY - 1)
            {
                if (StageN[PlayerY + 1][PlayerX - 1] != 'X' && StageN[PlayerY + 1][PlayerX - 1] != 'O' && StageN[PlayerY + 1][PlayerX - 1] != '*')
                {
                    if (IfFlag(PlayerX, PlayerY +2))
                    {
                        StageN[PlayerY + 1][PlayerX - 1] = '*';
                        RightBox += 1;
                    }
                    else StageN[PlayerY + 1][PlayerX - 1] = 'O';
                    if (IfFlag(PlayerX, PlayerY + 1))
                    {
                        StageN[PlayerY][PlayerX - 1] = 'p';
                        RightBox -= 1;
                    }
                    else StageN[PlayerY][PlayerX - 1] = 'P';
                    if (IfFlag(PlayerX, PlayerY))
                        StageN[PlayerY - 1][PlayerX - 1] = '+';
                    else StageN[PlayerY - 1][PlayerX - 1] = ' ';
                    PlayerY += 1;
                }
            }
        }
    }
    PrintStage();
}
void KeyPressA()
{
    if (PlayerX > 1)
    {
        if (StageN[PlayerY - 1][PlayerX - 2] == ' ')
        {
            StageN[PlayerY - 1][PlayerX - 2] = 'P';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerX -= 1;
        }
        else if (StageN[PlayerY - 1][PlayerX - 2] == '+')
        {
            StageN[PlayerY - 1][PlayerX - 2] = 'p';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerX -= 1;
        }
        else if (StageN[PlayerY - 1][PlayerX - 2] == 'O' || StageN[PlayerY - 1][PlayerX - 2] == '*')
        {
            if (PlayerX > 2)
            {
                if (StageN[PlayerY - 1][PlayerX - 3] != 'X' && StageN[PlayerY - 1][PlayerX - 3] != 'O' && StageN[PlayerY - 1][PlayerX - 3] != '*')
                {
                    if (IfFlag(PlayerX-2, PlayerY))
                    {
                        StageN[PlayerY - 1][PlayerX - 3] = '*';
                        RightBox += 1;
                    }
                    else StageN[PlayerY - 1][PlayerX - 3] = 'O';
                    if (IfFlag(PlayerX-1, PlayerY))
                    {
                        StageN[PlayerY - 1][PlayerX - 2] = 'p';
                        RightBox -= 1;
                    }
                    else StageN[PlayerY - 1][PlayerX - 2] = 'P';
                    if (IfFlag(PlayerX, PlayerY))
                        StageN[PlayerY - 1][PlayerX - 1] = '+';
                    else StageN[PlayerY - 1][PlayerX - 1] = ' ';
                    PlayerX -= 1;
                }
            }
        }
    }
    PrintStage();
}
void KeyPressD()
{
    if (PlayerX < MaxX)
    {
        if (StageN[PlayerY - 1][PlayerX] == ' ')
        {
            StageN[PlayerY - 1][PlayerX] = 'P';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerX += 1;
        }
        else if (StageN[PlayerY - 1][PlayerX] == '+')
        {
            StageN[PlayerY - 1][PlayerX] = 'p';
            if (IfFlag(PlayerX, PlayerY))
                StageN[PlayerY - 1][PlayerX - 1] = '+';
            else StageN[PlayerY - 1][PlayerX - 1] = ' ';
            PlayerX += 1;
        }
        else if (StageN[PlayerY - 1][PlayerX] == 'O' || StageN[PlayerY - 1][PlayerX] == '*')
        {
            if (PlayerX < MaxX - 1)
            {
                if (StageN[PlayerY - 1][PlayerX + 1] != 'X' && StageN[PlayerY - 1][PlayerX + 1] != 'O' && StageN[PlayerY - 1][PlayerX + 1] != '*')
                {
                    if (IfFlag(PlayerX + 2, PlayerY))
                    {
                        StageN[PlayerY - 1][PlayerX + 1] = '*';
                        RightBox += 1;
                    }
                    else StageN[PlayerY - 1][PlayerX + 1] = 'O';
                    if (IfFlag(PlayerX + 1, PlayerY))
                    {
                        StageN[PlayerY - 1][PlayerX] = 'p';
                        RightBox -= 1;
                    }
                    else StageN[PlayerY - 1][PlayerX] = 'P';
                    if (IfFlag(PlayerX, PlayerY))
                        StageN[PlayerY - 1][PlayerX - 1] = '+';
                    else StageN[PlayerY - 1][PlayerX - 1] = ' ';
                    PlayerX += 1;
                }
            }
        }
    }
    PrintStage();
}
int main()
{  
    while (1)
    {
        Menu();        
        while (RightBox != BoxNumber)
        {
            if (KDR = getchar())
            {
                if (KDR == 'w' || KDR == 'W') KeyPressW();
                if (KDR == 's' || KDR == 'S') KeyPressS();
                if (KDR == 'a' || KDR == 'A') KeyPressA();
                if (KDR == 'd' || KDR == 'D') KeyPressD();
            }
        }
        printf("你赢了！\n");
        system("pause");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
