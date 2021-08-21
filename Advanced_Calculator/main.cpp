#include <iostream>
#include <string>

#include "BigInteger.h"

int main()
{
    using namespace std;
    BigInt a("-123");
    a.printBinary();
    cout << endl;
    a.printString();

    cout << endl;

    uBigInt b("-123");
    b.printBinary();
    cout << endl;
    b.printString();
    return 0;
}