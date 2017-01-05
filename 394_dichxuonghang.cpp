#include <stdio.h>

void dichxoayvong(int s[][50], int row, int col)
{
	int tam[50];
	for (int j = 0; j < col; j++)
	{
		tam[j] = s[row - 1][j];
	}
	for (int i = row-2; i >=0 ; i--)
	{
		for (int j = 0; j < col; j++)
		{
			s[i + 1][j] = s[i][j];
		}
	}
	for (int j = 0; j < col; j++)
	{
		s[0][j] = tam[j];
	}
}
int main()
{
	int s[50][50]=
	{
		{ 2,3,5,6,4 },
		{ 45,3,1,5,5 },
		{ 98,6,4,5,3 },
		{5,6,4,8,6}
	};
	dichxoayvong(s, 4, 5);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%-10d", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
