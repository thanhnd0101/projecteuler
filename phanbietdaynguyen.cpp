#include <stdio.h>
void khongtrung(int s[50], int n, int a[50], int &k)
{
	int min = s[0];
	//tim gia tri nho nhat
	for (int i = 0; i < n; i++)
	{
		if (s[i] < min) min = s[i];
	}
	// chon ra danh sach
	k = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != min - 1)
		{
			a[k++] = s[i];
			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == s[i])
				{
					s[j] = min - 1;
				}
			}
		}
	}
	// sap xep
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (a[j] < a[i])
			{
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
//int main()
//{
//	int s[50] = { 2,2,1,5,4,5,8,9 };
//	int a[50], k;
//	khongtrung(s, 8, a, k);
//	for (int i = 0; i < k; i++)
//	{
//		printf("%-10d", a[i]);
//	}
//}