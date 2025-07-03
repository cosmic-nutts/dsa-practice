#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 3, 99, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 99;
    int result = linearSearch(arr, n, x);
    cout << "Element found at index: " << result << endl;
    return 0;
}