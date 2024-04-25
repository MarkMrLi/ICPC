#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n,m;
    cin>>n>>m;
    int odd1 = n/2 + n%2;
    int even1 = n/2;
    int odd2 = m / 2 + m%2;
    int even2 = m / 2;

    int ans = odd1 + odd2 - 1;
    if(!(m%2)||!(n%2))ans++;
    cout<<ans<<endl;
}

int main()
{
    int t;
    solve();
    return 0;
}