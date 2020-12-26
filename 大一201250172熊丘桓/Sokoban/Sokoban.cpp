//Sokoban
//EagleBear
//20.12.10
#include <bits/stdc++.h>
#include <cstdio>
#include <conio.h>
#include <windows.h>

typedef long long LL;
typedef long double LD;
const int MAXN = 300 + 10;
const double EPS = 1e-6;
const int INF = 0x3f3f3f3f;

const int W = 6, H = 4;
const int PAUSETIME = 2500;
const int PRINTGAPTIME = 50;
int n, m;
int map[MAXN][MAXN];
int alv[MAXN][MAXN];

void Print(const char* s, int gap = PRINTGAPTIME) {
	int len = strlen(s);
	for(int i = 0; i < len; ++i) {
		putchar(s[i]);
		Sleep(gap);
	}
}

FILE* GetInputFile(int mapId) {
	char inputFileName[100] = {0};
	sprintf(inputFileName, "map%d.txt", mapId);
	return fopen(inputFileName, "r");
}

int InitMap(FILE* inputFile) {
	memset(map, 0, sizeof map);
	memset(alv, 0, sizeof alv);
	int boxCnt = 0;
	char s[MAXN][MAXN];
	n = -1;
	while (fscanf(inputFile, "%s", s[++n]) != EOF);
	m = strlen(s[0]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '#') map[i][j] = 1;
			else if (s[i][j] == '&') map[i][j] = 2, ++boxCnt;
			else if (s[i][j] == '$') alv[i][j] = 3;
			else if (s[i][j] == '@') alv[i][j] = 4;
	
	return boxCnt;
}

void FillSokoban(char cur[][MAXN], int i, int j) {
	int x = i * H, y = j * W;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cur[x+i][y+j] = '@';

	int marginH = 
	cur[x+1][y+1] = 'Y';
	cur[x+1][y+2] = 'O';
	cur[x+1][y+3] = 'U';
	cur[x][y] = cur[x+H-1][y] = cur[x][y+W-1] = cur[x+H-1][y+W-1] = ' ';
}

void FillBox(char cur[][MAXN], int i, int j) {
	int x = i * H, y = j * W;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cur[x+i][y+j] = 'X';
	for (int i = 1; i < H-1; ++i)
		for (int j = 1; j < W-1; ++j)
			cur[x+i][y+j] = ' ';
}

void FillGoal(char cur[][MAXN], int i, int j) {
	int x = i * H, y = j * W;
	int marginH = (H-2)/2, marginW = (W-4)/2;
	cur[x+marginH][y+marginW] = 'G';
	cur[x+marginH][y+marginW+1] = 'E';
	cur[x+marginH][y+marginW+2] = 'T';
	cur[x+marginH+1][y+marginW] = 'H';
	cur[x+marginH+1][y+marginW+1] = 'E';
	cur[x+marginH+1][y+marginW+2] = 'R';
	cur[x+marginH+1][y+marginW+3] = 'E';
}

void Display(int mapId) {
	char cur[MAXN][MAXN];
	memset(cur, 0, sizeof cur);
	printf("Case #%d:\n", mapId);

	for (int i = 0; i < H*n; ++i)
		for (int j = 0; j < W*m; ++j) {
			int x = i / H, y = j / W;
			if (map[x][y] == 1) cur[i][j] = '#';
			else cur[i][j] = ' ';
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (alv[i][j] == 3) FillBox(cur, i, j);
			else if (alv[i][j] == 4) FillSokoban(cur, i, j);
			else if (map[i][j] == 2) FillGoal(cur, i, j);

	for (int i = 0; i < H * n; ++i)
		puts(cur[i]);
}

void FindSokoban(int& x, int& y) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (alv[i][j] == 4) return x = i, y = j, void();
}

void MoveUp(int& x, int& y) {
	if (!alv[x-1][y])
		if (map[x-1][y] == 1) return;
		else std::swap(alv[x-1][y], alv[x][y]), x--;
	else if (map[x-2][y] == 1 || alv[x-2][y]) return;
		else alv[x-2][y] = 3, alv[x-1][y] = 4, alv[x][y] = 0, x--;
}

void MoveDown(int& x, int& y) {
	if (!alv[x+1][y])
		if (map[x+1][y] == 1) return;
		else std::swap(alv[x+1][y], alv[x][y]), x++;
	else if (map[x+2][y] == 1 || alv[x+2][y]) return;
		else alv[x+2][y] = 3, alv[x+1][y] = 4, alv[x][y] = 0, x++;
}

void MoveLeft(int& x, int& y) {
	if (!alv[x][y-1])
		if (map[x][y-1] == 1) return;
		else std::swap(alv[x][y-1], alv[x][y]), --y;
	else if (map[x][y-2] == 1 || alv[x][y-2]) return;
		else alv[x][y-2] = 3, alv[x][y-1] = 4, alv[x][y] = 0, --y;
}

void MoveRight(int& x, int& y) {
	if (!alv[x][y+1])
		if (map[x][y+1] == 1) return;
		else std::swap(alv[x][y+1], alv[x][y]), ++y;
	else if (map[x][y+2] == 1 || alv[x][y+2]) return;
		else alv[x][y+2] = 3, alv[x][y+1] = 4, alv[x][y] = 0, y++;
}

bool CheckSuccess() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 2 && alv[i][j] != 3) return false;
	return true;
}

void Welcome(bool openWelcome) {
	if(!openWelcome) return;
	Print("Welcome to Sokoban the Game\n");
	Print("before you play the game, it's suggested that you read the document named readme.txt\n");
	Print("enter any key to continue\n");
	while (true) if (getch()) return;
}

void WelEnd(bool openWelend) {
	if(!openWelend) return;
	Print("You have passed all cases\n");
	Print("You must have had a difficult time on the game\n");
	Print("You have done really well\n");

	Print("The author is Eagle Bear(Xiong Qiuhuan) from Sofeware Engineering, NJU\n");
	Print("The create time is December 10th, 2020\n");
	Print("for the contest of \"Out of Way on the Center\"\n");
	Print("Wish you happy\n");
	Print("Any comment is welcome by email: 377568710@qq.com\n");
	Print("Wish you a good night\n");
	Print("Press any key to end\n");
	getchar();
}

int main() {
#ifdef EagleBear
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
#endif

	Welcome(true);
	int mapcnt = 99;
	for (int mapId = 0; mapId <= mapcnt; ++mapId) {
		FILE* inputFile = GetInputFile(mapId);
		if(!inputFile) continue;

		system("cls");
		int boxCnt = InitMap(inputFile);
		Display(mapId);

		bool restartTag = false;
		while (!CheckSuccess() && !restartTag) {
			char ch = getch();
			int x = 0, y = 0;
			FindSokoban(x, y);
			if (ch == 'W' || ch == 'w' || ch == 72) MoveUp(x, y);
			else if (ch == 'S' || ch == 's' || ch == 80) MoveDown(x, y);
			else if (ch == 'A' || ch == 'a' || ch == 75) MoveLeft(x, y);
			else if (ch == 'D' || ch == 'd' || ch == 77) MoveRight(x, y);
			else if (ch == 'R' || ch == 'r') restartTag = true;
			else if (ch == 'Z' || ch == 'z') break;

			system("cls");
			Display(mapId);
		}

		if(restartTag) --mapId;
		else {
			printf("You success!\n");
			printf("Let's try the next case\n");
			Sleep(PAUSETIME);
		}
	}

	system("cls");
	WelEnd(true);

#ifdef EagleBear
	fclose(stdin), fclose(stdout);
#endif
	return 0;
}
