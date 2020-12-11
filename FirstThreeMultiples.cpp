#include <iostream>
#include <vector>

std::vector<int> first_three_multiples(int num) {
    std::vector<int> arr;
    for(int i = 1; i <= 3; i++) {
        arr.push_back(num * i);
    }
    return arr;
}

int main() {
    for (int element : first_three_multiples(8)) {
        std::cout << element << "\n";
    }

}
