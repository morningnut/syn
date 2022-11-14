#include <stdio.h>
#include <string.h>
#define MAX 1000
int max(int x,int y){//max函数
	return x>y?x:y;
}
int n=4;								//作业数
int a[MAX]={0,5,12,4,8} ;				//作业在M1上的执行时间，从数组下标1开始
int b[MAX]={0,6,2,14,7} ;				//作业在M2上的执行时间，从数组下标1开始
int bestf;								//存放最优的调度时间
int f1;
int f2[MAX];
int x[MAX];								//当前的调度方案 
int bestx[MAX];							//存放当前作业的最优调度方案 
void swap(int *x,int *y)				//交换函数
{
	int temp=*x;
	*x=*y;
	*y=temp;
 }
void alg(int i)						//从第i层开始使用深度优先遍历
{
	if(i>n)							//达到叶子节点，产生一种调度方案 
	{
		if(f2[n]<bestf)//若当前达到局部最优
		{
			bestf=f2[n];
			for(int j=1;j<=n;j++)
			{
				bestx[j]=x[j];
			}
		 } 
	 }
	else{
		for(int j=i;j<=n;j++)			//未达到叶子节点，考虑其他方案 
		{
			swap(&x[i],&x[j]);
			f1+=a[x[i]];				//在第i层选择执行作业x[i],在M1上的执行时间 
			f2[i]=max(f1,f2[i-1])+b[x[i]]; 
			if(f2[i]<bestf)
			{
				alg(i+1);				//仅仅扩展调度时间小于bestf(最优调度时间)的节点 
			 } 
			f1-=a[x[i]];				//回溯，撤销对作业x[i]的选择，重新考虑其他作业
			swap(&x[i],&x[j]); 
		}
	} 
 } 
int main(){
	printf("42012226\t张笑晨\n");
	f1=0;
	bestf=999999;					//初始时的作业最优调度时间为无穷大
	memset(f2,0,sizeof(f1));			//初始f2数组中的执行时间为0
	for(int k=1;k<=n;k++){				//初始时作业的执行顺序：1，2、、、n 
		x[k]=k;
	} 
	alg(1);								//从作业1开始调度
	printf("最优调度时间为：%d\n最优调度方案为：",bestf);
	for(int j=1;j<=n;j++){
		printf("%d ",bestx[j]);
	}
	printf("\n");
	return 0;
}