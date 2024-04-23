#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long a,b,c;
int main()
{
    cin>>x>>y;

    if(y == 0) cout << x <<" "<<0<<" "<<0<<endl;
    else if(x*2500<y) cout<<-1<<endl;
    else if(x*2500==y) cout<<0<<" "<<0<<" "<<x<<endl;
    else if(x*1000==y) cout<<0<<" "<<x<<" "<<0<<endl;
    else if(y%1000==0&&x-(y/1000)>=0) cout<<x-(y/1000)<<" "<<y/1000<<" "<<0<<endl;
    else if(y%2500==0&&x-(y/2500)>=0) cout<<x-(y/2500)<<" "<<0<<" "<<y/2500<<endl;
    else
    {
        c=x-1;
        b=0;
        while(c*2500>y&&c>0)
        {
            c--;
        }
        if(c*2500==y) 
        {
            cout<<x-c<<" "<<0<<" "<<c<<endl;
            return 0;
        }
        while((y-c*2500)%1000!=0&&c>0)
        {
            c--;
        }
        if(c==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        cout<<x-c-(y-c*2500)/1000<<" "<<(y-c*2500)/1000<<" "<<c<<endl;
    }
    return 0;
}