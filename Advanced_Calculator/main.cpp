#include <iostream>
#include <string>

#include "BigInteger.h"

int main()
{
    using namespace std;
    BigInt a("+345");
    a.printBinary();
    cout << endl;
    a.printString();
    return 0;
}