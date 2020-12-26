// Czh
// 2020.12
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

const int Maxlen = 50;
const int Maxwidth = 50;
const int MaxgameCases = 10;
const int MaxTargetNum = Maxlen * Maxwidth;
const int directionX[] = {0, 0, 1, -1};
const int directionY[] = {1, -1, 0, 0};

int n, m, nowId, targetNum, gameCasesNum;
char status[Maxlen][Maxwidth];
bool isTarget[Maxlen][Maxwidth];

struct Target {
    int x, y;
} target[MaxTargetNum];

struct GameCases {
    int nIn, mIn, targetNumIn;
    char statusIn[Maxlen][Maxwidth];
    Target targetIn[MaxTargetNum];
} gameCases[MaxgameCases];

inline void readGameCases() {
    freopen("gameCase/gameCasesNum.txt", "r", stdin);
    scanf("%d", &gameCasesNum);

    // printf("%d\n", gameCasesNum);

    for (int i = 1; i <= gameCasesNum; i++) {
        string nowNum = "";
        for (int tmp = i; tmp; tmp /= 10) nowNum += ((tmp % 10) + '0');
        reverse(nowNum.begin(), nowNum.end());
        string fileName = "gameCase/case" + nowNum + ".txt";

        // cout << fileName << endl;

        char fileNameChar[100];
        memset(fileNameChar, 0, sizeof(fileNameChar));
        for (int i = 0; i < fileName.length(); i++) fileNameChar[i] = fileName[i];
        fileNameChar[fileName.length()]=  '\0';

        // puts(fileNameChar);

        freopen(fileNameChar, "r", stdin);
        scanf("%d%d", &gameCases[i].nIn, &gameCases[i].mIn);
        for (int j = 1; j <= gameCases[i].nIn; j++) scanf("%s", gameCases[i].statusIn[j] + 1);
        
        // printf("%d %d\n", gameCases[i].nIn, gameCases[i].mIn);
        // for (int j = 1; j <= gameCases[i].nIn; j++, puts("")) 
        //     for (int k = 1; k <= gameCases[i].mIn; k++)
        //         putchar(gameCases[i].statusIn[j][k]);

        gameCases[i].targetNumIn = 0;
        for (int j = 1; j <= gameCases[i].nIn; j++)
            for (int k = 1; k <= gameCases[i].mIn; k++) {
                if (gameCases[i].statusIn[j][k] == 'x') {
                    ++gameCases[i].targetNumIn;
                    gameCases[i].targetIn[gameCases[i].targetNumIn].x = j, gameCases[i].targetIn[gameCases[i].targetNumIn].y = k;
                }
                if (gameCases[i].statusIn[j][k] == '$') gameCases[i].statusIn[j][k] = ' ';
            }
        
        
        // printf("%d %d\n", gameCases[i].nIn, gameCases[i].mIn);
        // for (int j = 1; j <= gameCases[i].nIn; j++, puts("")) 
        //     for (int k = 1; k <= gameCases[i].mIn; k++)
        //         putchar(gameCases[i].statusIn[j][k]);
        // printf("%d\n", gameCases[i].targetNumIn);
    }
    freopen("con", "r", stdin);
}

inline void printMap() {
    system("cls");
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            putchar(status[i][j]);
}

inline void copyGameCases(int id) {
    n = gameCases[id].nIn, m = gameCases[id].mIn;
    
// DEBUG
    // printf("%d %d\n", n, m);
    // system("pause");
// DEBUG-end

    memset(status, 0, sizeof(status));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            status[i][j] = gameCases[id].statusIn[i][j];
    memset(isTarget, 0, sizeof(isTarget));
    targetNum = gameCases[id].targetNumIn;
    for (int i = 1; i <= targetNum; i++) {
        target[i] = gameCases[id].targetIn[i];
        isTarget[target[i].x][target[i].y] = 1;
    }
}

inline int getNowDirection() {
    int nowDirection = 0;
    for (char ch; ; ) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'w') nowDirection = 4;
            if (ch == 'a') nowDirection = 2;
            if (ch == 's') nowDirection = 3;
            if (ch == 'd') nowDirection = 1;
        }
        if (nowDirection) break;
    }
    --nowDirection;
    cin.sync();
    return nowDirection;
}

inline bool checkIfWin() {
    for (int i = 1; i <= targetNum; i++)
        if (status[target[i].x][target[i].y] != '=') 
            return false;
    return true;
}

inline bool checkIfLose() {
    int okNum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            if (status[i][j] == '=') {
                bool isLeftNotOk = (status[i + directionX[3]][j + directionY[3]] == '#' || status[i + directionX[3]][j + directionY[3]] == '=');
                bool isRightNotOk = (status[i + directionX[2]][j + directionY[2]] == '#' || status[i + directionX[2]][j + directionY[2]] == '=');
                bool isUpNotOk = (status[i + directionX[0]][j + directionY[0]] == '#' || status[i + directionX[0]][j + directionY[0]] == '=');
                bool isDownNotOk = (status[i + directionX[1]][j + directionY[1]] == '#' || status[i + directionX[1]][j + directionY[1]] == '=');
                if ((isLeftNotOk && isUpNotOk) || (isLeftNotOk && isDownNotOk) || (isRightNotOk && isUpNotOk) || (isRightNotOk && isDownNotOk)) continue;
                else ++okNum;
            }
    if (!okNum) return true;
    else return false;
}

inline void goStep(int nowDirection) {
    int nowX, nowY;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (status[i][j] == 'O') {
                nowX = i, nowY = j;
                break;
            }
    int toX = nowX + directionX[nowDirection], toY = nowY + directionY[nowDirection];
    if (status[toX][toY] == '#') return;
    else if (status[toX][toY] == ' ' || status[toX][toY] == 'x') {
        status[nowX][nowY] = gameCases[nowId].statusIn[nowX][nowY] == 'x' ? 'x' : ' ', status[toX][toY] = 'O';
        return;
    } else if (status[toX][toY] == '=') {
        int totoX = toX + directionX[nowDirection], totoY = toY + directionY[nowDirection];
        if (status[totoX][totoY] == ' ' || status[totoX][totoY] == 'x') {
            status[totoX][totoY] = '=', status[toX][toY] = 'O', status[nowX][nowY] = gameCases[nowId].statusIn[nowX][nowY] == 'x' ? 'x' : ' ';
        } else return;
    }
    return;
}

int main() {
    // SetConsoleTitle("Sokoban");
    system("mode con cols=30 lines=20");

    readGameCases();

    puts("Sokoban");
    puts("Press any key to start.");
    system("pause");
    // Sleep(3000);
    system("cls");

    for (int i = 1; i <= gameCasesNum; i++) {
        printf("Case %d\n", i);
        Sleep(1500);
        copyGameCases(i);
        nowId = i;
        printMap();
        bool flag = 0;
        for (; !checkIfWin(); ) {
            if (checkIfLose()) {
                puts("Try again");
                // system("pause");
                Sleep(3000);
                system("cls");
                i--;
                flag = 1;
                break;
            }
            int nowDirection = getNowDirection();

            // printf("%d\n", nowDirection);

            goStep(nowDirection);
            printMap();
        }
        if (!flag) {
            if (i == gameCasesNum) {
                puts("Conguratulations!");
                puts("You win!");
                system("pause");
            } else {
                puts("Conguratulations!");
                system("pause");
                system("cls");
            }    
        }
    }
    return 0;
}