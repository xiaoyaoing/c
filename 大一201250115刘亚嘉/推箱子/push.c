
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<mmsystem.h>
#pragma commen(lib,"winmm.lib")
int m[100][100][2],ch;
int p[4],pb[4];
int a,b,box=0;
int n;
bool IfBack=false,IfBreak=false,IfPlay=false;
void swap(int*,int*);
bool map(int);
void put();
int main() {
    n=0;
    setbuf(stdout, NULL);
    int i,j,k;
    printf("��������ĵ�ͼ��С������ǽ��ǽ�����飬�ԣ��� �У���ʽ���룩:");
    scanf("%d%d",&a,&b);
    printf("��������ĵ�ͼ(0:ǽ��ǽ�� 1���յ� 2���˵�λ�� 3������ 4���յ� 5��ǽ���ϰ�)��\n");
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            scanf("%d",&m[i][j][0]);
            m[i][j][1]=0;
        }
    }
    system("cls");
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            if(m[i][j][0]==0)printf("@  ");
            if(m[i][j][0]==1)printf("   ");
            if(m[i][j][0]==3){
                printf("#  ");
                box++;
            }
            if(m[i][j][0]==4){
                m[i][j][1]=1;
                printf("$  ");
                n++;
                m[i][j][0]=1;
            }
            if(m[i][j][0]==2){
                printf("*  ");
                p[0]=i;p[1]=j;
            }
            if(m[i][j][0]==5){
            	printf("@  ");
            	m[i][j][1]=2;
            	m[i][j][0]=0;
			}
        }
        printf("\n\n");
    }
    printf("@--ǽ��ǽ�����ϰ� #�������� $�����յ� *������ &�����������ڵ��յ�\n");
    printf("1-���� 2������ 3-���� 4-���� \n");
    printf("���ж���");
    scanf("%d",&k);
    while(map(k)==false){
        printf("�������");
        scanf("%d",&k);
    }
    printf("����ˣ�");
    system("pause");
    return 0;
}
bool map(int c){
    if(c==1){
        if(m[p[0]-1][p[1]][0]==1){
            swap(&m[p[0]-1][p[1]][0],&m[p[0]][p[1]][0]);
            ch=1;
            IfBack=false;
            pb[0]=p[0];pb[1]=p[1];
            p[0]--;
            put();
            return false;
        }
        if(m[p[0]-1][p[1]][0]==0)return false;
        if(m[p[0]-1][p[1]][0]==3){
            if(m[p[0]-2][p[1]][0]==1){
                swap(&m[p[0]-2][p[1]][0],&m[p[0]-1][p[1]][0]);
                swap(&m[p[0]][p[1]][0],&m[p[0]-1][p[1]][0]);
                if(m[p[0]-1][p[1]][1]==1)n++;
                if(m[p[0]-2][p[1]][1]==1)n--;
                pb[0]=p[0];pb[1]=p[1];
                ch=11;
                IfBack=false;
                p[0]--;
                put();
                if(n==0)return true;
                else return false;
            }
            if(m[p[0]-2][p[1]][0]==0||m[p[0]-2][p[1]][0]==3)return false;
        }
    }
    if(c==2){
        if(m[p[0]+1][p[1]][0]==1){
            swap(&m[p[0]+1][p[1]][0],&m[p[0]][p[1]][0]);
            pb[0]=p[0];pb[1]=p[1];
            ch=2;
            IfBack=false;
            p[0]++;
            put();
            return false;
        }
        if(m[p[0]+1][p[1]][0]==0)return false;
        if(m[p[0]+1][p[1]][0]==3){
            if(m[p[0]+2][p[1]][0]==1){
                swap(&m[p[0]+2][p[1]][0],&m[p[0]+1][p[1]][0]);
                swap(&m[p[0]][p[1]][0],&m[p[0]+1][p[1]][0]);
                if(m[p[0]+1][p[1]][1]==1)n++;
                if(m[p[0]+2][p[1]][1]==1)n--;
                ch=22;
                IfBack=false;
                pb[0]=p[0];pb[1]=p[1];
                p[0]++;
                put();
                if(n==0)return true;
                else return false;
            }
            if(m[p[0]+2][p[1]][0]==0||m[p[0]+2][p[1]][0]==3)return false;
        }
    }
    if(c==3){
        if(m[p[0]][p[1]-1][0]==1){
            swap(&m[p[0]][p[1]-1][0],&m[p[0]][p[1]][0]);
            pb[0]=p[0];pb[1]=p[1];
            ch=3;
            IfBack=false;
            p[1]--;
            put();
            return false;
        }
        if(m[p[0]][p[1]-1][0]==0)return false;
        if(m[p[0]][p[1]-1][0]==3){
            if(m[p[0]][p[1]-2][0]==1){
                swap(&m[p[0]][p[1]-2][0],&m[p[0]][p[1]-1][0]);
                swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]-1][0]);
                if(m[p[0]][p[1]-1][1]==1)n++;
                if(m[p[0]][p[1]-2][1]==1)n--;
                pb[0]=p[0];pb[1]=p[1];
                ch=33;
                IfBack=false;
                p[1]--;
                put();
                if(n==0)return true;
                else return false;
            }
            if(m[p[0]][p[1]-2][0]==0||m[p[0]][p[1]-2][0]==3)return false;
        }
    }
    if(c==4){
        if(m[p[0]][p[1]+1][0]==1){
            swap(&m[p[0]][p[1]+1][0],&m[p[0]][p[1]][0]);
            pb[0]=p[0];pb[1]=p[1];
            p[1]++;
            IfBack=false;
            ch=4;
            put();
            return false;
        }
        if(m[p[0]][p[1]+1][0]==0)return false;
        if(m[p[0]][p[1]+1][0]==3){
            if(m[p[0]][p[1]+2][0]==1){
                swap(&m[p[0]][p[1]+2][0],&m[p[0]][p[1]+1][0]);
                swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]+1][0]);
                if(m[p[0]][p[1]+1][1]==1)n++;
                if(m[p[0]][p[1]+2][1]==1)n--;
                pb[0]=p[0];pb[1]=p[1];
                p[1]++;
                IfBack=false;
                ch=44;
                put();
                if(n==0)return true;
                else return false;
            }
            if(m[p[0]][p[1]+2][0]==0||m[p[0]][p[1]+2][0]==3)return false;
        }
    }
    if(c==5){
    	if(IfBack){
    		printf("���Ѿ����ع��ˣ�\n");
    		return false;
		}
		else{
			IfBack=true;
	        if(ch==1){
	            swap(&m[p[0]][p[1]][0],&m[p[0]+1][p[1]][0]);
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==2){
	            swap(&m[p[0]][p[1]][0],&m[p[0]-1][p[1]][0]);
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==3){
	            swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]+1][0]);
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==4){
	            swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]-1][0]);
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==11){
	            swap(&m[p[0]+1][p[1]][0],&m[p[0]][p[1]][0]);
	            swap(&m[p[0]][p[1]][0],&m[p[0]-1][p[1]][0]);
	            if(m[p[0]-1][p[1]][1]==1)n++;
	            if(m[p[0]][p[1]][1]==1)n--;
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==22){
	            swap(&m[p[0]-1][p[1]][0],&m[p[0]][p[1]][0]);
	            swap(&m[p[0]][p[1]][0],&m[p[0]+1][p[1]][0]);
	            if(m[p[0]+1][p[1]][1]==1)n++;
	            if(m[p[0]][p[1]][1]==1)n--;
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
	        }
	        if(ch==33){
	            swap(&m[p[0]][p[1]+1][0],&m[p[0]][p[1]][0]);
	            swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]-1][0]);
	            if(m[p[0]][p[1]-1][1]==1)n++;
	            if(m[p[0]][p[1]][1]==1)n--;
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false; 
	        }
	        if(ch==44){
	            swap(&m[p[0]][p[1]-1][0],&m[p[0]][p[1]][0]);
	            swap(&m[p[0]][p[1]][0],&m[p[0]][p[1]+1][0]);
	            if(m[p[0]][p[1]+1][1]==1)n++;
	            if(m[p[0]][p[1]][1]==1)n--;
	            p[0]=pb[0];p[1]=pb[1];
	            put();
	            return false;
        	}
		}
    }
    if(c==6){
    	if(IfBreak){
    		printf("���Ѿ�ʹ�ù��ü����ˣ�\n");
    		return false;
		}
		else{
			if(ch==1){
				if(m[p[0]-1][p[1]][0]==0&&m[p[0]-1][p[1]][1]==2){
					m[p[0]-1][p[1]][0]=1;
					put();
					IfBreak=true;
					return false;
				}
				else{
					printf("����ʹ�ã�\n");
					return false;
				}
			}
			if(ch==2){
				if(m[p[0]+1][p[1]][0]==0&&m[p[0]+1][p[1]][1]==2){
					m[p[0]+1][p[1]][0]=1;
					put();
					IfBreak=true;
					return false;
				}
				else{
					printf("����ʹ�ã�\n");
					return false;
				}
			}
			if(ch==3){
				if(m[p[0]][p[1]-1][0]==0&&m[p[0]][p[1]-1][1]==2){
					m[p[0]][p[1]-1][0]=1;
					put();
					IfBreak=true;
					return false;
				}
				else{
					printf("����ʹ�ã�\n");
					return false;
				}
			}
			if(ch==4){
				if(m[p[0]][p[1]+1][0]==0&&m[p[0]][p[1]+1][1]==2){
					m[p[0]][p[1]+1][0]=1;
					put();
					IfBreak=true;
					return false;
				}
				else{
					printf("����ʹ�ã�\n");
					return false;
				}
			}
		}
	}
	if(c==7){
		if(IfPlay){
			if(1==PlaySound(NULL,NULL,SND_PURGE))
			IfPlay=false;
		}
		else{
			if(1==PlaySound(TEXT("bgm.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC))
			IfPlay=true;
		}
		return false; 
	}
    else {
    	printf("��������ȷ�����\n");
    	return false;
	}
}
void put(){
    system("cls");
    int i,j;
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            if(m[i][j][0]==0){
                printf("@  ");
            }
            if(m[i][j][0]==1){
                if(m[i][j][1]==1)printf("$  ");
                else printf("   ");
            }
            if(m[i][j][0]==2){
                printf("*  ");
            }
            if(m[i][j][0]==3){
                if(m[i][j][1]==1)printf("&  ");
                else printf("#  ");
            }
        }
        printf("\n\n");
    }
    printf("@--ǽ��ǽ�����ϰ� #�������� &�����յ� *������ &�����������ڵ��յ�\n");
    printf("1-���� 2������ 3-���� 4-���� 5�������أ��������ж�һ�κ󳷻�һ�Σ��� 6���������ϰ�����ǰһ���ж�����������Ƶ��ϰ��ҽ���ʹ��һ���Ҳ�����ǽ����7��������/�ر�bgm\n");
}
void swap(int*a1,int*b1){
    int tem;
    tem=*a1;
    *a1=*b1;
    *b1=tem;
}
