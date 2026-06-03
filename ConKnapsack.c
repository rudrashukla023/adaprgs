#include<stdio.h>

int main()
{
    int n,m,i,j,t,w[50],p[50];
    float r[50],profit=0;

    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&w[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        r[i]=(float)p[i]/w[i];
    }

    scanf("%d",&m);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(r[i]<r[j])
            {
                float temp=r[i];
                r[i]=r[j];
                r[j]=temp;

                t=w[i];
                w[i]=w[j];
                w[j]=t;

                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }

    printf("Discrete Profit = ");
    int cap=m,dprofit=0;

    for(i=0;i<n;i++)
        if(w[i]<=cap)
        {
            dprofit+=p[i];
            cap-=w[i];
        }

    printf("%d\n",dprofit);

    cap=m;

    for(i=0;i<n;i++)
        if(w[i]<=cap)
        {
            profit+=p[i];
            cap-=w[i];
        }
        else
        {
            profit+=((float)cap/w[i])*p[i];
            break;
        }

    printf("Continuous Profit = %.2f",profit);

    return 0;
}