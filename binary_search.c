/*Binary Search - Sort the array in ascending order, set 1 element as "low" & last as "high" & average as "mid",then compare key
with the mid , less than mid , greater than mid.
Time complexity = O(log n)
Why does Binary Search need a sorted array to perform the search operation?
In Binary Search, the array is repeatedly divided into two halves and the element is searched in that half whose last element
is greater than or equal to the element being searched. For this reason, Binary Search needs a sorted array to perform the search
operation.*/
#include<stdio.h>
int main()
{
    int a[10],n,i,key,f=0,high,mid,low=0,c=0;
    printf("Enter array limits :");
    scanf("%d",&n);
    printf("Enter the array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to be searched :");
    scanf("%d",&key);
    high=n;
    while(low<=high)
    {
        c++;
        mid=(high+low)/2;  //mid=low+(high-1)/2;
        if(key==a[mid])
        {
            f=1;
            printf("%d key is found in %d index\n",key,mid);
            break;
        }
        else if(key<a[mid])
        {
            high=mid-1;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
    }
    if(f==1)
        printf("Key is found\n");
    else
        printf("Key not found\n");
    printf("no. of comparisons %d",c);
 return 0;
}
/* Given a sorted array of size N and an integer K, find the position at which K is present in the array using binary search.
Example 1:
Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.*/
// #include<stdio.h>
// int main()
// {
//     int n,k,low=0,mid,high;
//     scanf("%d",&n);
//     int a[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     scanf("%d",&k);
//     high=n;
//     while(low<=high)
//     {
//         mid=(low+(high-1))/2;
//         if(k==a[mid])
//         {
//             printf("%d key is found in %d index\n",k,mid);
//             break;
//         }
//         else if(k<a[mid])
//         {
//             high=mid-1;
//         }
//         else if(k>a[mid])
//         {
//             low=mid+1;
//         }
//     }
//     return 0;
// }
