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
                printf("������ɼ����ո�ֿ���-1 �˳���");
	for(;;)
            {   
				scanf("%d",&n);
				
				if(n==-1) 
				   break;
				   
				a[n] = a[n]+1;
				
            }
	for(int i=1;i<=100;i++)
		if( a[i]!= 0 )
            printf("���� %d �� %d ��\n",i,a[i]);

	return 0; 
}