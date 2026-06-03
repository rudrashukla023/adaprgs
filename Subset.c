#include<stdio.h>

void subset(int a[],int sub[],int n,int i,int k,int sum,int target)
{
    if(sum==target)
    {
      printf("Subset found: ");
        for(int j=0;j<k;j++)
            printf("%d ",sub[j]);
        printf("\n");
        return;
    }

    if(i==n || sum>target)
        return;

    sub[k]=a[i];

    subset(a,sub,n,i+1,k+1,sum+a[i],target);

    subset(a,sub,n,i+1,k,sum,target);
}

int main()
{
    int n,i,target,a[50],sub[50];
    printf("Enter number of elements: ");
    scanf("%d",&n);
      printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter target sum: ");
    scanf("%d",&target);

    subset(a,sub,n,0,0,0,target);

    return 0;
}