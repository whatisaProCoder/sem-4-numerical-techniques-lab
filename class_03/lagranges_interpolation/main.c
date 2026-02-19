#include <stdio.h>

int main() {
  int n, i, j;
  float x[20], y[20], xp, yp = 0, term;

  printf("Enter number of data points: ");
  scanf("%d", &n);

  // Input data points
  printf("Enter values of x and y:\n");
  for (i = 0; i < n; i++) {
    printf("x[%d] = ", i);
    scanf("%f", &x[i]);
    printf("y[%d] = ", i);
    scanf("%f", &y[i]);
  }

  // Input interpolation point
  printf("Enter value of x to interpolate: ");
  scanf("%f", &xp);

  // Lagrange Interpolation Formula
  for (i = 0; i < n; i++) {
    term = y[i];

    for (j = 0; j < n; j++) {
      if (j != i) {
        term = term * (xp - x[j]) / (x[i] - x[j]);
      }
    }

    yp = yp + term;
  }

  printf("Interpolated value at x = %.3f is %.3f\n", xp, yp);

  return 0;
}

/* OUTPUT
Enter number of data points: 4
Enter values of x and y:
x[0] = 0
y[0] = 5
x[1] = 1
y[1] = 6
x[2] = 3
y[2] = 50
x[3] = 4
y[3] = 105
Enter value of x to interpolate: 2
Interpolated value at x = 2.000 is 19.000
*/