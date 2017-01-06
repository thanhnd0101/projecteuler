#include <stdio.h>
#define max 100

void nhapmangsothuc(float s[], int &n);
void doivitri(float &a, float &b);
void vitriletang(float s[], int n);
void xuatmangsothuc(float s[], int n);

int main()
{
	float s[max];
	int n;
	nhapmangsothuc(s, n);
	vitriletang(s, n);
	printf("Vi tri le tang dan trong mang.\n");
	xuatmangsothuc(s, n);
}

void nhapmangsothuc(float s[], int &n)
{
	do {
		printf("Nhap mang so thuc.\n");
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
	} while (n<0);
	for (int i = 0; i<n; i++)
	{
		printf("Nhap phan tu thu %d =", i + 1);
		scanf("%f", &s[i]);
	}
}
void xuatmangsothuc(float s[], int n)
{
	for (int i = 0; i<n; i++)
	{
		printf("Phan tu thu %d = %0.3f\n", i + 1, s[i]);
	}
}
void doivitri(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}
void vitriletang(float s[], int n)
{
	for (int i = 1; i < n; i += 2){
		for (int j = i + 2; j < n; j += 2){
			if (s[j] < s[i]){
				doivitri(s[j], s[i]);
			}
		}
	}
}