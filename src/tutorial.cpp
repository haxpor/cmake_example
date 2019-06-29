#include <stdio.h>
#include <stdlib.h>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <math.h>
#endif

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stdout, "%s Version %d.%d\n",
        argv[0],
        Tutorial_VERSION_MAJOR,
        Tutorial_VERSION_MINOR);
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }

  double input_value = atof(argv[1]);
#ifdef USE_MYMATH
  double output_value = mysqrt(input_value);
  fprintf(stdout, "Use MyFunctions\n");
#else
  double output_value = sqrt(input_value);
  fprintf(stdout, "Use math.h\n");
#endif

  fprintf(stdout, "The square root of %g is %g\n", input_value, output_value);
  return 0;
}
