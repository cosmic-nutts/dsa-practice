#include <iostream>
#include <climits>
using namespace std;


int maxelement(int arr[], int n){
    int max=INT_MIN; // Initialize max to the smallest possible integer
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int main() {
    int arr[] = {1, 5, 3, 99, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum element in array: " << maxelement(arr, n) << endl;
    return 0;
}