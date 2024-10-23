#include<stdio.h>
void main()
{
	int sp[10][10],tr[10][10],i,j,r,c,k=1;
	printf("Enter the row and column of sparse matrix :\n");
	scanf("%d%d",&r,&c);
	printf("Enter the elements of sparse matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
	          printf("Matrix[%d][%d] = ",i,j);
	          scanf("%d",&sp[i][j]);
		}
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		  if(sp[i][j]!=0)
		  {
		    tr[k][0]=i;
		    tr[k][1]=j;
		    tr[k][2]=sp[i][j];
		    k++;
		  }
		}
	}
	tr[0][0]=r;
	tr[0][1]=c;
	tr[0][2]=k-1;
	printf("\nsparse matrix\n");
	for(i=0;i<r;i++)
	{
	  printf("\n");
		for(j=0;j<c;j++)
		{
	          printf("%d\t",sp[i][j]);
	        }
	}
	
	printf("\n");
	printf("\nsparse matrix\n");
	printf("rows\tcloumn\tvalue");
	for(i=0;i<=k;i++)
	{
	  printf("\n");
		for(j=0;j<3;j++)
		{
	          printf("%d\t",tr[i][j]);
	        }
	}
	









}
