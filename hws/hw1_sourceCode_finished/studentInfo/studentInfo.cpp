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

    // ��������������ڲ��ҺͱȽ�
    bool operator==(const Student& other) const {
        return id == other.id && name == other.name;
    }

    bool operator<(const Student& other) const {
        return id < other.id;
    }

    void display() const {
        cout << "ѧ��: " << id << ", ����: " << name;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    // ��ʼ��ѧ����Ϣ
    void initializeStudents(int n) {
        students.clear();
        students.reserve(n); // Ԥ����ռ�����Ч��
        for (int i = 0; i < n; i++) {
            string id, name;
            cin >> id >> name;
            students.emplace_back(id, name); // ʹ��emplace_back������ʱ����
        }
    }

    // ��ָ��λ�ò���ѧ��
    int insertStudent(int position, const string& id, const string& name) {
        // λ��У�飨ע�⣺�û������λ�ô�1��ʼ��
        if (position < 1 || position > students.size() + 1) {
            return -1;
        }
        // ʹ�õ��������в���
        auto it = students.begin();
        advance(it, position - 1);
        students.emplace(it, id, name);
        return 0;
    }

    // ɾ��ָ��λ��ѧ��
    int removeStudent(int position) {
        if (position < 1 || position > students.size()) {
            return -1;
        }
        auto it = students.begin();
        advance(it, position - 1);
        students.erase(it);
        return 0;
    }

    // ������������
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

    // ����ѧ�Ų���
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

    // ��ȡѧ������
    int getStudentCount() const {
        return students.size();
    }

    // ��ʾ����ѧ����Ϣ�����ڵ��ԣ�
    void displayAll() const {
        cout << "=== ��ǰ����ѧ����Ϣ ===" << endl;
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

    // ��ȡ��ʼѧ����������Ϣ
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
        // ��ѡ��ÿ�β�������ʾ��ǰ״̬�������ã�
        // manager.displayAll();
    }

    return 0;
}