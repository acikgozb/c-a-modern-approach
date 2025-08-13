// Contains solutions for the programming projects
// written in Section 8.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PROJ1_NUM_SIZE 10
#define PROJ3_NUM_SIZE 10
#define PROJ4_NUM_SIZE 3
#define PROJ5_INITIAL_BALANCE 100.00
#define PROJ6_MSG_SIZE 25
#define PROJ15_MSG_SIZE 80
#define PROJ16_WORD_SIZE 20

#define ALPHABET_SIZE 26

void proj1(void) {
  bool digits[PROJ1_NUM_SIZE] = {false};
  int rep_digits[PROJ1_NUM_SIZE] = {};
  int rep_len = 0;

  printf("enter a number: ");
  long n;
  scanf("%ld", &n);

  int d;
  while (n > 0) {
    d = n % 10;
    if (digits[d]) {
      rep_digits[rep_len] = d;
      rep_len++;
    } else {
      digits[d] = true;
    }
    n /= 10;
  }

  if (rep_len == 0) {
    printf("no repeated digit");
  } else {
    printf("repeated digit(s):");
    for (int i = 0; i < rep_len; i++) {
      printf(" %d", rep_digits[i]);
    }
  }
}

void proj2(void) {
  int occurrences[10] = {0};

  printf("enter a number: ");
  long n;
  scanf("%ld", &n);

  int d;
  while (n > 0) {
    d = n % 10;
    occurrences[d]++;
    n /= 10;
  }

  printf("digit:      ");
  for (int i = 0; i < 10; i++) {
    printf(" %3d", i);
  }

  printf("\noccurrences:");
  for (int i = 0; i < 10; i++) {
    printf(" %3d", occurrences[i]);
  }
}

void proj3(void) {
  long n, remainder;
  bool digits[PROJ3_NUM_SIZE] = {false};
  int d;

  while (1) {
    printf("enter a number (n <= 0 to exit): ");
    scanf("%ld", &n);

    if (n <= 0) {
      break;
    }

    remainder = n;
    while (remainder > 0) {
      d = remainder % 10;
      if (digits[d]) {
        break;
      } else {
        digits[d] = true;
      }
      remainder /= 10;
    }

    if (remainder > 0) {
      printf("repeated digit\n");
    } else {
      printf("no repeated digit\n");
    }

    for (int i = 0; i < PROJ3_NUM_SIZE; i++) {
      digits[i] = false;
    }
  }
}

void proj4(void) {
  int a[PROJ4_NUM_SIZE], i;
  printf("enter %d numbers: ", PROJ4_NUM_SIZE);
  for (i = 0; i < PROJ4_NUM_SIZE; i++) {
    scanf("%d", &a[i]);
  }

  int len = (int)(sizeof(a) / sizeof(a[0]));

  printf("in reverse order:");
  for (i = len - 1; i >= 0; i--) {
    printf(" %d", a[i]);
  }

  printf("\n");
}

void proj5(void) {
  int i, low_rate, num_years, year;
  double value[5];

  printf("enter interest rate: ");
  scanf("%d", &low_rate);
  printf("enter number of years: ");
  scanf("%d", &num_years);

  int len = (int)(sizeof(value) / sizeof(value[0]));

  // First row.
  printf("\nYears");
  for (i = 0; i < len; i++) {
    printf("%6d%%", low_rate + i);
    value[i] = PROJ5_INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++) {
    printf("%3d    ", year);
    for (i = 0; i < len; i++) {
      for (int month = 1; month <= 12; month++) {
        value[i] += (low_rate + i) / 100.0 * value[i];
      }
      printf("%7.2f", value[i]);
    }
    printf("\n");
  }
}

// NOTE: Since the length of the message is not given,
// and the heap allocated arrays are not covered yet,
// the stack allocation is done based on the message
// provided in the project:
// Hey dude, C is rilly cool
void proj6(void) {
  char msg[PROJ6_MSG_SIZE];
  printf("enter message: ");
  for (int i = 0; i < PROJ6_MSG_SIZE; i++) {
    msg[i] = getchar();
  }

  for (int i = 0; i < PROJ6_MSG_SIZE; i++) {
    char ch = toupper(msg[i]);
    switch (ch) {
    case 'A':
      ch = '4';
      break;
    case 'B':
      ch = '8';
      break;
    case 'E':
      ch = '3';
      break;
    case 'I':
      ch = '1';
      break;
    case 'O':
      ch = '0';
      break;
    case 'S':
      ch = '5';
      break;
    default:
      break;
    }
    printf("%c", ch);
  }

  printf("!!!!!!!!!!\n");
}

void proj7(void) {
  int nums[5][5];

  for (int i = 0; i < 5; i++) {
    printf("enter row %d: ", i + 1);
    for (int j = 0; j < 5; j++) {
      scanf("%d", &nums[i][j]);
    }
  }

  printf("row totals:");
  for (int i = 0; i < 5; i++) {
    int r_sum = 0;
    for (int j = 0; j < 5; j++) {
      r_sum += nums[i][j];
    }
    printf(" %d", r_sum);
  }

  printf("\n");

  printf("column totals:");
  for (int i = 0; i < 5; i++) {
    int c_sum = 0;
    for (int j = 0; j < 5; j++) {
      c_sum = nums[j][i];
    }
    printf(" %d", c_sum);
  }

  printf("\n");
}

void proj8(void) {
  int grades[5][5];

  for (int i = 0; i < 5; i++) {
    printf("enter grade for student %d: ", i + 1);
    for (int j = 0; j < 5; j++) {
      scanf("%d", &grades[i][j]);
    }
  }

  int student_scores[5][2];
  int quiz_scores[5][3];
  for (int i = 0; i < 5; i++) {
    int student_total_score = 0;
    int student_avg_score = 0;

    int quiz_lowest_score = grades[i][0];
    int quiz_highest_score = grades[i][0];

    for (int j = 0; j < 5; j++) {
      student_total_score += grades[i][j];

      int quiz_score = grades[j][i];
      if (quiz_lowest_score > quiz_score) {
        quiz_lowest_score = quiz_score;
      }
      if (quiz_highest_score < quiz_score) {
        quiz_highest_score = quiz_score;
      }
    }

    student_avg_score = student_total_score / 5;
    student_scores[i][0] = student_avg_score;
    student_scores[i][1] = student_total_score;

    int quiz_avg_score = (quiz_lowest_score + quiz_highest_score) / 2;
    quiz_scores[i][0] = quiz_avg_score;
    quiz_scores[i][1] = quiz_lowest_score;
    quiz_scores[i][2] = quiz_highest_score;
  }

  printf("total score of students:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", student_scores[i][1]);
  }
  printf("\n");

  printf("average score of students:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", student_scores[i][0]);
  }
  printf("\n");

  printf("highest score of each quiz:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", quiz_scores[i][2]);
  }
  printf("\n");

  printf("lowest score of each quiz:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", quiz_scores[i][1]);
  }
  printf("\n");
  printf("average score of each quiz:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", quiz_scores[i][0]);
  }
  printf("\n");
}

void proj9(void) {
  char area[10][10] = {
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  };

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

      if (area[dir_y][dir_x] != '.') {
        continue;
      }

      area[dir_y][dir_x] = steps[i];
      current_pos_x = dir_x;
      current_pos_y = dir_y;
      walk_succeeded = true;
      break;
    }

    if (!walk_succeeded) {
      break;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c ", area[i][j]);
    }
    printf("\n");
  }
}

// NOTE: I probably misunderstood this, because showing
// the departure/arrival time as minutes is not really intuitive.
// And storing them as string would require a string array, which is
// not introduced yet.
void proj10(void) {
  int t_deps[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
  int t_arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

  int hour, minute;
  char time_format;
  printf("enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute, &time_format);

  if (toupper(time_format) == 'P') {
    hour += 12;
  }

  int t_user = hour * 60 + minute;

  int t_next_dep = -1;
  for (int i = 0; i < 8; i++) {
    if (t_user < t_deps[i]) {
      t_next_dep = t_deps[i];
    }
  }

  int t_closest_dep;
  int t_arrival;
  if (t_next_dep == -1) {
    t_closest_dep = t_deps[7];
    t_arrival = t_arrivals[7];
  } else {
    int t_prev_dep = t_deps[t_next_dep - 1];
    if (t_user >= t_prev_dep + (t_next_dep - t_prev_dep) / 2) {
      t_closest_dep = t_deps[t_next_dep];
      t_arrival = t_arrivals[t_next_dep];
    } else {
      t_closest_dep = t_prev_dep;
      t_arrival = t_arrivals[t_next_dep - 1];
    }
  }

  printf(
      "the closest departure time in minutes is %d, and arrival time is %d\n",
      t_closest_dep, t_arrival);
}

void proj11(void) {
  char num[14];

  printf("enter phone number: ");
  for (int i = 0; i < 14; i++) {
    num[i] = getchar();
  }

  printf("in numeric form: ");
  for (int i = 0; i < 14; i++) {
    char digit = num[i];

    switch (digit) {
    case 'A':
    case 'B':
    case 'C':
      digit = '2';
      break;
    case 'D':
    case 'E':
    case 'F':
      digit = '3';
      break;
    case 'G':
    case 'H':
    case 'I':
      digit = '4';
      break;
    case 'J':
    case 'K':
    case 'L':
      digit = '5';
      break;
    case 'M':
    case 'N':
    case 'O':
      digit = '6';
      break;
    case 'P':
    case 'R':
    case 'S':
      digit = '7';
      break;
    case 'T':
    case 'U':
    case 'V':
      digit = '8';
      break;
    case 'W':
    case 'X':
    case 'Y':
      digit = '9';
      break;
    default:
      break;
    }

    printf("%c", digit);
  }

  printf("\n");
}

void proj12(void) {
  int s_values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  printf("enter scrabble word: ");

  int s_value = 0;
  char ch;
  while ((ch = getchar()) != '\n') {
    // In ASCII, the letters are contiguous.
    // Therefore, the position of a single letter can be
    // found relatively by subtracting from the first letter.
    int letter_pos = (toupper(ch) - 'A');

    s_value += s_values[letter_pos];
  }

  printf("scrabble value: %d", s_value);
}

void proj13(void) {
  printf("enter a first and last name: ");

  char f_letter;
  scanf("%c", &f_letter);

  char ch;
  // The remaining letters of the first name
  // are meaningless, so remove them from the
  // buffer.
  while ((ch = getchar()) != ' ')
    ;

  char last_name[20];
  for (int i = 0; i < 20; i++) {
    char letter = getchar();
    last_name[i] = letter;

    if (letter == '\n') {
      break;
    }
  }

  printf("you entered the name: ");
  for (int i = 0; i < 20; i++) {
    char letter = last_name[i];
    if (letter == '\n') {
      break;
    }
    printf("%c", last_name[i]);
  }

  printf(", %c.\n", f_letter);
}

void proj14(void) {
  // Since the max length of a sentence is not given
  // in the project, I set the example sentence's length.
  char sentence[32];

  printf("enter a sentence: ");

  for (int i = 0; i < 32; i++) {
    char letter = getchar();
    sentence[i] = letter;
  }

  char last_letter = getchar();

  printf("reversal of sentence: ");

  int word_end_pos = 31;
  for (int i = word_end_pos; i >= 0; i--) {
    char letter = sentence[i];
    if (letter == ' ' || i == 0) {
      if (i == 0) {
        printf("%c", letter);
      }
      for (int j = i + 1; j <= word_end_pos; j++) {
        printf("%c", sentence[j]);
      }

      if (i != 0) {
        printf(" ");
      }

      word_end_pos = i - 1;
    }
  }

  printf("%c\n", last_letter);
}

void proj15(void) {
  char msg[PROJ15_MSG_SIZE];

  printf("enter message to be encrypted: ");
  int msg_len = 0;
  for (int i = 0; i < PROJ15_MSG_SIZE; i++) {
    char letter = getchar();
    if (letter == '\n') {
      break;
    }

    msg[i] = letter;
    msg_len++;
  }

  int shift;
  printf("enter shift amount (1-25): ");
  scanf("%d", &shift);

  printf("encrypted message: ");
  for (int i = 0; i < msg_len; i++) {
    char letter = msg[i];

    if (!isalpha(letter)) {
      printf("%c", letter);
      continue;
    }

    char ascii_ref = 'a';
    char uppercase = toupper(letter);
    if (letter == uppercase) {
      ascii_ref = 'A';
    }

    int encrypted_letter = ((letter - ascii_ref) + shift) % 26 + ascii_ref;
    printf("%c", encrypted_letter);
  }

  printf("\n");
}

void proj16(void) {
  int letter_occurrences[ALPHABET_SIZE] = {0};

  printf("enter first word: ");
  char ch;
  while ((ch = getchar()) != '\n') {
    int idx = tolower(ch) - 'a';
    letter_occurrences[idx]++;
  }

  printf("enter second word: ");
  while ((ch = getchar()) != '\n') {
    int idx = tolower(ch) - 'a';
    letter_occurrences[idx]--;
  }

  bool all_zeroes = true;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    int occurrence = letter_occurrences[i];
    if (occurrence != 0) {
      all_zeroes = false;
    }
  }

  if (all_zeroes) {
    printf("the words are anagrams.");
  } else {
    printf("the words are not anagrams.");
  }
}

void proj17(void) {
  printf("this program creates a magic square of a specified size.\n");
  printf("the size must be an odd number between 1 and 99.\n");
  int size;
  printf("enter size of magic square: ");
  scanf("%d", &size);

  int square[size][size];
  // Since we can't use array init for VLA's
  // we need to zero the entire memory of the
  // array by ourselves.
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      square[i][j] = 0;
    }
  }

  int x_pos = 0;
  int y_pos = size / 2;
  square[x_pos][y_pos] = 1;

  for (int i = 2; i <= size * size; i++) {
    x_pos--;
    y_pos++;

    if (x_pos < 0) {
      x_pos = size - 1;
    }
    if (y_pos > size - 1) {
      y_pos = 0;
    }

    if (square[x_pos][y_pos] != 0) {
      x_pos++;
    }

    square[x_pos][y_pos] = i;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%3d ", square[i][j]);
    }
    printf("\n");
  }
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
  proj9();
  proj10();
  proj11();
  proj12();
  proj13();
  proj14();
  proj15();
  proj16();
  proj17();

  return 0;
}
