/*
 * RobotUtils.cpp
 * Utility functions to help with various math and string related operations.
 *
 *  Created on: Feb 17, 2014
 *      Author: Vince
 */
#include "RobotUtils.h"

void Swap(float& f1, float& f2) {
	float tmp = f1;
	f1 = f2;
	f2 = tmp;
}

float Normalize(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	float range = b - a;
	if (range == 0.0) {
		range = 1.0;
	}
	//	Clamp first
	val = Clamp(a, b, val);
	float valRange = val - a;
	return valRange / range;
}

/**
 * Clamp a value into a range.
 */
float Clamp(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	//	Clamp dat
	if (val < a)
		return a;
	if (val > b)
		return b;
	return val;
}

bool InRangeEh(float a, float b, float val) {
	//	Enforce that a is the minimum and b is the maximum: swap if need be
	if (a > b) {
		Swap(a, b);
	}
	return val >= a && val <= b;
}

std::string FormatString(const char* fmt, ...) {
	//missing string printf
	//this is safe and convenient but not exactly efficient
	int size = 512;
	char* buffer = 0;
	buffer = new char[size];
	va_list vl;
	va_start(vl, fmt);
	int nsize = vsnprintf(buffer, size, fmt, vl);
	if (size <= nsize) { //fail delete buffer and try again
		delete[] buffer;
		buffer = 0;
		buffer = new char[nsize + 1]; //+1 for /0
		nsize = vsnprintf(buffer, size, fmt, vl);
	}
	std::string ret(buffer);
	va_end(vl);
	delete[] buffer;
	return ret;
}

