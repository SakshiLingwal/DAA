//Quick sort :O(nlogn) in best & average case ;O(n^2) in worst case.
#include<stdio.h>
void partition(int a[],int lb,int ub)
{
    int pivot=a[lb],i=lb,j=ub,t=0;
    if(lb>ub)
    {
        return;
    }
    else 
    {
        while(i<j) 
        {
          while(pivot>=a[i])
          {
            i++;
          }
          while(pivot<a[j])
         {
            j--;
         }
         if(i<j)
         {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
         }
        }    
        a[lb]=a[j];
        a[j]=pivot;
        partition(a,lb,j-1); 
        partition(a,j+1,ub); 
    }
}
int main()
{
    int a[20],n,i;
    printf("Enter array limit :");
    scanf("%d",&n);
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    partition(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}