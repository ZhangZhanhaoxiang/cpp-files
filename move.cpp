// 移动语义的使用
#include<iostream>
using namespace std;

class Holder
{
public:
    Holder(int size)                                        // Constructor
    {
        m_data = new int[size];
        m_size = size;
        cout << "默认构造函数" << endl;
    }

    ~Holder()                                               // Destructor
    {
        delete[] m_data;
        cout << "析构函数" << endl;
    }

    Holder(const Holder& other)
    {
        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
        cout << "复制构造函数" << endl;
    }

    Holder& operator=(const Holder& other)
    {
        cout << "复制赋值运算符" << endl;
        if(this == &other) return *this;
        delete[] m_data;
        m_data = new int[other.m_size];
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
        m_size = other.m_size;
        return *this;
    }

    Holder(Holder&& other)                                  // <-- rvalue reference in input
    {
        cout << "移动构造函数" << endl;
        m_data = other.m_data;                                    // (1)
        m_size = other.m_size;
        other.m_data = nullptr;                                   // (2)
        other.m_size = 0;
    }

    Holder& operator=(Holder&& other)                           // <-- rvalue reference in input
    {
        cout << "移动赋值运算符" << endl;
        if (this == &other) return *this;
        delete[] m_data;                                          // (1)
        m_data = other.m_data;                                    // (2)
        m_size = other.m_size;
        other.m_data = nullptr;                                   // (3)
        other.m_size = 0;
        return *this;
    }

private:
    int*   m_data;
    size_t m_size;
};


Holder createHolder(int size)
{
    cout << "调用createHolder()函数" << endl;
    return Holder(size);
}


int main()
{
    Holder h1(1000);                                        // regular constructor
    Holder h2(h1);                                            // copy constructor (lvalue in input)
    Holder h3 = createHolder(2000);                           // move constructor (rvalue in input) (1)
    h2 = h3;                                                  // assignment operator (lvalue in input)
    h2 = createHolder(500);
    return 0;
}
