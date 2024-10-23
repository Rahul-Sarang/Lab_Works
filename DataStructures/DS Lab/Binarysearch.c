#include<stdio.h>
void main()
{
   int i,j,n,mid,key;
   int space=0,count=0;
   space=7*sizeof(int);

   printf("Enter the limit of array :");
   scanf("%d",&n);
   count+=2;
  
   int a[n];
   space+=n*sizeof(int);

   printf("Enter the elements of array  accending order sorted  : \n");
   for(i=0;i<n;i++)
   { 
     scanf("%d",&a[i]);
     count+=2;
   }
   count++;
   printf("Enter the search key :");
   scanf("%d",&key);
   count+=2;

   int left=0,right=n-1;
   space+=2*sizeof(int);
  while (left<=right)
   {    count++;
        mid=(left+right)/2;
        count++;
       if (a[mid]==key)
         {
           printf("The key is found at %d th position\n",mid+1);
           break;
           count+=3;
         } 
        else if(key<a[mid])
         {
           right=mid-1;
           count+=2;
         }
        else 
        {
           left=mid+1; 
           count+=2;
        }
     
   }
   count++;
   
    if(left>right) 
            {
                    printf("The key is not found\n");
                    count+=2;
            }    

    printf("Space Complexity : %d\n",space);
    count++;
    count++;
    printf("Times Complexity : %d\n",count);  
  
}
