// Challenge Link: https://codeforces.com/group/iQQI5TD7io/contest/672700/problem/E



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> cities(n);
    vector<long long> towers(m);

    for (int i = 0; i < n; i++)
        cin >> cities[i];

    for (int i = 0; i < m; i++)
        cin >> towers[i];

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(towers.begin(), towers.end(), cities[i]);

        long long dist = 1e18;

        // Check right tower
        if (it != towers.end())
            dist = abs(*it - cities[i]);

        // Check left tower
        if (it != towers.begin()) {
            it--;
            dist = min(dist, abs(*it - cities[i]));
        }

        answer = max(answer, dist);
    }

    cout << answer;

    return 0;
}
