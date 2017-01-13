#include <stdio.h>
int ngay_1_1_1(int ngay, int thang, int nam, int &songay)
{
	songay = ngay;
	for (int i = 1; i < nam; i++)
	{
		songay += (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) ? 366 : 365;
	}
	for (int i = 1; i < thang; i++)
	{
		switch (i)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			songay += 30;
			break;
		case 2:
			songay += (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) ? 29 : 28;
			break;
		default:
			songay += 31;
			break;
		}
	}
	return songay;
}
