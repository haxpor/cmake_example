#include "MathFunctions.h"

// use approach in https://stackoverflow.com/a/29019938/571227
#define MINDIFF 2.25e-308

double mysqrt(double value)
{
  double root = value/3;
  double last;
  double diff = 1;
  if (value <= 0)
    return 0;

  do {
    last = root;
    root = (root + value / root) / 2;
    diff = root - last;
  } while (diff > MINDIFF || diff < -MINDIFF);
  return root;
}
