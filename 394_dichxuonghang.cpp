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

