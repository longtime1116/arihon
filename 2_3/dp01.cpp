#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef pair<int, int> P;

int n, W;
int w[100];
int v[100];
int cnt = 0;

int rec(int i, int w_sum) {
    cnt++;
    cout << "cnt: " << cnt << endl;

    if (i == n)
        return 0;

    int val1 = 0, val2;
    // i 個目を選ぶ
    if (w_sum + w[i] <= W)
        val1 = rec(i+1, w_sum + w[i]) + v[i];

    // i 個目を選ばない
    val2 = rec(i+1, w_sum);
    return max(val1, val2);
}

int main() {
    cin >> n >> W;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    // 全探索する
    // n 個全てについて選ぶ/選ばないの2通りあるので、O(n^2)
    cout << rec(0, 0) << endl;
}
