//Counting sort 
#include<stdio.h>
void count(int a[],int n)
{
    int b[n],i,max=a[0];
    //int count[25];
    for(i=0;i<n;i++)                    //for finding largest element of array 
    {
        if(a[i]>max)
        {
            max=a[i];
        } 
    }
    int count[max+1];
    for(i=0;i<max+1;i++)         //create a count array
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)           //create a array & initialize it with 0
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)        //store the no. of occurrence of each array element in count array
    {
        ++count[a[i]];
    }
    for(i=1;i<max+1;i++)         //update the count array
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)         //finding index of each ele. & place them in o/p array b[]
    {
        b[--count[a[i]]]=a[i];
    }
    //copy sorted array into original
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}
int main()
{
    int n,i,a[20];
    printf("Enter array limit :");
    scanf("%d",&n);
    printf("Enter array elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    count(a,n);
    printf("sorted array :");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}