#include<stdio.h>
#include<stdlib.h>

int x[10],n;

int place(int r,int c)
{
    for(int i=1;i<r;i++)
        if(x[i]==c || abs(x[i]-c)==abs(i-r))
            return 0;

    return 1;
}

int queen(int r)
{
    for(int c=1;c<=n;c++)
    {
        if(place(r,c))
        {
            x[r]=c;

            if(r==n)
                return 1;

            if(queen(r+1))
                return 1;
        }
    }

    return 0;
}

int main()
{
    scanf("%d",&n);

    queen(1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(x[i]==j)
                printf("Q ");
            else
                printf("# ");

        printf("\n");
    }

    return 0;
}