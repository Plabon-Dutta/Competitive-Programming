#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    string name;
    string company;
    int age;
    
    void introduce() {
        cout << "Name: " << name << '\n';
        cout << "Company: " << company << '\n';
        cout << "Age: " << age << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    Employee emplopee1;
    emplopee1.name = "Plabon";
    emplopee1.company = "Plabons Planet";
    emplopee1.age = 22;

    emplopee1.introduce();

    Employee emplopee2;
    emplopee2.name = "Elon Mask";
    emplopee2.company = "Space X";
    emplopee2.age = 51;

    emplopee2.introduce();
    
    return 0;
}
