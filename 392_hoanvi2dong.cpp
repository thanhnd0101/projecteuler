#include <stdio.h>

void hoanvi(int s[][50], int row1, int row2, int col)
{
	int tam;
	for (int i = 0; i < col; i++)
	{
		tam = s[row1][i];
		s[row1][i] = s[row2][i];
		s[row2][i] = tam;
	}
}
int main()
{
	int s[][50]=
	{
		{2,3,5,6,4},
		{45,3,1,5,5},
		{98,6,4,5,3}
	};
	hoanvi(s, 0, 2, 5);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%-10d", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}