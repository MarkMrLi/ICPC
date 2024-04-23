#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
int n;
vector<long> p;
bool solve(ll k,ll lcm)
{
    ll l = 1,r = 1e17;
    while(l <= r)
    {
        double res;
        ll mid = (l + r) / 2;
        if(mid % 2)
        {
            res = (mid + 1)/2;
            res = res/k * mid;
        }
        else
        {
            res = mid / 2;
            res = res / k * (mid + 1);
        }
        if(abs(res - lcm) < 1e-9)
        {
            cout<<mid<<endl;
            return true;
        }
        else
        {
            if(res - lcm < 0)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll lcm = 0;
    for(int i=1;i<=n;i++)
    {
        ll _;
        cin>>_;
        // p.push_back(_);
        if(i == 1)lcm = _;
        else
        {
            // __lcm(3,2);
            lcm = (lcm)/__gcd(lcm,_) * _;
        }
    }
    for(ll k=1;k<1e7;k++)
    {
        if(solve(k,lcm))break;
    }
    // cout<<lcm<<endl;
    return 0;
}