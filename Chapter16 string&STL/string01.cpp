#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


void test_01()
{
    // 在C++中string给出了9种构造函数
    using namespace std;
    //
    string one("Lottery Winner!"); // 将string对象初始化为s指向的char
    cout << one << endl;           // overloaded <<
    
    string two(20, '$');           // ctor #2
    cout << two << endl;
   
    string three(one); // ctor #3
    cout << three << endl;
    one += " Oops!"; // overloaded +=
    cout << one << endl;
    two = "Sorry! That was ";
    three[0] = 'P';

    string four;        // ctor #4
    four = two + three; // overloaded +, =
    cout << four << endl;
    char alls[] = "All's well that ends well";

    string five(alls, 20); // ctor #5
    cout << five << "!\n";

    string six(alls + 6, alls + 10); // ctor #6
    cout << six << ", ";
    string seven(&five[6], &five[10]); // ctor #6 again
    cout << seven << "...\n";

    string eight(four, 7, 16); // ctor #7
    cout << eight << " in motion!" << endl;
    // std::cin.get();
}

void test_02()
{
    // 为char输入字符串的3种方式
    // cin 空格暂停，并从空格开始读
    // getline() 读取一行，并丢弃‘\n’
    // get() 读取一行，不、不丢弃‘\n’

    // string 有两种方式
    // cin
    // getline()

    string stuff;
    cin >> stuff;
    getline(cin, stuff); // 从cin读到stuff
}

void test_03()
{
    // 使用string来读取一个文件
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;

    while (fin) // while input is good
    {
        
        ++count;
        getline(fin, item, ':');
        // 将fin中的数据输入到item中使用：分开
        // 指定分割符后换行符将视为常规字符,所以有俩空格
        cout << count << ": " << item << endl;
    }
    cout << "Done\n";
    fin.close();
}

void test_04()
{
    // 使用字符串
    // 1. 可以对字符进行比较，String类对全部的6个关系运算符进行了重载(> < == !=)
    // 2. 可以确定字符串的长度size() length() 为何两个函数完成相同的任务：length为较早的string类 size为了兼容stl
    // 3. 以多种方式在字符串中搜索给定的字符
    // 功能太多了
}

int main()
{
    // test_01();
    test_03();
    return 0;
}