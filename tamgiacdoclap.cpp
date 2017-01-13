#include <stdio.h>
#include <math.h>
struct diem
{
	float x;
	float y;
};
struct tamgiac
{
	diem a;
	diem b;
	diem c;
};
float khoangcach(diem A, diem B)
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}
float dttamgiac(diem A, diem B, diem C)
{
	float ca, cb, cc;
	ca = khoangcach(C, B);
	cb = khoangcach(A, C);
	cc = khoangcach(A, B);
	float p = (ca + cb + cc) / 2.0;
	return sqrt(p*(p - ca)*(p - cb)*(p - cc));
}
void tamgiacdoclap(diem ndiem[50], int n,diem &A,diem &B, diem &C)
{
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				for (int m = 0; m < n; m++)
				{
					int flag = 1;
					if (m != i && m != j && m != k)
					{
						int tong = dttamgiac(ndiem[m], ndiem[i], ndiem[j]) + dttamgiac(ndiem[m], ndiem[i], ndiem[k])
							+ dttamgiac(ndiem[m], ndiem[j], ndiem[k]);
						if (tong == dttamgiac(ndiem[i], ndiem[j], ndiem[k]))
						{
							flag = 0;
							break;
						}
					}
					if (flag == 1)
					{
						A = ndiem[i];
						B = ndiem[j];
						C = ndiem[k];
						return;
					}
				}
			}
		}
	}
}
