#include <math.h>
#include <stdio.h>

#define EPS 0.0001
#define f(x) (3 * (x) - 1 - cos(x))

int main() {
  float x0, x1, x2, f0, f1, f2;
  int i = 1;

  // Input until valid bracket is found
  do {
    printf("Enter x0: ");
    scanf("%f", &x0);
    printf("Enter x1: ");
    scanf("%f", &x1);

    if (f(x0) * f(x1) > 0) {
      printf("Invalid interval! f(x0) and f(x1) must have opposite signs.\n\n");
    }
  } while (f(x0) * f(x1) > 0);

  printf("\nIter\t   x0\t\t   x1\t\t   x2\t\t  f(x2)");

  do {
    f0 = f(x0);
    f1 = f(x1);

    x2 = x0 - (f0 * (x1 - x0)) / (f1 - f0);
    f2 = f(x2);

    printf("\n%d\t %10.4f\t %10.4f\t %10.4f\t %10.4f", i, x0, x1, x2, f2);

    if (f0 * f2 < 0)
      x1 = x2;
    else
      x0 = x2;

    i++;
  } while (fabs(f2) > EPS);

  printf("\n\nApproximate root = %.4f\n", x2);
  return 0;
}

/* OUTPUT
Enter x0: 0
Enter x1: 1

Iter       x0              x1              x2             f(x2)
1            0.0000          1.0000          0.5781         -0.1033
2            0.5781          1.0000          0.6060         -0.0041
3            0.6060          1.0000          0.6071         -0.0002
4            0.6071          1.0000          0.6071         -0.0000

Approximate root = 0.6071
*/