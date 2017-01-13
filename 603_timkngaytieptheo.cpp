#include <stdio.h>

void kngay(int ngay, int thang, int nam, int k, int &ngayt, int &thangt, int &namt)
{
	switch (thang)
	{
	case 4:
	case 6: 
	case 9:
	case 11:
		if (ngay + k <= 30)
		{
			ngayt = ngay + k;
			thangt = thang;
			namt = nam;
		}
		else
		{
			ngayt = ngay + k - 30;
			thangt = thang + 1;
			namt = nam;
		}
		return;
	case 2:
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		{
			if (ngay + k <= 29)
			{
				ngayt = ngay + k;
				thangt = thang;
				namt = nam;
			}
			else
			{
				ngayt = ngay + k - 29;
				thangt = thang + 1;
				namt = nam;
			}
		}
		else
		{
			if (ngay <= 28)
			{
				ngayt = ngay + k;
				thangt = thang;
				namt = nam;
			}
			else
			{
				ngayt = ngay + k - 29;
				thangt = thang + 1;
				namt = nam;
			}
		}
		return;
	case 12:
		if (ngay + k <= 31)
		{
			ngayt = ngay + k;
			thangt = thang;
			namt = nam;
		}
		else
		{
			ngayt = ngay + k - 31;
			thangt = 1;
			namt = nam+1;
		}
		return;
	default:
		if (ngay + k <= 31)
		{
			ngayt = ngay + k;
			thangt = thang;
			namt = nam;
		}
		else
		{
			ngayt = ngay + k - 31;
			thangt = thang + 1;
			namt = nam;
		}
		return;
	}
}
//int main()
//{
//	int ngayt, thangt,namt;
//	kngay(25, 12, 2016, 20, ngayt, thangt, namt);
//	printf("%d %d %d", ngayt, thangt, namt);
//	return 0;
//}