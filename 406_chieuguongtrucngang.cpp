#include <stdio.h>
void doidong(int s[][50], int row1, int row2, int col)
{
	int tam;
	for (int i = 0; i < col; i++)
	{
		tam = s[row1][i];
		s[row1][i] = s[row2][i];
		s[row2][i] = tam;
	}
}
void guong_ngang(int s[][50], int row, int col)
{
	for (int i = 0; i < row / 2; i++)
	{
		doidong(s, i, row - 1 - i, col);
	}
}