#include <vector>
#include <iostream>
#include <string>
using namespace std;
const int NUM = 5;

int main()
{
    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "You will do extractly as told. you will enter\n"
         << NUM << "book titles and your ratings(0-10).\n";
    int i;
    for (i = 0; i < NUM; i++)
    {
        // 输入书名
        cout << "Enter title # " << i + 1 << ": ";
        getline(cin, titles[i]);
        
        // 输入评价
        cout << "Enter your rating(0-10):";
        cin >> ratings[i];
        cin.get(); // 用来接收输入后的回车
    }
    cout << "Thank you. You entered the following:\n"
         << "Rating\tBook\n";
    
    // 显示
    for (i = 0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
}