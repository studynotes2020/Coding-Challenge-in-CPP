#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

//bottom left corner A,B,E,F 
//top right C,D,G,H

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int  total = (C-A)*(D-B)+(G-E)*(H-F);
        
        int64_t  left = max(A, E); 
        int64_t  down = max(B, F);
        int64_t  right = min(C,G);
        int64_t  up = min(D,H);
        
        int  overlap=0;

        if(up>down && right>left){
            overlap = (up - down)*(right - left);
        }
        
        return total - overlap;
    }
};

int main() {
    int A = 1, B = 2, C = 3, D = 4;
    int E = 5, F = 6, G = 7, H = 8;
    cout << Solution().computeArea(A, B, C, D, E, F, G, H) << endl;

    return 0;
}
