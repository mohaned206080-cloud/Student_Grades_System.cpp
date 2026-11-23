#include <bits/stdc++.h>
using namespace std;
class Student {
    private:
    string name;
    int age;
    vector<pair<string,int>>courses;
    public:
    static int count;
    Student(string name,int age) {
        this->name = name;
        this->age = age;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    void addcourse(string course,int grade) {
        bool valid = true;
        int courseindex = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].first== course) {
                valid = false;
                break;
            }
        }
        if (valid=true) {
            courses.push_back({course,grade});
            cout<<"course: "<<course<<" added successfully"<<endl;
        }else {
            cout<<"course is already exist"<<endl;
        }
    }
    void removecourse(string course) {
        bool valid = false;
        int courseindex = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].first == course) {
                valid = true;
                break;
            }
        }
        if (valid==true) {
            courses.erase(courses.begin()+courseindex);
            cout<<"course "<<course<<" removed"<<endl;
        }else {
            cout<<"course is not exist"<<endl;
        }
    }
    void display() {
        double avarage = 0;
        cout<<count<<"- Student: "<<name<<" Age: "<<age<<endl;
        if (courses.empty()) {
            cout<<" course: empty"<<endl;
        }else {
            for (int i = 0; i < courses.size(); i++) {
                cout<<" "<<i+1<<". course:"<<courses[i].first<<" grade:"<<courses[i].second<<endl;
                avarage += courses[i].second;
            }
        }
        avarage /= courses.size();
        cout<<" Average: "<<avarage<<" | Grade: ";
        if (avarage >= 90) {
            cout<<"A";
        }else if (avarage >= 80) {
            cout<<"B";
        }else if (avarage >= 70) {
            cout<<"C";
        }else if (avarage >= 60) {
            cout<<"D";
        }else if (avarage >= 50) {
            cout<<"E";
        }else {
            cout<<"F";
        }
        cout<<endl;
        count++;
    };
};
    int Student::count=1;
class Studentmanager {
    private:
    vector<Student> students;
    public:
    void addStudent() {
        string name;
        int age;
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<endl;
        cout<<"Enter age: ";
        cin>>age;
        cout<<endl;
        bool valid = true;
        int studentindex = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                valid = false;
                studentindex = i;
                break;
            }
        }
        if (valid==true) {
            students.push_back(Student{name,age});
            cout<<"Student \""<<name<<"\" added successfully"<<endl;
        }else {
            cout<<"student \""<<name<<"\" is already exist"<<endl;
        }
    }
    void removeStudent() {
        string name;
        cout<<"Enter name to remove: ";
        cin.ignore();
        getline(cin,name);
        cout<<endl;
        bool valid = true;
        int studentindex = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                valid = false;
                studentindex = i;
                break;
            }
        }
        if (valid==false) {
            students.erase(students.begin()+studentindex);
            cout<<"student \""<<name<<"\" removed"<<endl;
        }else {
            cout<<"student is no exist"<<endl;
        }
    }
    void addCourse() {
        string course;
        string name;
        int grade;
        cout<<"Enter student name: ";
        cin.ignore();
        getline(cin,name);
        cout<<endl;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                cout<<"Enter course name: ";
                cin.ignore();
                getline(cin,course);
                cout<<endl;
                cout<<"Enter course grade: ";
                cin>>grade;
                cout<<endl;
                students[i].addcourse(course,grade);
                return;
            }
            cout<<"student is not exist"<<endl;
        }
    }
    void removeCourse() {
        string course;
        string name;
        cout<<"Enter Student name: ";
        cin.ignore();
        getline(cin,name);
        cout<<endl;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName() == name) {
                cout<<"Enter course name to delete: ";
                cin>>course;
                cout<<endl;
                students[i].removecourse(course);
                return;
            }else {
                cout<<"student is not exist"<<endl;
                return;
            }
        }
    }
    void display() {
        if (students.empty()) {
            cout<<"No students found"<<endl;
            return;
        }
        for (int i = 0; i < students.size(); i++) {
            students[i].display();
        }
    }
};
void menu() {
    Studentmanager s;
    bool valid = true;
    while (valid==true) {
    cout<<"=== Student grade System ==="<<endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Remove Student"<<endl;
    cout<<"3. Add Course"<<endl;
    cout<<"4. Remove Course"<<endl;
    cout<<"5. Display Students"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    cout<<endl;
        switch (choice) {
            case 1: s.addStudent();break;
            case 2: s.removeStudent();break;
            case 3: s.addCourse();break;
            case 4: s.removeCourse();break;
            case 5: s.display();break;
            case 6: {
                cout<<"Goodbye"<<endl;
                valid = false;
                break;
            }
            default: cout<<"Invalid choice"<<endl;break;
        }
    }
}
int main() {
    menu();
    return 0;
}
