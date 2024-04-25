#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

vector<ll> a(N);
vector<ll> b(N);
vector<ll> b_sum(N + 1, 0);

void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    b_sum[n] = 0;
    for(int i = n - 1; ~i; i--) {
        b_sum[i] = b_sum[i + 1] + b[i];
    }
    vector<ll> ans(n + 1, 0x3f3f3f3f3f3f3f);
    ans[n] = 0;
    queue<int> tmp;
    tmp.push(n);

    for(int i = n - 1; ~i; i--) {
        queue<int> tmp2 = tmp;
        while(!tmp2.empty()) {
            int j = tmp2.front();
            tmp2.pop();
            ans[i] = min(ans[i], ans[j] + a[i] - b_sum[j] + b_sum[i + 1]);
        }
        while(!tmp.empty() && ans[i] <= ans[tmp.front()]) tmp.pop();
        tmp.push(i);
    }

    ll res = ans[0];
    for(int i = 0; i < m; i++) res = min(res, ans[i]);
    cout << res << endl;
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}