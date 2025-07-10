#include <iostream>
using namespace std;

void prec(int n) {
    if (n > 10) return;
    cout << n << endl;
    prec(n + 1);
}

int main() {
    prec(0);
    return 0;
}