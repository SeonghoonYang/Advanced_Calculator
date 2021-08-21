#include <iostream>
#include <string>

#include "BigInteger.h"

int main()
{
    using namespace std;
    BigInt a("123");
    BigInt b("124");
    BigInt c;

    c = a - b;
    c.printBinary();
    cout << endl;
    c.printString();

    return 0;
}