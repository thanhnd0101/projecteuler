#include <stdio.h>
#define max 10
int min(int arr[][max], int row, int col);
void dem(int arr[][max], int row, int col, int arr2[], int min, int &len);
int main()
{
	int arr[10][10];
	int arr2[100];
	int minx, len=0;
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
		minx = min(arr, 4, 5);
		dem(arr, 4, 5, arr2, minx,len);
		for (int i = 0; i < len; i++)
		{
			printf("%d ",arr2[i]);
		}
		fclose(mang);
	}
	return 0;
}
int min(int arr[][max], int row, int col)
{
	int min = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
		}
	}
	return min;
}
void dem(int arr[][max], int row, int col, int arr2[], int min, int &len)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] != min - 1)
			{
				arr2[len++] = arr[i][j];
			
			}
			for (int k = 0; k < 4; k++)
			{
				for (int m = 0; m < 5; m++)
				{
					if (arr[k][m] == arr[i][j] && k!=i && m!=j)
					{
						arr[k][m] = min - 1;
					}
				}
			}
		}
	}
}
