#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class Student {
public:
    string id;
    string name;

    Student(const string& studentId = "", const string& studentName = "")
        : id(studentId), name(studentName) {
    }

    // 重载运算符，便于查找和比较
    bool operator==(const Student& other) const {
        return id == other.id && name == other.name;
    }

    bool operator<(const Student& other) const {
        return id < other.id;
    }

    void display() const {
        cout << "学号: " << id << ", 姓名: " << name;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    // 初始化学生信息
    void initializeStudents(int n) {
        students.clear();
        students.reserve(n); // 预分配空间提升效率
        for (int i = 0; i < n; i++) {
            string id, name;
            cin >> id >> name;
            students.emplace_back(id, name); // 使用emplace_back避免临时对象
        }
    }

    // 在指定位置插入学生
    int insertStudent(int position, const string& id, const string& name) {
        // 位置校验（注意：用户输入的位置从1开始）
        if (position < 1 || position > students.size() + 1) {
            return -1;
        }
        // 使用迭代器进行插入
        auto it = students.begin();
        advance(it, position - 1);
        students.emplace(it, id, name);
        return 0;
    }

    // 删除指定位置学生
    int removeStudent(int position) {
        if (position < 1 || position > students.size()) {
            return -1;
        }
        auto it = students.begin();
        advance(it, position - 1);
        students.erase(it);
        return 0;
    }

    // 根据姓名查找
    void findByName(const string& name) {
        auto it = find_if(students.begin(), students.end(),
            [&name](const Student& s) { return s.name == name; });

        if (it != students.end()) {
            int pos = distance(students.begin(), it) + 1;
            cout << pos << " " << it->id << " " << it->name << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    // 根据学号查找
    void findByNumber(const string& id) {
        auto it = find_if(students.begin(), students.end(),
            [&id](const Student& s) { return s.id == id; });

        if (it != students.end()) {
            int pos = distance(students.begin(), it) + 1;
            cout << pos << " " << it->id << " " << it->name << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    // 获取学生数量
    int getStudentCount() const {
        return students.size();
    }

    // 显示所有学生信息（用于调试）
    void displayAll() const {
        cout << "=== 当前所有学生信息 ===" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << i + 1 << ": ";
            students[i].display();
            cout << endl;
        }
    }
};

int main() {
    StudentManager manager;
    int n;

    // 读取初始学生数量和信息
    cin >> n;
    manager.initializeStudents(n);

    string command;
    while (cin >> command) {
        if (command == "end") {
            cout << manager.getStudentCount() << endl;
            break;
        }
        else if (command == "insert") {
            int i;
            string id, name;
            cin >> i >> id >> name;
            int result = manager.insertStudent(i, id, name);
            cout << result << endl;
        }
        else if (command == "remove") {
            int j;
            cin >> j;
            int result = manager.removeStudent(j);
            cout << result << endl;
        }
        else if (command == "check") {
            string type, value;
            cin >> type >> value;
            if (type == "name") {
                manager.findByName(value);
            }
            else if (type == "no") {
                manager.findByNumber(value);
            }
        }
        // 可选：每次操作后显示当前状态（调试用）
        // manager.displayAll();
    }

    return 0;
}