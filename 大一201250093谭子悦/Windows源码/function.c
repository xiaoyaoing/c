//
// Created by NintenSAGA on 2020/12/11.
//
#include "Global.h"

void make_blank(int num){
    int i;
    for (i = 1;i <=num;i++) printf(" ");
}

void print_map(int map[][12], int x, int y){

    int blank = (50-2*(x+1))/2 + 1;
    int line = (50-y-6+1)/2;
    int i, m, n, temp;

    for(i = 0;i < line;i++) printf("\n");

    printf("©°");
    for(i = 0;i < 48;i++) printf("©¤");
    printf("©´\n");

    printf("©¦");
    printf("\tLevel:%d       Steps:%d\t   Items:%d\t",level,steps,items);
    make_blank(1);
    printf("©¦\n");


    printf("©¦");
    make_blank(blank-1);
    printf("©°");
    for(i = 0;i < x;i++) printf("©¤©¤");
    printf("©´");
    make_blank((50-2*(x+1))-blank-1);
    printf("©¦\n");

    for (n = 0;n < y;n++){
        printf("©¦");
        make_blank(blank-1);
        printf("©¦");
        for (m = 0;m < x;m++){
            temp = map[n][m];
            if (temp == 0) printf("  ");
            if (temp == 1) printf("¡ð");
            if (temp == 2) printf("¡ô");
            if (temp == 3) printf("¡ö");
            if (temp == 4) printf("¡ó");
            if (temp == 5) printf("¡ð");
            if (temp == 6) printf("¡ô");
            if (temp == 7) printf("¡÷");
        }
        printf("©¦");
        make_blank((50-2*(x+1))-blank-1);
        printf("©¦\n");
    }
    printf("©¦");
    make_blank(blank-1);
    printf("©¸");
    for(i = 0;i < x;i++) printf("©¤©¤");
    printf("©¼");
    make_blank((50-2*(x+1))-blank-1);
    printf("©¦\n");

    printf("©¦   *Move:W,S,A,D  *Restart:R  *Exit:.  *Item:I  ©¦\n");

    printf("©¸");
    for(i = 0;i < 48;i++) printf("©¤");
    printf("©¼\n");

    for(i = 0;i < ((50-y-6+1) - line);i++) printf("\n");

}