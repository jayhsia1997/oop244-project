/*
-----------------------------------------------------------
Milestone 2
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>

namespace seneca {
    // Constructor
    MenuItem::MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row) : m_content(nullptr),
                                                                                                     m_indent(0),
                                                                                                     m_indentSize(0),
                                                                                                     m_row(-1) {
        bool validContent = content && strlen(content) > 0;
        if (validContent) {
            bool onlyWhitespace = true;
            for (size_t i = 0; content[i] != '\0'; i++) {
                if (content[i] != ' ' && content[i] != '\t' && content[i] != '\n' && content[i] != '\r' && content[i] != '\f' && content[i] != '\v') {
                    onlyWhitespace = false;
                    break;
                }
            }
            validContent = !onlyWhitespace;
        }

        bool validIndent = indent <= 4;
        bool validIndentSize = indentSize <= 4;
        bool validRow = (row <= int(MaximumNumberOfMenuItems));

        // If all validations pass, set the MenuItem
        if (validContent && validIndent && validIndentSize && validRow) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
            m_indent = indent;
            m_indentSize = indentSize;
            m_row = row;
        }
    }

    // Destructor
    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    // Bool conversion operator
    MenuItem::operator bool() const {
        return !isEmpty();
    }

    // Display function
    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (isEmpty()) {
            ostr << "??????????";
        } else {
            for (unsigned int i = 0; i < m_indent * m_indentSize; i++) {
                ostr << " ";
            }

            if (m_row >= 0) {
                ostr << std::setw(2) << std::right << m_row << "- ";
            }

            const char* content = m_content;
            while (*content && (*content == ' ' || *content == '\t' || *content == '\n' || *content == '\r' || *content == '\f' || *content == '\v')) {
                content++;
            }
            ostr << content;
        }
        return ostr;
    }

    bool MenuItem::isEmpty() const {
        return m_content == nullptr;
    }


    Menu::Menu(const char* title, const char* exitOption, unsigned int indent, unsigned int indentSize) : m_indent(indent),
        m_indentSize(indentSize),
        m_numItems(0),
        m_title(title, indent, indentSize, -1),
        m_exitOption(exitOption, indent, indentSize, 0),
        m_prompt("> ", indent, indentSize, -1) {
        for (size_t i = 0; i < MaximumNumberOfMenuItems; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        for (size_t i = 0; i < MaximumNumberOfMenuItems; ++i) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* menuItem) {
        if (m_numItems < MaximumNumberOfMenuItems) {
            m_items[m_numItems] = new MenuItem(menuItem, m_indent, m_indentSize, int(m_numItems + 1));
            ++m_numItems;
        }
        return *this;
    }

    size_t Menu::select() const {
        if (m_title) {
            m_title.display() << std::endl;
        }
        for (unsigned int i = 0; i < m_numItems; ++i) {
            if (m_items[i]) {
                m_items[i]->display() << std::endl;
            }
        }
        m_exitOption.display() << std::endl;
        m_prompt.display();
        return static_cast<size_t>(ut.getInt(0, static_cast<int>(m_numItems)));
    }

    size_t operator<<(std::ostream& ostr, const Menu& m) {
        if (&ostr == &std::cout) {
            return m.select();
        }
        return 0u;
    }
}
