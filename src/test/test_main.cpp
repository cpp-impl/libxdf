#include "lib.hpp"
#include <cassert>
#include <iostream>

void test_printer_instantiation() {
  PrintHelloWorld printer;
  printer.print_hello_world();
}

int main() {
  std::cout << "[TEST] Running simple test..." << std::endl;

  test_printer_instantiation();

  std::cout << "[TEST] All tests passed." << std::endl;
  return 0;
}