#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
vector<ll> a(N, 0);
vector<ll> sum(N, 0);
vector<ll> sum_max(N, 0);

void solve() {
    int n;
    cin >> n;
    
    cin >> a[1];
    sum[1] = a[1];
    sum_max[1] = sum[1];
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum_max[i] = max(sum_max[i - 1], sum[i]);
    }
    if(a[1] < 0 || sum[n] < 0) {
        cout << -1 << endl;
        return;
    }
    int flag = 1;
    for(int i = 1; i <= n; i++) {
        if(sum[i] > 0) break;
        else if(sum[i] == 0) continue;
        else if(sum[i] < 0) {
            flag = 0;
            break;
        }
    }
    if(!flag) {
        cout << -1 << endl;
        return;
    }
    ll ans = 1;
    ll res = sum[1];
    for(int i = 2; i <= n; i++) {
        if(res + sum[i] < 0) {
            ll num = (-(res + sum[i])) / sum_max[i - 1] + (((-(res + sum[i])) % sum_max[i - 1]) == 0 ? 0 : 1);
            ans += num;
            res += num * sum_max[i - 1];
        }
        res += sum[i];
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    solve();
    return 0;
}