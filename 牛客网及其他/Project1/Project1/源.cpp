#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
a,,1,"b,"""
*/
int main() {
    string str;
    getline(cin, str);
    vector<string> res;
    int idx = 0;
    int pos = 0;
    bool flag = true;
    while (idx < str.size()) {
        string tmp;
        if (str[idx] == '"') {
            idx++;
            int match = 1;
            // ¼Ó¡°¡±×Ö·û´®
            while (idx < str.size()) {
                if (str[idx] == '"' && idx == str.size() - 1) {
                    match = 2;
                    break;
                } 
                if (str[idx] == '"' && str[idx + 1] == ',') {
                    match = 2;
                    break;
                }
                if (str[idx] == '"' && str[idx + 1] == '"') {
                    tmp += str[idx];
                    idx += 2;
                    continue;
                }
                tmp += str[idx];
                
                idx++;
            }
            if (match != 2) {
                flag = false;
                break;
            }
            if (tmp.empty()) tmp = "--";
            idx++; // È¥µô¶ººÅ
            res.push_back(tmp);
        } else {
            // Êý×ÖºÍÆÕÍ¨×Ö·û´®
            pos = str.find_first_of(',', idx);
            if (pos == string::npos) {
                pos = str.size();
            }
            tmp = str.substr(idx, pos - idx);
            if (tmp.empty()) tmp = "--";
            if (tmp.find('"') != string::npos) {
                flag = false;
                break;
            }
            res.push_back(tmp);
            idx = pos + 1;
        }
    }
    if (str.back() == ',') res.push_back("--");
    if (!flag) {
        cout << "ERROR" << endl;
    } else {
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << endl;
        }
    }

}