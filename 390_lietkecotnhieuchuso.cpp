#include <stdio.h>
#define max 50
void lietketcot(int s[][max], int row, int col,int dem[max])
{
	
	for (int i = 0; i < col; i++)
	{
		dem[i] = 0;
		for (int j = 0; j < row; j++)
		{
			while (s[j][i]!=0)
			{
				s[j][i] /= 10;
				dem[i]++;
			}
		}
	}
}
int main()
{
	int s[][max]
	{
		{1,2,3,4,5},
		{454,3,4,2,4},
		{12,323,1,2,4},
		{5,12,23,23,4}
	};
	int dem[max];
	lietketcot(s, 4, 5, dem);
	int nhieunhat = dem[0];
	for (int i = 0; i < 5; i++)
	{
		if (dem[i] > nhieunhat)nhieunhat = dem[i];
	}
	for (int i = 0; i < 5; i++)
	{
		if (dem[i] == nhieunhat) printf("Cot thu %d\n", i);
	}

	return 0;
}