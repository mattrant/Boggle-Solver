#ifndef DIE_H
#define DIE_H

#include <string>

class Die{
public:
    Die(std::string faces);
    //Changes the top face of the die
    void roll();
    std::string get_top() const;
private:
    std::string faces;
    std::string top;
};

#endif
