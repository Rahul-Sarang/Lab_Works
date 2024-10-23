#include<stdio.h>
void main()
 {
    int n, i, key, flag = 0, count = 0, space=0; 
    space=6*sizeof(int);
    printf("Enter the limit of array: "); 
    scanf("%d", &n);
    count += 2;  
    int a[n];  
    space+=n*sizeof(int);
    printf("Enter the elements of array: \n");
    count++;
    for (i = 0; i < n; i++)
    { 
        scanf("%d", &a[i]);
        count += 2;  
    }
    count ++;  
    printf("Enter the search key: "); 
    scanf("%d", &key);
    count += 2;  
    for (i = 0; i < n; i++) 
    {   
        if (a[i] == key)
        {   
            flag = 1;  
            break;  
        }
        count+=4;

    }
    count++;  
    if (flag == 1)
    { 
        printf("The search key %d is found at %dth position\n", key, i + 1);
        count += 2;  
    }
    else
    { 
        printf("The search key %d is not found\n", key);
        count += 2;  
    }
    printf("Space Complexity : %d\n",space);
    count++;
    count++;
    printf("Times Complexity : %d\n",count);  

}
