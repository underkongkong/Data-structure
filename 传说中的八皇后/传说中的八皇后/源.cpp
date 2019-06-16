#include<iostream>  
using namespace std;
int g_count = 0;                                    //��¼���÷��������ı���
													//����һ��bool�ͺ������жϸ�λ���Ƿ��ܷ��ûʺ�
bool CanPlace(int row, int col, int(*chess)[8])             //rowΪ������colΪ����
{

	//�ж�ͬһ�к�ͬһ���Ƿ��Ѿ��а˻ʺ�	
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
	{             //�ж����Ͻ��Ƿ��лʺ� 
		if (row - i<0 || col - i<0)
		{	        //�ж���û�е��߽磬������˾�break
			break;
		}
		if (chess[row - i][col - i] == 1)
		{     //�����Ͻ�ƽ��
			return false;
		}
	}

	for (int i = 0; i<8; i++)        //�ж����Ͻ��Ƿ��лʺ���������Ͻ�ͬ��
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
	{             //�ж����½��Ƿ��лʺ���������Ͻ�ͬ��
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
	{             //�ж����½��Ƿ��лʺ���������Ͻ�ͬ��
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
{           //�����������
	int chess2[8][8];                              //����һ����������Ķ�ά����
	for (int i = 0; i<8; i++)
	{                       //��ԭ���鸳���¶��������
		for (int j = 0; j<8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if (row == 8)
	{                            //������֣��������Ϊ8�������
		for (int i = 0; i<8; i++)
		{
			for (int j = 0; j<8; j++)
			{
				cout << chess2[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		g_count++;                        //���÷�������+1
	}
	else
	{
		for (int j = 0; j<8; j++)
		{
			if (CanPlace(row, j, chess2))
			{
				chess2[row][j] = 1;               //���ûʺ� 
				EightQueen(row + 1, j, chess2);  //���õݹ������һ�У���Ŀǰ�����鴫����һ��  
				chess2[row][j] = 0;  //�ݹ���һ����Ϻ󣬽���λ����Ϊ0�����Ƴ�ջ
			}
		}
	}
};

int main()
{
	int chess[8][8] = { 0 };                      //��ʼ����ά����ȫΪ0
		EightQueen(0, 0, chess);                     //����������������ж�Ϊ0
	cout << g_count << endl;                    //������÷�������
	system("pause");
	return 0;
}
