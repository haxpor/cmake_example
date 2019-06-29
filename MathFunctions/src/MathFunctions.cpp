#include "MathFunctions.h"
#include "TutorialConfig.h"

#if defined(HAVE_LOG) && defined(HAVE_EXP)
#include <math.h>
#endif

#if !defined(HAVE_LOG) || !defined(HAVE_EXP)
// use approach in https://stackoverflow.com/a/29019938/571227
#define MINDIFF 2.25e-308
#endif

double mysqrt(double value)
{
  if (value <= 0)
    return 0;

#if defined(HAVE_LOG) && defined(HAVE_EXP)
  return exp(log(value)*0.5);
#else
  double root = value/3;
  double last;
  double diff = 1;

  do {
    last = root;
    root = (root + value / root) / 2;
    diff = root - last;
  } while (diff > MINDIFF || diff < -MINDIFF);
  return root;
#endif
}
