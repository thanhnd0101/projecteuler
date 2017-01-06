#include <stdio.h>
void laygiatri(int s[][50], int row, int col, int bien[50], int &k)
{
	k = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			bien[k++] = s[i][j];
		}
	}
}
void sapxep(int bien[50], int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		int min = bien[i];
		for (int j = i + 1; j < k; j++)
		{
			if (bien[j] < bien[i])
			{
				int tam = bien[j];
				bien[j] = bien[i];
				bien[i] = tam;
			}
		}
	}
}
void xoan_oc(int s[][50], int row, int col, int bien[50])
{
	int cdt = 0, cdd = row - 1, cct = 0, ccp = col - 1;
	int k = 0;
	for (int m = 0; m <= row / 2; m++)
	{
		for (int j = cct; j <= ccp; j++)
		{
			int i = cdt;
			s[i][j] = bien[k++];
		}
		cdt++;
		for (int i = cdt; i <= cdd; i++)
		{
			int j = ccp;
			s[i][j] = bien[k++];
		}
		if (m == row / 2) return;
		ccp--;
		for (int j = ccp; j >= cct; j--)
		{
			int i = cdd;
			s[i][j] = bien[k++];
		}
		cdd--;
		for (int i = cdd; i >= cdt; i--)
		{
			int j = cct;
			s[i][j] = bien[k++];
		}
		cct++;
	}
}

//int main()
//{
//	int bien[50], k;
//	int s[50][50] =
//	{
//		{ 2,30,5,6,48,67,48,23,12 },
//		{ 36,3,1,51,56,25,36,48,14 },
//		{ 98,66,45,5,3,56,4,68,53 },
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			printf("%-10d", s[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	laygiatri(s, 3, 9, bien, k);
//	printf("\n");
//	for (int j = 0; j < k; j++)
//		{
//			printf("%-10d", bien[j]);
//		}
//	printf("\n");
//	printf("\n");
//	printf("\n");
//	sapxep(bien, k);
//	printf("\n");
//	for (int j = 0; j < k; j++)
//		{
//			printf("%-10d", bien[j]);
//		}
//	printf("\n");
//	printf("\n");
//	printf("\n");
//	xoan_oc(s, 3, 9, bien);
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			printf("%-10d", s[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}