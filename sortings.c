/*Bubble sort:
Time complexity :-
Worst case : O(n^2),Average case :O(n^2),Best case :O(n)-in optimized bubble sort*/
#include<stdio.h>
void bubble(int a[],int n)         //non-optimized sort
{
    int i,j,f=0,t;
    for(i=0;i<n-1;i++)
    {
        f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                f=1;
            }
        }
        if(f==0)
        break;
    }
}
void insertion(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;   
    }
}
void selection(int a[],int n)
{
    // int min,i,j;
    // for(i=0;i<n-1;i++)
    // {
    //     min=i;
    //     for(j=i+1;j<n;j++)
    //     {
    //       if(a[j]<a[min])
    //       {
    //          min=j;
    //       }
    //     }
    //     if(min!=i)
    //     {
    //         int t=a[i];
    //         a[i]=a[min];
    //         a[min]=t;
    //     }
    // }
    int i,j,k,temp;
    for (i=0;i<n-1;i++)
    {
        k=i;
        for (j=i;j<n;j++)//at first compare we make j and k to point at the same then j find the smaller than k and then k is assigned to j 
        {                   //and this is done until j reaches n
           if(a[j]<a[k])
            {
                k=j;
            }
        }
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}
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
void merge(int a[],int t[],int lb,int mid,int ub)
{
    int i=0,le=mid-1,k=lb;
    while(lb<=le && mid<=ub)
    {
        if(a[lb]<=a[mid])
        {
            t[k]=a[lb];
            lb++;
            k++;
        }
        else
        {
            t[k]=a[mid];
            mid++;
            k++;
        }
    }
    while(lb<=le)
    {
        t[k]=a[lb];
        k++;
        lb++;
    }
    while(mid<=ub)
    {
        t[k]=a[mid];
        k++;
        mid++;
    }
    for(i=0;i<=ub;i++)
    {
        a[i]=t[i];
    }
}
void mergesort(int a[],int t[],int lb,int ub)
{
    int mid=0;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(a,t,lb,mid);
        mergesort(a,t,mid+1,ub);
        merge(a,t,lb,mid+1,ub);
    }
}
void display(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int a[20],t[20],n,i,ch;
    printf("Enter array limit :");
    scanf("%d",&n);
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("Enter choice :\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Quick sort\n5.Merge sort\n6.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            bubble(a,n);
            display(a,n);
            break;
        case 2:
            insertion(a,n);
            display(a,n);
            break;
        case 3:
            selection(a,n);
            display(a,n);
            break;
        case 4:
            partition(a,0,n-1);
            display(a,n);
            break;
        case 5:
            mergesort(a,t,0,n-1);
            display(a,n);
            break;
        default:
            printf("Invalid choice \n");
            break;
        }
        printf("Do you wants to continue '1/0'?");
        scanf("%d",&ch);
    }
    while(ch==1);
    return 0;
}