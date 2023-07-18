#include <bits/stdc++.h>

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;

public:
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

    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        Age = age;
    }

    int getAge() {
        return Age;
    }
    
    void AskForPromotion () {
        if (Age >= 30) {
            cout << "Congratulations " << Name << "! You got Promotion!" << '\n';
        }
        else {
            cout << "Sorry " << Name << "! No Promotion for you!" << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    Employee emplopee1 = Employee("Plabon", "Plabons Planet", 22);


    Employee emplopee2 = Employee("Elon Mask", "Space X", 51);

    emplopee1.AskForPromotion();

    emplopee2.AskForPromotion();

    
    return 0;
}
