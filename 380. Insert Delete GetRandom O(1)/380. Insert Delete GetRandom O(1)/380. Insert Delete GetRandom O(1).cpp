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

/**
 * Runtime: 56 ms, faster than 63.70% of C++ online submissions for Insert Delete GetRandom O(1).
 * Memory Usage: 22.2 MB, less than 76.92% of C++ online submissions for Insert Delete GetRandom O(1).
 */
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet()
        : v(), m() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val) != 0) return false;
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.count(val) == 0) return false;
        // int idx = m[val];
        // v[idx] = v.back();
        // v.pop_back();
        // m.erase(val);
        // m[v[idx]] = idx;
        int last = v.back();
        m[last] = m[val];
        v[m[val]] = last;
        v.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {

        return v[rand() % v.size()];
    }
private:
    vector<int> v;
    unordered_map<int, int> m;
};



int main() {
}