#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CORD_DIMENSION_ONE 8
#define CORD_DIMENSION_TWO 2

#define ARR_DIMENSION_ONE 1000
#define ARR_DIMENSION_TWO 3

struct location {
  short int x, y, dx, dy;
};

static unsigned int SpiralStress(unsigned long int input) {
  unsigned short int iteration;
  struct location loc = {0, 0, 0, -1};

  // Possible dimensions for adjacent/diagonals.
  unsigned long int dimensions[CORD_DIMENSION_ONE][CORD_DIMENSION_TWO] = {
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {1, 1},
    {0, 1}
  };

  unsigned long int arr[ARR_DIMENSION_ONE][ARR_DIMENSION_TWO];
  for (int i = 0; i < ARR_DIMENSION_ONE; i++) {
    arr[i][0] = 0; // x axis
    arr[i][1] = 0; // y axis
    arr[i][2] = 0; // total
  }

  for (;;) {
    unsigned long int sum = 0;

    for (int i = 0; i < ARR_DIMENSION_ONE; i++) {
      for (int j = 0; j < CORD_DIMENSION_ONE; j++) {
        unsigned long int x_dims = loc.x + dimensions[j][0];
        unsigned long int y_dims = loc.y + dimensions[j][1];

        // if x == x,y==x sum
        if (x_dims == arr[i][0] && y_dims == arr[i][1]) {
          sum += arr[i][2]; // Sum total
        }
      }
    }

    if (loc.x == 0 && loc.y == 0) {
      arr[iteration][0] = 0;
      arr[iteration][1] = 0;
      arr[iteration][2] = 1;
    } else {
      arr[iteration][0] = loc.x;
      arr[iteration][1] = loc.y;
      arr[iteration][2] = sum;
    }

    if ((loc.x > 0 && loc.x == 1-loc.y) || (loc.x < 0 && loc.x == -loc.y) || loc.x == loc.y) {
      // This is required since C can't do multi assignment... Maybe figure out
      // a diff way.
      int tmp = loc.dx;

      loc.dx = -loc.dy;
      loc.dy = tmp;
    }


    loc.x += loc.dx, loc.y += loc.dy;
    iteration += 1;

    if (sum >= input)
      return sum;
  }
}

void test_solution() {
  unsigned long int input = 361527;
  assert(363010 == SpiralStress(input));
}

int main() {
  test_solution();
  return 0;
}
