#include <math.h>
#include <string>
#include <climits>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        string temp;
        long long num=0;
        int sign=1;
        int i=0;
        for (; i<str.size(); i++){
            if (str[i]==' ');
            else if (str[i]=='+') {
                i++;
                break;
            }
            else if (str[i]=='-'){
                sign=-1;
                i++;
                break;
            }
            else break;
        }
        
        for (; i<str.size(); i++){
            if (str[i]>='0' && str[i]<='9'){
                num = num*10 + str[i]-'0';
            }
            else break;
            
            if (num>INT_MAX) {
                if(sign==1) return INT_MAX;
                else return INT_MIN;
                
            }

        }
        return sign*num;
        

    }
};

class Solution2 {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        istringstream in(str);
        int num;
        in >> num;
        return num;
        
        
    }
};

int main() {
    string str = "235";
    int a = Solution().myAtoi(str);
    cout << a << endl;
    int b = Solution2().myAtoi(str);
    cout << b << endl;
    return 0;
}
