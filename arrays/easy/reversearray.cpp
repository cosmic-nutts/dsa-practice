#include <iostream>
using namespace std;

void reversed(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main() {
    int arr[] = {1, 5, 3, 99, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    reversed(arr, n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}