#include "utils.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::string Utils::GetFileContents(const std::string& filepath)
{
    std::ifstream file(filepath); // creates a new ifstream object, used to read text files

    if (!file.is_open())
    {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // reads all the file
    file.close();

    return buffer.str();
}
