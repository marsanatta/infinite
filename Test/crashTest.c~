#include <stdio.h>

typedef struct s
{
  int i;
  int *p;
}S;

int main() {

  S s;
  int *p = &s.i;
  p[0] = 4;
  printf("%d\n", s.i);
  p[1] = 3;
  printf("%d\n", *(&(s.i)+1));
  s.p = p;
  s.p[1] = 1;
  printf("%d\n", *(&(s.i)+1));
  s.p[0] = 2;
  printf("%d\n", s.i);
  return 0;
}
