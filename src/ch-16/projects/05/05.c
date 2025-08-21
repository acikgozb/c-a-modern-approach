// Modify Project 8 from Chapter 5 so that the times are stored in a single
// array. The elements of the array will be structures, each containing a
// departure time and the correspoding arrival time. The program will use a loop
// to search the array for the departure time closest to the time entered by the
// user.

#include <stdio.h>

struct flight {
  int departure_time;
  int arrival_time;
};

int find_closest_flight(const struct flight flights[], int len, int time);
void print_flight(const struct flight *flight);

int main(void) {
  const struct flight flights[] = {
      {.departure_time = 480, .arrival_time = 616},
      {.departure_time = 583, .arrival_time = 712},
      {.departure_time = 679, .arrival_time = 811},
      {.departure_time = 767, .arrival_time = 900},
      {.departure_time = 840, .arrival_time = 968},
      {.departure_time = 945, .arrival_time = 1075},
      {.departure_time = 1140, .arrival_time = 1280},
      {.departure_time = 1305, .arrival_time = 1438},
  };
  int len = sizeof(flights) / sizeof(flights[0]);

  int hour, minute;
  printf("enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);

  int time = hour * 60 + minute;
  int flight_num = find_closest_flight(flights, len, time);

  print_flight(&flights[flight_num]);

  return 0;
}

int find_closest_flight(const struct flight flights[], int len, int time) {
  int closest = -1;

  for (int i = 0; i < len - 1; i++) {
    int d1 = flights[i].departure_time;
    int d2 = flights[i + 1].departure_time;

    if (time <= d1 + (d2 - d1) / 2) {
      closest = i;
      break;
    }
  }

  if (closest == -1) {
    closest = len - 1;
  }

  return closest;
}

void print_flight(const struct flight *flight) {
  int d_hour = flight->departure_time / 60;
  int d_min = flight->departure_time % 60;

  int a_hour = flight->arrival_time / 60;
  int a_min = flight->arrival_time % 60;

  printf("closest departure is: %.2d:%.2d, arriving at %.2d:%.2d\n", d_hour,
         d_min, a_hour, a_min);
}
