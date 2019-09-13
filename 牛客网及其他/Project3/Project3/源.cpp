#include<string>
#include<iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    string str;
    while (input) {
        int last = input & 0x1;
        str.push_back('0' + last);
        input >>= 1;
    }
    int count = 0;
    int first_pos = -1;
    if (str.size() > 2) {
        for (int i = 0; i < str.size() - 2; i++) {
            if (str.substr(i, 3) == "101") {
                count++;
                if (first_pos == -1) first_pos = i;
            }
        }
    }

    cout << count << ' ' << first_pos;
}