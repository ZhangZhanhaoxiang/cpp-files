#include<iostream>
#include<random>

using namespace std;

int main()
{
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> distribution(1,6);
    int a=distribution(gen);
    cout << a << endl;
    return 0;
}
