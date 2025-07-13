#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
};

int main() {
    Person p1;
    p1.name = "John Doe";
    p1.age = 30;

    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    return 0;
}