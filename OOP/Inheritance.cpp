#include <bits/stdc++.h>

using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee {
protected:
    string Name;

private:
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

class Developer : public Employee { // if we don't use the public word then we can't use the methods of parent class
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age) {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void fixBug() {
        cout << Name << ' '; //As Name is Protracted so we can use it
        cout << "is fixing Bug using " << FavProgrammingLanguage;
        cout << " at " << getCompany() << '\n'; //As Company is private so we can't direct access it. so we used the getter function 
    }
};

class Teacher : public Employee {
public:
    string Subject;

    Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
        Subject = subject;
    }

    void teching() {
        cout << Name << " is teching " << Subject << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    Employee emplopee1 = Employee("Plabon", "Plabons Planet", 22);


    Employee emplopee2 = Employee("Elon Mask", "Space X", 51);

    emplopee1.AskForPromotion();

    emplopee2.AskForPromotion();

    Developer dev = Developer("Plabon", "XYZ", 22, "C++");

    dev.fixBug();
    dev.AskForPromotion();

    Teacher tc = Teacher("X", "XY", 33, "Bengali");
    tc.teching();
    tc.AskForPromotion();


    return 0;
}
