//
// Created by bradon on 1/23/20.
//
#include <stdexcept>

#include "Url.h"
#include<ctype.h>
#include <iostream>

Url::~Url(){}
Url::Url(const char *str) {
    int i = 0;
    int j = 0;
    int a = 0;
    while (str[a+2] != '\0') {
        if ((str[a] == ':' && str[a + 1] == '/' && str[a + 2] == '/') && isalnum(str[a-1])) {
            while (str[i - 1] != ':' && str[i] != '/' && str[i + 1] != '/') {
                scheme[j] = tolower(str[i]);
                schemeSize++;
                i++;
                j++;
            }
            j = 0;
            i = i + 3;
            while (str[i] != '/') {
                authority[j] = tolower(str[i]);
                authoritySize++;

                i++;
                j++;
            }
            if (str[i] == '/'){
                i =i+1;
            }
            j = 0;
            while (str[i+2] != '\0') {
                path[j] = str[i];
                pathSize++;
                j++;
                i++;
            }
            return;
        }
        a++;
    }
    a = 0;
    if (!(str[a] == '.' && str[a + 1] == '/' && str[a + 2] == '/')&& str[a-1] == isalnum(str[a-1])) {
        throw std::invalid_argument("Invalid syntax.");
    }
}

int Url::compare(const Url &other) {
    int i = 0;

    while ((i != schemeSize) || (i != other.schemeSize)) {
        if (scheme[i] < other.scheme[i]) {
            return -1;
        } else if (scheme[i] > other.scheme[i]) {
            return 1;
        }
        i++;
    }
    while ((i != authoritySize) || (i != other.authoritySize)) {
        if (authority[i] < other.authority[i]) {
            return -1;
        } else if (authority[i] > other.authority[i]) {
            return 1;
        }
        i++;
    }
    i = 0;
    while ((i != pathSize) || (i != other.pathSize)) {//while i is less than the length of either string
        if((path[i] >= 'A' && path[i] <= 'Z') && (other.path[i] >= 'a' && other.path[i] <= 'z')){
                return -1;
        }
        else if((path[i] >= 'a' && path[i] <= 'z') && (other.path[i] >= 'A' && other.path[i] <= 'Z')){
            return 1;
        }
        i++;
    }
    return 0;

}