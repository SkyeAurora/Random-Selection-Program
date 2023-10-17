#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define NUMWINNERS 1   //随机选出的人数

using namespace std;

// 定义学生类
class Student {
public:
    string name;

    Student(string name) {
        this->name = name;
    }
};

int main() {

    SetConsoleOutputCP(CP_UTF8);  //UTF8编码输出
    // 设置随机数种子
    srand(time(0));

    vector<Student> students;
    
    // 从文本文件中读取学生姓名
    ifstream inputFile("students.txt");
    string name;
    while (inputFile >> name) {
        students.push_back(Student(name));
    }
    inputFile.close();
    
    int numStudents = students.size(); // 学生总数
    int numWinners = NUMWINNERS; // 随机选出的人数
    
    if (numWinners > numStudents) {
        cout << "随机选人的数目不能超过学生总数！" << endl;
        return 0;
    }
    
    vector<Student> winners;
    
    // 随机选人
    for (int i = 0; i < numWinners; ++i) {
        int randomIndex = rand() % students.size();
        winners.push_back(students[randomIndex]);
        students.erase(students.begin() + randomIndex); // 从候选集合中移除已选出的人员
    }
    
    // 输出选人结果
    cout << "随机选出的学生为：" << endl;
    for (const auto& winner : winners) {
        cout << winner.name << endl;
    }
    
    cout << "按任意键以退出：";
    cin.get();

    return 0;
}