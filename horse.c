#include "stdio.h"

#define WIDTH   5//棋盘长度
#define HEIGHT  6//棋盘宽度
#define X   0//初始位置X
#define Y   0//初始位置Y

int width=WIDTH;int height=HEIGHT;
int chess[WIDTH][HEIGHT]={0};//棋盘
int fx[8]={1,1,2,2,-1,-1,-2,-2};int fy[8]={2,-2,1,-1,2,-2,1,-1};//行走方式
int count=0;//可行解数目

void alg(int horse_x,int horse_y,int depth);//回溯算法
void out();//输出函数
int check(int x,int y);//检查下一个位置是否合法的函数


int main(void){
    int horse_x=X;int horse_y=Y;
    chess[horse_x][horse_y]=1;
    alg(horse_x,horse_y,2);

}

void out(){
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf("%d ",chess[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");
}


int check(int x,int y){
    if (x>=0 && x<width && y>=0 && y<height && chess[x][y]==0)//坐标在棋盘内且该位置没有放过
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void alg(int horse_x,int horse_y,int depth){
    if (depth==width*height+1)//已经走完所有可能
    {
        count++;//可行解数目++
        printf("count : %d \n",count);
        out();//输出棋盘
        return;
    }
    for (int  i = 0; i < 8; i++)//尝试八种走法
    {
        int xx=horse_x+fx[i];int yy=horse_y+fy[i];//计算打算到达的目标的坐标
        if (check(xx,yy))//试图到达的位置是否合法？
        {
            chess[xx][yy]=depth;//棋盘对应位置赋予步骤值
            alg(xx,yy,depth+1);//递归计算下一步
            chess[xx][yy]=0;//回溯
        }
        
    }
    
    
}