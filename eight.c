#define SIZE    10//皇后数目
#include "stdio.h"


int queenes[SIZE]={0},counts=0;//queenes指示皇后位置，counts存储解的数目

int check_position(int row,int col){
    for (int i = 0; i < row; i++)
    {
        int data=queenes[i];//取出皇后的位置
        if (col==data)//与之前的皇后在同一列？
        {
            return 0;
        }
        if((i+data)==(row+col)||(i-data)==(row-col)){//与之前的皇后在同一对角线？
            return 0;
        }

    }
    return 1;
    
}

void print(void){//打印棋盘
    for(int row=0;row<SIZE;row++){
        for (int col = 0; col<SIZE ;col++)
        {
            if (col==queenes[row])
            {
                    printf("Q");
                    continue;
            }
            
            printf("口");
        }
        printf("\n");
        
        
    }
    printf("===================\n");
}

void alg(int row){//输入row表示安排第row行的皇后位置
    for (int col = 0; col < SIZE; col++)//考虑每一列
    {
        if (check_position(row,col))//当前位置能否放置？
        {//能：
            queenes[row]=col;//放在棋盘上
            if (row==SIZE-1)//已经放了八个皇后？
            {
                counts++;//可行解++
                print();//打印棋盘
                queenes[row]=0;//回溯
                return;
            }
            //还没放满八个皇后：
            alg(row+1);//递归放下一个
            queenes[row]=0;//回溯
            
        }
        
    }
    
}

int main(void){
    printf("42012226 张笑晨\n");
    alg(0);
    printf("num of result is : %d\n",counts);
}