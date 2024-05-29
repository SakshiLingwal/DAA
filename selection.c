/*II. Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort.
Your program should also find number of comparisons and number of swaps required.*/
#include <stdio.h>
int main()
{
    int a[20],m,n,i,j,min,t,swap=0,comparison=0;
    printf("Enter no. of test cases :");
    scanf("%d",&t);
    while(t)
    {
       printf("Enter array limit :");
       scanf("%d",&n);
       printf("Enter array elements :");
       for(i=0;i<n;i++)
       {
          scanf("%d",&a[i]);
       }
       for(i=0;i<n-1;i++)
       {
        min=i;
        for(j=i+1;j<n;j++)
        {
            comparison++;
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        swap++;
        if(min!=i)
        {
            m=a[min];
            a[min]=a[i];
            a[i]=m;
        }
       }
       printf("Array after sorting :");
      for(i=0;i<n;i++)
      {
        printf("%d\t",a[i]);
      } 
    printf("\ncomparison :%d\nswaps:%d\n",comparison,swap);
    t--;
    }   
    return 0;
}

// 8 comparisons = 28
// -13 65 -21 76 46 89 45 12 swaps = 7
// 10 21 32 34 46 51 54 65 76 78 97
// 54 65 34 76 78 97 46 32 51 21 comparisons = 45
// 15 swaps = 9
// 63 42 223 645 652 31 324 22 553 12 54 65 86 46 3
// comparisons