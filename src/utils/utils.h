#ifndef UTILS_CLASS_H
#define UTILS_CLASS_H

#include <string>

class Utils
{
public:
    static std::string GetFileContents(const std::string& filepath);
};

#endif