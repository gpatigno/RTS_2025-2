#include <stdio.h>

int fib(int n){
   int m;	
   if (n <= 1) return n;
   m = fib(n-1) + fib(n-2);
   return m;
}

int main (){
 int n = 9;
  printf("\nEl numero Fibonacci para n=%d es: Fib(n)=%d\n\n", n, fib(n));
  return 0;
}
