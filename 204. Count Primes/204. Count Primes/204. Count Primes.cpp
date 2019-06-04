#include <iostream>
#include <fstream>
#include <sstream>

#include <array>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <tuple>

#include <algorithm>
#include <utility>
#include <memory>
#include <limits>
#include <functional>
#include <numeric>

#include <cstring> 
#include <cstdio>
#include <climits>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    /**
     * Runtime: 28 ms, faster than 88.66% of C++ online submissions for Count Primes.
     * Memory Usage: 21.8 MB, less than 5.14% of C++ online submissions for Count Primes.
     */
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = 0;
        vector<int> not_prime(n, 0);
        for (int i = 2; i < n; i++) {
            if (not_prime[i] == 0) {
                count++;
                for (int j = 2; i * j < n; ++j) {
                    not_prime[i * j] = 1;
                }
            }
        }
        return count;
    }
};


int main() {
    Solution sln;
}