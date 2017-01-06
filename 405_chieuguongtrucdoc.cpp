#include <stdio.h>
void doicot(int s[][50], int col1, int col2, int row)
{
	int tam;
	for (int i = 0; i < row; i++)
	{
		tam = s[i][col1];
		s[i][col1] = s[i][col2];
		s[i][col2] = tam;
	}
}
void guong_doc(int s[][50], int row, int col)
{
	for (int i = 0; i < col / 2; i++)
	{
		doicot(s, i, col - 1 - i, row);
	}
}