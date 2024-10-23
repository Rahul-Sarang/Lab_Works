#include<stdio.h>
void main()
{


 int i,j,n,temp;
   printf("Enter the limit of array :");
   scanf("%d",&n);
   int a[n];
   printf("Enter the elements of array : \n");
   for(i=0;i<n;i++)
   { 
     scanf("%d",&a[i]);
   }
   
  for(i=0;i<n-1;i++)
   {
    int min=i;
      for(j=i+1;j<n;j++)
        { 
          if(a[j]<a[min])
          {
          	min=j;
          }
        }
         temp=a[min];
         a[min]=a[i];
         a[i]=temp;
    }
     printf("sorted array\n");
     for(i=0;i<n;i++)
   { 
     
     printf("%d  ",a[i]);
   }
   
}
