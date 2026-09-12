#pragma once

#include <iostream>

class PrintHelloWorld {
public:
  constexpr void print_hello_world() {
    std::cout << "Hello, it's now my World!" << std::endl;
  }
};
