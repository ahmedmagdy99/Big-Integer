#include <bits/stdc++.h>

using namespace std;
#ifndef BIGINT_H
#define BIGINT_H


class BigInt
{
private:
    string decStr;
    int decInt;
public:
    BigInt(string );
    BigInt(int );
    BigInt operator+ (BigInt&);
    BigInt operator- (BigInt&);
    bool operator==(BigInt m);
    bool operator!=(BigInt);
    bool operator> (BigInt m);
    bool operator< (BigInt m);
    BigInt operator--(int );
    BigInt operator++(int );
    friend ostream& operator<<(ostream& out, const BigInt& in );
    friend istream& operator>>(istream& in, BigInt& number);
};


#endif // BIGINT_H
