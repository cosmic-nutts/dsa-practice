#include <iostream>
using namespace std;

pair<int,int> countoddeven(int *arr,int n){
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    return make_pair(odd, even);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> result = countoddeven(arr, n);
    cout << "Odd numbers: " << result.first << endl;
    cout << "Even numbers: " << result.second << endl;
    return 0;
}