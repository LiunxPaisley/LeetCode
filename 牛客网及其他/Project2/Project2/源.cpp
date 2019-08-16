#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

/**
2
10 5 2
13 0 3 5 0 4 9 0 6 8 0 7 5 1 2 6 1 6 3 2 9 7 3 4 3 3 5 3 3 8 3 3 9 3 5 8 9 7 8 9
10 0 2
13 0 3 5 0 4 9 0 6 8 0 7 5 1 2 6 1 6 3 2 9 7 3 4 3 3 5 3 3 8 3 3 9 3 5 8 9 7 8 9

*/
int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        int m = 0, i = 0, n = 0;
        cin >> m >> i >> n;
        vector<vector<int>> table(m, vector<int>(m, 0));
        int k = 0;
        cin >> k;
        {
            int i = 0, j = 0, w = 0;
            while (k--) {
                cin >> i >> j >> w;
                table[i][j] = w;
                table[j][i] = w;
            }
        }
        for (auto x : table) {
            for (auto y : x) {
                cout << y << ' ';
            }
            cout << endl;
        }
        set<int> rec;
        rec.insert(i);
        queue<pair<int, int>> que;
        int count = 0;
        for (int l = 0; l < m; l++) {
            if (table[i][l]) {
                que.push({ l,table[i][l] });
                count++;
                //rec.insert(l);
            }
        }
        
        for (int lc = 1; lc < n; lc++) {
            int cnt = count;
            count = 0;
            while (cnt--) {
                pair<int, int> tmp = que.front();
                que.pop();
                for (int x = 0; x < m; x++) {
                    if (table[tmp.first][x] && !table[i][x] && x != i) {
                        
                        rec.insert(tmp.first);

                        que.push({ x, tmp.second + table[tmp.first][x] });
                        count++;
                    }
                }
            }
        }
        //for (auto x : rec) {
        //    cout << "x: " << x << ", ";
        //}
        cout << endl;
        vector<pair<int, int>> res;
        while (!que.empty()) {
            if (!rec.count(que.front().first)) {
                res.push_back(que.front());
            }
            que.pop();
        }
        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second > b.second) return true;
            if (a.second == b.second && a.first > b.first) return true;
            return false;
            });
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].first << ' ';
        }
        if (res.empty()) {
            cout << -1;
        }
        cout << endl;
    }
}