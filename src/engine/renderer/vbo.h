#ifndef VBO_CLASS_H
#define VBO_CLASS_H

class VBO {

private:
    unsigned int ID;

public:
    VBO(const float vertices[]);
    unsigned int GetId() {return this->ID;}
};

#endif