#include <iostream>
#include <string>
#include <vector>

struct Review {
    std::string title;
    int rating;
};

// 对Review进行输入
// 输入正确返回true
// 输入错误返回false
bool FillReview(Review & rr); 

// 显示Review
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;
    // 一个vector容器相当于一个数组
    vector<Review> books;
    Review temp;

    // 如果Review输入没有错误
    // 将Review添加到Vector的容器中
    while (FillReview(temp))
        books.push_back(temp);

    // Vector的内置函数，数组的数量
    int num = books.size();
    
    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
            << "Rating\tBook\n";
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        cout << "Reprising:\n"
            << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        vector <Review> oldlist(books);     // copy constructor used
        if (num > 3)
        {
            // remove 2 items
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            // insert 1 item
            books.insert(books.begin(), oldlist.begin() + 1,
                        oldlist.begin() + 2);
            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    // std::cin.get();
	return 0;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating; 
    
    // 判断cin的输入是否为int，因为rating的数据类型为int
    if (!std::cin)  
        return false;
    
    // 将剩余的字符串取完
    // get rid of rest of input line
    while (std::cin.get() != '\n') 
        continue;
    
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl; 
}