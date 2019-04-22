#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int n, W;
int w[100];
int v[100];
int dp[100][100];

int rec(int i, int w_sum) {
    if (dp[i][w_sum] != -1) {
        return dp[i][w_sum];
        // cout << i << "," << w_sum << endl;
    }

    if (i == n)
        return 0;

    int val1 = 0, val2;
    // i 個目を選ぶ
    if (w_sum + w[i] <= W)
        val1 = rec(i+1, w_sum + w[i]) + v[i];

    // i 個目を選ばない
    val2 = rec(i+1, w_sum);
    return dp[i][w_sum] = max(val1, val2);
}

int main() {
    cin >> n >> W;

    // 都合上、1 オリジンにしておく
    // すなわち、n個目の重さがw[n]に入る
    for (int i = 1; i < n+1; i++) {
        cin >> w[i];
        cin >> v[i];
    }
    memset(dp, 0, sizeof(int) * 100 * 100);

    // 漸化式を解いて dp テーブルを埋めていく
    // dp[i+1][j] は、i 個目までの荷物が使えるとした時に、
    // weight の合計が j 以下になるように選択したときの最大の v の和
    REP(i, n) {
        REP(j, W+1) {
            if (j - w[i+1] < 0)
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i+1]]+v[i+1]);
        }
    }
    cout << dp[n][W] << endl;
     for (int i = 0; i < n+1; i++) {
         for (int j = 0; j < W+1; j++) {
             cout << dp[i][j] << ",";
         }
         cout << endl;
     }
}

