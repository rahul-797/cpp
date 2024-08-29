#include <stdio.h>
#include <math.h>
#define SIZE 4
void main()
{
	int i,j,d,a[SIZE][SIZE];
	long int deter(int b[SIZE][SIZE],int n);
	void print(int b[SIZE][SIZE], int n);
	for(i=0; i<SIZE; i++)
		for(j=0; j<SIZE; j++)
			scanf("%d",&a[i][j]);
	d=deter(a,SIZE);
	printf("Determinant of\n");
	print(a,SIZE);
	printf("is %d\n",d);
}
long int deter(int b[SIZE][SIZE], int n)
{
	int i,j,k,l,m,c[SIZE][SIZE];
	long int sum=0;
	if(n==2)
	{
		sum=b[0][0]*b[1][1] - b[0][1]*b[1][0];
		return sum;
	}
	for(k=0; k<n; k++)
	{
		l=0;
		m=0;
		for(i=1; i<n; i++)
			for(j=0; j<n; j++)
			{
				if(j==k) continue;
				c[l][m]=b[i][j];
				m++;
				if(m==n-1)
				{
					l++;
					m=0;
				}
			}
		sum+=b[0][k]*pow(-1,k)*deter(c,n-1);
	}
	return sum;
}

void print(int b[][SIZE], int n)

{	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%2d",b[i][j]);
		printf("\n");
	}
}

