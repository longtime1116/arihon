// p64

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define INF (10000)
typedef long long int lli;
typedef pair<int, int> P;



int main() {
    int n;
    cin >> n;
    int a[n+1];
    int dp[n];
    fill(dp, dp+n, INF);

    REP(i, n) {
        cin >> a[i];
    }

    // O(nlogn)にする
    // 最長増加部分列の個数が i+1 個になるときの末尾(最大)の数字
    REP(i, n) {
        // a[i] 以上の最小の数が入っている場所のポインタを返すので、そこを上書き
        *lower_bound(dp, dp+n, a[i])= a[i];
    }

    REP(i, n) {
        cout << dp[i] << ",";
    }
    cout << endl;
    cout << lower_bound(dp, dp+n, INF) - dp << endl;
}
