// p66

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int dp[100][100];


int main() {
    int n, m;
    cin >> n >> m;

    // dp[i][j] => i個の区別できないものをj個に分割する通り数
    REP(i, n) {
        REP(j, m) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int diff;
            if (i < j)
                diff = 0;
            else if (i == j)
                diff = 1;
            else
                diff = dp[i-j-1][j];

            dp[i][j] = dp[i][j-1] + diff;
        }
    }

    REP(i, n) {
        REP(j, m) {
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << dp[n-1][m-1] << endl;
}
