//Tower of hanaoi
#include<stdio.h>
void tower(int n,char s,char d,char a)
{
    if(n==1)            //if there is only 1 disk then it'll directly moves to destination
    {
        printf("\nMove disk 1 from %c to %c",s,d);
        return ;
    }
    tower(n-1,s,a,d);
    printf("\nMove disk %d from %c to %c",n,s,d);
    tower(n-1,a,d,s);
}
int main()
{
    int n;
    printf("Enter no. of disks :");
    scanf("%d",&n);
    printf("Sequence of moves involved in the tower of hanaoi are :\n");
    tower(n,'s','d','a');
    return 0;
}