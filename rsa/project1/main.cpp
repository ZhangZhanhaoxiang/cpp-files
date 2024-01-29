#include<iostream>
#include<algorithm>
//#include<cmath>
#include<gmpxx.h>
#include<string>
using namespace std;

void Encrypt(mpz_class&, int, mpz_class, int);

int main()
{
    int p=229, q=619;
    int n=p*q;
    int phi=(p-1)*(q-1);

    //找公钥e
    int e=phi;
    while (__gcd(phi,e) != 1) e--;

    //找私钥d
    int d=phi;
    while (e * d % phi != 1) d--;

    cout<<"Public Key (e, n) = ("<<e<<", "<<n<<")"<<endl;
    cout<<"Private Key (d, n) = ("<<d<<", "<<n<<")"<<endl;

    mpz_class plaintext,ciphertext,decryptext;
    cin>>plaintext;

    //加密
    //mpz_class P(plaintext);
    //cout<<P.get_si()<<endl;
    //mpz_pow_ui(P,e);
    Encrypt(&ciphertext,n,plaintext,e);
    cout<<ciphertext<<endl;
    
    //解密
    //mpz_class D(ciphertext);
    Encrypt(&decryptext,n,ciphertext,d);
    cout<<decryptext<<endl;


    return 0;
    
}

void Encrypt(mpz_class& ans, int a, mpz_class b, int c)
{
    ans=1;
    a = a % c;
    while (b>0)
    {
        if (b % 2 == 1) ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    //return ans.get_str();
}