#include <stdio.h>

void ngay(int nam, int songay, int &ngay,int &thang)
{
	ngay = songay;
	for (int i = 1; i <= 12; i++)
	{
		thang = i;
		switch (i)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (ngay <= 30) return;
			else ngay -= 30;
			break;
		case 2:
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
			{
				if (ngay <= 29) return;
				else ngay -= 29;
			}
			else
			{
				if (ngay <= 28) return;
				else	ngay -= 28;
			}
			break;
		default: 
			if (ngay <= 31) return;
			else ngay -= 31;
			break;
		}
	}
}
