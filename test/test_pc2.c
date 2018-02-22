#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include "pc2.h"
#include <cmocka.h>


static void test_pc2(void **state) {
  print_pc2();
  (void) state;
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_pc2),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
