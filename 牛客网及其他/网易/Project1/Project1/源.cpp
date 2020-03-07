#include <iostream>
#include <ctime>
using namespace std;

static int extractBit(const int           locationOfBitFromRight,
                      const long long int theEncodedNumber)
{
    return (theEncodedNumber & (1LL << locationOfBitFromRight))
           >> locationOfBitFromRight;
}

int main()
{
    clock_t st, en;
    int     k = 0;

    for (int yy = 1; yy <= 100; yy++) {
        st = clock();
        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= (1 << 30); j++) {
                if (extractBit(i, j)) {
                    //                    k++;
                }
            }
        }
        en = clock();
        cout << (double)(en - st) / CLOCKS_PER_SEC << endl;
    }

    //    cout<<k<<endl;
    return 0;
}
// 34.5
// 33.7

//#include <iostream>
//
//#include <vector>
//#include <string>
//#include <map>
//
//
//using namespace std;
//
//
//
//
//int main() {
//    int t = 0;
//    cin >> t;
//    int n = 0, m = 0, k = 0;
//    vector<string> result;
//    for (int iter = 0; iter < t; ++iter) {
//        cin >> n >> m >> k;
//        cout << n << m << k;
//        vector<vector<int>> sq(n, vector<int>(m, 0));
//        int x = 0, y = 0;
//        for (int i = 0; i < k; ++i) {
//            cin >> x >> y;
//            sq[x][y] = 1;
//        }
//        int c = 0, d = 0;
//        cin >> c >> d;
//        int res = 0;
//        int flag = false;
//        vector<vector<int>> good(c, vector<int>(d, 1));
//        for (int i = 0; i < n - c + 1; ++i) {
//            for (int j = 0; j < m - d + 1; ++j) {
//                for (int x = 0; x < c; ++x) {
//                    for (int y = 0; y < d; ++y) {
//                        res += good[x][y] & sq[x + i][y + j];
//                    }
//                }
//                if (!res) {
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag) {
//                break;
//            }
//        }
//        if (flag) {
//            result.push_back("YES");
//        } else {
//            result.push_back("NO");
//        }
//    }
//    for (int i = 0; i < result.size(); ++i) {
//        cout << result[i] << endl;
//    }
//}
/**
9
1 4
2 5
1 9
1 15
2 4
1 11
2 10
2 7
2 9

2
3 3 1
1 1
2 2
3 3 1
2 2
2 2
*/