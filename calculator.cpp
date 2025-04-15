#include "calculator.hpp"

// No importing external libraries to validate whether a string is a valid double number. 
// No converting the string to a double or using try-catch blocks for validation.

double parse_number(const std::string &expression)
{
    double result = 0.0;
    double decimal = 1.0;
    bool foundDecimal = false;
    double sign = 1.0;

    // If the last character in the string is a decimal with no following points, it's invalid
    if (expression[expression.length() - 1] == '.')
    {
        return INVALID;
    }
    
    // If first character is not a digit, "-", or "+", it's invalid
    if (!(isDigit(expression[0])) && expression[0] != '-' && expression[0] != '+')
    {
        return INVALID;
    }
    else if (isDigit(expression[0]))
    {
        result = result * 10 + (expression[0] - '0');
    }
    else if (expression[0] == '-')
    {
        sign = -1.0;
    }
    
    // Checks rest of string
    for (char c : expression.substr(1))
    {
        
        // If character is a decimal
        if (c == '.')
        {
            // And there's already been a decimal, it's invalid
            if(foundDecimal)
            {
                return INVALID;
            }
            // Else it's the first decimal, continue
            else
            {
                foundDecimal = true;
            }
        }

        // If the character is a number
        else if (isDigit(c))
        {

            // And it's past the decimal
            if(foundDecimal)
            {
                decimal /= 10;
                result += (c - '0') * decimal;
            }
            // Otherwise, just add it
            else
            {
                result = result * 10 + (c - '0');
            }
        }

        // If the character is not a decimal or number, it's invalid
        else
        {
            return INVALID;
        }
    }
    
    return result * sign;
}

// Returns true if charcter is digit
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}
