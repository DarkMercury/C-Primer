#include<iostream>
#include<string>
using namespace std;

void test01()
{
    // cin在遇到空格时就会停止读数
    // 输入利用空格隔开两个字符串
    // cin在第一次取的时候，只会读取前一个字符串，到空格结束，此时缓冲区还保留着前面输入的第二个字符串
    // 第二个cin就会直接从缓冲区取残留数据，而不会请求输入。
    // 124 321
    // b不会请求重新键入
    char a[100];
    cin>>a;
    for(int i=0;i<3;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    
    char b[100];
    cin>>b;
    for(int i=0;i<3;i++)
    {
        cout<<b[i];
    }
    cout<<endl;
}

void test02()
{
    char a[100];
    cin>>a;
    for(int i=0;i<3;i++)
    {
        cout<<a[i];
    }
    cout<<endl;

    // while (std::cin.get() != '\n') // 将剩余的字符串取完
    // continue;
    cin.ignore(100, '\n');// 也会提取空格，然后忽略，要不到‘/n’

    char b[100];
    cin>>b;
    for(int i=0;i<3;i++)
    {
        cout<<b[i];
    }
    cout<<endl;

}


int main()
{

    test02();
    return 0;
}