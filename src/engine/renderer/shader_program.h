#ifndef SHADER_PROGRAM_CLASS_H
#define SHADER_PROGRAM_CLASS_H

#include <string>


class ShaderProgram
{
private:
    unsigned int ID;
public:
    ShaderProgram(const std::string &vertexShaderFile, const std::string &fragShaderFile);
    void Use();
    void Delete();
};

#endif