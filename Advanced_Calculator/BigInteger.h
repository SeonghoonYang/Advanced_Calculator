#pragma once

#include <string>

#define _32_MULTIPLE 4

class BigInt
{
private:
	uint32_t bits[_32_MULTIPLE];
	bool isCorrectFormat(const std::string& stringNum);

public:
	BigInt();
	BigInt(const std::string& stringNum);

	BigInt& operator + (const BigInt& bigInt);
	BigInt& operator - (const BigInt& bigInt);

	void printString();
	void printBinary();
};