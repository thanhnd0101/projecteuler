#include <stdio.h>	
#include <math.h>

void kc_min(int s[][50], int n, int giatri[2])
{
	int kc = abs(s[0][0] - s[0][1]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			for (int m = j+1; m < n; m++)
			{
				int tam = abs(s[i][j] - s[i][m]);
				if (tam < kc && s[i][j]!=s[i][m]) kc = tam;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			for (int m = j + 1; m < n; m++)
			{
				if (abs(s[i][j] - s[i][m]) == kc)
				{
					giatri[0] = s[i][j];
					giatri[1] = s[i][m];
					return;
				}
			}
		}
	}
}
//int main()
//{
//	int s[50][50]=
//	{
//		{12,78,48,57,43},
//		{23,66,45,54,12},
//		{465,66,78,14,33},
//		{56,76,9,25,44},
//		{34,67,65,87,43}
//	};
//	int giatri[2];
//	kc_min(s, 5, giatri);
//	printf("%d %d", giatri[0], giatri[1]);
//
//	return 0;
//}