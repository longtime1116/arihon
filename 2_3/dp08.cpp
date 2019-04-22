// p67

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;


int dp[100][100];

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];

    REP(i, n) {
        cin >> a[i];
    }

    // i 個目までの要素で最長な個数はdp[i]個
    int sum = 0;
    REP(i, n+1) {
        sum += a[i];
        REP(j, m+1) {
            if (j == 0)
                dp[i+1][j] = 1;
            else if (sum < j)
                dp[i+1][j] = 0;
            else if (j - 1 - a[i] < 0)
                dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
            else
                dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]];
        }
    }

    REP(i, n+1) {
        REP(j, m+1) {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
}
