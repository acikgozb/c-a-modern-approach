// Remove the global arrays in `poker.c` example and have the program store the
// cards in a 5x2 array. Each row of the array represents a card. The first
// element of a row represents the rank of a card. The second element of a row
// represents the suit of a card.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards(int hand[5][2]);
void analyze_hand(int hand[5][2]);
void print_result(void);

int main(void) {
  int hand[5][2];
  for (;;) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

void read_cards(int hand[5][2]) {
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  for (int i = 0; i < NUM_CARDS; i++) {
    hand[i][0] = 0;
    hand[i][1] = 0;
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
      continue;
    }

    bool card_exists = false;
    for (int i = 0; i < cards_read; i++) {
      int c_rank = hand[i][0];
      int c_suit = hand[i][1];
      if (c_rank == rank && c_suit == suit) {
        card_exists = true;
        break;
      }
    }

    if (card_exists) {
      printf("duplicate card; ignored.\n");
    } else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

void analyze_hand(int hand[5][2]) {
  straight = false;
  four = false;
  three = false;
  pairs = 0;

  // flush.
  flush = false;
  int suit;
  for (suit = 0; suit < NUM_SUITS; suit++) {
    int s_count = 0;

    for (int i = 0; i < NUM_CARDS; i++) {
      if (hand[i][1] == suit) {
        s_count++;
      }
    }
    if (s_count == NUM_CARDS) {
      flush = true;
      break;
    }
  }

  // straight.
  int ranks[NUM_RANKS] = {0};
  for (int i = 0; i < NUM_CARDS; i++) {
    ranks[hand[i][0]]++;
  }

  int rank = 0;
  while (ranks[rank] == 0) {
    rank++;
  }

  int num_consec = 0;
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
