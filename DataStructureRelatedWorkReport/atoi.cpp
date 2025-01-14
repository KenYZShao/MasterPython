#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        bool start = false;
        int sign = 1;
        long res = 0;
        for (char c : s) {
            if ('0' <= c && c <= '9') {//means c= 0,1,2,3,4,5,6,7,8,9
                start = true;
                res = res * 10 + (c - '0');
                if (res > INT_MAX) {
                    break;
                }
            }
            else if (!start && c == ' ') {//!start avoids i/p="   +0 123"
                continue;
           }
            else if (!start && c == '+') {//handling -+12
                start = true;
            }
            else if (!start && c == '-') {//handling +-12 出现第二个的时候start已经拨true,不能进入else if循环，而进入break
                sign = -1;
                start = true;
            }
            else {
                break;
            }
        }
        res *= sign;
        if (res < INT_MIN) {
            res = INT_MIN;
        }
        else if (res > INT_MAX) {
            res = INT_MAX;
        }
        return int(res);
    }
};

void main() {
    Solution obj;
    cout << obj.myAtoi("+1");//create object!!!
    //Solution::myAtoi("-12");
}
