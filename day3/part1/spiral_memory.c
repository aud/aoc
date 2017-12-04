#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STATIC_COUNT 2

typedef struct {
   int x;
   int y;
} location;

typedef struct {
  int iteration;
  int count;
} loop;

// Force every possible variation and only return the absolute value (abs) from stdlib preprocesser.
// See https://www.tutorialspoint.com/c_standard_library/c_function_abs.htm
// Direction is up/down/left/right
int Spiral(int input) {
  loop lp = {2, 1};
  location loc = {1, 0};

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
  int input = 1024;
  assert(31 == Spiral(input));
}

void test_example_two() {
  int input = 12;
  assert(3 == Spiral(input));
}

void test_example_three() {
  int input = 23;
  assert(2 == Spiral(input));
}

void test_example_four() {
  int input = 1024;
  assert(31 == Spiral(input));
}

void expected_result() {
  int input = 361527;
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
