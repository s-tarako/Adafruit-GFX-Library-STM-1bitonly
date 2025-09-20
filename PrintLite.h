#pragma once
#include "stdint.h"
#include <cstring>
#include <string>
class Print{
public:
  virtual size_t write(uint8_t c) = 0; // Pure virtual function for writing data
  virtual size_t write(const uint8_t *buffer, size_t size){
      while(size--) {
          write(*buffer++);
      }
      return 0;
  }
  inline virtual size_t print(const char *str) {
    return write((const uint8_t *)str, strlen(str)); // Default implementation for printing strings
  }
  inline virtual size_t println(const char *str) {
    size_t len = print(str); // Print the string
    write('\n'); // Add newline character
    return len + 1; // Return total length including newline
  }
  virtual void flush(){}; // Declaration only, implementation moved to .cpp

};
typedef void __FlashStringHelper;
typedef std::string String;