#include<stdio.h>
struct poly
{
    int coef;
    int expo;
}p1[10],p2[10],p3[20];
     void inp(struct poly a[],int n)
    {
        for(int i=0;i<n;i++)
       {
          printf("Enter the coefficient :");
          scanf("%d",&a[i].coef);
          printf("Enter the exponent :");
          scanf("%d",&a[i].expo); 
        }
    }
void main()
{
int n1,n2;
printf("enter the number terms in the first polynomial :");
scanf("%d",&n1);
printf("enter the number terms in the second polynomial :");
scanf("%d",&n2);
printf("First polynomial \n");
inp(p1,n1);
printf("second polynomial \n");
inp(p2,n2);
int i=0,j=0,k=0;
    while (i<n1&&j<n2)
    {
         if(p1[i].expo==p2[j].expo)
        {   
             p3[k].coef=p1[i].coef+p2[j].coef;
             p3[k].expo=p1[i].expo;
             i++;
             j++;  
             k++;
        }
        else if(p1[i].expo<p2[j].expo)
        {
             p3[k].coef=p2[j].coef;
             p3[k].expo=p2[j].expo;
             j++;
             k++;   
         }
         else
         {
             p3[k].coef=p1[i].coef;
             p3[k].expo=p1[i].expo;
             i++;
             k++;

         }
    }
    while(i<n1)
    {
         p3[k].coef=p1[i].coef;
         p3[k].expo=p1[i].expo;
         i++;
         k++;
    }
    while(j<n2)
    {
         p3[k].coef=p2[j].coef;
         p3[k].expo=p2[j].expo;
         j++;
         k++;
    }
    int n3=k;
    printf("Sum of first and second polynomial \n");
    for(i=0;i<n3;i++)
    {
      printf(" (%dx^%d) ",p3[i].coef,p3[i].expo);
      if(i<n3-1)
      {
        printf("+");
      }
    }

}
