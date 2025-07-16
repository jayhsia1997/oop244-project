/*
-----------------------------------------------------------
Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {
    class Menu; // forward declaration

    class MenuItem {
        char* m_content{}; // Character pointer to hold MenuItem content dynamically
        unsigned int m_indent{}; // Number of indentations
        unsigned int m_indentSize{}; // Size of each indentation in characters
        int m_row{-1}; // Row number for numbering MenuItem objects

        MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        bool isEmpty() const;
        friend class Menu;
    };

    class Menu {
        unsigned int m_indent{};
        unsigned int m_indentSize{};
        unsigned int m_numItems{};
        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_prompt;
        MenuItem* m_items[MaximumNumberOfMenuItems]{};

    public:
        Menu(const char* title, const char* exitOption = "Exit", unsigned int indent = 0u, unsigned int indentSize = 3u);
        ~Menu();
        // Menu(const Menu&) = delete;
        // Menu& operator=(const Menu&) = delete;
        Menu& operator<<(const char* menuItem);
        size_t select() const;
    };

    size_t operator<<(std::ostream& ostr, const Menu& m);
}

#endif // !SENECA_MENU_H
