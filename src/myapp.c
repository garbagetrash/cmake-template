#include "myapp.h"
#include <stdio.h>
#include "pc1.h"
#include "pc2.h"


void print_stuff(void) {
  print_pc1();
  print_pc2();
}

int main(void) {
  print_stuff();
  printf("Done!\n");
}
