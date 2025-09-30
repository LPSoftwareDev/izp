#include <stdio.h>

int main(void) {
  int a = 2;
  int b = 3;
  int c = 4;
  int D;

  int x = 3;

  int start = 2;
  int end = 5;
  int num = 4;

  int z[] = {3, 4};
  int obdelnik[] = {0, 0, 5, 5};

  int h;
  int j;
  int k;

  scanf("%i", &h);
  scanf("%i", &j);
  scanf("%i", &k);

  D = b * b - 4 * a * c;
  printf("D = %i\n", D);

  if (x % 2 == 0) {
    printf("%i je parne\n", x);
  } else {
    printf("%i je neparne\n", x);
  }

  if (D == 0) {
    printf("rovnice s a:%i, b:%i, c:%i ma 1 reseni\n", a, b, c);
  } else if (D > 0) {
    printf("rovnice s a:%i, b:%i, c:%i ma 2 reseni\n", a, b, c);
  } else {
    printf("rovnice s a:%i, b:%i, c:%i ma 0 reseni\n", a, b, c);
  }

  if (num > start && num < end) {
    printf("bod %i lezi na usecke <%i, %i>\n", num, start, end);
  } else {
    printf("bod %i nelezi na usecke <%i, %i>\n", num, start, end);
  }

  if (z[0] > obdelnik[0] && z[0] < obdelnik[2] && z[1] > obdelnik[1] &&
      z[1] < obdelnik[3]) {
    printf("bod: [%i, %i] lezi v obdelniki: A[%i, %i] a B[%i, %i]\n", z[0],
           z[1], obdelnik[0], obdelnik[1], obdelnik[2], obdelnik[3]);
  } else {
    printf("bod: [%i, %i] nelezi v obdelniku: A[%i, %i] a B[%i, %i]\n", z[0],
           z[1], obdelnik[0], obdelnik[1], obdelnik[2], obdelnik[3]);
  }
}
