#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    int zero_num = 0,one_num = 0;
    vector<int> a(n);
    for(int i = 0;i < n;i++)
    {
        char b;
        cin>>b;
        a[i] = b - '0';
        if(a[i])one_num++;
        else zero_num++;
    }
    int ans = 0;
    int now_one_num = 0;
    int now_zere_num = 0;
    double min_dis = 1.0*n/2;
    for(int i = 0;i < n;i++)
    {
        if(a[i])now_one_num++;
        else now_zere_num++;
        int x = i+1;
        double dis = abs(1.0*n/2 - x);
        if(dis < min_dis&&now_zere_num >= x / 2 + x % 2 && one_num  - now_one_num>= (n - x) / 2 + (n - x) % 2)
        {
            ans = x;
            min_dis = dis;
        }
    }
    if(!ans)
    {
        if(one_num < n / 2 + n % 2)ans = n;
    }
    cout<<ans<<endl;
    
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