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
 * Runtime: 144 ms, faster than 94.89 % of C++ online submissions for Find Median from Data Stream.
 * Memory Usage : 42.3 MB, less than 100.00 % of C++ online submissions for Find Median from Data Stream.
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()
        : max_heap(), min_heap() {
        max_heap.push(INT_MIN);
        min_heap.push(INT_MAX);
    }

    void addNum(int num) {
        if (num <= max_heap.top()) {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            max_heap.push(num);
        } else if (num >= min_heap.top()) {
            if (max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            min_heap.push(num);
        } else {
            if (max_heap.size() < min_heap.size()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return min_heap.top();
        }
    }
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};


int main() {
    MedianFinder sln;
}