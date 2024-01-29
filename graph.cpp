#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    for (int i = 1; i <= 166; ++i)
    {
        cout << "_";
    }
    cout << endl;
    for (float y = 1.8; y >= -1.8; y -= 0.1)
    {
        cout << "|";
        for (float x = -4; x <= 4; x += 0.05)
        {
            if (sin(x*3)-y*3 <= 0.0)
            {
                cout << ".";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "|\n";
    }
    for (int i = 1; i <= 166; ++i)
    {
        cout << "-";
    }
    cout << endl;
    return 0;
}

// AADDAD AC
// DDDDABCD ABC
// BCBDCBCB ABD BCD
// DCDDCAB AD ABCD
