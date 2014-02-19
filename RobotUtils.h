/*
 * RobotUtils.h
 * Utility functions to help with various math and string related operations.
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */

#ifndef ROBOTUTILS_H_
#define ROBOTUTILS_H_

#include <string>

/**
 * Swaps the float values passed to it.
 * For example:
 * float a = 2.0;
 * float b = 3.0;
 * Swap(a, b);
 * bool aSwapped = (a == 3.0); // TRUE
 * bool bSwapped = (b == 2.0); // FALSE
 */
void Swap(float& f1, float& f2);

/**
 * Normalizes a value between two limits. 
 * Limits may be passed in any order (large, small; or small, large).
 * Returns a value between 0.0 and 1.0.
 * For example:
 * Normalize(0.0, 50.0, 25.0) // Returns 0.5
 * Normalize(2.0, 0.0, 2.0) // Returns 1.0 (also with reversed limit order)
 * Normalize(1.0, 5.0, 2.0) // Returns 0.25
 */
float Normalize(float a, float b, float val);
/**
 * Clamps a value between two limits. 
 * Limits may be passed in any order (large, small; or small, large).
 * In effect, this function is the same as min(maxVal, max(minVal, val));
 */
float Clamp(float a, float b, float val);
/**
 * Checks if val is between two limits. 
 * Limits may be passed in any order (large, small; or small, large).
 */
bool InRangeEh(float a, float b, float val);

/**
 * Formats a string in the same manner that printf does, except without the printing to console part and instead returns the formatted string.
 */
std::string FormatString(const char* formatStr, ...);

#endif /* ROBOTUTILS_H_ */
