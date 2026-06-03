#include<stdio.h>

void warshall(int p[10][10],int n)
{
    int i,j,k;

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                p[i][j]=p[i][j] || (p[i][k] && p[k][j]);
}

int main()
{
    int p[10][10],n,i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&p[i][j]);

    warshall(p,n);

    printf("\nTransitive Closure Matrix:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",p[i][j]);

        printf("\n");
    }

    return 0;
}