#include "xuly.h"
#define max 50
void nhapmang(int arr[][max], int &row, int &col)
{
	do
	{
		printf("Nhap so dong: ");
		scanf_s("%d", &row);
		printf("Nhap so cot: ");
		scanf_s("%d", &col);
	} while (row < 0 || col < 0);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Nhap phan tu thu [%d][%d]: ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}
}
void xuatmang(int arr[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-10d", arr[i][j]);
		}
		printf("\n");
	}
}
int Tongmang(int arr[][max], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
int Tansophantu(int arr[][max], int row, int col, int x)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == x) count++;
		}
	}
	return count;
}
int Tansonguyenduong(int arr[][max], int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > 0) count++;
		}
	}
	return count;
}
int tong_khong_am(int arr[][max], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] >= 0) sum += arr[i][j];
		}
	}
	return sum;
}
int tongcheochinh(int arr[][max], int row, int col)
{
	if (row != col) return -1;
	int sum = 0;
	int i = 0;;
	for (int j = 0; j < col;)
	{
		sum += arr[i][j];
		i++;
		j++;
	}
	return sum;
}
int tongcheophu(int arr[][max], int row, int col)
{
	if (row != col) return -1;
	int sum = 0;
	int i = row - 1;;
	for (int j = 0; j < col;)
	{
		sum += arr[i][j];
		i--;
		j++;
	}
	return sum;
}
void tangtrendong(int arr[][max], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][k] < arr[i][j])
					swap(arr[i][k], arr[i][j]);
			}
		}
	}
}
void tichmatran(int arr1[][max], int row1, int col1, int arr2[][max], int col2, int arr3[][max])
{
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			arr3[i][j] = 0;
			for (int k = 0; k < col1; k++)
			{
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
}
void congmatran(int arr1[][max], int row, int col, int arr2[][max], int arr3[][max])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr3[i][j] = 0;
			arr3[i][j] += arr1[i][j] + arr2[i][j];
		}
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void cottang_hanggiam(int arr[][max], int row, int col)
{
	//Tang tren cot
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int k = i + 1; k < row; k++)
			{
				if (arr[k][j] < arr[i][j])
					swap(arr[k][j], arr[i][j]);
			}
		}
	}
	//Giam tren dong
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][k] > arr[i][j])
					swap(arr[i][k], arr[i][j]);
			}
		}
	}
}
void cottang_hangtang(int arr[][max], int row, int col)
{
	//Tang tren cot
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int k = i + 1; k < row; k++)
			{
				if (arr[k][j] < arr[i][j])
					swap(arr[k][j], arr[i][j]);
			}
		}
	}
	//Tang tren dong
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = j + 1; k < col; k++)
			{
				if (arr[i][k] < arr[i][j])
					swap(arr[i][k], arr[i][j]);
			}
		}
	}
}
//void nhap_n_matran(int arr[][max][max], int &n, int row[], int col[])
//{
//	do
//	{
//		printf("Nhap n: ");
//		scanf_s("%d", &n);
//	} while (n < 0);
//	for (int i = 0; i < n; i++)
//	{
//		printf("Nhap mang thu %d: \n", i);
//		do
//		{	printf("Nhap so dong: ");
//			scanf_s("%d", &row[i]);
//			printf("Nhap so cot: ");
//			scanf_s("%d", &col[i]);
//		} while (row[i] < 2 || col[i] < 1);
//		for (int j = 0; j < row[i]; j++)
//		{
//			for (int k = 0; k < col[i]; k++)
//			{
//				printf("Phan tu [%d][%d]: ", j, k);
//				scanf_s("%d", &arr[i][j][k]);
//			}
//		}
//	}
//}
//void tich_n_matran(int arr[][max][max], int n, int row[], int col[], int arr2[][max], int &dong,int &cot)
//{
//	for (int i = 0; i < max; i++)
//	{
//		for (int j = 0; j < max; j++)
//		{
//			arr2[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < n-1 ; i++)
//	{
//		if (col[i] != row[i + 1])
//		{
//			printf("Khong the tinh tich vi khong thoa dieu kien tich ma tran.\n");
//			return;
//		}
//		else
//		{
//			dong = row[i];
//			cot = col[i + 1];
//			for (int j = 0; j < row[i]; j++)
//			{
//				for (int k = 0; k < col[i+1]; k++)
//				{
//					for (int m = 0; k < col[i+1]; m++)
//					{
//						arr2[j][k] += arr[i][j][m] * arr[i][m][k];
//					}
//				}
//			}
//		}
//	}
//}

void xoay_matran(int arr[][max], int row, int col, int arr2[][max], int &row2, int &col2)
{
	int temp;
	row2 = col;
	col2 = row;
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			arr2[i][j] = arr[row - 1 - j][i];
		}
	}
}
void xoay_matran_n(int arr[][max], int row, int col, int arr2[][max], int row2[max], int col2[max], int n)
{
	if (n == 1)
	{
		xoay_matran(arr, row, col, arr2, row2[0], col2[0]);
		return;
	}
	else
	{
		int k;
		xoay_matran(arr, row, col, arr2, row2[0], col2[0]);
		for (int i = 0; i < row2[0]; i++)
		{
			for (int j = 0; j < col2[0]; j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}
		for (k = 1; k < n; k++)
		{
			for (int i = 0; i < row2[k - 1]; i++)
			{
				for (int j = 0; j < col2[k - 1]; j++)
				{
					arr[i][j] = arr2[i][j];
				}
			}
			xoay_matran(arr, row2[k - 1], col2[k - 1], arr2, row2[k], col2[k]);
		}
	}
}
void xoa_cot(int arr[][max], int row, int &col, int cot)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = cot - 1; j < col - 1; j++)
		{
			arr[i][j] = arr[i][j + 1];
		}
	}
	col--;
}
void xoa_hang(int arr[][max], int &row, int col, int hang)
{
	for (int i = hang - 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}
	row--;
}
void trungnhau(int arr[][max], int row, int col, int arr2[][max], int row2, int col2)
{
	int flag;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			flag = 0;
			for (int k = 0; k < row2; k++)
			{
				for (int m = 0; m < col2; m++)
				{
					if (arr[i][j] == arr2[k][m])
					{
						flag = 1;
						arr2[k][m] = 0;
					}
				}
			}
			if (flag == 1) arr[i][j] = 0;
		}
	}
}
int nhonhat_dong(int arr[][max], int row, int col)
{
	int i = row, min = arr[row][0];
	for (int j = 0; j < col - 1; j++)
	{
		for (int k = j + 1; k < col; k++)
		{
			if (arr[i][k] < min) min = arr[i][k];
		}
	}
	return min;
}
int nhonhat_cot(int arr[][max], int row, int col)
{
	int min = arr[0][col], i = col;
	for (int j = 0; j < row - 1; j++)
	{
		for (int k = j + 1; k < row; k++)
		{
			if (arr[k][i] < min) min = arr[k][i];
		}
	}
	return min;
}
int nhonhat_mang(int arr[][max], int row, int col)
{
	int min = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}
	}
	return min;
}