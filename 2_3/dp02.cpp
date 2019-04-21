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

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cin >> v[i];
    }
    memset(dp, -1, sizeof(int) * 100 * 100);

    // 無駄が多いので、メモ化再帰する
    // dp[i][j] は、i 個目までの荷物が使えるとした時に、
    // weight の合計が j 以下になるように選択したときの最大の v の和
    cout << rec(0, 0) << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << endl;
    //     }
    // }
}

