#include<bits/stdc++.h>
using namespace std;


int main(){
    int i,j,k,a[20][20],d,n,e,fp[20],bp[20],tf[20][20];

    printf("\nEnter no of edges:");
    scanf(" %d",&e);
    printf("\nEnter no of nodes:");
    scanf(" %d",&n);
    k = 0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j] = 0;
    while(k<e){
        printf("\nEnter start node,end node,duration: ");
        scanf("%d %d %d",&i,&j,&d);
        a[i][j] = d;
        k++;
    }
    for(int i=1;i<=n;++i){
        fp[i]=0;
        bp[i] = 1000;
    }
    for(int j=2;j<=n;++j)
        for(int i=1;i<j;++i){
            if((a[i][j]!=0)&&(fp[j]<fp[i]+a[i][j]))
                fp[j] = fp[i]+a[i][j];
        }

    for(int i=n-1;i>=1;--i)
        for(int j=n;j>i;--j){
            if((a[i][j]!=0)&&(bp[i]>bp[j]-a[i][j]))
                bp[i]=bp[j]-a[i][j];
        }
    for(int i=1;i<n;++i)
        for(int j=2;j<=n;++j){
            if(a[i][j]!=0)
                tf[i][j] = bp[j]-fp[i]-a[i][j];
        }

    printf("\nCritical activities: ");
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if((i<j)&&(a[i][j]!=0)&&(fp[i]==bp[i])&&(fp[j]==bp[j])&&(fp[j]-fp[i]==a[i][j]))
                printf("(%d-%d)\t",i,j);
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]!=0){
                printf("%d-%d\t%d",i,j,tf[i][j]);
            }
        }
    }

    for(int i=1;i<=n;++i)
        printf("%d/%d",fp[i],fp[j]);

    return 0;
}
