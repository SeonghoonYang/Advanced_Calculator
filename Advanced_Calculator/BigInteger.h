#pragma once

#include <string>

typedef unsigned char BYTE;
#define _64_MULTIPLE 2

class uBigInt
{
protected:
	uint64_t bits[_64_MULTIPLE];
	bool isCorrectFormat(const std::string& stringNum);

public:
	uBigInt();
	uBigInt(const std::string& stringNum);

	void printString();
	void printBinary();
};

class BigInt : public uBigInt
{
public:
	BigInt();
	BigInt(const std::string& stringNum);

	void printString();
	void printBinary();
};