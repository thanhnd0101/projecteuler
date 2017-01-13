#include <stdio.h>

void tanso(int s[][50], int row, int col, int ts[][50],int itnhat[50],int &e)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ts[i][j] = -1;
		}
	}

	int count;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			count = 1;
			for (int h = 0; h < row; h++)
			{
				for (int g = 0; g < col; g++)
				{
					if (s[h][g] == s[i][j] && i != h&&j != g)
					{
						count++;
						ts[h][g] = 0;
					}
				}
			}
			if (ts[i][j] != 0)
			{
				ts[i][j] = count;
			}
		}
	}
	int min = ts[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (ts[i][j] < min && ts[i][j] != 0)
			{
				min = ts[i][j];
			}
		}
	}
	e = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (ts[i][j] == min)
			{
				itnhat[e++] = s[i][j];
			}
		}
	}
}
//int main()
//{
//	int s[50][50] =
//	{
//		{ 2,3,5,3,48,67,48,23,12 },
//		{ 36,3,1,51,56,25,36,48,14 },
//		{ 98,66,45,5,3,56,5,68,53 },
//	};
//	
//	int ts[50][50],itnhat[100],e, k;
//	tanso(s, 3, 9, ts, itnhat, e);
//	for (int i = 0; i < e; i++)
//	{
//		printf("%d ", itnhat[i]);
//	}
//	return 0;
//}