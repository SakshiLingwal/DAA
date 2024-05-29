/*I. Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program 
should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted
from their place) required for sorting the array.*/
#include <stdio.h>
int main()
{
    int a[20],n,i,j,temp,t,shift=0,comparison=0;
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
       for(i=1;i<n;i++)
       {
         temp=a[i];
         j=i-1;
         while(a[j]>temp && j>=0)
         {
            a[j+1]=a[j];
            shift++;
            comparison++;
            j--;
         }
         a[j+1]=temp;
         shift++;
       }
       printf("Array after sorting :");
      for(i=0;i<n;i++)
      {
        printf("%d\t",a[i]);
      } 
      printf("\ncomparison :%d\nshift:%d\n",comparison,shift);
      t--;
    }   
    return 0;
}
// -23 65 -31 76 46 89 45 32 shifts = 20
// 10 21 32 34 46 51 54 65 76 78 97
// 54 65 34 76 78 97 46 32 51 21 comparisons = 28
// 15 shifts = 37
// 63 42 223 645 652 31 324 22 553 -12 54 65 86 46 325 -12 22 31 42 46 54 63 65 86 223 324 325 553 645 652