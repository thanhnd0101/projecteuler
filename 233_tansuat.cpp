#include <stdio.h>
#define max 100

void nhapmangnguyen(int s[], int &n);
void xuattansuat(int s[], int ts[], int n);
void tansuat(int s[], int ts[], int n);

int main()
{
	int s[max], ts[max], n;
	nhapmangnguyen(s, n);
	tansuat(s, ts, n);
	xuattansuat(s, ts, n);
}

void nhapmangnguyen(int s[], int &n)
{
	do {
		printf("Nhap mang so thuc.\n");
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
	} while (n < 0);
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d =", i + 1);
		scanf("%d", &s[i]);
	}
}
void xuattansuat(int s[], int ts[], int n)
{
	printf("_______________________\n");
	printf("|%-10s|%-10s|\n", "Gia tri", "Tan suat");
	for (int i = 0; i < n; i++)
	{
		if (ts[i] != 0)
		{
			printf("_______________________\n");
			printf("|%-10d|%-10d|\n", s[i], ts[i]);
		}
	}
	printf("_______________________\n");
}
void tansuat(int s[], int ts[], int n)
{
	int count;
	for (int i = 0; i < n; i++)
	{
		ts[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				count++;
				ts[j] = 0;
			}
		}
		if (ts[i] != 0)
		{
			ts[i] = count;
		}
	}
}