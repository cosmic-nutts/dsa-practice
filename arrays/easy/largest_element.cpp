#include <iostream>
#include <vector>
using namespace std;

int largestelement(const vector<int>& arr) {
    if (arr.empty()) {
        return 0; // or throw an exception
    }
    
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // fix: should be arr[i], not arr[i+1]
        }
    }
    return largest;
}

int main() {
    vector<int> numbers = {5, 10, 3, 8, 15, 7};
    cout << "Largest element: " << largestelement(numbers) << endl;
    return 0;
}
