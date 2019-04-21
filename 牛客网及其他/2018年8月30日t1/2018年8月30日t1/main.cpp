#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v1(n);
    for (int i = 0; i < v1.size(); i++)
    {
        cin >> v1[i];
    }
    vector<set<char>> v2(m, set<char>());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v2[i].insert(v1[j][i]);
        }
    }
    string result(m, ' ');


    //for (int i = 0; i < m; i++)
    //{
    //    result[i] = v2[i];
    //}
    int flag = 0;
    //for (int i = 0; i < n; i++)
    //{
    //    if (v1[i] == result)
    //    {
    //        flag = 1;
    //    }
    //}
    if (flag)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (v2[i][j] != v2[i][0])
                {
                    result[i] = v2[i][j];
                    flag      = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (v1[i] == result)
                        {
                            flag = 1;
                        }
                    }
                    if (flag)
                        break;
                }
            }
            if (!flag)
                break;
        }
    }
    if (flag)
    {
        cout << '-';
    }
    else
    {
        cout << result;
    }
}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<string> v1(n);
//    for (int i = 0; i < v1.size(); i++)
//    {
//        cin >> v1[i];
//    }
//    vector<string> v2(m, string(n, ' '));
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            v2[i][j] = v1[j][i];
//        }
//    }
//    string result(m, ' ');
//    for (int i = 0; i < m; i++)
//    {
//        string& v = v2[i];
//        sort(v.begin(), v.end());
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        result[i] = v2[i][0];
//    }
//    int flag = 0;
//    for (int i = 0; i < n; i++)
//    {
//        if (v1[i] == result)
//        {
//            flag = 1;
//        }
//    }
//    if (flag)
//    {
//        for (int i = m - 1; i >= 0; i--)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (v2[i][j] != v2[i][0])
//                {
//                    result[i] = v2[i][j];
//                    flag      = 0;
//                    for (int i = 0; i < n; i++)
//                    {
//                        if (v1[i] == result)
//                        {
//                            flag = 1;
//                        }
//                    }
//                    if (flag)
//                        break;
//                }
//            }
//            if (!flag)
//                break;
//        }
//    }
//    if (flag)
//    {
//        cout << '-';
//    }
//    else
//    {
//        cout << result;
//    }
//}