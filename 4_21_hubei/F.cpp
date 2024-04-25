#include<bits/stdc++.h>
//1 1 2 1 2 1 2 1 2 1 2 1
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 2);
    for(int i = 0; i < 2 * n + 2; i++) {
        cin >> a[i];
    }
    int len = 0;
    string ans;
    for(int i = 2; i < 2 * n + 2; i++) {
        if(len == n) break;
        if(i % 2 == 0) {
            if(len)
            {
                if(a[i - 2] <= 2) {
                    if(ans[len - 1] == 'a') ans.push_back('b');
                    else ans.push_back('a');
                    len++;
                }
                else {
                    ans.push_back(ans[len - 2]);
                    len++;
                }
                int tmp = len;
                for(int j = 2; j < a[i]; j += 2) {
                    ans.push_back(ans[tmp - 1 - j / 2]);
                    len++;
                }
            }
            else {
                ans.push_back('a');
                len++;
            }
            i = len * 2;
        }
        else {
            if(a[i] == 1) {
                if(ans[len - 1] == 'a') ans.push_back('b');
                else ans.push_back('a');
                len++;
            }
            else {
                int tmp = len;
                for(int j = 1; j < a[i]; j += 2) {
                    ans.push_back(ans[tmp - (j + 1) / 2]);
                    len++;
                }
            }
            i = len * 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    solve();
    return 0;
}