#include <iostream>
using namespace std;

class Person {
    string name;
    int age;
public:
    // Getter for name
    string getName() const {
        return name;
    }
    // Setter for name
    void setName(const string& newName) {
        name = newName;
    }
    // Getter for age
    int getAge() const {
        return age;
    }
    // Setter for age
    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        } else {
            cout << "Age cannot be negative." << endl;
        }
    }
};

int main() {
    Person p1;
    p1.setName("John Doe");
    p1.setAge(30);

    cout << "Name: " << p1.getName() << endl;
    cout << "Age: " << p1.getAge() << endl;
    return 0;
}