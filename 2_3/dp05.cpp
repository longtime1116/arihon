// p64

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;



int main() {
    int n;
    cin >> n;
    int a[n+1];
    int dp[n] = {0};

    REP(i, n) {
        cin >> a[i];
    }

    // i 個目までの要素で最長な個数はdp[i]個
    REP(i, n) {
        dp[i] = 1;
        REP(j, i) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    REP(i, n) {
        cout << dp[i] << ",";
    }
}
