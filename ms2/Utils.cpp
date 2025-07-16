/*
-----------------------------------------------------------
Milestone 2
Module: Utils
Filename: Utils.cpp
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
#include <iostream>
#include <sstream>
#include "Utils.h"
using namespace std;

namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src) const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }

    char* Utils::strcpy(char* des, const char* src) const {
        int i;
        for (i = 0; src[i]; i++)
            des[i] = src[i];
        des[i] = char(0);
        return des;
    }

    int Utils::strlen(const char* str) const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch) const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    int Utils::getInt() const {
        int value{};
        bool done = false;
        string line;
        while (!done) {
            getline(cin, line);
            if (line.size() == 0) {
                cout << "You must enter a value: ";
                continue;
            }
            stringstream ss(line);
            ss >> value;
            if (ss.fail()) {
                cout << "Invalid integer: ";
                continue;
            }
            char c;
            if (ss >> c) {
                cout << "Only an integer please: ";
                continue;
            }
            done = true;
        }
        return value;
    }

    int Utils::getInt(int min, int max) const {
        int val{};
        bool done = false;
        while (!done) {
            val = getInt();
            if (val < min || val > max) {
                cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
            } else {
                done = true;
            }
        }
        return val;
    }
}
