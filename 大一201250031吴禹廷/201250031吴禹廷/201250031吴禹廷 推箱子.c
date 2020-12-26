#include<stdio.h>
#include<stdlib.h>
#define a 4
#define b 5
#define line 8
#define row 12
char map[line][row][a][b];
int i,j,k,l;
void printmap(){
	system("cls");
	for(i=0;i<line;i++){
		for(k=0;k<a;k++){
			for(j=0;j<row;j++){
				for(l=0;l<b;l++)
				printf("%c",map[i][j][k][l]);
			}
			printf("\n");
		}
	}
}
void barrier(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		for(l=0;l<b;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='*';
		} 
	}
}
void box(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		for(l=0;l<b;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='#';
		} 
	}
}
void character(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		for(l=0;l<b;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='c';
		} 
	}
}
void goal(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		if(k==0||k==(a-1)){
			for(l=0;l<b;l++){
				ptr=&map[line1][row1][k][l];
				*ptr='!';
			}
		}
		else{
			ptr=&map[line1][row1][k][0];
			*ptr='!';
			ptr=&map[line1][row1][k][b-1];
			*ptr='!';
			for(l=1;l<b-1;l++){
				ptr=&map[line1][row1][k][l];
				*ptr='\0';
			}
		}
	}
}
void characterInGoal(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		if(k==0||k==(a-1)){
			for(l=0;l<b;l++){
				ptr=&map[line1][row1][k][l];
				*ptr='!';
			}
		}
		else{
			ptr=&map[line1][row1][k][0];
			*ptr='!';
			ptr=&map[line1][row1][k][b-1];
			*ptr='!';
		}
	}
	for(k=1;k<a-1;k++){
		for(l=1;l<b-1;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='c';
		}
	}
}
void boxInGoal(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		if(k==0||k==(a-1)){
			for(l=0;l<b;l++){
				ptr=&map[line1][row1][k][l];
				*ptr='!';
			}
		}
		else{
			ptr=&map[line1][row1][k][0];
			*ptr='!';
			ptr=&map[line1][row1][k][b-1];
			*ptr='!';
		}
	}
	for(k=1;k<a-1;k++){
		for(l=1;l<b-1;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='#';
		}
	}
}
void blank(int line1,int row1){
	char*ptr;
	for(k=0;k<a;k++){
		for(l=0;l<b;l++){
			ptr=&map[line1][row1][k][l];
			*ptr='\0';
		} 
	}
}
char type1(int line1,int row1){
	char type;
	type=map[line1][row1][0][0];
	return type;
}
char type2(int line1,int row1){
	char type;
	type=map[line1][row1][1][1];
	return type;
}
int main(){
	int x,y;
	char gesture;
	for(x=0;x<line;x++){
		switch(x){
			case 0:
				for(y=3;y<=7;y++) barrier(x,y);break;
			case 1:
				for(y=0;y<=3;y++) barrier(x,y);
				barrier(x,7);
				break;
			case 2:
				barrier(x,0);barrier(x,3);barrier(x,7);
				goal(x,1);goal(x,2);
				box(x,4);box(x,5);
				break;
			case 3:
				barrier(x,0);
				for(y=7;y<row;y++) barrier(x,y);
				goal(x,2);goal(x,3);
				box(x,4);
				break;
			case 4:
				barrier(x,0);barrier(x,3);barrier(x,5);barrier(x,7);barrier(x,row-1);
				character(x,2);
				break;
			case 5:
				barrier(x,0);barrier(x,row-1);
				box(x,3);box(x,row-3);
				break;
			case 6:
				barrier(x,0);
				for(y=3;y<row-2;y++) barrier(x,y);
				barrier(x,row-1);
				goal(x,row-2);
				break;
			case 7:
				for(y=0;y<=3;y++) barrier(x,y);
				for(y=row-3;y<row;y++) barrier(x,y);
				break;
		}
    }
	printmap();
	x=4;y=2;
	while(!((map[2][1][1][1]=='#')&&(map[2][2][1][1]=='#')&&(map[3][2][1][1]=='#')&&(map[3][3][1][1]=='#')&&(map[line-2][row-2][1][1]=='#'))){
		scanf("%c",&gesture);
		switch(gesture){
			case 'w':
				if(type2(x-1,y)!='*'){
					if(type2(x-2,y)=='\0'){
						if(type2(x-1,y)=='#'){
							if(type1(x,y)=='c'){
								if(type1(x-1,y)=='#'){
									if(type1(x-2,y)=='\0'){
										blank(x,y);character(x-1,y);box(x-2,y);
									}
									if(type1(x-2,y)=='!'){
										blank(x,y);character(x-1,y);boxInGoal(x-2,y);
									}
								}
								if(type1(x-1,y)=='!'){
									blank(x,y);characterInGoal(x-1,y);boxInGoal(x-2,y);
								} 
							}
							if(type1(x,y)=='!'){
								if(type1(x-1,y)=='!'){
									goal(x,y);characterInGoal(x-1,y);box(x-2,y);
								}
								if(type1(x-1,y)=='#'){
									goal(x,y);character(x-1,y);box(x-2,y);
								}
							}
						}
					}
					if(type2(x-1,y)=='\0'){
							if(type1(x,y)=='c'){
								if(type1(x-1,y)=='\0'){
									blank(x,y);character(x-1,y);
								}
								if(type1(x-1,y)=='!'){
									blank(x,y);characterInGoal(x-1,y);
								}
							}
							if(type1(x,y)=='!'){
								if(type1(x-1,y)=='\0'){
									goal(x,y);character(x-1,y);
								}
								if(type1(x-1,y)=='!'){
									goal(x,y);characterInGoal(x-1,y);
								}
							}
						}
					x--;
				}

				break;
			case 's':
				if(type2(x+1,y)!='*'){
					if(type2(x+2,y)=='\0'){
						if(type2(x+1,y)=='#'){
							if(type1(x,y)=='c'){
								if(type1(x+1,y)=='#'){
									if(type1(x+2,y)=='\0'){
										blank(x,y);character(x+1,y);box(x+2,y);
									}
									if(type1(x+2,y)=='!'){
										blank(x,y);character(x+1,y);boxInGoal(x+2,y);
									}
								}
								if(type1(x+1,y)=='!'){
									blank(x,y);characterInGoal(x-1,y);boxInGoal(x-2,y);
								} 
							}
							if(type1(x,y)=='!'){
								if(type1(x+1,y)=='!'){
									goal(x,y);characterInGoal(x+1,y);box(x+2,y);
								}
								if(type1(x+1,y)=='#'){
									goal(x,y);character(x+1,y);box(x+2,y);
								}
							}
						}
					}
					if(type2(x+1,y)=='\0'){
						if(type1(x,y)=='c'){
							if(type1(x+1,y)=='\0'){
								blank(x,y);character(x+1,y);
							}
							if(type1(x+1,y)=='!'){
								blank(x,y);characterInGoal(x+1,y);
							}
						}
						if(type1(x,y)=='!'){
							if(type1(x+1,y)=='\0'){
								goal(x,y);character(x+1,y);
							}
							if(type1(x+1,y)=='!'){
								goal(x,y);characterInGoal(x+1,y);
							}
						}
					}
					x++;
				}
				break;
			case 'a':
				if(type2(x,y-1)!='*'){
					if(type2(x,y-2)=='\0'){
						if(type2(x,y-1)=='#'){
							if(type1(x,y)=='c'){
								if(type1(x,y-1)=='#'){
									if(type1(x,y-2)=='\0'){
										blank(x,y);character(x,y-1);box(x,y-2);
									}
									if(type1(x,y-2)=='!'){
										blank(x,y);character(x,y-1);boxInGoal(x,y-2);
									}
								}
								if(type1(x,y-1)=='!'){
									blank(x,y);characterInGoal(x,y-1);boxInGoal(x,y-2);
								} 
							}
							if(type1(x,y)=='!'){
								if(type1(x,y-1)=='!'){
									goal(x,y);characterInGoal(x,y-1);box(x,y-2);
								}
								if(type1(x,y-1)=='#'){
									goal(x,y);character(x,y-1);box(x,y-2);
								}
							}
						}
					}
					if(type2(x,y-1)=='\0'){
							if(type1(x,y)=='c'){
								if(type1(x,y-1)=='\0'){
									blank(x,y);character(x,y-1);
								}
								if(type1(x,y-1)=='!'){
									blank(x,y);characterInGoal(x,y-1);
								}
							}
							if(type1(x,y)=='!'){
								if(type1(x,y-1)=='\0'){
									goal(x,y);character(x,y-1);
								}
								if(type1(x,y-1)=='!'){
									goal(x,y);characterInGoal(x,y-1);
								}
							}
						}
					y--;
				}
				break;
			case 'd':
				if(type2(x,y+1)!='*'){
					if(type2(x,y+2)=='\0'){
						if(type2(x,y+1)=='#'){
							if(type1(x,y)=='c'){
								if(type1(x,y+1)=='#'){
									if(type1(x,y+2)=='\0'){
										blank(x,y);character(x,y+1);box(x,y+2);
									}
									if(type1(x,y+2)=='!'){
										blank(x,y);character(x,y+1);boxInGoal(x,y+2);
									}
								}
								if(type1(x,y+1)=='!'){
									blank(x,y);characterInGoal(x,y+1);boxInGoal(x,y+2);
								} 
							}
							if(type1(x,y)=='!'){
								if(type1(x,y+1)=='!'){
									goal(x,y);characterInGoal(x,y+1);box(x,y+2);
								}
								if(type1(x,y+1)=='#'){
									goal(x,y);character(x,y+1);box(x,y+2);
								}
							}
						}
					}
					if(type2(x,y+1)=='\0'){
						if(type1(x,y)=='c'){
							if(type1(x,y+1)=='\0'){
								blank(x,y);character(x,y+1);
							}
							if(type1(x,y+1)=='!'){
								blank(x,y);characterInGoal(x,y+1);
							}
						}
						if(type1(x,y)=='!'){
			    			if(type1(x,y+1)=='\0'){
								goal(x,y);character(x,y+1);
							}
							if(type1(x,y+1)=='!'){
								goal(x,y);characterInGoal(x,y+1);
							}
						}
					}
					y++;
				}
				break;
			case '\n':
				continue;
			default:
				printf("Please input 'w,a,s,d'\n");
				break;
				
				
		}
		printmap();
	}
	printf("Success!\n");	
}
	
