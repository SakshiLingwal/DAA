//Heap sort
#include<stdio.h>
void heapify(int arr[], int N, int i)
{
    int largest=i;
    int left=2*i;
    int right =2*i+1;
    
    if(left<N && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<N && arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!= i) 
    {
        int t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        heapify(arr,N,largest);
    }
}
void heapSort(int arr[], int N)
{
    for(int i=N/2;i>= 0;i--)    //for(int i=N/2-1;i>= 0;i--) for few cases
    {
        heapify(arr,N,i);
    }
    for (int i=N-1;i>=0;i--) 
    {
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        heapify(arr,i,0);
    }
}
int main()
{
    int arr[20],N,i;
    printf("Enter array limit :");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, N);
    printf("Sorted array is :");
    for (int i=0;i<N;i++)
        printf("%d ",arr[i]);
    return 0;
}
