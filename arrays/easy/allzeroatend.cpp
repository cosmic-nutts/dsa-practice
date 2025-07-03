#include <iostream>
using namespace std;

void allzeroend(int *arr,int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==0 && arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]!=0 && arr[j]==0){
            i++;
            j--;
        }
        else if(arr[i]==0 && arr[j]==0){
            j--;
        }
        else{
            i++;
        }
    }
}

int main() {
    int arr[] = {1, 0, 0, 4, 3, 0, 2, 0, 9, 0, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    allzeroend(arr, n);
    cout << "Array after moving all zeroes to end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}