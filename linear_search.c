/*Linear Search - input an array and key , then search the key linearly.
Time complexity = O(n)
/*Given an array of non negative integers, design a linear algorithm and implement it using a program to find whether given key 
element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n))*/

#include<stdio.h>
int main()
{
    int a[10],n,i,j,f,c,key,t;
    scanf("%d",&t);                       //no. of test cases
    while(t)
    {
      f=0;
      c=0;
      printf("Enter array limit :");
      scanf("%d",&n);
      printf("Enter array elements :");
      for(i=0;i<n;i++)
      {
        scanf("%d",&a[i]);  
      }
      printf("Enter key to be searched :");
      scanf("%d",&key);
      for(i=0;i<n;i++)
      {
        c++;
        if(key==a[i])
        {
            f=1;
            break;
        }
      }
        if(f==1)
           printf("Present  %d\n",c);
        else
           printf("Not Present %d\n",c);
         t--;
    }
    return 0;
}