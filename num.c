#include <stdio.h>
int main()
{
    printf("42012226\t 张笑晨\n结果：");
    int A[101]={0};
    int B[101]={0};//结果数组 
    int i,j,k,n,r;
    A[1]=1;//A数组初始化
    n=1;   
    i=1; 
    while(A[1]<=9){  
	    if(i>=n){//发现有更大的满足条件的高精度数据 
            n=i;//转存到数组B中
            for(k=1;k<=n;k++)  
                B[k]=A[k];
        }
        i++;
        r=0;
        for(j=1;j<=i;j++){//检查第i位是否满足条件 
		    r=r*10+A[j]; 
		    r%=i;
        }
        if(r!=0){//若不满足条件 
            A[i]+=(i-r);//第i位可能的解
            while(A[i]>9 && i>1){//搜索完第i位的解，回溯到前一位 
			    A[i]=0;  
                i--;
                A[i]+=i;
            }   
        }
    }
for (k=1;k<=n;k++) 
    printf("%d",B[k]);
printf("\n");
return 0;
} 
