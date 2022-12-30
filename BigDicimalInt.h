#ifndef BIGDICIMALINT_H
#define BIGDICIMALINT_H
#include<iostream>
using namespace std;
class BigDecimalInt
{
    public:
BigDecimalInt();
BigDecimalInt (string decStr);
BigDecimalInt (int decInt);
BigDecimalInt operator+ (BigDecimalInt anotherDec);
BigDecimalInt operator- (BigDecimalInt anotherDec);
bool operator< (BigDecimalInt anotherDec);
bool operator> (BigDecimalInt anotherDec);
bool operator==(BigDecimalInt anotherDec);
BigDecimalInt operator= (BigDecimalInt anotherDec);
int size();
int sign();
friend ostream & operator<<(ostream & out, BigDecimalInt& b);
       virtual ~BigDecimalInt();

    protected:

    private:
         string num;
};

#endif // BIGDICIMALINT_H
