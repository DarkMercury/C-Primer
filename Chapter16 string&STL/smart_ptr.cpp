#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Report
{
private:
    string str;

public:
    Report(const string s) : str(s) { cout << "Object Created!\n"; }
    ~Report(){cout<<"Object Delete!\n";}
    // 这个const声明这个函数为只读函数
    // 作用：1.提高程序的可读性 2.提高程序的健壮性
    // 声明了const后该函数不能修改成员数据
    void comment() const {cout <<str<<endl;}
};


void test()
{
    int a = 10;
    {
        int b = 2;
        b = 1;
        cout<<b;
    }
    cout<<a;
    // 外部不能使用{}中的b

}



int main()
{
    // 花括号的作用是标明作用域
    {
        auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment(); // to invoke member function
    }
    {
    
        shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment(); // to invoke member function
    }
    {
        unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment(); // to invoke member function
    }
    return 0;
}
