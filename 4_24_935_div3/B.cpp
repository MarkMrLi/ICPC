#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    ll ans = 2;
    ans += m / a + m / b;
    cout << ans << endl;

    
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