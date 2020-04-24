#ifndef MEMBERDO
#define MEMBERDO

#include "LinkedList.h"
#include <string>

class MemberDO
{
private:
    int key;
    std::string lastName;
    char firstInit;
    double dues;
public:
    MemberDO();
    MemberDO(int, std::string, char, double);

    int getKey() const;
    void setKey(int);
    std::string getLastName() const;
    void setLastName(std::string);
    char getFirstInitial() const;
    void setFirstInitial(char);
    double getDues() const;
    void setDues(double);
    bool operator < (MemberDO order){//compare by less than
        return(this->getKey() < order.getKey());
    };
    bool operator == (MemberDO other){//compare by equal to.
        return(this->getKey() == other.getKey());
    }

    //MemberDO& operator=(const )
};

#endif