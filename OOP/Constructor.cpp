#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    
    void introduce() {
        cout << "Name: " << Name << '\n';
        cout << "Company: " << Company << '\n';
        cout << "Age: " << Age << '\n';
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
