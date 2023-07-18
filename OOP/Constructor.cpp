#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    string name;
    string company;
    int age;

    Employee(string Name, string Company, int Age) {
        name = Name;
        company = Company;
        age = Age;
    }
    
    void introduce() {
        cout << "Name: " << name << '\n';
        cout << "Company: " << company << '\n';
        cout << "Age: " << age << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    Employee emplopee1 = Employee("Plabon", "Plabons Planet", 22);

    emplopee1.introduce();

    Employee emplopee2 = Employee("Elon Mask", "Space X", 51);

    emplopee2.introduce();
    
    return 0;
}
