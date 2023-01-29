#include <iostream>
#include <string>
#include <memory>
using namespace std;

void test01()
{
    // 智能指针使用的注意事项
    auto_ptr<string> films[5] = {
        auto_ptr<string>(new string("Fowl Balls")),
        auto_ptr<string>(new string("Duck Walks")),
        auto_ptr<string>(new string("Chicken Runs")),
        auto_ptr<string>(new string("Turkey Runs")),
        auto_ptr<string>(new string("Goose Eggs"))};

    // 在这里pwin指向 "Chicken Runs"
    // films[2]也指向 "Chicken Runs"
    // 因为在auto_ptr中pwin接管了films[2]的所有权限，再调用films[2]就会出现问题
    auto_ptr<string> pwin;
    pwin = films[2];

    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << endl;
}

void test02()
{
    // 智能指针使用的注意事项
    // shared_ptr有引用计数器
    // 只有引用计数器为空时才会释放内存空间

    shared_ptr<string> films[5] = {
        shared_ptr<string>(new string("Fowl Balls")),
        shared_ptr<string>(new string("Duck Walks")),
        shared_ptr<string>(new string("Chicken Runs")),
        shared_ptr<string>(new string("Turkey Runs")),
        shared_ptr<string>(new string("Goose Eggs"))};

    // 引用计数器变为2
    shared_ptr<string> pwin;
    pwin = films[3];

    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << endl;
}

unique_ptr<string> demo(const char *s)
{
    // unique_ptr的常见用法
    unique_ptr<string> temp(new string(s));
    return temp;
}

void test03()
{
    unique_ptr<string> ps;
    ps = demo("unique string");
    cout << *ps << endl;
}

int main()
{
    test03();
    return 0;
}