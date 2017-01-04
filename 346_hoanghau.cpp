#include <stdio.h>
#define max 10
bool maxrow(int arr[][max], int row, int col, int vtrow, int vtcol);
bool maxcol(int arr[][max], int row, int col, int vtrow, int vtcol);
int main()
{
	int arr[max][max];
	FILE *mang = fopen("mang.txt", "r");
	if (mang == NULL)
	{
		printf("Some problem in opening file.\n");
		fclose(mang);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				fscanf(mang, "%d", &arr[i][j]);
			}
		}

	}
}
bool maxrow(int arr[][max], int row,int col, int vtrow,int vtcol)
{
	for (int i = 0; i < col; i++)
	{
		if (arr[row][i] > arr[vtrow][vtcol]) return false;
	}
	return true;
}
bool maxcol(int arr[][max], int row, int col, int vtrow, int vtcol)
{
	for (int i = 0; i < row; i++)
	{
		if (arr[i][col] > arr[vtrow][vtcol]) return false;
	}
	return true;
}
bool maxdiagonal(int arr[][max], int row, int col, int vtrow, int vtcol)
{
	int m = vtcol - vtrow;
	if (m > 0)
	{
		for (int i = 0; i < row;)
		{
			for (int j = m; j < col;)
			{
				if (arr[i][j] > arr[vtrow][vtcol]) return false;
				i--;
				j--;
			}
		}
	}
	else
	{
		for (int i = -m; i < row;)
		{
			for (int j = 0; j < col;)
			{
				if (arr[i][j] > arr[vtrow][vtcol]) return false;
				i--;
				j--;
			}
		}
	}


}