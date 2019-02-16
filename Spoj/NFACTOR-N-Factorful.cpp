
#include <bits/stdc++.h>
using namespace std;

int divisor[1000010] , result[11][1000010] ;

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(divisor[i]==0)
        {
            for(int j=i;j<=1000000;j+=i)
            divisor[j]++;
        }
    }


    for(int j=0;j<=10;j++)
    {
        for(int i=1;i<=1000000;i++)
        result[j][i] = result[j][i-1] + (bool) ( divisor[i] == j ) ;
    }
}

int main()
{
    sieve();
    int t ;
    scanf("%d",&t);
    while( t-- )
    {
        int a , b , n ;
        scanf("%d%d%d",&a,&b,&n);
        printf("%d\n",result[n][b]-result[n][a-1]);
    }
    return 0;
}
