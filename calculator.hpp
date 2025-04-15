#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);
bool isDigit(char c);
const double INVALID = -1.7976931348623157E+308; // To return a "false" value for the parse_number function

#endif // __CALCULATOR_HPP
