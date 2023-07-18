#include <bits/stdc++.h>

using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;
    
    void introduce() {
        cout << "Name: " << Name << '\n';
        cout << "Company: " << Company << '\n';
        cout << "Age: " << Age << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    Employee emplopee1;
    emplopee1.Name = "Plabon";
    emplopee1.Company = "Plabons Planet";
    emplopee1.Age = 22;

    emplopee1.introduce();

    Employee emplopee2;
    emplopee2.Name = "Elon Mask";
    emplopee2.Company = "Space X";
    emplopee2.Age = 51;

    emplopee2.introduce();
    
    return 0;
}
