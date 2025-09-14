// Contains solutions for the programming projects
// written in Section 9.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROJ1_MAX_SIZE 100
#define ALPHABET_SIZE 26

void selection_sort(int a[], int len);
float income_tax(float income);
void generate_random_walk(char walk[10][10]);
void print_walk(char walk[10][10]);
void read_word(int counts[ALPHABET_SIZE]);
bool equal_array(int counts1[ALPHABET_SIZE], int counts2[ALPHABET_SIZE]);
void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);
int calculate_polynomial(int x);
int power(int x, int n);
int roll_dice(void);
bool play_game(void);

void selection_sort(int a[], int len) {
  if (len == 0) {
    return;
  }

  int max = a[0];
  int max_idx = 0;
  for (int i = 1; i < len; i++) {
    if (a[i] > max) {
      max = a[i];
      max_idx = i;
    }
  }

  int tmp = a[len - 1];
  a[len - 1] = max;
  a[max_idx] = tmp;

  selection_sort(a, len - 1);
}

float income_tax(float income) {
  float tax;
  if (income < 750.00f) {
    tax = income * .01f;
  } else if (income < 2250.00f) {
    tax = 7.50f + (income - 750.00f) * .02f;
  } else if (income < 3750.00f) {
    tax = 37.50f + (income - 2250.00f) * .03f;
  } else if (income < 5250.00f) {
    tax = 82.50f + (income - 3750.00f) * .04f;
  } else if (income < 7000.00f) {
    tax = 142.50f + (income - 5250.00f) * .05f;
  } else {
    tax = 230.00f + (income - 7000.00f) * .06f;
  }

  return tax;
}

void generate_random_walk(char walk[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      walk[i][j] = '.';
    }
  }

  char steps[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  srand((unsigned)time(NULL));

  int current_pos_x = 0;
  int current_pos_y = 0;

  for (int i = 0; i < 26; i++) {
    int walk_dir = rand() % 4;
    bool walk_attempts[4] = {false};
    bool walk_succeeded = false;
    for (; !walk_attempts[walk_dir % 4]; walk_dir++) {
      int dir_x = current_pos_x;
      int dir_y = current_pos_y;
      walk_attempts[walk_dir % 4] = true;

      switch (walk_dir % 4) {
      case 0:
        dir_y -= 1;
        break;
      case 1:
        dir_x += 1;
        break;
      case 2:
        dir_y += 1;
        break;
      case 3:
        dir_x -= 1;
        break;
      default:
        break;
      }

      if (dir_x < 0 || dir_x > 9) {
        continue;
      }

      if (dir_y < 0 || dir_y > 9) {
        continue;
      }

      if (walk[dir_y][dir_x] != '.') {
        continue;
      }

      walk[dir_y][dir_x] = steps[i];
      current_pos_x = dir_x;
      current_pos_y = dir_y;
      walk_succeeded = true;
      break;
    }

    if (!walk_succeeded) {
      break;
    }
  }
}

void print_walk(char walk[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }
}

void read_word(int counts[ALPHABET_SIZE]) {
  int ch;
  while ((ch = getchar()) != '\n') {
    int idx = tolower(ch) - 'a';
    counts[idx]++;
  }
}

bool equal_array(int counts1[ALPHABET_SIZE], int counts2[ALPHABET_SIZE]) {
  bool is_equal = true;

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (counts1[i] != counts2[i]) {
      is_equal = false;
      break;
    }
  }

  return is_equal;
}

void create_magic_square(int n, int magic_square[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      magic_square[i][j] = 0;
    }
  }

  int x_pos = 0;
  int y_pos = n / 2;
  magic_square[x_pos][y_pos] = 1;

  for (int i = 2; i <= n * n; i++) {
    x_pos--;
    y_pos++;

    if (x_pos < 0) {
      x_pos = n - 1;
    }
    if (y_pos > n - 1) {
      y_pos = 0;
    }

    if (magic_square[x_pos][y_pos] != 0) {
      x_pos++;
    }

    magic_square[x_pos][y_pos] = i;
  }
}

void print_magic_square(int n, int magic_square[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%3d ", magic_square[i][j]);
    }
    printf("\n");
  }
}

int calculate_polynomial(int x) {
  int x_sqr = x * x;
  int x_pow_4 = x_sqr * x_sqr;

  return 3 * x_pow_4 * x + 2 * x_pow_4 - 5 * x * x_sqr - x_sqr + 7 * x - 6;
}

int power(int x, int n) {
  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0) {
    int base = power(x, n / 2);
    return base * base;
  } else {
    return x * power(x, n - 1);
  }
}

int roll_dice(void) {
  int d1 = rand() % 6;
  int d2 = rand() % 6;

  return d1 + d2;
}

bool play_game(void) {
  int point = roll_dice();
  printf("you rolled: %2d\n", point);
  if (point == 7 || point == 11) {
    return true;
  }
  if (point == 2 || point == 3 || point == 12) {
    return false;
  }

  printf("your point is %2d\n", point);

  while (1) {
    int dice = roll_dice();
    printf("you rolled: %2d\n", dice);
    if (dice == 7) {
      return false;
    }
    if (dice == 8 || dice == point) {
      return true;
    }
  }
}

void proj1(void) {
  int a[PROJ1_MAX_SIZE] = {0};
  int len = 0;

  printf("enter a series of integers: ");
  while (1) {
    scanf("%d", &a[len]);
    len++;

    int ch = getchar();
    if (ch == ' ') {
      continue;
    }
    if (ch == '\n') {
      break;
    }
  }

  selection_sort(a, len);

  printf("sorted: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
}

void proj2(void) {
  float income;
  printf("enter the amount of taxable income: ");
  scanf("%f", &income);

  float tax = income_tax(income);

  printf("tax due: $%.2f\n", tax);
}

void proj3(void) {
  char area[10][10];
  generate_random_walk(area);
  print_walk(area);
}

void proj4(void) {
  int first_word_letters[ALPHABET_SIZE] = {0};
  int second_word_letters[ALPHABET_SIZE] = {0};

  printf("enter first word: ");
  read_word(first_word_letters);

  printf("enter second word: ");
  read_word(second_word_letters);

  bool is_equal = equal_array(first_word_letters, second_word_letters);
  if (is_equal) {
    printf("the words are anagrams.");
  } else {
    printf("the words are not anagrams.");
  }
}

void proj5(void) {
  printf("this program creates a magic square of a specified size.\n");
  printf("the size must be an odd number between 1 and 99.\n");

  int size;
  printf("enter size of magic square: ");
  scanf("%d", &size);

  int square[size][size];
  create_magic_square(size, square);

  print_magic_square(size, square);
}

void proj6(void) {
  printf("enter an integer: ");
  int x;
  scanf("%d", &x);

  int res = calculate_polynomial(x);

  printf("the result is %d\n", res);
}

void proj7(void) {
  printf("enter an integer: ");
  int x;
  scanf("%d", &x);

  printf("enter its power: ");
  int n;
  scanf("%d", &n);

  int res = power(x, n);

  printf("%d^%d = %d", x, n, res);
}

void proj8(void) {
  int wins = 0;
  int losses = 0;

  srand((unsigned)time(NULL));

  while (1) {
    if (play_game()) {
      printf("you won!\n");
      wins++;
    } else {
      printf("you lose!\n");
      losses++;
    }

    printf("\nplay again? ");
    int answer = getchar();

    // Clear out the remaining bytes on stdin.
    char l;
    while ((l = getchar()) != '\n')
      ;

    printf("\n");

    if (tolower(answer) != 'y') {
      break;
    }
  }

  printf("wins: %3d\tlosses: %3d", wins, losses);
}

int main(void) {
  proj1();
  proj2();
  proj3();
  proj4();
  proj5();
  proj6();
  proj7();
  proj8();

  return 0;
}
