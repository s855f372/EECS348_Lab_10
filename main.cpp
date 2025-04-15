#include "calculator.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    // Read file
    std::string fileName;
    std::cout << "Input File Name: ";
    std::cin >> fileName;
    std::ifstream file(fileName);

    //std::ifstream file("test.txt");
    std::string line;
    
    // Identify if number is valid double
    // Add double with -123.456 and print result
    while (std::getline(file, line)) 
    {
        if(parse_number(line) != INVALID)
        {
            std::cout << parse_number(line) - 123.456 << std::endl;
        }
        else
        {
            std::cout << "[INVALID NUMBER]" << std::endl;
        }
    }

}
