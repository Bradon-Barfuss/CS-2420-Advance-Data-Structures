//
// Created by bradon on 1/23/20.
//

#ifndef DYNAMICSTRINGURL_URL_H
#define DYNAMICSTRINGURL_URL_H
#include "DynamicString.h"


class Url : public DynamicString {
public:
    Url(const char* str);
    ~Url();
    int compare(const Url& other);
    char scheme[100];
    char authority[100];
    char path[100];
    int schemeSize = 0;
    int authoritySize = 0;
    int pathSize = 0;
};


#endif //DYNAMICSTRINGURL_URL_H
