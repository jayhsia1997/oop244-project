#include "Menu.h"
#include <cstring>
#include <iomanip>

namespace seneca {

   // Constructor
   MenuItem::MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row) 
      : m_content(nullptr), m_indent(0), m_indentSize(0), m_row(-1) {
      
      bool validContent = content && strlen(content) > 0;
      if (validContent) {
         bool onlyWhitespace = true;
         for (size_t i = 0; content[i] != '\0'; i++) {
            if (content[i] != ' ' && content[i] != '\t' && content[i] != '\n' && 
                content[i] != '\r' && content[i] != '\f' && content[i] != '\v') {
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
         while (*content && (*content == ' ' || *content == '\t' || *content == '\n' || 
                           *content == '\r' || *content == '\f' || *content == '\v')) {
            content++;
         }
         ostr << content;
      }
      return ostr;
   }
   
   bool MenuItem::isEmpty() const {
      return m_content == nullptr;
   }

}
