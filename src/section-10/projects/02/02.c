// Modify the `poker.c` example by moving the global arrays `num_in_rank` and
// `num_in_suit` into `main`.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards(int ranks[NUM_RANKS], int suits[NUM_SUITS]);
void analyze_hand(int ranks[NUM_RANKS], int suits[NUM_SUITS]);
void print_result(void);

int main(void) {
  int num_in_rank[NUM_RANKS];
  int num_in_suits[NUM_SUITS];

  for (;;) {
    read_cards(num_in_rank, num_in_suits);
    analyze_hand(num_in_rank, num_in_suits);
    print_result();
  }
}

void read_cards(int ranks[NUM_RANKS], int suits[NUM_SUITS]) {
  bool card_exists[NUM_RANKS][NUM_SUITS];
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  for (rank = 0; rank < NUM_RANKS; rank++) {
    ranks[rank] = 0;
    for (suit = 0; suit < NUM_SUITS; suit++) {
      card_exists[rank][suit] = false;
    }
  }

  for (suit = 0; suit < NUM_SUITS; suit++) {
    suits[suit] = 0;
  }

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("enter a card: ");
    rank_ch = getchar();
    switch (rank_ch) {
    case '0':
      exit(EXIT_SUCCESS);
    case '2':
      rank = 0;
      break;
    case '3':
      rank = 1;
      break;
    case '4':
      rank = 2;
      break;
    case '5':
      rank = 3;
      break;
    case '6':
      rank = 4;
      break;
    case '7':
      rank = 5;
      break;
    case '8':
      rank = 6;
      break;
    case '9':
      rank = 7;
      break;
    case 't':
      rank = 8;
      break;
    case 'j':
    case 'T':
      rank = 9;
      break;
    case 'q':
    case 'Q':
      rank = 10;
      break;
    case 'k':
    case 'K':
      rank = 11;
      break;
    case 'a':
    case 'A':
      rank = 12;
      break;
    default:
      bad_card = true;
      break;
    }

    suit_ch = getchar();
    switch (suit_ch) {
    case 'c':
    case 'C':
      suit = 0;
      break;
    case 'd':
    case 'D':
      suit = 1;
      break;
    case 'h':
    case 'H':
      suit = 2;
      break;
    case 's':
    case 'S':
      suit = 3;
      break;
    default:
      bad_card = true;
    }

    while ((ch = getchar()) != '\n') {
      if (ch == ' ') {
        bad_card = true;
      }
    }

    if (bad_card) {
      printf("bad card; ignored.\n");
    } else if (card_exists[rank][suit]) {
      printf("duplicate card; ignored.\n");
    } else {
      ranks[rank]++;
      suits[suit]++;
      card_exists[rank][suit] = true;
      cards_read++;
    }
  }
}

void analyze_hand(int ranks[NUM_RANKS], int suits[NUM_SUITS]) {
  int num_consec = 0;
  int rank, suit;

  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  // flush.
  for (suit = 0; suit < NUM_SUITS; suit++) {
    if (suits[suit] == NUM_CARDS) {
      flush = true;
    }
  }

  // straight.
  rank = 0;
  while (ranks[rank] == 0) {
    rank++;
  }
  for (; rank < NUM_RANKS && ranks[rank] > 0; rank++) {
    num_consec++;
  }
  if (num_consec == NUM_CARDS) {
    straight = true;
    return;
  }

  // four-of-a-kind, three-of-a-kind, and pairs.
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (ranks[rank] == 4) {
      four = true;
    }
    if (ranks[rank] == 3) {
      three = true;
    }
    if (ranks[rank] == 2) {
      pairs++;
    }
  }
}

void print_result(void) {
  if (straight && flush) {
    printf("straight flush");
  } else if (four) {
    printf("four of a kind");
  } else if (three && pairs == 1) {
    printf("full house");
  } else if (flush) {
    printf("flush");
  } else if (straight) {
    printf("straight");
  } else if (three) {
    printf("three of a kind");
  } else if (pairs == 2) {
    printf("two pairs");
  } else if (pairs == 1) {
    printf("pair");
  } else {
    printf("high card");
  }

  printf("\n\n");
}
