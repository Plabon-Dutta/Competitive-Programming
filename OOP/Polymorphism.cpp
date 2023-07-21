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

    virtual void work() {
        cout << Name << " is checking email and performing his task" << '\n';
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

    void work() {
        cout << Name << " is writing codes in " << FavProgrammingLanguage << '\n';
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

    Developer dev = Developer("Plabon", "XYZ", 22, "C++");

    dev.work();

    Teacher tc = Teacher("X", "XY", 33, "Bengali");
    tc.work();

    Employee *emp1 = &dev;
    Employee *emp2 = &tc;

    emp1 -> work();
    emp2 -> work();

    return 0;
}
