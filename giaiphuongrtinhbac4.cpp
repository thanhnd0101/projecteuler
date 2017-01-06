#include <stdio.h>
#include <math.h>
// -1 vo nghiem
// 1 vo so nghiem
int bac4(float a, float b, float c, float nghiem[4], int &k)
{
	k = 0;
	float t1, t2, denta;
	int flag1, flag2;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (c == 0)
			{
				nghiem[k++] = 0;
			}
			else
			{
				if ((c > 0 && b > 0) || (c < 0 && b < 0))
				{
					return -1;
				}
				if ((c > 0 && b < 0) || (c < 0 && b>0))
				{
					nghiem[k++] = -sqrt(-c / b);
					nghiem[k++] = sqrt(-c / b);
				}
			}
		}
	}
	else
	{
		denta = b*b - 4 * a*c;
		if (denta < 0)
		{
			return -1;
		}
		else if (denta == 0)
		{
			t1 = -b / (2.0 * a);
			if (t1 < 0)
			{
				return -1;
			}
			else if (t1 == 0)
			{
				nghiem[k++] = 0;
			}
			else
			{
				nghiem[k++] = -sqrt(t1);
				nghiem[k++] = sqrt(t1);
			}
		}
		else
		{
			t1 = (-b - sqrt(denta)) / (2 * a);
			t2 = (-b + sqrt(denta)) / (2 * a);
			if (t1 < 0)
			{
				flag1 = -1;
			}
			else if (t1 == 0)
			{
				nghiem[k++] = 0;
				flag1 = 1;
			}
			else
			{
				nghiem[k++] = -sqrt(t1);
				nghiem[k++] = sqrt(t1);
				flag1 = 1;
			}
			if (t2 < 0)
			{
				flag2 = -1;
			}
			else if (t2 == 0)
			{
				nghiem[k++] = 0;
				flag2 = 1;
			}
			else
			{
				nghiem[k++] = -sqrt(t2);
				nghiem[k++] = sqrt(t2);
				flag2 = 1;
			}
			if (flag1 == -1 && flag2 == -1)
			{
				return -1;
			}
		}
	}
}