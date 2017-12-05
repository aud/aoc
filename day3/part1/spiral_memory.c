#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STATIC_COUNT 2

struct location {
  short int x, y;
};

struct loop {
  unsigned int iteration, count;
};

// Force every possible variation and only return the absolute value (abs) from stdlib preprocesser.
// See https://www.tutorialspoint.com/c_standard_library/c_function_abs.htm
// Direction is up/down/left/right
static unsigned int Spiral(unsigned long int input) {
  struct loop lp = {2, 1};
  struct location loc = {1, 0};

  for (;;) {
    for (int i = 0; i < lp.count; i++) {
      loc.y++, lp.iteration++;

      if (lp.iteration == input)
        return abs(loc.x) + abs(loc.y);
    }

    for (int i = 0; i < lp.count+1; i++) {
      loc.x--, lp.iteration++;

      if (lp.iteration == input)
        return abs(loc.x) + abs(loc.y);
    }

    for (int i = 0; i < lp.count+1; i++) {
      loc.y--, lp.iteration++;

      if (lp.iteration == input)
        return abs(loc.x) + abs(loc.y);
    }

    for (int i = 0; i < lp.count+1; i++) {
      loc.x++, lp.iteration++;

      if (lp.iteration == input)
        return abs(loc.x) + abs(loc.y);
    }

    lp.count += STATIC_COUNT;
    loc.x++, lp.iteration++;
  }
}

void test_example_one() {
  unsigned short int input = 1024;
  assert(31 == Spiral(input));
}

void test_example_two() {
  unsigned short int input = 12;
  assert(3 == Spiral(input));
}

void test_example_three() {
  unsigned short int input = 23;
  assert(2 == Spiral(input));
}

void test_example_four() {
  unsigned short int input = 1024;
  assert(31 == Spiral(input));
}

void expected_result() {
  unsigned long int input = 361527;
  printf("Expected result: %d\n", Spiral(input));
}

int main() {
  test_example_one();
  test_example_two();
  test_example_three();
  test_example_four();

  expected_result();
  
  return 0;
}
