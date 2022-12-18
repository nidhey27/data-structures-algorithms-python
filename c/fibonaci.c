#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int fibonaci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return (fibonaci(n - 1) + fibonaci(n - 2));
  }
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
  int n = 3;
  int fact = factorial(n);
  printf("Factorial of %d: %d\n", n, fact);

  printf("Fibonaci Series: \n");
  for (int i = 0; i < 20; i++) {
    printf("%d ", fibonaci(i));
  }
  printf("\n");
  printf("%d", fib(n));
  return 0;
}