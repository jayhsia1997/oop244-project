/*
-----------------------------------------------------------
Milestone 2
Module: Utils
Filename: Utils.h
-----------------------------------------------------------
Author: Jay Hsia
Student number: 112935242
Email: phsia1@myseneca.ca
Subject: OOP244NFF
-----------------------------------------------------------
Revision History
------- ---------- ----------------------------------------
Version Date       Reason
v0.0.1  2025-07-16 Implement all functions
-----------------------------------------------------------
v0.0.1
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <iostream>

namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;
        char* strcpy(char* des, const char* src) const;
        int strlen(const char* str) const;
        bool isspace(char ch) const;
        bool isspace(const char* cstring) const;
        int getInt() const;
        int getInt(int min, int max) const;
    };

    extern Utils ut;
}

#endif // !SENECA_UTILS_H
