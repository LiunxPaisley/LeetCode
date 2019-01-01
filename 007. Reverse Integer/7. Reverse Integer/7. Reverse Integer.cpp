#include <iostream>
#include <algorithm>
#include <cstdio>

class Solution {
public:
    int reverse(int x)
    {
        int b = 0;
        while (x != 0)
        {
            int lhs = b * 10;
            if (!(lhs / 10 == b))
            {
                b = 0;
                break;
            }
            int rhs = x % 10;
            b       = lhs + rhs;
            x       = x / 10;
        }
        return b;
    }
};

int main() {
    Solution* s = new Solution();
    int input = -1236469;
    int output = s->reverse(input);
    printf("input = %d\noutput = %d\n", input, output);
}