#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

class Utils {
public:
    static int safeStoi(const std::string& str, const std::string& fieldName = "");
    static std::string toLower(const std::string& str);
    static std::string trim(const std::string& str);
};

#endif