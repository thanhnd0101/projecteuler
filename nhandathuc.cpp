#include <stdio.h>

struct donthuc
{
	float a;
	int n;
};
struct dathuc
{
	float a[50]; // mang cac he so
	int n; // so bac cao nhat
};
void nhapdathuc(dathuc &A)
{
	do
	{
		printf("Nhap bac da thuc: ");
		scanf_s("%d", &A.n);
	} while (A.n < 1);
	for (int i = 0; i <= A.n; i++)
	{
		printf("Nhap he so tai x^%d:", i);
		scanf_s("%f", &A.a[i]);
	}
}
void xuatdathuc(dathuc A)
{
	int i;
	for ( i = 0; i < A.n; i++)
	{
		printf("%3.1f*x^%d + ", A.a[i], i);
	}
	printf("%3.1f*x^%d \n", A.a[A.n], i);
}
dathuc tong_don(donthuc A, donthuc B)
{
	dathuc C;
	for (int i = 0; i <= (A.n > B.n) ? A.n : B.n; i++)
	{
		C.a[i] = (i == A.n) ? A.a : 0 + (i == B.n) ? B.a : 0;
		C.n = i;
	}
	return C;
}

dathuc tong_da(dathuc A, dathuc B)
{
	dathuc C;
	for (int i = 0; i <= ((A.n > B.n) ? A.n : B.n); i++)
	{
		C.a[i] = ((i <= A.n) ? A.a[i] : 0) + ((i <= B.n) ? B.a[i] : 0);
		C.n = i;
	}
	return C;
}
dathuc nhandathuc(dathuc A, dathuc B)
{
	dathuc C;
	C.n = A.n + B.n;
	for (int i = 0; i <= C.n; i++)
	{
		C.a[i] = 0;
	}
	for (int vtpt = 0; vtpt <= C.n; vtpt++)
	{
		for (int i = 0; i <= B.n; i++)
		{
			for (int j = 0; j <= A.n; j++)
			{
				if (i + j == vtpt) C.a[vtpt] += A.a[j] * B.a[i];
			}
		}
	}
	return C;
}
int main()
{
	dathuc A,B;
	nhapdathuc(A);
	xuatdathuc(A);
	nhapdathuc(B);
	xuatdathuc(B);
	xuatdathuc(tong_da(A, B));
	xuatdathuc(nhandathuc(A, B));
	return 0;
}