#include<iostream>  
using namespace std;
int g_count = 0;                                    //记录放置方法总数的变量
													//定义一个bool型函数，判断该位置是否能放置皇后
bool CanPlace(int row, int col, int(*chess)[8])             //row为行数，col为列数
{

	//判断同一行和同一列是否已经有八皇后	
	for (int i = 0; i<8; i++)
	{
		if (chess[i][col] == 1)
		{
			return false;
		}
		if (chess[row][i] == 1)
		{
			return false;
		}
	}

	for (int i = 0; i<8; i++)
	{             //判断左上角是否有皇后 
		if (row - i<0 || col - i<0)
		{	        //判断有没有到边界，如果到了就break
			break;
		}
		if (chess[row - i][col - i] == 1)
		{     //往左上角平移
			return false;
		}
	}

	for (int i = 0; i<8; i++)        //判断右上角是否有皇后，其余和左上角同理
	{
		if (row - i<0 || col + i>7)
		{
			break;
		}
		if (chess[row - i][col + i] == 1)
		{
			return false;
		}

	}

	for (int i = 0; i<8; i++)
	{             //判断左下角是否有皇后，其余和左上角同理
		if (row + i>7 || col - i<0)
		{
			break;
		}
		if (chess[row + i][col - i] == 1)
		{
			return false;
		}
	}


	for (int i = 0; i<8; i++)
	{             //判断右下角是否有皇后，其余和左上角同理
		if (row + i>7 || col + i>7)
		{
			break;
		}
		if (chess[row + i][col + i] == 1)
		{
			return false;
		}
	}

	return true;
}

void EightQueen(int row, int col, int(*chess)[8])
{           //定义输出函数
	int chess2[8][8];                              //定义一个用于输出的二维数组
	for (int i = 0; i<8; i++)
	{                       //将原数组赋给新定义的数组
		for (int j = 0; j<8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (row == 8)
	{                            //输出部分，如果行数为8，则输出
		for (int i = 0; i<8; i++)
		{
			for (int j = 0; j<8; j++)
			{
				cout << chess2[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		g_count++;                        //放置方法总数+1
	}
	else
	{
		for (int j = 0; j<8; j++)
		{
			if (CanPlace(row, j, chess2))
			{
				chess2[row][j] = 1;               //放置皇后 
				EightQueen(row + 1, j, chess2);  //利用递归进入下一行，将目前的数组传入下一层  
				chess2[row][j] = 0;  //递归下一层完毕后，将该位置置为0，类似出栈
			}
		}
	}
};

int main()
{
	int chess[8][8] = { 0 };                      //初始化二维数组全为0
		EightQueen(0, 0, chess);                     //调用输出函数，行列都为0
	cout << g_count << endl;                    //输出放置方法总数
	system("pause");
	return 0;
}
