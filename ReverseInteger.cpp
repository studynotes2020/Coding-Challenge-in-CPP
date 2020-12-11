#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        while (x%10==0){ //tackle 10, 230...
            x=x/10;
        }
        
        vector<int> vecDigit;
        while(x){
            vecDigit.push_back(x%10);
            x = x/10;
        }
        int len=vecDigit.size(); 
        long revX=0;
        for(int i=0; i<len; i++) {
             revX += vecDigit[i]*pow(10,len-i);
             if (revX/10>INT_MAX) return 0;
             if (revX/10<INT_MIN) return 0;
        }
        return revX/10;

        
    }
};
