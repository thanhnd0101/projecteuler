#include <stdio.h>
#define max 100
void nhapmang2nguyen(int arr[][max], int &row, int &col)
{
	do
	{
		printf("Nhap vao so dong: ");
		scanf_s("%d", &row);
		printf("Nhap vao so cot: ");
		scanf_s("%d", &col);
	} while (row < 0 || col < 0);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Nhap phan tu thu [%d][%d]:", i,j);
			scanf_s("%d", &arr[i][j]);
		}
	}
}
void xuatmang2nguyen(int arr[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Phan tu thu arr[%d][%d]: %d", i, j, arr[i][j]);
		}
	}
}
bool kiemtracucdai(int arr[][max], int row, int col, int vtrow, int vtcol)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (vtrow + i >= 0 && vtcol + j >= 0 && vtrow+i<row && vtcol+i<col && !(i == 0 && j == 0))
			{
				if (arr[vtrow][vtcol] < arr[vtrow + i][vtcol + j]) return false;
			}
		}
	}
	return true;
}
void duongbien(int arr[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (kiemtracucdai(arr, row, col, i, j) == true)
				printf("%d\t", arr[i][j]);
		}
	}
}
int main()
{
	int arr[max][max];
	int row, col;
	nhapmang2nguyen(arr, row, col);
	printf("Phan tu cuc dai trong ma tran la: \n");
	duongbien(arr, row, col);
}