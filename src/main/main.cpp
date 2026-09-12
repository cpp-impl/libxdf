#include "lib.hpp"

// ! macro to mark variables as unused
#define UNUSED(x) ((void)(x))

int main(int argc, char *argv[]) {
  UNUSED(argc);
  UNUSED(argv);

  PrintHelloWorld printer;
  printer.print_hello_world();
  return 0;
}
