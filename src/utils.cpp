#include "utils.hpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iostream>  

int Utils::safeStoi(const std::string& str, const std::string& fieldName) {
    try {
        if (str.empty()) return 0;

         std::string numStr = str;
        if (numStr.find("PB") == 0) {
            numStr = numStr.substr(2);
        }

        return std::stoi(numStr);  
    } catch (const std::invalid_argument& e) {
        std::cout << "Erro ao converter '" << str << "' para inteiro" 
                 << (fieldName.empty() ? "" : " (campo: " + fieldName + ")") << std::endl;  
        return 0;
    }
}

std::string Utils::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (std::string::npos == first) return str;
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}