#include <iostream> 
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

using namespace std;

int main() 
{ 
	int a[101]={0};
	int n;
                printf("请输入成绩，空格分开，-1 退出：");
	for(;;)
            {   
				scanf("%d",&n);
				
				if(n==-1) 
				   break;
				   
				a[n] = a[n]+1;
				
            }
	for(int i=1;i<=100;i++)
		if( a[i]!= 0 )
            printf("分数 %d 的 %d 人\n",i,a[i]);

	return 0; 
}