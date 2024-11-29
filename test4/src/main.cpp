#include "../includes/Lists.hpp"
#include <cstdint>
#include <iostream>
#include <stdlib.h>

class Student
{
private:
    std::wstring name;
    uint16_t number = 0;
    int32_t exp = 0;

public:
    Student() = default;
    Student(const std::wstring &name, uint16_t number, int32_t exp) :
        name(name), number(number), exp(exp) {}
    // getter
    std::wstring getName() const { return name; }
    uint16_t getNumber() const { return number; }
    int32_t getExp() const { return exp; }
    // setter
    void setName(std::wstring name) { this->name = name; }
    void setNumber(uint16_t number) { this->number = number; }
    void setExp(int32_t exp) { this->exp = exp; }
    bool operator>=(const Student &other) const { return exp >= other.exp; }
    bool operator<=(const Student &other) const { return exp <= other.exp; }
    bool operator>(const Student &other) const { return exp > other.exp; }
    bool operator<(const Student &other) const { return exp < other.exp; }
};

int main()
{
    // setlocale(LC_CTYPE, "Chinese_China.936");
    // system("chcp 65001 > nul");
    // setlocale(LC_ALL, "Chinese_China");
    setlocale(LC_CTYPE, "");
    Lists<Student> students;
    bool IsQuit = false;
    while (!IsQuit)
    {
        std::wcout << L"课堂经验值管理小程序" << "\n"
                   << L"1 ------ 建立新的学生经验值表" << "\n"
                   << L"2 ------ 插入学生" << "\n"
                   << L"3 ------ 删除学生" << "\n"
                   << L"4 ------ 显示全部学生信息" << "\n"
                   << L"5 ------ 为某学号学生加指定经验值" << "\n"
                   << L"6 ------ 为某学号学生减指定经验值" << "\n"
                   << L"7 ------ 按姓名查找学生经验值" << "\n"
                   << L"8 ------ 求经验值最高的学生信息" << "\n"
                   << L"9 ------ 排序" << "\n"
                   << L"0 ------ 退出程序" << "\n"
                   << L"请选择菜单编号[0-8):";
        int choice;
        std::wcin >> choice;
        switch (choice)
        {
        case 1:
            // 建立学生经验值表
            {
                if (!students.empty())
                {
                    students.clear();
                }
                std::wcout << L"学生经验值表已建立";
            }
            break;
        case 2:
            // 插入学生
            {
                std::wstring name;
                uint16_t number;
                int32_t exp;
                std::wcin.ignore();
                std::wcout << L"请输入学生姓名：";
                std::getline(std::wcin, name);
                std::wcout << L"请输入学生学号：";
                std::wcin >> number;
                std::wcout << L"请输入学生经验值：";
                std::wcin >> exp;
                Student student(name, number, exp);
                students.push_back(student);
                std::wcout << L"学生信息插入成功！" << "\n";
            }
            break;
        case 3:
            // 删除学生
            {
                std::wstring name;
                std::wcin.ignore();
                std::wcout << L"请输入要删除的学生姓名：";
                std::getline(std::wcin, name);
                auto it = students.begin();
                bool found = false;
                while (it != students.end())
                {
                    if (it->getName() == name)
                    {
                        students.remove(it);
                        std::wcout << L"学生信息删除成功！" << "\n";
                        found = true;
                        break;
                    }
                    it++;
                }
                if (it == students.end() && !found)
                {
                    std::wcout << L"没有找到该学生！" << "\n";
                }
            }
            break;
        case 4:
            // 显示全部学生信息
            {
                if (students.empty())
                {
                    std::wcout << L"学生经验值表为空！" << "\n";
                }
                else
                {
                    std::wcout << L"学号\t姓名\t经验值" << "\n";
                    for (const auto &it : students)
                    {
                        std::wcout << it.getNumber() << "\t" << it.getName() << "\t" << it.getExp() << "\n";
                    }
                }
                // std::wcout << "请按任意键返回......";
            }
            break;
        case 5:
            // 为某学号学生加指定经验值
            {
                uint16_t number;
                int32_t exp;
                std::wcin.ignore();
                std::wcout << L"请输入学生学号：";
                std::wcin >> number;
                std::wcout << L"请输入要增加的经验值：";
                std::wcin >> exp;
                auto it = students.begin();
                while (it != students.end())
                {
                    if (it->getNumber() == number)
                    {
                        it->setExp(it->getExp() + exp);
                        std::wcout << L"学生信息修改成功！" << "\n";
                        break;
                    }
                    it++;
                }
                if (it == students.end())
                {
                    std::wcout << L"没有找到该学生！" << "\n";
                }
            }
            break;
        case 6:
            // 为某学号学生减指定经验值
            {
                uint16_t number;
                int32_t exp;
                std::wcin.ignore();
                std::wcout << L"请输入学生学号：";
                std::wcin >> number;
                std::wcout << L"请输入要减少的经验值：";
                std::wcin >> exp;
                auto it = students.begin();
                while (it != students.end())
                {
                    if (it->getNumber() == number)
                    {
                        it->setExp(it->getExp() - exp);
                        std::wcout << L"学生信息修改成功！" << "\n";
                        break;
                    }
                    it++;
                }
                if (it == students.end())
                {
                    std::wcout << L"没有找到该学生！" << "\n";
                }
            }
            break;
        case 7:
            // 按姓名查找学生经验值
            {
                std::wstring name;
                std::wcin.ignore();
                std::wcout << L"请输入要查找的学生姓名：";
                std::getline(std::wcin, name);
                auto it = students.begin();
                while (it != students.end())
                {
                    if (it->getName() == name)
                    {
                        std::wcout << L"学号：" << it->getNumber() << "\n"
                                   << L"姓名：" << it->getName() << "\n"
                                   << L"经验值：" << it->getExp() << "\n";
                        break;
                    }
                    it++;
                }
                if (it == students.end())
                {
                    std::wcout << L"没有找到该学生！" << "\n";
                }
            }
            break;
        case 8:
            // 求经验值最高的学生信息
            {
                if (students.empty())
                {
                    std::wcout << L"学生经验值表为空！" << "\n";
                }
                else
                {
                    auto it = students.begin();
                    auto max_it = it;
                    while (it != students.end())
                    {
                        if (it->getExp() > max_it->getExp())
                        {
                            max_it = it;
                        }
                        it++;
                    }
                    std::wcout << L"学号：" << max_it->getNumber() << "\n"
                               << L"姓名：" << max_it->getName() << "\n"
                               << L"经验值：" << max_it->getExp() << "\n";
                }
            }
            break;
        case 9:
            // 排序
            students.QuickSort();
            break;
        case 0:
            // 退出程序
            return 0;
            break;
        default:
            std::wcout << L"输入错误，请重新输入！" << "\n";
            break;
        }
        std::wcout << "\n";
#ifdef _WIN32  
        system("pause");
        system("cls");
#endif
#ifdef __linux__
        std::wcin.ignore();
        std::wcout << L"请按任意键继续";
        std::wcin.get();
        system("clear");
#endif
    }
}