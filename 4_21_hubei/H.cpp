#include<bits/stdc++.h>

using namespace std;
#define MOD 998244353
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    map<ll,ll>mpa;
    for(int i = 1;i <= m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u]++;
        a[v]++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i])mpa[a[i]]++;
    }
    ll ans = 0;
    vector<pair<ll,ll>> b;
    for(auto [v1,num1]:mpa)
    {
        b.push_back({v1,num1});
        // for(auto [v2,num2]:mpa)
        // {
        //     if(v1 == v2)continue;
        //     else
        //     {
        //         ans += (v1^v2)%MOD*(v1|v2)%MOD*(v1&v2)%MOD*num1%MOD*num2%MOD;
        //     }
        // }
    }
    for(int i = 0;i < b.size();i++)
    {
        for(int j = i + 1;j < b.size();j++)
        {
            ll v1 = b[i].first;//,v2 = b[j].first,num1 = b[i].second,num2 = b[j].second;
            ll v2 = b[j].first;
            ll num1 = b[i].second;
            ll num2 = b[j].second;
            ans += (v1^v2)%MOD*(v1|v2)%MOD*(v1&v2)%MOD*num1%MOD*num2%MOD;
        }
    }
    cout<<ans%MOD<<endl;
}