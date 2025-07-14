#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>
#include "constants.h"

namespace seneca {

   class MenuItem {
   private:
      char* m_content;           // Character pointer to hold MenuItem content dynamically
      unsigned int m_indent;     // Number of indentations
      unsigned int m_indentSize; // Size of each indentation in characters
      int m_row;                // Row number for numbering MenuItem objects

   public:
      // Constructor
      MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row);
      
      // Destructor
      ~MenuItem();
      
      // Copy constructor (deleted to prevent copying)
      MenuItem(const MenuItem&) = delete;
      
      // Copy assignment operator (deleted to prevent assignment)
      MenuItem& operator=(const MenuItem&) = delete;
      
      // Bool conversion operator
      operator bool() const;
      
      // Display function
      std::ostream& display(std::ostream& ostr = std::cout) const;
      
      // Helper function to check if MenuItem is in safe empty state
      bool isEmpty() const;
   };

}

#endif // !SENECA_MENU_H


