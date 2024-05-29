#include<stdio.h>
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb,k=lb,j=mid+1;
    int t[ub+1];
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            t[k]=a[i];
            i++;
            k++;
        }
        else
        {
            t[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        t[k]=a[i];
        k++;
        i++;
    }
    while(j<=ub)
    {
        t[k]=a[j];
        k++;
        j++;
    }
    for(int s=lb;s<=ub;s++)
    {
        a[s]=t[s];
    }
}
void mergesort(int a[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main()
{
    int a[20],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}