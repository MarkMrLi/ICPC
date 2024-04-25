#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> p(n + 1);
    int now_ind = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        if(p[i] == x)now_ind = i;
    }
    if(n)
    {
        int k = 0;
        int i1,j1,i2,j2;
        // if(p[(n+2)/2] <= x)
        // {
        //     k++;
        //     i1 = now_ind;
        //     j1 = (n+2)/2 - 1;
        //     now_ind = j1;
        // }
        // else
        // {
        //     i1 = now_ind;
        //     j1 = (n + 2)/2;
        //     now_ind = j1;
        // }
        int l = 1,r = n + 1;
        while(r - l > 1)
        {
            int mid = (r + l)/2;
            if(p[mid] <= x)l = mid;
            else r = mid;
        }
        cout<<1<<endl<<now_ind<<" "<<l<<endl;
    }
    // else if(n == 1)
    // {
    //     cout<<0<<endl;
    // }
    // else if(n == 2)
    // {
    //     if(now_ind)
    //     cout<<1<<endl<<now_ind<<1<<endl;
    //     else
    //     cout<<0<<endl;
    // }
    
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