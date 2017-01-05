#include <stdio.h>
#define max 10

int ktcuctri(int arr[][max], int row, int col, int vtrow, int vtcol);
int main()
{
	int count=0;
	int arr[max][max];
	FILE *mang = fopen("mang.txt", "r");
	if (mang == NULL)
	{
		printf("Something wrong in opening file.\n");
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
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (ktcuctri(arr, 4, 5, i, j) == 1) {
					printf("%d  ", arr[i][j]);
					count++;
				}
			}
		}
		if (count != 0)
		{
			printf("So luong phan tu cuc tri trong ma tran la : %d\n", count);
		}
	}
	fclose(mang);
	return 0;
}
int ktcuctri(int arr[][max], int row, int col, int vtrow, int vtcol)
{
	int flagctieu = 1;
	int flagcdai = 1;
	for (int i = vtrow - 1; i <= vtrow +1; i++)
	{
		for (int j = vtcol - 1; j <= vtcol+1; j++)
		{
			if (arr[vtrow][vtcol] < arr[i][j] && i >= 0 && j >= 0 && i < row && j < col )
			{
				flagcdai = 0;
			}
			if (arr[vtrow][vtcol] > arr[i][j] && i >= 0 && j >= 0 && i < row && j < col )
			{
				flagctieu = 0;
			}
		}
	}
	if (flagcdai == 1 || flagctieu == 1) return 1;
	else return 0;
}