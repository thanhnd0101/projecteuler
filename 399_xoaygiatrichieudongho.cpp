#include <stdio.h>
#define max 50
void xoaykimdongho(int s[max][max],int row,int col)
{
	int temp=s[0][col-1];
	int tam1,tam2;
	tam1=s[0][0];
	for (int j=0;j<col-1;j++)
	{
		tam2=s[0][j+1];
		s[0][j+1]=tam1;
		tam1=tam2;
	}
	for(int i=0;i<row-1;i++)
	{
		tam2=s[i+1][col-1];
		s[i+1][col-1]=tam1;
		tam1=tam2;
	}
	for(int j=col-1;j>0;j--)
	{
		tam2=s[row-1][j-1];
		s[row-1][j-1]=tam1;
		tam1=tam2;
	}
	for(int i=row-1;i>0;i--)
	{
		tam2=s[i-1][0];
		s[i-1][0]=tam1;
		tam1=tam2;
	}
}
int main()
{
	int s[][max]=
	{
		{75,62,54,87},
		{40,33,28,46},
		{18,15,10,20},
		{67,53,23,-20}
	};
	xoaykimdongho(s,4,4);
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%-10d",s[i][j]);
		}
		printf("\n");
	}
}
