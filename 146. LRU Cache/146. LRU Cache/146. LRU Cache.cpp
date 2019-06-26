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
 * Runtime: 124 ms, faster than 48.17% of C++ online submissions for LRU Cache.
 * Memory Usage: 40 MB, less than 46.74% of C++ online submissions for LRU Cache.
 */
class LRUCache {
public:
    LRUCache(int capacity)
        : cap(capacity), cache(), keys() {

    }

    int get(int key) {
        if (cache.count(key)) {
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key].second = keys.begin();
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key].second = keys.begin();
            cache[key].first = value;
            return;
        }
        if (cache.size() == cap) {
            int k = keys.back();
            keys.pop_back();
            cache.erase(k);
        }
        keys.push_front(key);
        cache[key] = { value, keys.begin() };
    }
private:
    int cap;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
};


int main() {
    /**
     * Your LRUCache object will be instantiated and called as such:
     */
    int capacity = 2;
    int key = 2;
    int value = 2;
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);
 
}