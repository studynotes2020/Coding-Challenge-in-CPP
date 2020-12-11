#include <iostream>
#include <vector>

using namespace std;

int main() {
	double arr[5] = {21.1, 32.8, 23.4, 45.2, 37.4};
	double *pt = arr; // pt points to arr[0]
	cout << *pt << endl;

	++pt; // pt points to arr[1]
	cout << *pt << endl;

	double x = *++pt; // increment pointer then take the value
	cout << *pt << endl;

	++*pt; // increment pointed-to value
    cout << *pt << endl;

    (*pt)++; // increment pointed-to value
    cout << *pt << endl;

    x = *pt++;
    cout << x << ' ' << *pt << endl;

    int guests = 0;
    while (guests++ < 3) cout << guests << '\t';
    cout << endl;

    guests = 0;
    while (++guests < 3) cout << guests << '\t';
}