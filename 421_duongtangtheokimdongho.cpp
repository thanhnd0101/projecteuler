#include <stdio.h>
void laybien(int s[][50], int row, int col, int bien[], int &k)
{
	k = 0;
	for (int j = 0; j < col; j++)
	{
		bien[k++] = s[0][j];
	}
	for (int i = 1; i < row; i++)
	{
		bien[k++] = s[i][col - 1];
	}
	for (int j = col - 2; j >= 0; j--)
	{
		bien[k++] = s[row - 1][j];
	}
	for (int i = row - 2; i > 0; i--)
	{
		bien[k++] = s[i][0];
	}
}
void sapxepbien(int bien[], int k)
{
	int tam;
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (bien[i] > 0)
			{
				if (bien[i] > bien[j] && bien[j] > 0)
				{
					tam = bien[i];
					bien[i] = bien[j];
					bien[j] = tam;
				}
			}
		}
	}
}
void duong_dongho(int s[][50], int row, int col, int bien[])
{
	int k = 0;
	for (int j = 0; j < col; j++)
	{
		s[0][j] = bien[k++];
	}
	for (int i = 1; i < row; i++)
	{
		s[i][col - 1] = bien[k++];
	}
	for (int j = col - 2; j >= 0; j--)
	{
		s[row - 1][j] = bien[k++];
	}
	for (int i = row - 2; i > 0; i--)
	{
		s[i][0] = bien[k++];
	}
}