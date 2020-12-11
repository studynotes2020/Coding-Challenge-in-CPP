#include <iostream>
#include <vector>

using namespace std;

// This is a very limited count sort, have to start from zero
vector<int> CountSort(int A[], int N) {
    // assume 0 <= A[i] < range of any element A[i]
    int *pi = new int[N]();
    vector<int> res;

    for (int i = 0; i < N; i++)
        pi[A[i]]++;

    for (int j = 0; j < N; j++)
        while (pi[j]) {
            res.push_back(j);
            pi[j] -= 1;
        }
    return res;
}

int main() {
    int A[5] = {3,1,4,0,2};
    int N = 5;
    vector<int> res = CountSort(A, N);
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
}