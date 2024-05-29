// Jump search
/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given
key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k]
and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the
element key. (Complexity < O(n), O(sqrt(n))where n is the number of elements need to be scanned for searching)*/
#include <stdio.h>
#include <math.h>
int main()
{
  int t;
  scanf("%d", &t);
  while(t!=0)
  {
    int a[20],n,i,key,jump,c=0,f=0,low;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
    scanf("%d", &key);
    jump = (int)floor(sqrt(n));
    for (i = 0; i < n; i += jump)   //binary search with jumps
    {
      c++;
      if (a[i] == key)
        return i;
      else if (a[i] < key)
        low = i;
      else if (a[i] > key)
        break;
    }
    for (i = low; i < n; i++)     //linear search 
    {
      c++;
      if (a[i] == key)
      {
        f = 1;
        break;
      }
    }
    if (f == 1)
      printf("Key found at %d index\n", i);
    else
      printf("Key not found");
    t--;
  }
  return 0;
}