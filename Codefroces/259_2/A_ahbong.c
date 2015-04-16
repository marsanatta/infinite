#include <stdio.h>

void
print_chars(char c, int times)
{
  int i;
  for (i = 0; i < times; ++i) {
    putc(c, stdout);
  }
}

void
print_line(int n, int idx)
{
  int star_num = n / 2 - idx;
  int dia_num = 1 + idx * 2;
  print_chars('*', star_num);
  print_chars('D', dia_num);
  print_chars('*', star_num);
  putc('\n', stdout);
}

void
print_diamond(int n)
{
  int i;
  for (i = 0; i < n / 2; ++i) {
    print_line(n, i);
  }
  for (i = n / 2; i >= 0; --i) {
    print_line(n, i);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  print_diamond(n);
  return 0;
}
