#include <conio.h>
#include <stdio.h>
#include <windows.h>
//下面是预留的函数
#define  width 16
#define  height 16
#define  initmap \
#define size_for_every_level 618
#define location "lxx.txt"
//下面是第一关的地图模块
int map_1[width][height]= { \
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0}, \
	{1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0}, \
	{1,0,0,0,0,0,3,0,1,0,0,0,0,0,0,0}, \
	{1,0,1,0,0,1,3,0,1,0,0,0,0,0,0,0}, \
	{1,0,2,0,2,1,4,0,1,0,0,0,0,0,0,0}, \
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
};
int map_2[width][height]= { \
{0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0}, \
{1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0}, \
{1,2,2,1,3,3,0,1,0,0,0,0,0,0,0,0}, \
{1,0,2,2,3,0,0,1,1,1,1,1,0,0,0,0}, \
{1,0,4,1,0,1,0,1,0,0,0,1,0,0,0,0}, \
{1,0,0,3,0,0,0,0,0,3,0,1,0,0,0,0}, \
{1,0,0,1,1,1,1,1,1,1,2,1,0,0,0,0}, \
{1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
};
int map_3[width][height]={ \
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0}, \
{0,0,1,1,0,1,0,1,1,1,1,0,0,0,0,0}, \
{0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,0}, \
{1,1,0,3,0,0,0,0,0,0,1,0,0,0,0,0}, \
{1,0,0,0,4,3,0,1,0,0,1,0,0,0,0,0}, \
{1,1,1,0,3,1,1,1,0,0,1,0,0,0,0,0}, \
{0,0,1,0,0,1,2,2,0,0,1,0,0,0,0,0}, \
{0,1,1,0,1,1,2,1,0,1,1,0,0,0,0,0}, \
{0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0}, \
{0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0}, \
{0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, \
};
int  mapch[width][height];
void yincangguangbiao();
void guangbiaodingwei(int x,int y);
void printfont();
void weizhaodaowenjianbaocuo();
int selectlevel();
void enterfromfile();
void menu();
void refresh();
void releasing_map();
void detection();
void pass_or_not();
void operation();
void gaibianshuzushuzhi(char ch);
int time();
void process();
int zuidaguankashu();
int shuruguanka();
int main () {

	refresh();
	process();
	return 0;
}
void printfont() {
	guangbiaodingwei(34,17);
	printf("本关剩余目标：");
	guangbiaodingwei(34,19);
	printf("本关已走步数：");
	guangbiaodingwei(32,21);
	printf("您使用 秒完成了本关！");
	guangbiaodingwei(49,19);
	printf("0");
}
int n=1;
void weizhaodaowenjianbaocuo() {
	system("cls");
	int i;
	if(n==2)
	{
	
	for(int i=0; i<width; i++) {
		for(int j=0; j<height; j++) {
			mapch[i][j]=map_1[i][j];
		}
	}
	
}
if(n==4)
	{
	
	for(int i=0; i<width; i++) {
		for(int j=0; j<height; j++) {
			mapch[i][j]=map_2[i][j];
		}
	}
	
}
if(n==6)
	{
	
	for(int i=0; i<width; i++) {
		for(int j=0; j<height; j++) {
			mapch[i][j]=map_3[i][j];
		}
	}
	
}
	Sleep(2000);
	system("cls");
	releasing_map();
	detection();
	printfont();
	
}

int max=0;
int zuidaguankashu() {
	FILE* fp=NULL;
	fopen("lxx.txt","r");
	if (fp==NULL) {
		weizhaodaowenjianbaocuo();
		
		return 0;
	}
	int temp=0;
	rewind(fp);
	while(!feof(fp)) {
		fgetc(fp);
		temp++;

	}
	fclose(fp);
	int size_for_every_level=618;
	max=temp/(size_for_every_level)+1;
	return 1;
}
int shuruguanka() {
	guangbiaodingwei(26,8);
	printf("请输入关卡后按回车：");
	guangbiaodingwei(36,10);
	printf("可输入的关卡为1-%d",max);
	guangbiaodingwei(48,10);
	scanf("%d",&n);
}
int selectlevel() {
	system("cls");
	if(!zuidaguankashu())  return 0;
	guangbiaodingwei(26,8);
	printf("请输入关卡后按回车：");
	guangbiaodingwei(36,10);
	printf("可输入的关卡为1-%d",max);
	guangbiaodingwei(48,10);
	scanf("%d",&n);
	while(n<1||n>max) {
		int shuruguanka;
	}
	return 1;
}
void enterfromfile() {
	FILE*fp=NULL;
	fopen("lxx.txt","rb");
	if(fp==NULL) {
		weizhaodaowenjianbaocuo();
		return ;

	}
/*	int skip=(n-1)*618;
	fseek(fp,skip,0);
	int i,j;
	for(i=0; i<width; i++) {
		for(j=0; j<height; j++) {
			fscanf(fp,"%d ",&mapch[i][j]);
			printf("%d ",mapch[i][j]);
		}
		printf("\n");

	}
	fclose(fp);
	system("cls");
}*/}
void menu() {
	system("cls");
	guangbiaodingwei(39,8);
	printf("推箱子");
	guangbiaodingwei(34,10);
	printf("输入1 开始新游戏");
	guangbiaodingwei(34,12);
/*	printf("输入2 选择关卡"); */   
	guangbiaodingwei(34,14);
	printf("输入3 退出游戏");char ch;
Head:
	guangbiaodingwei(34,16);
	ch=getchar();
	if(ch=='3') {
		system("cls");
		guangbiaodingwei(34,10);
		printf("See you !");
		Sleep(1919);
		exit(0);
	}
/*	else if(ch=='2') {
		selectlevel();
			return;
	}*/
	else if(ch=='1') {
		n++;
	} else {
		guangbiaodingwei(27,10);
		printf("您输入的关卡有误，请重新输入");
		goto Head;

	}
	enterfromfile();
	detection();
	releasing_map();
	printfont();
}
int not_completed_yet;
void detection() {
	not_completed_yet=0;
	int i,j;
	for(i=0; i<width; i++)
		for(j=0; j<height; j++)
			if(mapch[i][j]==2) {
				not_completed_yet++;
			}
	guangbiaodingwei(50,17);
	printf("%d",not_completed_yet);
}
void refresh() {
	system("title 推箱子");
	system("mode con cols=84 lines=26");
	menu();
	yincangguangbiao();
	zuidaguankashu();


}

int updatetime() {
	int now;
	SYSTEMTIME system_time;
	GetLocalTime(&system_time);
	now = system_time.wMinute * 60+system_time.wSecond;
	return now;
}

void releasing_map() {
	guangbiaodingwei(26,1);
	int i,j;
	for(i=0; i<width; i++) {
		for(j=0; j<height; j++) {
			if(mapch[i][j]==1)
				printf("口");
			else if(mapch[i][j]==2)
				printf("※");
			else if(mapch[i][j]==3)
				printf("箱");
			else if(mapch[i][j]==4)
				printf("人");
			else if(mapch[i][j]==5)
				printf("√");
			else if(mapch[i][j]==6)
				printf("仌");
			else printf("  ");


		}
		guangbiaodingwei(26,i+1);
	}
}
int opnum;
int time_1;
int time_2;
void pass_or_not() {
	if(not_completed_yet==0) {
		n++;
		if(n>max) {
			releasing_map();
			guangbiaodingwei(26,22);
			printf("已通关");
			Sleep(3000);


			opnum=0;
			time_1=updatetime(),time_2=0;
			menu();
		} else {
			releasing_map();
			Sleep(2000);
			enterfromfile();
			detection();
			printfont();
			opnum=0;
			time_1=updatetime(),time_2=0;
		}
	}
}
int i,j;
int box_x, box_y;
int boxnext_x, boxnext_y;
int peonext_x, peonext_y;

void gaibianshuzushuzhi(char ch) {
	for (i = 0; i <width; i++ ) {
		for (j = 0; j <width; j++ ) {
			if (mapch[i][j] == 4 || mapch[i][j] == 6 || mapch[i][j] == 7) {
				if (ch == 'w') {
					box_y = i - 1;
					box_x = j;
					boxnext_y = i - 2;
					boxnext_x = j;
					peonext_y = i - 1;
					peonext_x = j;
				} else if (ch == 'a') {
					box_y = i;
					box_x = j - 1;
					boxnext_y = i;
					boxnext_x = j - 2;
					peonext_y = i;
					peonext_x = j - 1;
				} else if (ch == 's') {
					box_y = i+1;
					box_x = j;
					boxnext_y = i+2;
					boxnext_x = j;
					peonext_y = i+1;
					peonext_x = j;
				} else if (ch == 'd') {
					box_y = i;
					box_x = j+1;
					boxnext_y = i;
					boxnext_x = j+2;
					peonext_y = i;
					peonext_x = j+1;
				}


				if (mapch[box_y][box_x] == 3 || mapch[box_y][box_x] == 8)
					if (mapch[boxnext_y][boxnext_x] == 1 || mapch[boxnext_y][boxnext_x] == 3 || mapch[boxnext_y][boxnext_x] == 8)
						return;

				if (mapch[box_y][box_x] == 1)
					return;

				opnum++ ;
				guangbiaodingwei(49, 19);
				printf("%d", opnum);
				if (mapch[box_y][box_x] == 3 || mapch[box_y][box_x] == 8) {
					if (mapch[box_y][box_x] == 3)
						mapch[box_y][box_x] = 0;
					else if (mapch[box_y][box_x] == 8)
						mapch[box_y][box_x] = 5;
					if (mapch[boxnext_y][boxnext_x] == 2) {
						mapch[boxnext_y][boxnext_x] = 5;
						not_completed_yet--;
						guangbiaodingwei(50, 17);
						printf("%d", not_completed_yet);
					} else if (mapch[boxnext_y][boxnext_x] == 0)
						mapch[boxnext_y][boxnext_x] = 3;
					else if (mapch[boxnext_y][boxnext_x] == 5)
						mapch[boxnext_y][boxnext_x] = 8;
				}


				if (mapch[i][j] == 6)
					mapch[i][j] = 2;
				else if (mapch[i][j] == 7)
					mapch[i][j] = 5;
				else if (mapch[i][j] == 4)
					mapch[i][j] = 0;
				if (mapch[peonext_y][peonext_x] == 0 || mapch[peonext_y][peonext_y] == 3)
					mapch[peonext_y][peonext_x] = 4;

				if (mapch[peonext_y][peonext_x] == 2)
					mapch[peonext_y][peonext_x] = 6;

				if (mapch[peonext_y][peonext_x] == 5)
					mapch[peonext_y][peonext_x] = 7;

				if (mapch[peonext_y][peonext_x] == 8)
					mapch[peonext_y][peonext_x] = 7;

				goto L1;
			}
		}
	}

L1:
	pass_or_not();
}

void operation() {
	char ch = _getch();
	switch (ch) {
		case 'w':
			gaibianshuzushuzhi(ch);
			break;
		case 'a':
			gaibianshuzushuzhi(ch);
			break;
		case 's':
			gaibianshuzushuzhi(ch);
			break;
		case 'd':
			gaibianshuzushuzhi(ch);
			break;
	}
	releasing_map();
}


void process() {
	time_1= updatetime();
	while (1) {

		time_2 = updatetime() - time_1;
		guangbiaodingwei(39, 21);
		printf("%d s",time_2);
		if(kbhit())
			operation();
		Sleep(20);
	}
}
void guangbiaodingwei(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void yincangguangbiao() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

