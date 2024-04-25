#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a,b,c;
int sum;
void solve() {
    cin>>a>>b>>c;
    sum = 0;
    sum+=a;

    sum+=b/3;
    if(b%3==1)
    {
        if(c<=1) 
        {
            cout<<-1<<endl;
            return;
        }
        else 
        {
            sum++;
            c=c-2;
            sum+=c/3+!!(c%3);
        }
    }
    else if(b%3==2)
    {
        if(!c)
        {
            cout<<-1<<endl;
            return;
        }
        else
        {
            sum+=(b%3+c)/3+!!((b%3+c)%3);
        }
    }
    else {
        sum+=c/3+!!(c%3);
    }
    cout<<sum<<endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}