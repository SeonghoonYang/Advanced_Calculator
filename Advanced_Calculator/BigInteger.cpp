#include "BigInteger.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool uBigInt::isCorrectFormat(const std::string& stringNum)
{
	if (stringNum[0] < '0' || stringNum[0] > '9')
		if (stringNum[0] != '-' && stringNum[0] != '+')
			return false;

	for (size_t i = 1; i < stringNum.size(); i++) {
		if (stringNum[i] < '0' || stringNum[i] > '9')
			return false;
	}

	return true;
}

uBigInt::uBigInt()
	:uBigInt("0")
{}

uBigInt::uBigInt(const std::string& stringNum)
{
	memset(bits, 0, sizeof(bits));
	string temp = stringNum;
	if (!isCorrectFormat(temp)) {
		temp = "0";
	}
	uint64_t t, carry;
	int n = 0, idx = _64_MULTIPLE - 1;

	size_t a = 0;
	if (stringNum[0] == '-' || stringNum[0] == '+')
		a = 1;

	while (1) {
		carry = 0LL;
		for (size_t i = a; i < temp.size(); i++) {
			t = static_cast<uint64_t>(temp[i] - '0');
			t += carry * 10LL;
			carry = t & 1LL;// t가 홀수이면 carry는 1.
			temp[i] = static_cast<char>(t >> 1) + '0';
		}
		if (n != 0 && (n % 64 == 0)) {
			n = 0;
			idx--;
			if (idx < 0) break;
		}
		bits[idx] |= carry << n++; // 마지막 캐리값이 바이너리 값.
	}

	if (stringNum[0] == '-') {
		uint64_t temp[_64_MULTIPLE];
		int tCarry = 0;
		memcpy(temp, bits, sizeof(temp));
		// 비트 뒤집고 + 1
		temp[_64_MULTIPLE - 1] = ~temp[_64_MULTIPLE - 1];
		temp[_64_MULTIPLE - 1]++;
		if (temp[_64_MULTIPLE - 1] < bits[_64_MULTIPLE - 1])
			tCarry = 1;
		for (int i = _64_MULTIPLE - 2; i >= 0; i--) {
			temp[i] = ~temp[i] + tCarry;
			if (temp[i] <= bits[i])
				tCarry = 1;
			else
				tCarry = 0;
		}
		memcpy(bits, temp, sizeof(bits));
	}
}

void uBigInt::printString()
{
	//사인드 정수로 가정함
	string stringNum("0");
	int t, idx = -1, n = 0;
	int carry1 = 0, carry2 = 0;

	for (int i = 0; i < 64 * _64_MULTIPLE; i++) {

		if (i % 64 == 0) {
			n = 0;
			idx++;
		}

		if (bits[idx] & (0x8000000000000000LL >> n++))
			carry1 = 1;
		else
			carry1 = 0;

		t = (static_cast<int>(stringNum[0] - '0') << 1) + carry1;
		stringNum[0] = static_cast<char>(t % 10) + '0';
		carry2 = t > 9 ? 1 : 0;

		for (size_t j = 1; j < stringNum.size(); j++) {
			t = (static_cast<int>(stringNum[j] - '0') << 1) + carry2;
			stringNum[j] = static_cast<char>(t % 10) + '0';
			carry2 = t > 9 ? 1 : 0;
		}

		if (carry2)
			stringNum.push_back('1');
	}

	for (int i = stringNum.size() - 1; i >= 0; i--) {
		cout << stringNum[i];
	}
}

void uBigInt::printBinary()
{
	int idx = -1;
	int n = 0;
	for (int i = 0; i < sizeof(bits) << 3; i++) {
		if (i != 0 && i % 8 == 0) std::cout << std::endl;
		if (i != 0 && i % 4 == 0 && i % 8 != 0) std::cout << ' ';
		if (i % 64 == 0) {
			n = 0;
			idx++;
		}
		std::cout << static_cast<bool>((bits[idx] & (0x8000000000000000LL >> n++)));

	}
}


bool BigInt::isCorrectFormat(const std::string& stringNum)
{
	if (stringNum[0] < '0' || stringNum[0] > '9')
		if (stringNum[0] != '-' && stringNum[0] != '+')
			return false;

	for (size_t i = 1; i < stringNum.size(); i++) {
		if (stringNum[i] < '0' || stringNum[i] > '9')
			return false;
	}

	return true;
}

BigInt::BigInt()
	:BigInt("0")
{
}

BigInt::BigInt(const std::string& stringNum)
{
	memset(bits, 0, sizeof(bits));
	string temp = stringNum;
	if (!isCorrectFormat(temp)) {
		temp = "0";
	}
	uint64_t t, carry;
	int n = 0, idx = _64_MULTIPLE - 1;

	size_t a = 0;
	if (stringNum[0] == '-' || stringNum[0] == '+')
		a = 1;

	while (1) {
		carry = 0LL;
		for (size_t i = a; i < temp.size(); i++) {
			t = static_cast<uint64_t>(temp[i] - '0');
			t += carry * 10LL;
			carry = t & 1LL;// t가 홀수이면 carry는 1.
			temp[i] = static_cast<char>(t >> 1) + '0';
		}
		if (n != 0 && (n % 64 == 0)) {
			n = 0;
			idx--;
			if (idx < 0) break;
		}
		bits[idx] |= carry << n++; // 마지막 캐리값이 바이너리 값.
	}

	if (stringNum[0] == '-') {
		uint64_t temp[_64_MULTIPLE];
		int tCarry = 0;
		memcpy(temp, bits, sizeof(temp));
		// 비트 뒤집고 + 1
		temp[_64_MULTIPLE - 1] = ~temp[_64_MULTIPLE - 1];
		temp[_64_MULTIPLE - 1]++;
		if (temp[_64_MULTIPLE - 1] < bits[_64_MULTIPLE - 1])
			tCarry = 1;
		for (int i = _64_MULTIPLE - 2; i >= 0; i--) {
			temp[i] = ~temp[i] + tCarry;
			if (temp[i] <= bits[i])
				tCarry = 1;
			else
				tCarry = 0;
		}
		memcpy(bits, temp, sizeof(bits));
	}
}

BigInt& BigInt::operator+(const BigInt& bigInt)
{
	uint64_t temp = 0, carry = 0;
	for (int i = _64_MULTIPLE - 1; i >= 0; i--) {
		temp = bits[i] + bigInt.bits[i] + carry;
		if (bits[i] > temp) { // 오버플로우가 났다 -> 캐리 발생
			carry = 1;
		}
		else {
			carry = 0;
		}
		bits[i] = temp;
	}
	return *this;
}

BigInt& BigInt::operator-(const BigInt& bigInt)
{
	uint64_t temp = 0, carry = 0;
	for (int i = _64_MULTIPLE - 1; i >= 0; i--) {
		temp = bits[i] - bigInt.bits[i] - carry;
		if (bits[i] < temp) { // 오버플로우가 났다 -> 캐리 발생
			carry = 1;
		}
		else {
			carry = 0;
		}
		bits[i] = temp;
	}
	return *this;
}

void BigInt::printString()
{
	string stringNum("0");

	bool minusFlag = false;

	uint64_t temp[_64_MULTIPLE];
	memcpy(temp, bits, sizeof(bits));

	// 음수일 경우 비트 뒤집고 1을 더함
	if (bits[0] & 0x8000000000000000LL) {
		minusFlag = true;

		int n = _64_MULTIPLE;
		uint64_t idx, bitMask = 1ULL;
		for (idx = 0; idx < 8 * sizeof(uint64_t) * _64_MULTIPLE; idx++) {
			
			if (idx % (8 * sizeof(uint64_t)) == 0) {
				n--;
				bitMask = 1;
			}

			if (temp[n] & bitMask) break; // 오른쪽에서부터 가장 먼저 1이 나오는 구간
			
			bitMask <<= 1;
		}

		// 브레이크를 못하면? 비트 모두 0이면? 그럴 일이 없음
		// 애초에 msb가 1인 것에서 출발함으로
		
		// temp[n] 인 부분에선 부분 뒤집기, n 미만 에선 전체뒤집기
		bitMask = 1ULL;
		bitMask <<= idx % (8 * sizeof(uint64_t));
		
		for (idx++; idx < (8 * sizeof(uint64_t) * (_64_MULTIPLE - n)); idx++) {
			bitMask <<= 1;
			if (temp[n] & bitMask) {
				temp[n] &= (~bitMask);
			}
			else {
				temp[n] |= bitMask;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			temp[i] = ~temp[i];
		}

		/*minusFlag = true;
		int tCarry = 0;
		temp[_64_MULTIPLE - 1] = ~temp[_64_MULTIPLE - 1];
		temp[_64_MULTIPLE - 1]++;
		if (temp[_64_MULTIPLE - 1] < bits[_64_MULTIPLE - 1])
			tCarry = 1;
		for (int i = _64_MULTIPLE - 2; i >= 0; i--) {
			temp[i] = ~temp[i] + tCarry;
			if (temp[i] <= bits[i])
				tCarry = 1;
			else
				tCarry = 0;
		}*/
		//맨앞의 64개 비트는 어떻게 조작?
	}
	//cout << temp[0] << ' ' << temp[1];

	int t, idx = -1, n = 0;
	int carry1 = 0, carry2 = 0;

	for (int i = 0; i < 64 * _64_MULTIPLE; i++) {

		if (i % 64 == 0) {
			n = 0;
			idx++;
		}

		if (temp[idx] & (0x8000000000000000LL >> n++))
			carry1 = 1;
		else
			carry1 = 0;

		t = (static_cast<int>(stringNum[0] - '0') << 1) + carry1;
		stringNum[0] = static_cast<char>(t % 10) + '0';
		carry2 = t > 9 ? 1 : 0;

		for (size_t j = 1; j < stringNum.size(); j++) {
			t = (static_cast<int>(stringNum[j] - '0') << 1) + carry2;
			stringNum[j] = static_cast<char>(t % 10) + '0';
			carry2 = t > 9 ? 1 : 0;
		}

		if (carry2)
			stringNum.push_back('1');
	}

	if (minusFlag) {
		stringNum.push_back('-');
	}

	for (int i = stringNum.size() - 1; i >= 0; i--) {
		cout << stringNum[i];
	}
}

void BigInt::printBinary()
{
	int idx = -1;
	int n = 0;
	for (int i = 0; i < sizeof(bits) << 3; i++) {
		if (i != 0 && i % 8 == 0) std::cout << std::endl;
		if (i != 0 && i % 4 == 0 && i % 8 != 0) std::cout << ' ';
		if (i % 64 == 0) {
			n = 0;
			idx++;
		}
		std::cout << static_cast<bool>((bits[idx] & (0x8000000000000000LL >> n++)));

	}
}
