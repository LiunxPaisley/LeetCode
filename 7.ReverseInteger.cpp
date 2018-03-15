#include <cstdio>

class Solution {
public:
    int reverse(int x) {
        // bool r = true;
        // printf("x = %d\n", x);
        // long long y = x;
        // if(y < 0)
        // {
        //     y = -y;
        //     r = false;
        // }
        // printf("y = %lld\n", y);
        int b = 0;
        while(x != 0)
        {
            int lhs = b*10;
            // printf("lhs = %d, b = %d\n", lhs, b);
            // printf("lhs^b = %d, lhs^10 = %d\n", lhs^b, lhs^10);
            if(!(lhs / 10 == b))
            {
                b = 0;
                break;
            }
            int rhs = x%10;
            // printf("rhs = %d\n", rhs);
            b = lhs + rhs;
            
            x = x/10;
        }
        return b;
        // if(r)
        // {
        //     return b;
        // }
        // else{
        //     return -b;
        // }
        
    }
};

int main()
{
    Solution* s = new Solution();
    int input = -1236469;
    int output = s->reverse(input);
    printf("input = %d\noutput = %d\n", input, output);
}