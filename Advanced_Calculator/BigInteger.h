#pragma once

#include <string>

typedef unsigned char BYTE;
#define _64_MULTIPLE 4

class uBigInt
{
private:
	uint64_t bits[_64_MULTIPLE];
	bool isCorrectFormat(const std::string& stringNum);

public:
	uBigInt();
	uBigInt(const std::string& stringNum);
	uBigInt(const uBigInt& ubigint);

	void printString();
	void printBinary();
};

class BigInt
{
private:
	uint64_t bits[_64_MULTIPLE];
	bool isCorrectFormat(const std::string& stringNum);

public:
	BigInt();
	BigInt(const std::string& stringNum);

	void printString();
	void printBinary();
};